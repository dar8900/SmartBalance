#include "BalanceLCD.h"
#include "LCDLib.h"
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
	"Preferito 1",
	"Preferito 2",
	"Preferito 3",
	"Preferito 4",
	"Calibrazione",
};

void PreferenceInit()
{
	for(uint8_t PrefIndex = 0; PrefIndex < MAX_PREFERENCE; PrefIndex++)
	{
		FoodPreference[PrefIndex].CategoryValue = EEPROM.read(FoodPreference[PrefIndex].CategoryAddr);
		FoodPreference[PrefIndex].FoodValue = EEPROM.read(FoodPreference[PrefIndex].FoodAddr);
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
			delay(30);
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
		WeightStr = String(Weight, 4) + "kg";
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
		delay(30);
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
	String Carb = "C:" + String(CategoryTable[Category].NutritionalTable[Food].Carbs) + "g";
	String Prot = "P:" + String(CategoryTable[Category].NutritionalTable[Food].Prot) + "g";
	String Fats = "G:" + String(CategoryTable[Category].NutritionalTable[Food].Fats) + "g";
	String CategoryName = String(CategoryTable[Category].CategoryName);
	LCDPrintString(ONE, CENTER_ALIGN, "Valori in 100g di:");
	while(!ExitShowInfo)
	{
		FoodMaxItem = *CategoryTable[Category].TableSizeArray;
		FoodName = String(CategoryTable[Category].NutritionalTable[Food].FoodName);
		Calories = String(CategoryTable[Category].NutritionalTable[Food].Calories) + "kcal";
		Carb = "C:" + String(CategoryTable[Category].NutritionalTable[Food].Carbs) + "g";
		Prot = "P:" + String(CategoryTable[Category].NutritionalTable[Food].Prot) + "g";
		Fats = "G:" + String(CategoryTable[Category].NutritionalTable[Food].Fats) + "g";	
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
		delay(30);
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
				EEPROMUpdate(FoodPreference[PreferenceChoice].CategoryAddr, CategoryChoice);
				EEPROMUpdate(FoodPreference[PreferenceChoice].FoodAddr, FoodChoice);
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
				EEPROMUpdate(FoodPreference[PreferenceChoice].CategoryAddr, CategoryChoice);
				EEPROMUpdate(FoodPreference[PreferenceChoice].FoodAddr, FoodChoice);
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
	}
	LCDMoveCursor(ItemPos, 0);
	LCDShowIcon(TO_RIGHT_ARROW);	
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
		delay(30);
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
		delay(30);
	}
	return Choice;
}