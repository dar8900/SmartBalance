#include "SmartBalance.h"
#include "LCDLib.h"
#include "BalanceLCD.h"
#include "Calibration.h"
#include "Foods.h"
#include <Wire.h>
#include <EEPROM.h>

#define SDA_PIN   5
#define SCL_PIN   4


void setup() 
{
	Serial.begin(9600);
	pinMode(UP_PIN, INPUT);
	pinMode(DOWN_PIN, INPUT);
	pinMode(OK_TARE_PIN, INPUT);
	pinMode(EXIT_PIN, INPUT);
	Wire.begin(SDA_PIN, SCL_PIN); // Inizializza I2C per NodeMCU
	EEPROM.begin(512);
	LCDInit();
#ifndef CALIBRATION_PROCEDURE
	BalanceSetup();
#else
	FirstCalibration()
#endif
}

void loop() 
{
#ifndef CALIBRATION_PROCEDURE
	if(FoodChoiceMenu())
	{
		ShowMeasure();
	}
	
#endif
}
