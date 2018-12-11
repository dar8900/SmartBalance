#ifndef FOODS_H
#define FOODS_H
#include <Arduino.h>
#include <stdint.h>

typedef struct
{
	const char*     FoodName;
	const uint16_t  Calories;
	const float     Carbs;
	const float     Prot;
	const float     Fats;
	
}NUTRITIONAL_VALUES;

typedef struct
{
	const char *CategoryName;
	const NUTRITIONAL_VALUES *NutritionalTable;
	const uint8_t *TableSizeArray;
}NUTRITIONAL_CATEGORIES;

typedef enum
{
	Verdura = 0,	
	Frutta 	   ,
	Pesce 	   ,
	Latticini  ,
	Pasta 	   ,
	Pane_e_co  ,
	Manzo      ,
	Maiale 	   ,
	Pollame    ,
	Uova 	   ,
	Alcolici   ,
	
	MAX_CATEGORIES
}CATEGORIES_ITEMS;



extern uint8_t NutritionalTableSizes[MAX_CATEGORIES];






extern const NUTRITIONAL_CATEGORIES CategoryTable[];


void CalcNutritionalValues(float Weight, uint8_t Category, uint8_t Food, 
							uint16_t *Calories, uint16_t *Carbs, uint16_t *Prot, 
							uint16_t *Fats);
void FillNutritionalTableSizeArray(void);
#endif