#ifndef FOODS_H
#define FOODS_H
#include <Arduino.h>
#include <stdint.h>

typedef struct
{
	const String FoodName;
	const uint16_t  Calories;
	
}NUTRITIONAL_VALUES;

typedef struct
{
	const String CategoryName;
	const NUTRITIONAL_VALUES *NutritionalTable;
	uint8_t TableSize;
}NUTRITIONAL_CATEGORIES;

enum
{
	Verdura,  	
	Frutta,		
	Carne,		
	Pesce, 		
	Latticini_uova,
	Pasta, 		
	Pane_co,	
	Cheat_meal,
	MAX_CATEGORIES
};



extern const NUTRITIONAL_CATEGORIES CategoryTable[];

#endif