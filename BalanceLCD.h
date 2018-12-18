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
	PREFERENCE_1_FUNCTION,
	PREFERENCE_2_FUNCTION,
	PREFERENCE_3_FUNCTION,
	PREFERENCE_4_FUNCTION,
	CALIBRATION_FUNCTION,
	MAX_FUNCTIONS
}MAIN_FUNCTIONS;

typedef struct
{
	uint8_t CategoryAddr;
	uint8_t FoodAddr;
	uint8_t CategoryValue;
	uint8_t FoodValue;
	
}PREFERENCE_TYPE;

typedef enum
{
	PREFERENCE_1 = 0,
	PREFERENCE_2,
	PREFERENCE_3,
	PREFERENCE_4,
	MAX_PREFERENCE
}PREFERENCE_NUMBER;


extern short UpArrow[];
extern short DownArrow[];
extern short ToRightArrow[];
extern short ToLeftArrow[];

extern uint8_t  CategoryChoice;
extern uint16_t  FoodChoice;
extern MAIN_FUNCTIONS WichFunction;

void PreferenceInit(void);
bool FoodChoiceMenu(void); 
void ShowMeasure(void);
void ShowInfo(void);
MAIN_FUNCTIONS MenuChoice(void);
bool CheckPreference(uint8_t PreferenceChoice);
bool CheckYesNo(void);
#endif