/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/


#include "Calibration.h"
#include "HX711.h"
#include <EEPROM.h>
#include "EepromAddr.h"
#include "LCDLib.h"
#include "Keyboard.h"
#include "SmartBalance.h"
#include "BalanceLCD.h"
	
extern PREFERENCE_TYPE FoodPreference[MAX_PREFERENCE];
 
HX711 scale(HX711_CLK, HX711_DOUT);


void BalanceSetup()
{
	uint8_t BalanceMode = 10;
	float CalibrationValue = 0.0;
	BalanceMode = EEPROM.read(CALIBRATION_MODE_ADDR);
	if(BalanceMode != CALIBRATION_MODE && BalanceMode != NORMAL_MODE)
	{
		ClearLCD();
		EEPROMUpdate(CALIBRATION_MODE_ADDR, CALIBRATION_MODE);
		for(uint8_t PrefIndex = 0; PrefIndex < MAX_PREFERENCE; PrefIndex++)
		{
			EEPROMUpdate(FoodPreference[PrefIndex].CategoryAddr, INVALID_EEPROM_VALUE);
			EEPROMUpdate(FoodPreference[PrefIndex].FoodAddr, INVALID_EEPROM_VALUE);
		}	
		LCDPrintString(ONE, CENTER_ALIGN, "Inizializzo la");
		LCDPrintString(TWO, CENTER_ALIGN, "bilancia, attendere");
		delay(1000);
		ClearLCD();
		LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
		delay(1500);
		ESP.restart();
	}
	if(BalanceMode == CALIBRATION_MODE)
	{
		ClearLCD();
		LCDPrintString(ONE, CENTER_ALIGN, "Modalita:");
		LCDPrintString(ONE, CENTER_ALIGN, "CALIBRAZIONE");
		delay(1500);
		ClearLCD();
		AutoCalibration();
		EEPROMUpdate(CALIBRATION_MODE_ADDR, NORMAL_MODE);
		delay(100);
		ClearLCD();
		LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
		delay(1500);
		ClearLCD();
		ESP.restart();		
	}
	if(BalanceMode == NORMAL_MODE)
	{
		EEPROM.get(CALIBRATION_ADDR, CalibrationValue);
		scale.set_scale(CalibrationValue);
		scale.tare(5); //Reset the scale to 0
		delay(1000);
	}	
}

void Calibration()
{
	float calibration_factor = 500; // this calibration factor is adjusted according to my load cell
	scale.set_scale();
	scale.tare(); //Reset the scale to 0
	String ValueUnit;
	long zero_factor = scale.read_average();
	uint8_t ButtonPress = NO_PRESS;
	bool ExitCalibration = false;
	ClearLCD();
	while(!ExitCalibration)
	{
		scale.set_scale(calibration_factor); //Adjust to this calibration factor
		LCDPrintString(TWO, LEFT_ALIGN, "Peso:");
		ValueUnit = String(scale.get_units(10), 3) + "g";
		LCDPrintString(TWO, RIGHT_ALIGN, ValueUnit);
		LCDPrintString(THREE, LEFT_ALIGN, "K fact:");
		LCDPrintString(THREE, RIGHT_ALIGN, String(calibration_factor, 4));
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				calibration_factor -= 1;
				ClearLCD();
				break;
			case DOWN:
				calibration_factor += 1;
				ClearLCD();
				break;
			case OK_TARE:
				calibration_factor += 10;
				ClearLCD();				
				break;
			case EXIT:
				ExitCalibration = true;
				EEPROM.put(CALIBRATION_ADDR, calibration_factor);
				EEPROM.commit();
				break;
			default:
				break;		
		}
		delay(200);
	}
}

void AutoCalibration()
{
	uint16_t WeightTarget = 0;
	String WeightTargetStr;
	uint8_t ButtonPress = NO_PRESS, PointPos = 0, TimerPoint = 100;
	float CalibrationFactor = 500.0, ReadedWeight = 0.0;
	bool ExitSetWeightTarget = false;
	ClearLCD();
	while(!ExitSetWeightTarget)
	{
		LCDPrintString(ONE, CENTER_ALIGN, "Inserire il");
		LCDPrintString(TWO, CENTER_ALIGN, "peso target:");
		WeightTargetStr = String(WeightTarget) + "g";
		LCDPrintString(THREE, CENTER_ALIGN, WeightTargetStr);
		LCDPrintString(FOUR, CENTER_ALIGN, "Premere su, giu, ok");
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(WeightTarget > 0)
					WeightTarget -= 10;
				else
					WeightTarget = 5000;
			case DOWN:
				if(WeightTarget < 5000)
					WeightTarget += 10;
				else
					WeightTarget = 0;
				break;
			case OK_TARE:
				ExitSetWeightTarget = true;
				break;
			case EXIT:
				break;
			default:
				break;		
		}
		delay(30);	
	}
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Sto calibrando");
	scale.set_scale();
	scale.tare(); //Reset the scale to 0
	while(1)
	{
		scale.set_scale(CalibrationFactor);
		ReadedWeight = round(scale.get_units(10));
		if((uint16_t)ReadedWeight > WeightTarget)
			CalibrationFactor--;
		else if((uint16_t)ReadedWeight < WeightTarget)
			CalibrationFactor++;
		else if((uint16_t)ReadedWeight == WeightTarget)
			break;
		TimerPoint--;
		if(TimerPoint == 0)
		{
			TimerPoint = 100;
			LCDPrintString(TWO, PointPos, ".");
			PointPos++;
			if(PointPos == LCD_COL)
			{
				PointPos = 0;
				ClearLCDLine(TWO);
			}
			LCDPrintString(FOUR, CENTER_ALIGN, String(ReadedWeight) + "g" + " --> " + String(WeightTarget) + "g");
		}
		delay(10);
	}
	EEPROM.put(CALIBRATION_ADDR, CalibrationFactor);
	EEPROM.commit();
	ClearLCD();
	LCDPrintString(TWO, CENTER_ALIGN, "Bilancia calibrata");
	delay(1500);
	ClearLCD();
}

float GetWeight()
{
	return scale.get_units(5);	// In kg
}

void SetTare()
{
	scale.tare(5);
}
