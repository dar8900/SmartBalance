#include "SmartBalance.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <LCDLib.h>
#include "BalanceLCD.h"
#include "Calibration.h"
#include "Foods.h"
#include <Wire.h>
#include <EEPROM.h>
#include "EepromAddr.h"
#include "Web.h"
#include "Keyboard.h"

#define SDA_PIN   5
#define SCL_PIN   4

extern WiFiClient client;
extern uint8_t PreferenceNumber;

SYSTEM_FLAGS Flags;


void CheckEvent()
{
	// if(client.connected())
	// {
		// Flags.ClientConnected = true;
		// HandleClient();
	// }
}



// void EEPROM.write(uint8_t Addr, uint8_t Value)
// {
	// if(EEPROM.read(Addr) != Value)
	// {
		// EEPROM.write(Addr, Value);
		// EEPROM.commit();
	// }
// }

void Wait(uint8_t Row, bool Clear)
{
	uint8_t ButtonPress = NO_PRESS;
	bool ExitWait = false;
	if(Clear)
		ClearLCD();
	LCDPrintString(Row, CENTER_ALIGN, "premere ok...");
	while(!ExitWait)
	{
		ButtonPress = KeyPressed();
		switch(ButtonPress)
		{
			case UP:
			case DOWN:
			case EXIT:
				break;
			case OK_TARE:
				ExitWait = true;
				break;
			default:
				break;
		}
		yield();
	}
	ClearLCD();
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
	ClearLCD();
	LCDPrintString(TWO, CENTER_ALIGN, "Home Microtech");
	delay(1000);
	ClearLCD();
	Wait(TWO, true);
	BalanceSetup();
	FillNutritionalTableSizeArray();
	//WebServerInit();
	CategoryChoice = MAX_CATEGORY;
	FoodChoice = MAX_FOOD;
	PreferenceInit();
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
		case COMPLETE_LAUNCH_FUNCTION:
			LaunchMenu();
			break;
		case PREFERENCE_1_FUNCTION:
			if(CheckPreference(PREFERENCE_1))
				ShowMeasure();
			break;
		case PREFERENCE_2_FUNCTION:
			if(CheckPreference(PREFERENCE_2))
				ShowMeasure();
			break;
		case PREFERENCE_3_FUNCTION:
			if(CheckPreference(PREFERENCE_3))
				ShowMeasure();
			break;
		case PREFERENCE_4_FUNCTION:
			if(CheckPreference(PREFERENCE_4))
				ShowMeasure();
			break;
		case CALIBRATION_FUNCTION:
			EEPROM.write(CALIBRATION_MODE_ADDR, CALIBRATION_MODE);
			ClearLCD();
			LCDPrintString(ONE, CENTER_ALIGN, "Passaggio alla");
			LCDPrintString(TWO, CENTER_ALIGN, "calibrazione");
			delay(1000);
			ClearLCD();
			LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
			delay(1000);
			EEPROM.commit();
			ESP.restart();	
		default:
			break;		
	}
	yield();
}
