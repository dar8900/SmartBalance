#ifndef BALANCE_LCD_H
#define BALANCE_LCD_H
#include <Arduino.h>
#include <stdint.h>

extern uint8_t  CategoryChoice;
extern uint8_t  FoodChoice;


bool FoodChoiceMenu(void); 
void ShowMeasure(void);
#endif