#include "BalanceLCD.h"
#include "LCDLib.h"
#include "Keyboard.h"
#include "Foods.h"
#include "Calibration.h"

uint8_t  CategoryChoice;
uint8_t  FoodChoice;
MAIN_FUNCTIONS WichFunction;

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
};



// Prima la scelta della categoria, poi la scelta dell'alimento
bool FoodChoiceMenu() 
{
	bool IsCategory = true, IsFood = false; // Se vero selezioni la categoria altrimenti il cibo
	uint8_t Category = 0, Food = 0, FoodMaxItem = 0;
	bool Exit = false, ChoiceComplete = false;
	uint8_t ButtonPress = NO_PRESS;
	String NumItem;
	ClearLCD();
	while(!Exit)
	{
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
					Exit = true;
				}
				break;
			case EXIT:
				Exit = true;
				break;
			default:
				break;
		}
		delay(100);
	}
	return ChoiceComplete;
}

void ShowMeasure()
{
	uint8_t ButtonPress = NO_PRESS;
	float Weight = 0.0, OldWeight = 0.0;
	uint16_t Calories = 0;
	uint16_t Carbs = 0, Protein = 0, Fats = 0;
	bool ExitShowMeasure = false;
	String WeightStr, CaloriesStr, CarbsStr, ProtStr, FatsStr, FibersStr;
	ClearLCD();
	while(!ExitShowMeasure)
	{
		LCDPrintString(ONE, CENTER_ALIGN, String(CategoryTable[CategoryChoice].NutritionalTable[FoodChoice].FoodName));
		Weight = GetWeight();
		if(OldWeight != Weight)
			ClearLCD();
		CalcNutritionalValues(Weight, CategoryChoice, FoodChoice, &Calories, &Carbs, &Protein, &Fats);
		WeightStr = String(Weight, 4) + "kg";
		CaloriesStr = String(Calories) + "kcal";
		CarbsStr = "C: " + String(Carbs)    + "g";
		ProtStr = "P: " + String(Protein)  + "g";
		FatsStr = "G: " + String(Fats)     + "g";
		LCDPrintString(TWO, LEFT_ALIGN, WeightStr);
		LCDPrintString(TWO, RIGHT_ALIGN, CaloriesStr);
		LCDPrintString(THREE, LEFT_ALIGN, CarbsStr);
		LCDPrintString(THREE, RIGHT_ALIGN, ProtStr);
		LCDPrintString(FOUR, CENTER_ALIGN, FatsStr);
		
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
		delay(400);
	}
}

void ShowInfo()
{
	uint8_t ButtonPress = NO_PRESS;
	uint8_t Food = FoodChoice, FoodMaxItem = 0, Category = CategoryChoice;
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
				break;
			default:
				break;		
		}
		delay(100);
	}
}


MAIN_FUNCTIONS MenuChoice()
{
	uint8_t ButtonPress = NO_PRESS;
	uint8_t ArrowPos = 1;
	bool ExitMenuChoice = false;
	uint8_t FunctionChoice = BALANCE_FUNCTION;
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Scegliere funzione");
	for(uint8_t MenuIndx = 0; MenuIndx < MAX_FUNCTIONS; MenuIndx++)
	{
		LCDPrintString(TWO + MenuIndx, AFTER_ARROW_POS, MenuTitle[MenuIndx]);
	}
	while(!ExitMenuChoice)
	{
		LCDMoveCursor(ArrowPos, 0);
		LCDShowIcon(TO_RIGHT_ARROW);
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case EXIT:
				break;
			case UP:
				ClearChar(ArrowPos, 0);
				if(FunctionChoice > BALANCE_FUNCTION)
					FunctionChoice--;
				else
					FunctionChoice = MAX_FUNCTIONS - 1;
				if(ArrowPos > 1)
					ArrowPos--;
				else
					ArrowPos = MAX_FUNCTIONS;
				break;
			case DOWN:
				ClearChar(ArrowPos, 0);
				if(FunctionChoice < MAX_FUNCTIONS - 1)
					FunctionChoice++;
				else
					FunctionChoice = BALANCE_FUNCTION;
				if(ArrowPos < MAX_FUNCTIONS)
					ArrowPos++;
				else
					ArrowPos = 1;
				break;
			case OK_TARE:
				ExitMenuChoice = true;
				break;
			default:
				break;			
			
		}
		delay(100);
	}
	return (MAIN_FUNCTIONS)FunctionChoice;
}

