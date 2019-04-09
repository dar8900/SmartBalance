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

void Reboot()
{
	ESP.restart();
}

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
		delay(50);
	}
	ClearLCD();
}

void setup() 
{
	Serial.begin(9600);
	pinMode(DOWN_PIN, INPUT);
	pinMode(OK_TARE_PIN, INPUT);
	pinMode(EXIT_PIN, INPUT);
	// pinMode(UP_PIN, INPUT);

	Wire.begin(SDA_PIN, SCL_PIN); // Inizializza I2C per NodeMCU
	EEPROM.begin(512);
	LCDInit();
	ScaleInit();
	LCDCreateIcon(UpArrow, UP_ARROW);
	LCDCreateIcon(DownArrow, DOWN_ARROW);
	LCDCreateIcon(ToRightArrow, TO_RIGHT_ARROW);
	LCDCreateIcon(ToLeftArrow, TO_LEFT_ARROW);
	ClearLCD();
	LCDPrintString(TWO, CENTER_ALIGN, "Home Microtech");
	delay(1500);
	ClearLCD();
	// Wait(TWO, true);
	BalanceSetup();
	// FillNutritionalTableSizeArray();
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
		case BALANCE_FUNCTION_NORM:
			ShowNormalMeasure();
			break;
		case BALANCE_FUNCTION_CAL:
			if(FoodChoiceMenu())
			{
				ShowMeasureCal();
			}
			break;
		case INFO_FUNCTION:
			if(FoodChoiceMenu())
			{
				ShowInfo();
			}
			break;
		case COMPLETE_LAUNCH_FUNCTION:
			LaunchMenu();
			break;
		case PREFERENCE_1_FUNCTION:
			if(CheckPreference(PREFERENCE_1))
				ShowMeasureCal();
			break;
		case PREFERENCE_2_FUNCTION:
			if(CheckPreference(PREFERENCE_2))
				ShowMeasureCal();
			break;
		case PREFERENCE_3_FUNCTION:
			if(CheckPreference(PREFERENCE_3))
				ShowMeasureCal();
			break;
		case PREFERENCE_4_FUNCTION:
			if(CheckPreference(PREFERENCE_4))
				ShowMeasureCal();
			break;
		case PREFERENCE_5_FUNCTION:
			if(CheckPreference(PREFERENCE_5))
				ShowMeasureCal();
			break;
		case PREFERENCE_6_FUNCTION:
			if(CheckPreference(PREFERENCE_6))
				ShowMeasureCal();
			break;
		case PREFERENCE_7_FUNCTION:
			if(CheckPreference(PREFERENCE_7))
				ShowMeasureCal();
			break;
		case PREFERENCE_8_FUNCTION:
			if(CheckPreference(PREFERENCE_8))
				ShowMeasureCal();
			break;
		case PREFERENCE_9_FUNCTION:
			if(CheckPreference(PREFERENCE_9))
				ShowMeasureCal();
			break;
		case PREFERENCE_10_FUNCTION:
			if(CheckPreference(PREFERENCE_10))
				ShowMeasureCal();
			break;
		case PREFERENCE_11_FUNCTION:
			if(CheckPreference(PREFERENCE_11))
				ShowMeasureCal();
			break;
		case PREFERENCE_12_FUNCTION:
			if(CheckPreference(PREFERENCE_12))
				ShowMeasureCal();
			break;
		case PREFERENCE_13_FUNCTION:
			if(CheckPreference(PREFERENCE_13))
				ShowMeasureCal();
			break;
		case PREFERENCE_14_FUNCTION:
			if(CheckPreference(PREFERENCE_14))
				ShowMeasureCal();
			break;
		case PREFERENCE_15_FUNCTION:
			if(CheckPreference(PREFERENCE_15))
				ShowMeasureCal();
			break;
		case PREFERENCE_16_FUNCTION:
			if(CheckPreference(PREFERENCE_16))
				ShowMeasureCal();
			break;
		case PREFERENCE_17_FUNCTION:
			if(CheckPreference(PREFERENCE_17))
				ShowMeasureCal();
			break;
		case PREFERENCE_18_FUNCTION:
			if(CheckPreference(PREFERENCE_18))
				ShowMeasureCal();
			break;
		case PREFERENCE_19_FUNCTION:
			if(CheckPreference(PREFERENCE_19))
				ShowMeasureCal();
			break;
		case PREFERENCE_20_FUNCTION:
			if(CheckPreference(PREFERENCE_20))
				ShowMeasureCal();
			break;
		case CALIBRATION_FUNCTION:
			{
				EEPROM.write(CALIBRATION_MODE_ADDR, CALIBRATION_MODE);
				ClearLCD();
				LCDPrintString(ONE, CENTER_ALIGN, "Passaggio alla");
				LCDPrintString(TWO, CENTER_ALIGN, "calibrazione");
				delay(1000);
				ClearLCD();
				LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
				EEPROM.commit();
				delay(1000);			
				ESP.restart();	
			}
		case RESET_DEFAULT:
			{
				EEPROM.write(CALIBRATION_MODE_ADDR, RESET_DEFAULT_MODE);
				ClearLCD();
				LCDPrintString(ONE, CENTER_ALIGN, "Reset a");
				LCDPrintString(TWO, CENTER_ALIGN, "default");
				delay(1000);
				ClearLCD();	
				LCDPrintString(TWO, CENTER_ALIGN, "Riavvio in corso");
				EEPROM.commit();
				delay(1000);
				ESP.restart();	
			}			
		default:
			break;		
	}
	delay(500);
}
