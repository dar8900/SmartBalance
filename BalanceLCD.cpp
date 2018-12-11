#include "BalanceLCD.h"
#include "LCDLib.h"
#include "Keyboard.h"
#include "Foods.h"
#include "Calibration.h"

uint8_t  CategoryChoice;
uint8_t  FoodChoice;

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

// Prima la scelta della categoria, poi la scelta dell'alimento
bool FoodChoiceMenu() 
{
	bool IsCategory = true, IsFood = false; // Se vero selezioni la categoria altrimenti il cibo
	uint8_t Category = 0, Food = 0, FoodMaxItem = 0;
	bool Exit = false, ChoiceComplete = false;
	uint8_t ButtonPress = NO_PRESS;
	ClearLCD();
	while(!Exit)
	{
		if(IsFood)
		{
			LCDPrintString(ONE, CENTER_ALIGN, String(CategoryTable[Category].CategoryName));
			LCDPrintString(TWO, CENTER_ALIGN, String(CategoryTable[Category].NutritionalTable[Food].FoodName));
			FoodMaxItem = CategoryTable[Category].TableSize;
		}
		if(IsCategory)
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Categoria: ");
			LCDPrintString(TWO, CENTER_ALIGN, String(CategoryTable[Category].CategoryName));			
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