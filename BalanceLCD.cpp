#include "BalanceLCD.h"
#include <LCDLib.h>
#include "Keyboard.h"
#include "Foods.h"
#include "Calibration.h"
#include "SmartBalance.h"
#include "EepromAddr.h"
#include <EEPROM.h>

#define MAX_LCD_LINE_MENU 3


PREFERENCE_TYPE FoodPreference[MAX_PREFERENCE] = 
{
	{FOOD_1_ADDR, FOOD_1_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_2_ADDR, FOOD_2_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_3_ADDR, FOOD_3_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_4_ADDR, FOOD_4_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
};

uint8_t  CategoryChoice;
uint16_t  FoodChoice;
MAIN_FUNCTIONS WichFunction;
uint8_t PreferenceNumber;
uint16_t CaloriesReached = 0;
uint16_t MacrosReached = 0;
uint8_t MacroChoiced = 0;

short UpArrow[] = 
{
	0x04,
	0x0E,
	0x1F,
	0x04,
	0x04,
	0x04,
	0x04,
	0x04,
};

short DownArrow[] = 
{
	0x04,
	0x04,
	0x04,
	0x04,
	0x04,
	0x1F,
	0x0E,
	0x04,
};

short ToRightArrow[] = 
{
	0x08,
	0x0C,
	0x0E,
	0x0F,
	0x0F,
	0x0E,
	0x0C,
	0x08
};

short ToLeftArrow[] = 
{
	0x02,
	0x06,
	0x0E,
	0x1E,
	0x1E,
	0x0E,
	0x06,
	0x02
};

String MenuTitle[] = 
{
	"Bilancia",
	"Informazioni",
	"Pasto",
	"Preferito 1",
	"Preferito 2",
	"Preferito 3",
	"Preferito 4",
	"Calibrazione",
};

enum
{
	PER_CALORIE = 0,
	PER_MACROS,
	MAX_LAUNCH_CHOICE	
};

typedef enum
{
	CARBS = 0,
	PROTEINS,
	FATS,
	MAX_MACROS_TYPE
}MACROS_TYPE;

String LaunchMenuStr[] =
{
	"Per calorie",
	"Per macros",	
};

String MacrosName[] = 
{
	"Carboidrati",
	"Proteine",
	"Grassi",
};

void PreferenceInit()
{
	for(uint8_t PrefIndex = 0; PrefIndex < MAX_PREFERENCE; PrefIndex++)
	{
		FoodPreference[PrefIndex].CategoryValue = EEPROM.read(FoodPreference[PrefIndex].CategoryAddr);
		FoodPreference[PrefIndex].FoodValue = EEPROM.read(FoodPreference[PrefIndex].FoodAddr);
	}	
	yield();
}


// Prima la scelta della categoria, poi la scelta dell'alimento
bool FoodChoiceMenu() 
{
	bool IsCategory = true, IsFood = false; // Se vero selezioni la categoria altrimenti il cibo
	uint8_t Category = 0;
	uint16_t Food = 0, FoodMaxItem = 0;
	bool ExitFoodChoice = false, ChoiceComplete = false;
	uint8_t ButtonPress = NO_PRESS;
	String NumItem;
	ClearLCD();
	if(CategoryChoice == MAX_CATEGORY && FoodChoice == MAX_FOOD)
	{
		while(!ExitFoodChoice)
		{
			CheckEvent();
			if(IsFood)
			{
				LCDPrintString(ONE, CENTER_ALIGN, String(CategoryTable[Category].CategoryName));
				LCDPrintString(TWO, CENTER_ALIGN, String(CategoryTable[Category].NutritionalTable[Food].FoodName));
				FoodMaxItem = *CategoryTable[Category].TableSizeArray;
				NumItem = String(Food + 1) + "/" + String(FoodMaxItem);
				LCDPrintString(FOUR, CENTER_ALIGN, NumItem);
			}
			if(IsCategory)
			{
				LCDPrintString(ONE, CENTER_ALIGN, "Categoria: ");
				LCDPrintString(TWO, CENTER_ALIGN, String(CategoryTable[Category].CategoryName));
				NumItem = String(Category + 1) + "/" + String(MAX_CATEGORIES);
				LCDPrintString(FOUR, CENTER_ALIGN, NumItem);
			}
			ButtonPress = KeyPressed();
			switch(ButtonPress)
			{
				case UP:
					if(IsCategory)
					{
						if(Category > 0)
							Category--;
						else
							Category = MAX_CATEGORIES - 1;
					}
					if(IsFood)
					{
						if(Food > 0)
							Food--;
						else
							Food = FoodMaxItem;
					}
					ClearLCDLine(TWO);
					break;
				case DOWN:
					if(IsCategory)
					{
						if(Category < MAX_CATEGORIES - 1)
							Category++;
						else
							Category = 0;
					}
					if(IsFood)
					{
						if(Food < FoodMaxItem)
							Food++;
						else
							Food = 0;
					}
					ClearLCDLine(TWO);
					break;
				case OK_TARE:
					if(IsCategory)
					{
						IsFood = true;
						IsCategory = false;
						CategoryChoice = Category;
						ClearLCD();
					}
					if(IsFood)
					{
						IsFood = false;
						ChoiceComplete = true;
						FoodChoice = Food;
						ExitFoodChoice = true;
					}
					break;
				case EXIT:
					ExitFoodChoice = true;
					CategoryChoice = MAX_CATEGORY;
					FoodChoice = MAX_FOOD;
					break;
				default:
					break;
			}
			yield();
		}
	}
	else
	{
		ChoiceComplete = true;
	}
	return ChoiceComplete;
}

void ShowMeasure()
{
	uint8_t ButtonPress = NO_PRESS;
	float Weight = 0.0, OldWeight = 0.0;
	uint16_t Food = FoodChoice, FoodItemMax = *CategoryTable[CategoryChoice].TableSizeArray, Calories = 0;
	uint16_t Carbs = 0, Protein = 0, Fats = 0;
	bool ExitShowMeasure = false;
	char Values[5];
	String WeightStr, CaloriesStr, CarbsStr, ProtStr, FatsStr;
	ClearLCD();
	while(!ExitShowMeasure)
	{
		LCDPrintString(ONE, CENTER_ALIGN, String(CategoryTable[CategoryChoice].NutritionalTable[Food].FoodName));
		Weight = GetWeight();
		CalcNutritionalValues(Weight, CategoryChoice, Food, &Calories, &Carbs, &Protein, &Fats);
		WeightStr = String(Weight, 4) + "g";
		snprintf(Values, 5, "%   d", Calories);
		CaloriesStr = String(Values) + "kcal";
		snprintf(Values, 5, "%   d", Carbs);
		CarbsStr = "C: " + String(Values)    + "g";
		snprintf(Values, 5, "%   d", Protein);
		ProtStr = "P: " + String(Values)  + "g";
		snprintf(Values, 5, "%   d", Fats);
		FatsStr = "G: " + String(Values)     + "g";
		LCDPrintString(TWO, LEFT_ALIGN, WeightStr);
		LCDPrintString(TWO, RIGHT_ALIGN, CaloriesStr);
		LCDPrintString(THREE, LEFT_ALIGN, CarbsStr);
		LCDPrintString(THREE, RIGHT_ALIGN, ProtStr);
		LCDPrintString(FOUR, CENTER_ALIGN, FatsStr);
		CheckEvent();
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case EXIT:
				ExitShowMeasure = true;
				if(Flags.LaunchModeCal)
					CaloriesReached += Calories;
				else if(Flags.LaunchModeMacro)
				{
					if(MacroChoiced == CARBS)
						MacrosReached += Carbs;
					else if(MacroChoiced == PROTEINS)
						MacrosReached += Protein;
					else
						MacrosReached += Fats;
				}
				else
				{
					CaloriesReached = 0;
					MacrosReached = 0;
				}
				CategoryChoice = MAX_CATEGORY;
				FoodChoice = MAX_FOOD;
				break;
			case UP:
				if(Food > 0)
					Food--;
				else
					Food = FoodItemMax;
				ClearLCD();
				break;
			case DOWN:
				if(Food < FoodItemMax)
					Food++;
				else
					Food = 0;
				ClearLCD();
				break;
			case OK_TARE:
				SetTare();
				ClearLCD();
				break;
			default:
				break;
		}
		OldWeight = Weight;
		yield();
	}
}

void ShowInfo()
{
	uint8_t ButtonPress = NO_PRESS;
	uint16_t Food = FoodChoice, FoodMaxItem = 0;
	uint16_t Category = CategoryChoice;
	bool ExitShowInfo = false;
	ClearLCD();
	String FoodName = String(CategoryTable[Category].NutritionalTable[Food].FoodName);
	String Calories = String(CategoryTable[Category].NutritionalTable[Food].Calories) + "kcal";
	String Carb = "C: " + String(CategoryTable[Category].NutritionalTable[Food].Carbs) + "g";
	String Prot = "P: " + String(CategoryTable[Category].NutritionalTable[Food].Prot) + "g";
	String Fats = "G: " + String(CategoryTable[Category].NutritionalTable[Food].Fats) + "g";
	String CategoryName = String(CategoryTable[Category].CategoryName);
	LCDPrintString(ONE, CENTER_ALIGN, "Valori in 100g di:");
	while(!ExitShowInfo)
	{
		FoodMaxItem = *CategoryTable[Category].TableSizeArray;
		FoodName = String(CategoryTable[Category].NutritionalTable[Food].FoodName);
		Calories = String(CategoryTable[Category].NutritionalTable[Food].Calories) + "kcal";
		Carb = "C: " + String(CategoryTable[Category].NutritionalTable[Food].Carbs) + "g";
		Prot = "P: " + String(CategoryTable[Category].NutritionalTable[Food].Prot) + "g";
		Fats = "G: " + String(CategoryTable[Category].NutritionalTable[Food].Fats) + "g";	
		LCDPrintString(TWO, CENTER_ALIGN, FoodName);
		LCDPrintString(THREE, LEFT_ALIGN, Calories);
		LCDPrintString(THREE, RIGHT_ALIGN, Carb);
		LCDPrintString(FOUR, LEFT_ALIGN, Prot);
		LCDPrintString(FOUR, RIGHT_ALIGN, Fats);
		CheckEvent();
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(Food > 0)
					Food--;
				else
					Food = FoodMaxItem;
				ClearLCDLine(TWO);
				ClearLCDLine(THREE);
				ClearLCDLine(FOUR);
				break;
			case DOWN:
				if(Food < FoodMaxItem)
					Food++;
				else
					Food = 0;
				ClearLCDLine(TWO);
				ClearLCDLine(THREE);
				ClearLCDLine(FOUR);
				break;
			case OK_TARE:
				if(Category < MAX_CATEGORIES - 1)
					Category++;
				else
					Category = 0;
				Food = 0;
				ClearLCD();
				CategoryName = String(CategoryTable[Category].CategoryName);
				LCDPrintString(TWO, CENTER_ALIGN, CategoryName);
				delay(1000);
				ClearLCDLine(TWO);
				LCDPrintString(ONE, CENTER_ALIGN, "Valori in 100g di:");
				break;
			case EXIT:
				ExitShowInfo = true;
				CategoryChoice = MAX_CATEGORY;
				FoodChoice = MAX_FOOD;
				break;
			default:
				break;		
		}
		yield();
	}
}



bool CheckPreference(uint8_t PreferenceChoice)
{
	bool Checked = false;
	if(FoodPreference[PreferenceChoice].CategoryValue == INVALID_EEPROM_VALUE && 
		FoodPreference[PreferenceChoice].FoodValue == INVALID_EEPROM_VALUE)
	{
		ClearLCD();
		LCDPrintString(ONE, CENTER_ALIGN, "Nessun cibo");
		LCDPrintString(TWO, CENTER_ALIGN, "memorizzato.");
		LCDPrintString(THREE, CENTER_ALIGN, "Impostarlo?");
		if(CheckYesNo())
		{
			ClearLCD();
			CategoryChoice = MAX_CATEGORY;
			FoodChoice = MAX_FOOD;
			if(FoodChoiceMenu())
			{
				// FoodPreference[PreferenceChoice].CategoryValue = CategoryChoice;
				// FoodPreference[PreferenceChoice].FoodValue = FoodChoice;
				EEPROM.write(FoodPreference[PreferenceChoice].CategoryAddr, CategoryChoice);
				EEPROM.write(FoodPreference[PreferenceChoice].FoodAddr, FoodChoice);
				EEPROM.commit();
				ClearLCD();
				LCDPrintString(TWO, CENTER_ALIGN, "Preferenza salvata");
				delay(1500);
				ClearLCD();
				Checked = true;
			}
			else
				Checked = false;
		}
		else
			Checked = false;
	}
	else
	{
		ClearLCD();
		LCDPrintString(TWO, CENTER_ALIGN, "Impostare una");
		LCDPrintString(THREE, CENTER_ALIGN, "nuova preferenza?");
		if(CheckYesNo())
		{
			ClearLCD();
			CategoryChoice = MAX_CATEGORY;
			FoodChoice = MAX_FOOD;
			if(FoodChoiceMenu())
			{
				// FoodPreference[PreferenceChoice].CategoryValue = CategoryChoice;
				// FoodPreference[PreferenceChoice].FoodValue = FoodChoice;
				EEPROM.write(FoodPreference[PreferenceChoice].CategoryAddr, CategoryChoice);
				EEPROM.write(FoodPreference[PreferenceChoice].FoodAddr, FoodChoice);
				EEPROM.commit();
				ClearLCD();
				LCDPrintString(TWO, CENTER_ALIGN, "Preferenza salvata");
				delay(1500);
				ClearLCD();
				Checked = true;
			}
			else
			{
				ClearLCD();
				LCDPrintString(TWO, CENTER_ALIGN, "Non salvata");
				delay(1500);
				ClearLCD();
				Checked = false;
			}
		}
		else
		{
			CategoryChoice = FoodPreference[PreferenceChoice].CategoryValue;
			FoodChoice = FoodPreference[PreferenceChoice].FoodValue;
			Checked = true;
		}
	}
	return Checked;
}

static void RefreshMenuChoice(String *Title, uint8_t MaxItem, uint8_t ItemPos, uint8_t FirstListItem)
{
	uint8_t Aux = 0;
	for(uint8_t MenuIndx = 0; MenuIndx < MAX_LCD_LINE_MENU; MenuIndx++)
	{
		Aux = FirstListItem + MenuIndx;
		if(Aux >= MaxItem)
			break;
		LCDPrintString(TWO + MenuIndx, AFTER_ARROW_POS, Title[MenuIndx]);
		yield();
	}

	LCDShowIcon(TO_RIGHT_ARROW, ItemPos, 0);	
}


void LaunchMenu()
{
	uint8_t ButtonPress = NO_PRESS;
	uint8_t ArrowPos = 1, OldArrowPos = 1;
	uint8_t TopItem = 0;
	bool ExitLaunchMenuChoice = false, ShowFunc = false;
	uint8_t FunctionChoice = 0;
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Scegli il calcolo");
	while(!ExitLaunchMenuChoice)
	{
		RefreshMenuChoice(LaunchMenuStr, MAX_LAUNCH_CHOICE, ArrowPos, TopItem);
		CheckEvent();
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case EXIT:
				ExitLaunchMenuChoice = true;
				break;
			case UP:
				if(FunctionChoice > 0)
					FunctionChoice--;
				else
					FunctionChoice = MAX_LAUNCH_CHOICE - 1;
				break;
			case DOWN:
				if(FunctionChoice < MAX_LAUNCH_CHOICE - 1)
					FunctionChoice++;
				else
					FunctionChoice = 0;
				break;
			case OK_TARE:
				ShowFunc = true;
				ExitLaunchMenuChoice = true;
				break;
			default:
				break;			
			
		}
		if(FunctionChoice < MAX_LCD_LINE_MENU)
		{
			TopItem = 0;
			ArrowPos = FunctionChoice  + 1;
			if(OldArrowPos != ArrowPos)
			{
				ClearChar(OldArrowPos, 0);
				OldArrowPos = ArrowPos;
			}
		}
		else
		{
			TopItem = FunctionChoice - MAX_LCD_LINE_MENU + 1;
			ArrowPos = MAX_LCD_LINE_MENU;
			if(OldArrowPos != ArrowPos)
			{
				ClearChar(OldArrowPos, 0);
				OldArrowPos = ArrowPos;
			}
		}
		yield();
	}
	if(ShowFunc)
	{
		if(FunctionChoice == PER_CALORIE)
			CompleteLaunchCalories();
		else
			CompleteLaunchMacros();
	}		
}



void CompleteLaunchMacros()
{
	uint8_t ButtonPress = NO_PRESS;
	uint8_t WichMacro = 0;
	uint16_t MacrosTarget = 0;
	uint8_t DishesNumber = 0, DishIndex = 0;
	bool ChoiceTargetAndDishes = false, ChoiceMacro = false, Target = true, Dishes = false;
	ClearLCD();
	Flags.LaunchModeMacro = true;
	while(!ChoiceMacro)
	{
		LCDPrintString(ONE, CENTER_ALIGN, "Scegli il tipo");
		LCDPrintString(TWO, CENTER_ALIGN, "di macronutriente");
		LCDPrintString(THREE, CENTER_ALIGN, MacrosName[WichMacro]);
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(WichMacro > 0)
					WichMacro--;
				else
					WichMacro = MAX_MACROS_TYPE - 1;
				ClearLCDLine(THREE);
				break;
			case DOWN:
				if(WichMacro < MAX_MACROS_TYPE - 1)
					WichMacro++;
				else
					WichMacro = 0;
				ClearLCDLine(THREE);
				break;
			case OK_TARE:
				ChoiceMacro = true;
				break;
			case EXIT:
				Flags.LaunchModeMacro = false;
				return;
				break;
			default:
				break;
		}
		yield();				
	}
	MacroChoiced = WichMacro;
	ClearLCD();
	while(!ChoiceTargetAndDishes)
	{
		if(Target)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Quanti grammi di");
			LCDPrintString(TWO, CENTER_ALIGN, MacrosName[WichMacro]);
			LCDPrintString(THREE, CENTER_ALIGN, "vuoi raggiungere?");
			LCDPrintString(FOUR, CENTER_ALIGN, String(MacrosTarget) + "g");
		}
		if(Dishes)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Scegli il numero");
			LCDPrintString(TWO, CENTER_ALIGN, "di piatti");
			LCDPrintString(THREE, CENTER_ALIGN, "del tuo pasto:");
			LCDPrintString(FOUR, CENTER_ALIGN, String(DishesNumber));			
		}
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(Target)
				{
					if(MacrosTarget > 0)
						MacrosTarget -= 10;
					else
						MacrosTarget = 1000;
				}
				if(Dishes)
				{
					if(DishesNumber > 0)
						DishesNumber--;
					else
						DishesNumber = 10;
				}
				ClearLCDLine(FOUR);
				break;
			case DOWN:
				if(Target)
				{
					if(MacrosTarget < 1000)
						MacrosTarget += 10;
					else
						MacrosTarget = 0;
				}
				if(Dishes)
				{
					if(DishesNumber < 10)
						DishesNumber++;
					else
						DishesNumber = 0;
				}
				ClearLCDLine(FOUR);
				break;
			case OK_TARE:
				if(Target)
				{
					Target = false;
					Dishes = true;
				}
				else if(Dishes)
				{
					ChoiceTargetAndDishes = true;
				}
				break;
			case EXIT:
				Flags.LaunchModeMacro = false;
				return;
				break;
			default:
				break;
		}
		yield();
	}
	MacrosReached = 0;
	for(DishIndex = 1; DishIndex <= DishesNumber; DishesNumber++)
	{
		int32_t Diff = MacrosTarget - MacrosReached;
		ClearLCD();
		LCDPrintString(ONE, CENTER_ALIGN, "Piatto "+ String(DishesNumber));
		LCDPrintString(TWO, CENTER_ALIGN, "Per continuare");
		Wait(THREE, false);
		if(FoodChoiceMenu())
		{
			ShowMeasure();
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Grammi rimanenti:");
			LCDPrintString(TWO, CENTER_ALIGN, String(Diff) + "g");
			LCDPrintString(THREE, CENTER_ALIGN, "Per continuare");
			Wait(FOUR, false);
		}
		else
			continue;
		if(Diff <= 0)
		{
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Grammi target");
			LCDPrintString(TWO, CENTER_ALIGN, "raggiunti!");	
			delay(1500);
			if(Diff < 0)
			{
				Diff = -Diff;
				ClearLCD();
				LCDPrintString(ONE, CENTER_ALIGN, "Superato il target");
				LCDPrintString(TWO, CENTER_ALIGN, "di:");	
				LCDPrintString(THREE, CENTER_ALIGN, String(Diff) + "g");	
				delay(1500);		
			}
			ClearLCD();
			break;
		}	
	}
	MacrosReached = 0;
	Flags.LaunchModeMacro = false;
	return;
}


void CompleteLaunchCalories()
{
	uint8_t ButtonPress = NO_PRESS;
	uint16_t CaloriesTarget = 0;
	uint8_t DishesNumber = 0, DishIndex = 0;
	bool ChoiceTargetAndDishes = false, Target = true, Dishes = false;
	ClearLCD();
	Flags.LaunchModeCal = true;
	while(!ChoiceTargetAndDishes)
	{
		if(Target)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Scegli il target");
			LCDPrintString(TWO, CENTER_ALIGN, "di calorie del tuo");
			LCDPrintString(THREE, CENTER_ALIGN, "pasto:");
			LCDPrintString(FOUR, CENTER_ALIGN, String(CaloriesTarget) + "kcal");
		}
		if(Dishes)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Scegli il numero");
			LCDPrintString(TWO, CENTER_ALIGN, "di piatti");
			LCDPrintString(THREE, CENTER_ALIGN, "del tuo pasto:");
			LCDPrintString(FOUR, CENTER_ALIGN, String(DishesNumber));			
		}
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(Target)
				{
					if(CaloriesTarget > 0)
						CaloriesTarget -= 10;
					else
						CaloriesTarget = 10000;
				}
				if(Dishes)
				{
					if(DishesNumber > 0)
						DishesNumber--;
					else
						DishesNumber = 10;
				}
				ClearLCDLine(FOUR);
				break;
			case DOWN:
				if(Target)
				{
					if(CaloriesTarget < 10000)
						CaloriesTarget += 10;
					else
						CaloriesTarget = 0;
				}
				if(Dishes)
				{
					if(DishesNumber < 10)
						DishesNumber++;
					else
						DishesNumber = 0;
				}
				ClearLCDLine(FOUR);
				break;
			case OK_TARE:
				if(Target)
				{
					Target = false;
					Dishes = true;
				}
				else if(Dishes)
				{
					ChoiceTargetAndDishes = true;
				}
				break;
			case EXIT:
				Flags.LaunchModeCal = false;
				return;
				break;
			default:
				break;
		}
		yield();
	}
	CaloriesReached = 0;
	for(DishIndex = 1; DishIndex <= DishesNumber; DishesNumber++)
	{
		int32_t Diff = CaloriesTarget - CaloriesReached;
		ClearLCD();
		LCDPrintString(ONE, CENTER_ALIGN, "Piatto "+ String(DishesNumber));
		LCDPrintString(TWO, CENTER_ALIGN, "Per continuare");
		Wait(THREE, false);
		CategoryChoice = MAX_CATEGORY;
		FoodChoice = MAX_FOOD;
		if(FoodChoiceMenu())
		{
			ShowMeasure();
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Calorie rimanenti:");
			LCDPrintString(TWO, CENTER_ALIGN, String(Diff) + "kcal");
			LCDPrintString(THREE, CENTER_ALIGN, "Per continuare");
			Wait(FOUR, false);
		}
		else
			continue;
		if(Diff <= 0)
		{
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Calorie target");
			LCDPrintString(TWO, CENTER_ALIGN, "raggiunte!");	
			delay(1500);
			if(Diff < 0)
			{
				Diff = -Diff;
				ClearLCD();
				LCDPrintString(ONE, CENTER_ALIGN, "Superato il target");
				LCDPrintString(TWO, CENTER_ALIGN, "di:");	
				LCDPrintString(THREE, CENTER_ALIGN, String(Diff) + "kcal");	
				delay(1500);		
			}
			ClearLCD();
			break;
		}	
		yield();
	}
	CaloriesReached = 0;
	Flags.LaunchModeCal = false;
	return;
}


MAIN_FUNCTIONS MenuChoice()
{
	uint8_t ButtonPress = NO_PRESS;
	uint8_t ArrowPos = 1, OldArrowPos = 1;
	uint8_t TopItem = 0;
	bool ExitMenuChoice = false;
	uint8_t FunctionChoice = BALANCE_FUNCTION;
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Scegli la funzione");
	while(!ExitMenuChoice)
	{
		RefreshMenuChoice(MenuTitle, MAX_FUNCTIONS, ArrowPos, TopItem);
		CheckEvent();
		if(Flags.CategoryModified)
		{
			Flags.CategoryModified = false;
			FunctionChoice = BALANCE_FUNCTION;
			ExitMenuChoice = true;
		}
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case EXIT:
				break;
			case UP:
				if(FunctionChoice > BALANCE_FUNCTION)
					FunctionChoice--;
				else
					FunctionChoice = MAX_FUNCTIONS - 1;
				break;
			case DOWN:
				if(FunctionChoice < MAX_FUNCTIONS - 1)
					FunctionChoice++;
				else
					FunctionChoice = BALANCE_FUNCTION;
				break;
			case OK_TARE:
				ExitMenuChoice = true;
				break;
			default:
				break;			
			
		}
		if(FunctionChoice < MAX_LCD_LINE_MENU)
		{
			TopItem = 0;
			ArrowPos = FunctionChoice  + 1;
			if(OldArrowPos != ArrowPos)
			{
				ClearChar(OldArrowPos, 0);
				OldArrowPos = ArrowPos;
			}
		}
		else
		{
			TopItem = FunctionChoice - MAX_LCD_LINE_MENU + 1;
			ArrowPos = MAX_LCD_LINE_MENU;
			if(OldArrowPos != ArrowPos)
			{
				ClearChar(OldArrowPos, 0);
				OldArrowPos = ArrowPos;
			}
		}
		yield();
	}
	return (MAIN_FUNCTIONS)FunctionChoice;
}


bool CheckYesNo()
{
	bool Exit = false, Choice = false;
	String YesNo[] = {"No", "Si"};
	uint8_t ButtonPress = NO_PRESS;
	short YesNoChoice = 0;
	while(!Exit)
	{
		LCDPrintString(FOUR, CENTER_ALIGN, YesNo[YesNoChoice]);
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(YesNoChoice == 0)
					YesNoChoice = 1;
				else
					YesNoChoice = 0;
				ClearLCDLine(FOUR);
				break;
			case DOWN:
				if(YesNoChoice == 1)
					YesNoChoice = 0;
				else
					YesNoChoice = 1;
					ClearLCDLine(FOUR);
				break;
			case OK_TARE:
				if(YesNoChoice == 1)
				{
					Exit = true;
					Choice = true;
				}
				else
				{
					Exit = true;
					Choice = false;
				}
				break;
			case EXIT:
				Exit = true;
				Choice = false;
			default:
				break;
		}
		ButtonPress = NO_PRESS;
		yield();
	}
	return Choice;
}