#include "SmartBalance.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "LCDLib.h"
#include "BalanceLCD.h"
#include "Calibration.h"
#include "Foods.h"
#include <Wire.h>
#include <EEPROM.h>
#include "EepromAddr.h"
#include "Web.h"

#define SDA_PIN   5
#define SCL_PIN   4

extern WiFiClient client;

SYSTEM_FLAGS Flags;


void CheckEvent()
{
	// if(client.connected())
	// {
		// Flags.ClientConnected = true;
		// HandleClient();
	// }
}



void EEPROMUpdate(uint8_t Addr, uint8_t Value)
{
	if(EEPROM.read(Addr) != Value)
	{
		EEPROM.write(Addr, Value);
		EEPROM.commit();
	}
}



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
	LCDCreateIcon(UpArrow, UP_ARROW);
	LCDCreateIcon(DownArrow, DOWN_ARROW);
	LCDCreateIcon(ToRightArrow, TO_RIGHT_ARROW);
	LCDCreateIcon(ToLeftArrow, TO_LEFT_ARROW);
	BalanceSetup();
	FillNutritionalTableSizeArray();
	//WebServerInit();
	CategoryChoice = MAX_CATEGORY;
	FoodChoice = MAX_FOOD;
}

void loop() 
{
	WichFunction = MenuChoice();
	switch(WichFunction)
	{
		case BALANCE_FUNCTION:
			if(FoodChoiceMenu())
			{
				ShowMeasure();
			}
			break;
		case INFO_FUNCTION:
			if(FoodChoiceMenu)
			{
				ShowInfo();
			}
			break;
		case CALIBRATION_FUNCTION:
			EEPROMUpdate(CALIBRATION_MODE_ADDR, CALIBRATION_MODE);
			delay(100);
			ESP.restart();	
		default:
			break;		
	}
}
