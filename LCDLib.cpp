#include "LCDLib.h"
#include <LiquidCrystal_I2C.h> // Libreria LCD I2C
#include <Wire.h>

LiquidCrystal_I2C lcd_main(0x27, 16,2);

void LCDInit()
{
	lcd_main.begin();
}

void ClearLCD()
{
    //delay(10);
    lcd_main.clear();
    //lcd_main.home();
}

void LCDMoveCursor(short row, short col)
{
	lcd_main.setCursor(col, row);
}

void BlinkDisplay(short NumTimes, short PulseTime)
{
	short num = 0, Pulse = PulseTime;
	if(Pulse < 20)
		Pulse = 20;
	for(num = 0; num < NumTimes; num++)
	{
		LCDDisplayLight(true);
		delay(Pulse);
		LCDDisplayLight(false);
		delay(Pulse);
	}
	LCDDisplayLight(true);
}

// Utilizzano un oggetto di tipo LCD
void LCDPrintString(short row, short col, String string)
{
  if(row > MAX_LCD_ROW || string.length() > MAX_LCD_ROW + 1 )
  {
	lcd_main.clear();
	if(string.length() > MAX_LCD_COL + 1)
	{
		col = CENTER_ALIGN;
		string = "STRING TOO BIG";
	}
	else
	{
		col = CENTER_ALIGN;
		row = MAX_LCD_ROW;
		string = "OVER DIMENSION";		
	}
  }
  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - string.length()) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - string.length();
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(string);

}

void LCDPrintValue(short row, short col, short value)
{
  String ValStr = String(value);
  if(row > MAX_LCD_ROW || ValStr.length() > MAX_LCD_COL + 1)
  {
	lcd_main.clear();
	col = CENTER_ALIGN;
	row = MAX_LCD_ROW;
    ValStr = "OVER DIMENSION";
    return;
  }

  switch(col)
  {
    case CENTER_ALIGN:
      col = ((MAX_LCD_COL+1) - ValStr.length()) / 2;
      break;
    case RIGHT_ALIGN:
      col = (MAX_LCD_COL+1) - ValStr.length();
      break;
    case LEFT_ALIGN:
      col = 0;
      break;
    default:
      lcd_main.home();
      break;
  }
  lcd_main.setCursor(col, row);
  lcd_main.print(ValStr);
}


void ClearLCDLine(short row)
{
  lcd_main.setCursor(0, row);
  lcd_main.print("                ");
}

void LCDDisplayLight(bool IsOn)
{
	if(IsOn)
		lcd_main.backlight();
	else
		lcd_main.noBacklight();
}

void LCDBlink(bool IsBlinking)
{
	if(IsBlinking)
		lcd_main.blink();
	else
		lcd_main.noBlink();
}
