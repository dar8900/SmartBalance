/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/


#include "Calibration.h"

#include <EEPROM.h>
#include "EepromAddr.h"
#include <LCDLib.h>
#include "Keyboard.h"
#include "SmartBalance.h"
#include "BalanceLCD.h"
	
extern PREFERENCE_TYPE FoodPreference[MAX_PREFERENCE];
 
HX711 scale;


void BalanceSetup()
{
	uint8_t BalanceMode = 10;
	float CalibrationValue = 0.0;
	BalanceMode = EEPROM.read(CALIBRATION_MODE_ADDR);
	if(BalanceMode != CALIBRATION_MODE && BalanceMode != NORMAL_MODE)
	{
		ClearLCD();
		EEPROM.write(CALIBRATION_MODE_ADDR, CALIBRATION_MODE);
		for(uint8_t PrefIndex = 0; PrefIndex < MAX_PREFERENCE; PrefIndex++)
		{
			EEPROM.write(FoodPreference[PrefIndex].CategoryAddr, INVALID_EEPROM_VALUE);
			EEPROM.write(FoodPreference[PrefIndex].FoodAddr, INVALID_EEPROM_VALUE);
			delay(10);
		}	
		LCDPrintString(ONE, CENTER_ALIGN, "Inizializzo la");
		LCDPrintString(TWO, CENTER_ALIGN, "bilancia, attendere");
		delay(1000);
		ClearLCD();
		LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
		EEPROM.commit();
		delay(1500);
		ESP.restart();
	}
	if(BalanceMode == CALIBRATION_MODE)
	{
		ClearLCD();
		LCDPrintString(ONE, CENTER_ALIGN, "Modalita:");
		LCDPrintString(TWO, CENTER_ALIGN, "CALIBRAZIONE");
		delay(1500);
		ClearLCD();
		while(!IsScaleReady())
		{
			LCDPrintString(ONE, CENTER_ALIGN, "Bilancia non pronta");
		}
		ClearLCD();
		AutoCalibration();
		EEPROM.write(CALIBRATION_MODE_ADDR, NORMAL_MODE);
		delay(100);
		ClearLCD();
		LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
		delay(1500);
		ClearLCD();
		EEPROM.commit();
		delay(1000);
		ESP.restart();		
	}
	if(BalanceMode == NORMAL_MODE)
	{
		EEPROM.get(CALIBRATION_ADDR, CalibrationValue);
		scale.set_scale(CalibrationValue);
		scale.tare(5); //Reset the scale to 0
		delay(500);
	}	
}

// void Calibration()
// {
	// float calibration_factor = 500; // this calibration factor is adjusted according to my load cell
	// scale.set_scale();
	// scale.tare(); //Reset the scale to 0
	// String ValueUnit;
	// long zero_factor = scale.read_average();
	// uint8_t ButtonPress = NO_PRESS;
	// bool ExitCalibration = false;
	// ClearLCD();
	// while(!ExitCalibration)
	// {
		// scale.set_scale(calibration_factor); //Adjust to this calibration factor
		// LCDPrintString(TWO, LEFT_ALIGN, "Peso:");
		// ValueUnit = String(scale.get_units(10), 3) + "g";
		// LCDPrintString(TWO, RIGHT_ALIGN, ValueUnit);
		// LCDPrintString(THREE, LEFT_ALIGN, "K fact:");
		// LCDPrintString(THREE, RIGHT_ALIGN, String(calibration_factor, 4));
		// ButtonPress = KeyPressed();
		// switch(ButtonPress)
		// {
			// case UP:
				// calibration_factor -= 1;
				// ClearLCD();
				// break;
			// case DOWN:
				// calibration_factor += 1;
				// ClearLCD();
				// break;
			// case OK_TARE:
				// calibration_factor += 10;
				// ClearLCD();				
				// break;
			// case EXIT:
				// ExitCalibration = true;
				// EEPROM.put(CALIBRATION_ADDR, calibration_factor);
				// EEPROM.commit();
				// break;
			// default:
				// break;		
		// }
		// yield();
	// }
// }

// IL CELLULARE CON LA COVER PESA 208g

void AutoCalibration()
{
	uint16_t WeightTarget = 0;
	char PrintStr[21];
	uint8_t ButtonPress = NO_PRESS, PointPos = 0, TimerPoint = 1;
	float CalibrationFactor = 10.0, ReadedWeight = 0.0;
	bool ExitSetWeightTarget = false, ToggleValueView = false;
	uint16_t TimeExec = 0;
	ClearLCD();
	while(!ExitSetWeightTarget)
	{
		LCDPrintString(ONE, CENTER_ALIGN, "Inserire il");
		LCDPrintString(TWO, CENTER_ALIGN, "peso target:");
		snprintf(PrintStr, 20, "%dg", WeightTarget);
		LCDPrintString(THREE, CENTER_ALIGN, PrintStr);
		LCDPrintString(FOUR, CENTER_ALIGN, "Premere su, giu, ok");
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				if(WeightTarget > 0)
					WeightTarget--;
				else
					WeightTarget = 5000;
			case DOWN:
				if(WeightTarget < 5000)
					WeightTarget++;
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
		delay(25);	
	}
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Lasciare la bilancia");
	LCDPrintString(TWO, CENTER_ALIGN, "vuota e");
	Wait(THREE, false);
	ResetScale(); // Reset the balace scale
	ResetTare(); //Reset the scale to 0
	delay(1000);
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Mettere il peso");
	LCDPrintString(TWO, CENTER_ALIGN, "target sulla");
	LCDPrintString(THREE, CENTER_ALIGN, "bilancia e");
	Wait(FOUR, false);
	ClearLCD();
	LCDPrintString(ONE, CENTER_ALIGN, "Sto calibrando");
	float OldCalibrationF = 0.0;
	while(1)
	{
		if(CalibrationFactor != OldCalibrationF)
		{
			OldCalibrationF = CalibrationFactor;
			SetScale(CalibrationFactor);
		}
		ReadedWeight = roundf(scale.get_units(10));
		if(ReadedWeight < (float)WeightTarget)
		{
			CalibrationFactor -= 1.0;
			if(CalibrationFactor == 0)
				CalibrationFactor = -1.0;
		}
		else if(ReadedWeight > (float)WeightTarget)
		{
			CalibrationFactor += 1.0;
			if(CalibrationFactor == 0)
				CalibrationFactor = 1.0;
		}
		else if(ReadedWeight == (float)WeightTarget)
			break;

		LCDPrintString(TWO, LEFT_ALIGN, "Letto:");
		LCDPrintString(TWO, RIGHT_ALIGN, "Target:");
		snprintf(PrintStr, 20, "%8.1fg", ReadedWeight);
		LCDPrintString(THREE, LEFT_ALIGN, PrintStr);
		snprintf(PrintStr, 20, "%%dg", WeightTarget);
		LCDPrintString(THREE, RIGHT_ALIGN, PrintStr);
		snprintf(PrintStr, 20, "%4.1f%s", CalibrationFactor, " units");
		LCDPrintString(FOUR, CENTER_ALIGN, PrintStr);
		
		delay(200);
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
	return scale.get_units(5);	// In g
}

void ScaleInit()
{
	scale.begin(HX711_DOUT, HX711_CLK);
}

bool IsScaleReady()
{
	return scale.is_ready();
}

void SetTare()
{
	scale.tare(5);
}

void SetScale(float NewScale)
{
	scale.set_scale(NewScale);
}

void ResetTare()
{
	scale.tare();
}

void ResetScale()
{
	scale.set_scale();
}