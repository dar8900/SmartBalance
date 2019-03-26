#ifndef CALIBRATION_H
#define CALIBRATION_H
#include <Arduino.h>
#include <stdint.h>
#include "HX711.h"

#define HX711_CLK   1
#define HX711_DOUT  3


typedef enum
{
	CALIBRATION_MODE = 0,
	NORMAL_MODE
}BALANCE_MODES;


void AutoCalibration(void);
void Calibration(void);

void BalanceSetup(void);
float GetWeight(void);
void SetTare(void);
void SetScale(float NewScale);
void ResetTare(void);
void ResetScale(void);
void ScaleInit(void);
bool IsScaleReady(void);
#endif