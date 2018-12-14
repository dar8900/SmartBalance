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

	

 
HX711 scale(HX711_CLK, HX711_DOUT);



void FirstCalibration()
{
	float calibration_factor = 0; // this calibration factor is adjusted according to my load cell
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
		LCDPrintString(ONE, LEFT_ALIGN, "Units:");
		ValueUnit = String(scale.get_units(10), 3) + "kg";
		LCDPrintString(ONE, RIGHT_ALIGN, ValueUnit);
		LCDPrintString(TWO, LEFT_ALIGN, "Cal fact:");
		LCDPrintString(TWO, RIGHT_ALIGN, String(calibration_factor, 4));
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
				calibration_factor -=1;
				ClearLCD();
				break;
			case DOWN:
				calibration_factor +=1;
				ClearLCD();
				break;
			case OK_TARE:
				calibration_factor +=10;
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
		delay(50);
	}
}



void BalanceSetup()
{
	uint8_t BalanceMode = 10;
	float CalibrationValue = 0.0;
	BalanceMode = EEPROM.read(CALIBRATION_MODE_ADDR);
	if(BalanceMode != CALIBRATION_MODE || BalanceMode != NORMAL_MODE)
	{
		BalanceMode = NORMAL_MODE;
		EEPROM.write(CALIBRATION_MODE_ADDR, BalanceMode);
		EEPROM.commit();
		delay(100);
		ESP.restart();
	}
	if(BalanceMode == CALIBRATION_MODE)
	{
		FirstCalibration();
		EEPROM.write(CALIBRATION_MODE_ADDR, NORMAL_MODE);
		EEPROM.commit();
		delay(100);
		ESP.restart();		
	}
	else if(BalanceMode == NORMAL_MODE)
	{
		EEPROM.get(CALIBRATION_ADDR, CalibrationValue);
		scale.set_scale(CalibrationValue);
		scale.tare(5); //Reset the scale to 0
		delay(1000);
	}	
}

float GetWeight()
{
	float ReadedWeight = 0.0;
	ReadedWeight = scale.get_units(10);	// In kg
	return ReadedWeight;	
}

void SetTare()
{
	scale.tare(5);
}
