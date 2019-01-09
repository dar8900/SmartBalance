#include "SmartBalance.h"
#include "Keyboard.h"


uint8_t KeyPressed()
{
	uint8_t WichPressed = NO_PRESS;
	uint8_t PinIndex = 0;
	for(PinIndex = UP_PIN; PinIndex <= EXIT_PIN; PinIndex++)
	{
		if(digitalRead(PinIndex))
		{
			switch(PinIndex)
			{
				case UP_PIN:
					WichPressed = UP;
					break;
				case DOWN_PIN:
					WichPressed = DOWN;
					break;
				case OK_TARE_PIN:
					WichPressed = OK_TARE;
					break;
				case EXIT_PIN:
					WichPressed = EXIT;
					break;
				default:
					break;
			}
			break;
		}
		else
			WichPressed = NO_PRESS;
		yield();
	}
	return WichPressed;
}