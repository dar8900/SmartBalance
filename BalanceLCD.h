#ifndef BALANCE_LCD_H
#define BALANCE_LCD_H
#include <Arduino.h>
#include <stdint.h>

enum
{
	UP_ARROW = 0,
	DOWN_ARROW,
	TO_RIGHT_ARROW,
	TO_LEFT_ARROW,
	MAX_BALANCE_ICON
};

typedef enum
{
	BALANCE_FUNCTION = 0,
	INFO_FUNCTION,
	CALIBRATION_FUNCTION,
	MAX_FUNCTIONS
}MAIN_FUNCTIONS;


extern short UpArrow[];
extern short DownArrow[];
extern short ToRightArrow[];
extern short ToLeftArrow[];

extern uint8_t  CategoryChoice;
extern uint16_t  FoodChoice;
extern MAIN_FUNCTIONS WichFunction;

bool FoodChoiceMenu(void); 
void ShowMeasure(void);
void ShowInfo(void);
MAIN_FUNCTIONS MenuChoice(void);
#endif