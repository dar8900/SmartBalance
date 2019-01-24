#ifndef SMARTBALANCE_H
#define SMARTBALANCE_H

#include <Arduino.h>

typedef enum
{
	UP_PIN = 12,    // 12
	DOWN_PIN,       // 13
	OK_TARE_PIN,    // 14
	EXIT_PIN        // 15
}PINS;

typedef struct
{
	bool ClientConnected;
	bool CategoryModified;	
	bool LaunchModeCal;
	bool LaunchModeMacro;
}SYSTEM_FLAGS;

extern SYSTEM_FLAGS Flags;

void CheckEvent(void);
void Wait(uint8_t Row, bool Clear);
#endif