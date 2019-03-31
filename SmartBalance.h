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


// #define	UP_PIN       16          // 12 D3
// #define	DOWN_PIN     13       // 13 D7
// #define	OK_TARE_PIN  14    // 14 D5
// #define	EXIT_PIN     15        // 15 D8


typedef struct
{
	bool ClientConnected;
	bool CategoryModified;	
	bool LaunchModeCal;
	bool LaunchModeMacro;
}SYSTEM_FLAGS;

extern SYSTEM_FLAGS Flags;

void Reboot(void);
void CheckEvent(void);
void Wait(uint8_t Row, bool Clear);
#endif