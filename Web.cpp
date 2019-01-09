#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <EEPROM.h>
#include "BalanceLCD.h"
#include "LCDLib.h"
#include "Keyboard.h"
#include "Foods.h"
#include "Calibration.h"
#include "Web.h"
#include "EepromAddr.h"
#include "BalanceLCD.h"
#include "SmartBalance.h"


/* Set these to your desired credentials. */
const char *ssid = "SmartB_AP";
const char *password = "SmartB";
const char *DNSName = "SB01";

ESP8266WebServer server(80);
WiFiClient client;

String HomePage;

static void BuildCategoryFoodHtml()
{
	String Option = "";
	HomePage = "<!DOCTYPE html> <html><body><h2style=\"text-align:center;\">Categoria</h2><p style=\"text-align:center;\">Selezione la categoria:</p><form style=\"text-align:center;\" action=\"/category_selection\" method=\"POST\">  <select name=\"category\">"; 
	for(uint8_t i = 0; i < MAX_CATEGORIES; i++)
	{
		Option += "<option name=";
		Option += "\"categoria ";
		Option += String(i+1) + "\"";
		Option += "value=\"";
		Option += "categoria_";
		Option += String(i+1) + "\">";
		Option += String(CategoryTable[i].CategoryName);
		Option += "</option>";
		yield();
	}
	HomePage += Option + "</select><br><br>";
	HomePage += "<input type=\"submit\" value=\"Scegli categoria\"></form>";
	// HomePage += "<h2>Cibo</h2><p>Selezione il cibo:</p><form action=\"/food_selection\" method=\"POST\">  <select name=\"food\">"; 
	// for(uint8_t i = 0; i < MAX_CATEGORIES; i++)
	// {
		// Option = "<option name=";
		// Option += "\"cibo ";
		// Option += String(i+1) + "\"";
		// Option += "value=\"";
		// Option += "cibo_";
		// Option += String(i+1) + "\">";
		// Option += String(CategoryTable[i].CategoryName);
		// Option += "</option>";
	// }
	HomePage += "</body></html>";
}


void WebServerInit()
{
	if(WiFi.softAP(ssid, password))
	{
		ClearLCD();
		if (MDNS.begin(DNSName)) 
		{        
			LCDPrintString(ONE, CENTER_ALIGN, "Nome Web:");
			LCDPrintString(TWO, CENTER_ALIGN, "http://SB01.local");
			LCDPrintString(THREE, LEFT_ALIGN, "IP:");
			LCDPrintString(THREE, RIGHT_ALIGN, String(WiFi.softAPIP()));
			LCDPrintString(FOUR, LEFT_ALIGN, "SSID:");
			LCDPrintString(FOUR, RIGHT_ALIGN, String(ssid));
		} 
		else
		{

			LCDPrintString(TWO, LEFT_ALIGN, "IP:");
			LCDPrintString(TWO, RIGHT_ALIGN, String(WiFi.softAPIP()));
			LCDPrintString(THREE, LEFT_ALIGN, "SSID:");
			LCDPrintString(THREE, RIGHT_ALIGN, String(ssid));
		}
		delay(1500);
		ClearLCD();
		BuildCategoryFoodHtml();
		server.begin(); 
		server.on("/", HTTP_GET, handleHomePage);
		server.on("/category_selection", HTTP_POST, handleCategorySelection);
		server.onNotFound(handleNotFound);
	}
}

static uint8_t SearchCategoryNumber(String CategoryName)
{
	uint8_t i = 0;
	for(i = 0; i < MAX_CATEGORIES; i++)
	{
		if(CategoryName == String(CategoryTable[i].CategoryName))
			break;
		yield();
	}
	return i;
}

static int16_t SearchFoodNumber(String Food, NUTRITIONAL_VALUES *NutritionalTable, uint8_t NutritionalTableSize)
{
	int16_t FoodIndex = 0;
	bool Found = false;
	for(FoodIndex = 0; FoodIndex <= NutritionalTableSize; FoodIndex++)
	{
		if(String(NutritionalTable[FoodIndex].FoodName) == Food)
		{
			Found = true;
			break;
		}
		yield();
	}
	if(Found)
		return FoodIndex;
	else
		return -1;
}

void handleHomePage()
{
	server.send(200, "text/html", HomePage.c_str());
}

void handleCategorySelection() 
{                
	String ClientCategoryChoice = String(server.arg("category"));
	CategoryChoice = SearchCategoryNumber(ClientCategoryChoice);
	Flags.CategoryModified = true;
	ClearLCD();
	LCDPrintString(TWO, CENTER_ALIGN, "Categoria " + CategoryChoice);
	delay(3000);
	ClearLCD();
}

void handleNotFound()
{
	server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

void HandleClient()
{
	server.handleClient();                     // Listen for HTTP requests from clients
}

    // <option name=\"categoria n\" value=\"categoria_n\">Nome categoria</option>
  // </select>
  // <br><br>
 // <input type=\"submit\" value=\"Scegli categoria\">
// </form>


// <form action=\"/category_selection\" method=\"POST\">
  // <select name="category">
    // <option name=\"categoria n\" value="categoria_n">Nome categoria</option>
  // </select>
  // <br><br>
 // <input type=\"submit\" value=\"Scegli categoria\">
// </form>


// </body>
// </html>
// ";





/*

void handleRoot();              // function prototypes for HTTP handlers
void handleLogin();
void handleNotFound();

void setup(void){

	WiFi.softAP(ssid, password);

  if (MDNS.begin("SB01")) 
  {              // Start the mDNS responder for esp8266.local
    Serial.println("mDNS responder started");
  } 
  else 
  {
    Serial.println("Error setting up MDNS responder!");
  }

  server.on("/", HTTP_GET, handleRoot);        // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/login", HTTP_POST, handleLogin); // Call the 'handleLogin' function when a POST request is made to URI "/login"
  server.onNotFound(handleNotFound);           // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

  server.begin();                            // Actually start the server
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();                     // Listen for HTTP requests from clients
}

void handleRoot() {                          // When URI / is requested, send a web page with a button to toggle the LED
  server.send(200, "text/html", "<form action=\"/login\" method=\"POST\"><input type=\"text\" name=\"username\" placeholder=\"Username\"></br><input type=\"password\" name=\"password\" placeholder=\"Password\"></br><input type=\"submit\" value=\"Login\"></form><p>Try 'John Doe' and 'password123' ...</p>");
}

void handleLogin() {                         // If a POST request is made to URI /login
  if( ! server.hasArg("username") || ! server.hasArg("password") 
      || server.arg("username") == NULL || server.arg("password") == NULL) { // If the POST request doesn't have username and password data
    server.send(400, "text/plain", "400: Invalid Request");         // The request is invalid, so send HTTP status 400
    return;
  }
  if(server.arg("username") == "John Doe" && server.arg("password") == "password123") { // If both the username and the password are correct
    server.send(200, "text/html", "<h1>Welcome, " + server.arg("username") + "!</h1><p>Login successful</p>");
  } else {                                                                              // Username and password don't match
    server.send(401, "text/plain", "401: Unauthorized");
  }
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}
*/