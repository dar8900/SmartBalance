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
}SYSTEM_FLAGS;

extern SYSTEM_FLAGS Flags;

void EEPROMUpdate(uint8_t Addr, uint8_t Value);
void CheckEvent(void);

#endif