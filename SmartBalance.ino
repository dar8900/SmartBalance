#include "SmartBalance.h"
#include "BalanceLCD.h"
#include "Calibration.h"
#include "Foods.h"


void setup() 
{
	Serial.begin(9600);
	pinMode(UP_PIN, INPUT);
	pinMode(DOWN_PIN, INPUT);
	pinMode(OK_TARE_PIN, INPUT);
	pinMode(EXIT_PIN, INPUT);

}

void loop() 
{

}
