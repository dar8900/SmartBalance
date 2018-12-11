#ifndef BALANCE_LCD_H
#define BALANCE_LCD_H
#include <Arduino.h>
#include <stdint.h>

enum
{
	UP_ARROW = 0,
	DOWN_ARROW,
	MAX_BALANCE_ICON
};


extern uint8_t  CategoryChoice;
extern uint8_t  FoodChoice;


bool FoodChoiceMenu(void); 
void ShowMeasure(void);
#endif