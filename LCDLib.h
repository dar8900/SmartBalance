#ifndef LCDLIB_H
#define LCDLIB_H
#include <Arduino.h>

#define MAX_LCD_ROW    1
#define MAX_LCD_COL   15

#define CENTER_ALIGN  25
#define RIGHT_ALIGN   MAX_LCD_COL
#define LEFT_ALIGN     0

typedef enum
{
	ONE = 0,
	TWO,
	// THREE,
	// FOUR
} LCD_ROWS;

void LCDInit(void);
void LCDMoveCursor(short row, short col);
void ClearLCD(void);
void BlinkDisplay(short NumTimes);
void LCDPrintString(short row, short col, String string);
void LCDPrintValue(short row, short col, short value);
void ClearLCDLine(short row);
void LCDDisplayLight(bool IsOn);
void LCDBlink(bool IsBlinking);

#endif