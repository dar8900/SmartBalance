#ifndef WEB_H
#define WEB_H
#include <Arduino.h>
#include <stdint.h>


void handleHomePage(void);
void handleCategorySelection(void);
void WebServer(void);
void handleNotFound(void);

#endif