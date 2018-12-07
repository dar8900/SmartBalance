#ifndef FOODS_H
#define FOODS_H
#include <Arduino.h>
#include <stdint.h>

typedef struct
{
	String FoodName;
	uint16_t  Calories;
	
}NUTRITIONAL_VALUES;

typedef struct
{
	String CategoryName;
	const NUTRITIONAL_VALUES *NutritionalTable;
}NUTRITIONAL_CATEGORIES;



#endif