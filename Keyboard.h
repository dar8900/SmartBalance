#ifndef KEABOARD_H
#define KEABOARD_H
#include <Arduino.h>
#include <stdint.h>

typedef enum
{
	UP,
	DOWN,
	OK_TARE,
	EXIT,
	NO_PRESS	
}BUTTONS;

uint8_t KeyPressed(void);


#endif