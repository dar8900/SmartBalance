#ifndef CALIBRATION_H
#define CALIBRATION_H
#include <Arduino.h>
#include <stdint.h>

#define HX711_CLK   2
#define HX711_DOUT  3


void FirstCalibration(void);

void BalanceSetup(void);
float GetWeight(void);
void SetTare(void);

#endif