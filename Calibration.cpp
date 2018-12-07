/*
 Setup your scale and start the sketch WITHOUT a weight on the scale
 Once readings are displayed place the weight on the scale
 Press +/- or a/z to adjust the calibration_factor until the output readings match the known weight
 Arduino pin 6 -> HX711 CLK
 Arduino pin 5 -> HX711 DOUT
 Arduino pin 5V -> HX711 VCC
 Arduino pin GND -> HX711 GND 
*/


#include "Calibration.h"
#include "HX711.h"
#include <EEPROM.h>
#include "EepromAddr.h"


#define CALIBRATION_PROCEDURE	

#define WEIGHT_TEST 	100
 
HX711 scale(HX711_CLK, HX711_DOUT);




#ifdef CALIBRATION_PROCEDURE

float calibration_factor = 0; // this calibration factor is adjusted according to my load cell

void FirstCalibration()
{
	scale.set_scale();
	scale.tare(); //Reset the scale to 0

	long zero_factor = scale.read_average();
	
	while(1)
	{
		scale.set_scale(calibration_factor); //Adjust to this calibration factor

		Serial.print("Reading: ");
		Serial.print(scale.get_units(10), 3);
		Serial.print(" kg"); //Change this to kg and re-adjust the calibration factor if you follow SI units like a sane person
		Serial.print(" calibration_factor: ");
		Serial.print(calibration_factor);
		Serial.println();
		if(Serial.available())
		{
			char temp = Serial.read();
			if(temp == '+')
				calibration_factor += 1;
			else if(temp == '-')
				calibration_factor -= 1;
			else if(temp == 'w')
				calibration_factor += 10;
			else if(temp == 's')
				calibration_factor -= 10;
			else if(temp == 'o')
			{
				EEPROM.put(CALIBRATION_ADDR, calibration_factor);
				break;
			}
			else if(temp == 'e')
				break;
		}
	}
}
#endif // CALIBRATION_PROCEDURE


void BalanceSetup()
{
	float CalibrationValue = 0.0;
	EEPROM.get(CALIBRATION_ADDR, CalibrationValue);
	scale.set_scale(CalibrationValue);
	scale.tare(5); //Reset the scale to 0
	delay(1000);	
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

