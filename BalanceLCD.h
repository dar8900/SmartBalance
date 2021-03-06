#ifndef BALANCE_LCD_H
#define BALANCE_LCD_H
#include <Arduino.h>
#include <stdint.h>

#define MAX_LCD_CHARS	20

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
	BALANCE_FUNCTION_NORM = 0,
	BALANCE_FUNCTION_CAL,
	INFO_FUNCTION,
	COMPLETE_LAUNCH_FUNCTION,
	PREFERENCE_1_FUNCTION,
	PREFERENCE_2_FUNCTION,
	PREFERENCE_3_FUNCTION,
	PREFERENCE_4_FUNCTION,
	PREFERENCE_5_FUNCTION, 
	PREFERENCE_6_FUNCTION,
	PREFERENCE_7_FUNCTION,
	PREFERENCE_8_FUNCTION,
	PREFERENCE_9_FUNCTION,
	PREFERENCE_10_FUNCTION,
	PREFERENCE_11_FUNCTION,
	PREFERENCE_12_FUNCTION,
	PREFERENCE_13_FUNCTION,
	PREFERENCE_14_FUNCTION,
	PREFERENCE_15_FUNCTION,
	PREFERENCE_16_FUNCTION,
	PREFERENCE_17_FUNCTION,
	PREFERENCE_18_FUNCTION,
	PREFERENCE_19_FUNCTION,
	PREFERENCE_20_FUNCTION,
	CALIBRATION_FUNCTION,
	RESET_DEFAULT,
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
	PREFERENCE_5, 
	PREFERENCE_6,
	PREFERENCE_7,
	PREFERENCE_8,
	PREFERENCE_9,
	PREFERENCE_10,
	PREFERENCE_11,
	PREFERENCE_12,
	PREFERENCE_13,
	PREFERENCE_14,
	PREFERENCE_15,
	PREFERENCE_16,
	PREFERENCE_17,
	PREFERENCE_18,
	PREFERENCE_19,
	PREFERENCE_20,

	MAX_PREFERENCE
}PREFERENCE_NUMBER;


extern uint8_t UpArrow[];
extern uint8_t DownArrow[];
extern uint8_t ToRightArrow[];
extern uint8_t ToLeftArrow[];

extern uint8_t  CategoryChoice;
extern uint16_t  FoodChoice;
extern MAIN_FUNCTIONS WichFunction;

void PreferenceInit(void);
bool FoodChoiceMenu(void); 
void LaunchMenu(void);
void CompleteLaunchMacros(void);
void CompleteLaunchCalories(void);
void ShowNormalMeasure(void);
void ShowMeasureCal(void);
void ShowInfo(void);
MAIN_FUNCTIONS MenuChoice(void);
bool CheckPreference(uint8_t PreferenceChoice);
bool CheckYesNo(void);
void ToCalibration(void);
void ResetDefault(void);
#endif