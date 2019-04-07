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
	{FOOD_1_ADDR , FOOD_1_ADDR + 1 , INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_2_ADDR , FOOD_2_ADDR + 1 , INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_3_ADDR , FOOD_3_ADDR + 1 , INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_4_ADDR , FOOD_4_ADDR + 1 , INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_5_ADDR , FOOD_5_ADDR  + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_6_ADDR , FOOD_6_ADDR  + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_7_ADDR , FOOD_7_ADDR  + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_8_ADDR , FOOD_8_ADDR  + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_9_ADDR , FOOD_9_ADDR  + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_10_ADDR, FOOD_10_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_11_ADDR, FOOD_11_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_12_ADDR, FOOD_12_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_13_ADDR, FOOD_13_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_14_ADDR, FOOD_14_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_15_ADDR, FOOD_15_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_16_ADDR, FOOD_16_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_17_ADDR, FOOD_17_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_18_ADDR, FOOD_18_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_19_ADDR, FOOD_19_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
	{FOOD_20_ADDR, FOOD_20_ADDR + 1, INVALID_EEPROM_VALUE, INVALID_EEPROM_VALUE},
};

uint8_t  CategoryChoice;
uint16_t  FoodChoice;
MAIN_FUNCTIONS WichFunction;
uint8_t PreferenceNumber;
uint16_t CaloriesReached = 0;
uint16_t MacrosReached = 0;
uint8_t MacroChoiced = 0;

uint8_t UpArrow[] = 
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

uint8_t DownArrow[] = 
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

uint8_t ToRightArrow[] = 
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

uint8_t ToLeftArrow[] = 
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

const char  *MenuTitle[] = 
{
	"Bilancia normale",
	"Bilancia calorie",
	"Informazioni",
	"Pasto",
	"Preferito 1",
	"Preferito 2",
	"Preferito 3",
	"Preferito 4",
	"Preferito 5",
	"Preferito 6",
	"Preferito 7",
	"Preferito 8",
	"Preferito 9",
	"Preferito 10",
	"Preferito 11",
	"Preferito 12",
	"Preferito 13",
	"Preferito 14",
	"Preferito 15",
	"Preferito 16",
	"Preferito 17",
	"Preferito 18",
	"Preferito 19",
	"Preferito 20",
	"Calibrazione",
	"Impostaz. fabbrica",
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

const char *LaunchMenuStr[] =
{
	"Per calorie",
	"Per macros",	
};

const char *MacrosName[] = 
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
		delay(1);
	}	
	
}


// Prima la scelta della categoria, poi la scelta dell'alimento
bool FoodChoiceMenu() 
{
	bool IsCategory = true, IsFood = false; // Se vero selezioni la categoria altrimenti il cibo
	uint8_t Category = 0;
	uint16_t Food = 0, FoodMaxItem = 0;
	bool ExitFoodChoice = false, ChoiceComplete = false;
	uint8_t ButtonPress = NO_PRESS;
	// String NumItem;
	char StrToPrint[MAX_LCD_CHARS + 1];
	ClearLCD();
	ButtonPress = NO_PRESS;
	if(CategoryChoice == MAX_CATEGORY && FoodChoice == MAX_FOOD)
	{
		while(!ExitFoodChoice)
		{
			CheckEvent();
			if(IsCategory)
			{
				LCDPrintString(ONE, CENTER_ALIGN, "Categoria: ");
				LCDPrintString(TWO, CENTER_ALIGN, CategoryTable[Category].CategoryName);
				snprintf(StrToPrint, MAX_LCD_CHARS, "%d/%d", Category + 1, MAX_CATEGORIES);
				LCDPrintString(FOUR, CENTER_ALIGN, StrToPrint);
			}
			if(IsFood)
			{
				LCDPrintString(ONE, CENTER_ALIGN, CategoryTable[Category].CategoryName);
				LCDPrintString(TWO, CENTER_ALIGN, CategoryTable[Category].NutritionalTable[Food].FoodName);
				FoodMaxItem = CategoryTable[Category].FoodTableSize;
				snprintf(StrToPrint, MAX_LCD_CHARS, "%d/%d", Food + 1, FoodMaxItem);
				LCDPrintString(FOUR, CENTER_ALIGN, StrToPrint);
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
					ClearLCDLine(FOUR);
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
					ClearLCDLine(FOUR);
					break;
				case OK_TARE:
					if(IsCategory)
					{
						IsFood = true;
						IsCategory = false;
						CategoryChoice = Category;
						ClearLCD();
						// ButtonPress = NO_PRESS;
					}
					else if(IsFood)
					{
						IsFood = false;
						ChoiceComplete = true;
						FoodChoice = Food;
						ExitFoodChoice = true;
						// ButtonPress = NO_PRESS;
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
			delay(250);
		}
	}
	else
	{
		ChoiceComplete = true;
	}
	return ChoiceComplete;

}

void ShowNormalMeasure()
{
	uint8_t ButtonPress = NO_PRESS;
	float Weight = 0.0, OldWeight = 0.0;
	bool ExitShowMeasure = false;
	char Values[MAX_LCD_CHARS + 1];
	String WeightStr;
	ClearLCD();
	while(!ExitShowMeasure)
	{
		LCDPrintString(ONE, CENTER_ALIGN, "Peso letto:");
		Weight = roundf(GetWeight());
		if(Weight < 1000)
			snprintf(Values, MAX_LCD_CHARS, "%6.0fg", Weight);
		else
			snprintf(Values, MAX_LCD_CHARS, "%4.3fkg", Weight / 1000);
		if(OldWeight != Weight)
		{
			OldWeight = Weight;
			ClearLCDLine(TWO);
		}
		LCDPrintString(TWO, CENTER_ALIGN, Values);
		LCDPrintString(FOUR, CENTER_ALIGN, "OK per la tara");
		CheckEvent();
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case EXIT:
				ExitShowMeasure = true;
				break;
			case UP:
			case DOWN:
				break;
			case OK_TARE:
				SetTare();
				ClearLCD();
				break;
			default:
				break;
		}
		OldWeight = Weight;
		delay(100);
	}
}


void ShowMeasureCal()
{
	uint8_t ButtonPress = NO_PRESS;
	float Weight = 0.0, OldWeight = 0.0;
	uint16_t Food = FoodChoice, FoodItemMax = CategoryTable[CategoryChoice].FoodTableSize, Calories = 0;
	uint16_t Carbs = 0, Protein = 0, Fats = 0;
	bool ExitShowMeasure = false;
	char Values[MAX_LCD_CHARS + 1];
	uint8_t RefreshCnt = 35;
	ClearLCD();
	while(!ExitShowMeasure)
	{
		LCDPrintString(ONE, CENTER_ALIGN, CategoryTable[CategoryChoice].NutritionalTable[Food].FoodName);
		Weight = roundf(GetWeight());
		CalcNutritionalValues(Weight, CategoryChoice, Food, &Calories, &Carbs, &Protein, &Fats);
		if(Weight < 1000)
		{
			snprintf(Values, MAX_LCD_CHARS, "%6.0fg  %dkcal", Weight, Calories);
			LCDPrintString(TWO, CENTER_ALIGN, Values);
		}
		else
		{
			snprintf(Values, MAX_LCD_CHARS, "%4.3fkg %dkcal", Weight/1000.0, Calories);
			LCDPrintString(TWO, CENTER_ALIGN, Values);			
		}
		snprintf(Values, MAX_LCD_CHARS, "C:%dg P:%dg", Carbs, Protein);
		LCDPrintString(THREE, CENTER_ALIGN, Values);
		snprintf(Values, MAX_LCD_CHARS, "F:%dg", Fats);
		LCDPrintString(FOUR, CENTER_ALIGN, Values);
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
		RefreshCnt--;
		if(RefreshCnt == 0)
		{
			RefreshCnt = 35;
			ClearLCD();			
		}
		delay(100);
	}
}

void ShowInfo()
{
	uint8_t ButtonPress = NO_PRESS;
	uint16_t Food = FoodChoice, FoodMaxItem = 0;
	uint16_t Category = CategoryChoice;
	bool ExitShowInfo = false;
	char InfoStr[MAX_LCD_CHARS + 1];
	ClearLCD();

	LCDPrintString(ONE, CENTER_ALIGN, "Valori in 100g di:");
	while(!ExitShowInfo)
	{
		FoodMaxItem = CategoryTable[Category].FoodTableSize;		
		LCDPrintString(TWO, CENTER_ALIGN, CategoryTable[Category].NutritionalTable[Food].FoodName);
		snprintf(InfoStr, MAX_LCD_CHARS, "%dkcal  C:%4.0fg", CategoryTable[Category].NutritionalTable[Food].Calories, CategoryTable[Category].NutritionalTable[Food].Carbs);
		LCDPrintString(THREE, CENTER_ALIGN, InfoStr);
		snprintf(InfoStr, MAX_LCD_CHARS, "P:%4.0fg  F:%4.0fg", CategoryTable[Category].NutritionalTable[Food].Prot, CategoryTable[Category].NutritionalTable[Food].Fats);
		LCDPrintString(FOUR, CENTER_ALIGN, InfoStr);		
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
				LCDPrintString(TWO, CENTER_ALIGN, CategoryTable[Category].CategoryName);
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
		delay(250);
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

static void RefreshMenuChoice(const char *Title[], uint8_t MaxItem, uint8_t ItemPos, uint8_t FirstListItem)
{
	uint8_t Aux = 0;
	for(uint8_t MenuIndx = 0; MenuIndx < MAX_LCD_LINE_MENU; MenuIndx++)
	{
		Aux = FirstListItem + MenuIndx;
		if(Aux >= MaxItem)
			break;
		LCDPrintString(TWO + MenuIndx, AFTER_ARROW_POS, Title[Aux]);
		delay(5);
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
		delay(250);
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
	char MacrosStr[MAX_LCD_CHARS + 1];
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
		delay(250);				
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
			snprintf(MacrosStr, MAX_LCD_CHARS, "%dg", MacrosTarget);
			LCDPrintString(FOUR, CENTER_ALIGN, MacrosStr);
		}
		if(Dishes)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Scegli il numero");
			LCDPrintString(TWO, CENTER_ALIGN, "di piatti");
			LCDPrintString(THREE, CENTER_ALIGN, "del tuo pasto:");
			LCDPrintValue(FOUR, CENTER_ALIGN, DishesNumber);			
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
					ClearLCD();
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
		delay(250);
	}
	MacrosReached = 0;
	for(DishIndex = 1; DishIndex <= DishesNumber; DishIndex++)
	{
		int32_t Diff = MacrosTarget - MacrosReached;
		ClearLCD();
		snprintf(MacrosStr, MAX_LCD_CHARS, "%s%d", "Piatto ", DishIndex);
		LCDPrintString(ONE, CENTER_ALIGN, MacrosStr);
		LCDPrintString(TWO, CENTER_ALIGN, "Per continuare");
		Wait(THREE, false);
		if(FoodChoiceMenu())
		{
			ShowMeasureCal();
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Grammi rimanenti:");
			snprintf(MacrosStr, MAX_LCD_CHARS, "%dg", Diff);
			LCDPrintString(TWO, CENTER_ALIGN, MacrosStr);
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
				snprintf(MacrosStr, MAX_LCD_CHARS, "%dg", Diff);
				LCDPrintString(THREE, CENTER_ALIGN, MacrosStr);	
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
	char MacrosStr[MAX_LCD_CHARS + 1];
	while(!ChoiceTargetAndDishes)
	{
		if(Target)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Scegli il target");
			LCDPrintString(TWO, CENTER_ALIGN, "di calorie del tuo");
			LCDPrintString(THREE, CENTER_ALIGN, "pasto:");
			snprintf(MacrosStr, MAX_LCD_CHARS, "%dkcal", CaloriesTarget);
			LCDPrintString(FOUR, CENTER_ALIGN, MacrosStr);
		}
		if(Dishes)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Scegli il numero");
			LCDPrintString(TWO, CENTER_ALIGN, "di piatti");
			LCDPrintString(THREE, CENTER_ALIGN, "del tuo pasto:");
			LCDPrintValue(FOUR, CENTER_ALIGN, DishesNumber);			
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
					ClearLCD();
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
		delay(250);
	}
	CaloriesReached = 0;
	for(DishIndex = 1; DishIndex <= DishesNumber; DishIndex++)
	{
		int32_t Diff = CaloriesTarget - CaloriesReached;
		ClearLCD();
		snprintf(MacrosStr, MAX_LCD_CHARS, "%s%d", "Piatto: ", DishIndex);
		LCDPrintString(ONE, CENTER_ALIGN, MacrosStr);
		LCDPrintString(TWO, CENTER_ALIGN, "Per continuare");
		Wait(THREE, false);
		CategoryChoice = MAX_CATEGORY;
		FoodChoice = MAX_FOOD;
		if(FoodChoiceMenu())
		{
			ShowMeasureCal();
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Calorie rimanenti:");
			snprintf(MacrosStr, MAX_LCD_CHARS, "%dkcal", Diff);
			LCDPrintString(TWO, CENTER_ALIGN, MacrosStr);
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
				snprintf(MacrosStr, MAX_LCD_CHARS, "%dkcal", Diff);
				LCDPrintString(THREE, CENTER_ALIGN, MacrosStr);	
				delay(1500);		
			}
			ClearLCD();
			break;
		}	
		delay(250);
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
	uint8_t FunctionChoice = BALANCE_FUNCTION_NORM, OldFunctionChoice = BALANCE_FUNCTION_NORM;
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Scegli la funzione");
	while(!ExitMenuChoice)
	{
		// uint8_t Aux = 0;
		// for(uint8_t MenuIndx = 0; MenuIndx < MAX_LCD_LINE_MENU; MenuIndx++)
		// {
			// Aux = TopItem + MenuIndx;
			// if(Aux >= MAX_FUNCTIONS)
				// break;
			// LCDPrintString(TWO + MenuIndx, AFTER_ARROW_POS, MenuTitle[Aux]);
			// // delay(10);
		// }
		LCDPrintString(ONE, CENTER_ALIGN, "Scegli la funzione");
		RefreshMenuChoice(MenuTitle, MAX_FUNCTIONS, ArrowPos, TopItem);
		LCDShowIcon(TO_RIGHT_ARROW, ArrowPos, 0);

		CheckEvent();
		if(Flags.CategoryModified)
		{
			Flags.CategoryModified = false;
			FunctionChoice = BALANCE_FUNCTION_NORM;
			ExitMenuChoice = true;
		}
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case EXIT:
				break;
			case UP:
				if(FunctionChoice > BALANCE_FUNCTION_NORM)
					FunctionChoice--;
				else
					FunctionChoice = MAX_FUNCTIONS - 1;
				break;
			case DOWN:
				if(FunctionChoice < MAX_FUNCTIONS - 1)
					FunctionChoice++;
				else
					FunctionChoice = BALANCE_FUNCTION_NORM;
				break;
			case OK_TARE:
				ExitMenuChoice = true;
				break;
			default:
				break;			
			
		}
		if(FunctionChoice < MAX_LCD_LINE_MENU)
		{
			if(OldFunctionChoice >= MAX_LCD_LINE_MENU)
			{
				ClearLCD();
				OldFunctionChoice = FunctionChoice;
			}
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
			if(FunctionChoice != OldFunctionChoice)
			{
				ClearLCD();
				OldFunctionChoice = FunctionChoice;
			}
			TopItem = FunctionChoice - MAX_LCD_LINE_MENU + 1;
			ArrowPos = MAX_LCD_LINE_MENU;
			if(OldArrowPos != ArrowPos)
			{
				ClearChar(OldArrowPos, 0);
				OldArrowPos = ArrowPos;
			}
		}
		delay(50);
	}
	return (MAIN_FUNCTIONS)FunctionChoice;
}


bool CheckYesNo()
{
	bool Exit = false, Choice = false;
	const char *YesNo[] = {"No", "Si"};
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
		delay(100);
	}
	return Choice;
}