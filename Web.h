#ifndef WEB_H
#define WEB_H
#include <Arduino.h>
#include <stdint.h>


void handleHomePage(void);
void handleCategorySelection(void);
void WebServerInit(void);
void handleNotFound(void);
void HandleClient(void);

#endif