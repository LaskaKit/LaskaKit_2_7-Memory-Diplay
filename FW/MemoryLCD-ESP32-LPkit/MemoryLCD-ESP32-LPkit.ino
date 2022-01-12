/*
*
* Example code for 2.7" memoryLCD with ESP32-LPkit.
* https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/
* This example shows the bitmap on the screen. 
* 
* made by laskakit.cz
* 
* Libraries:
* https://github.com/adafruit/Adafruit_SHARP_Memory_Display
* https://github.com/adafruit/Adafruit-GFX-Library
*/
#include <WiFi.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>
#include "bitmap.h"

// SPI
#define SHARP_SCK  18
#define SHARP_MOSI 23
#define SHARP_SS   5

// definition of display and connection
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 400, 240);

#define BLACK 0
#define WHITE 1

void setup() {
  WiFi.mode(WIFI_MODE_NULL); // disable Wi-Fi
  Serial.begin(115200); // Serial

  // start & clear the display
  display.begin();  // initialization
  display.setRotation(0); // rotation
  display.clearDisplay(); // clear display
  display.setCursor(0,0); // set cursor
  display.setTextColor(BLACK, WHITE); // set color
  display.fillRect( 0,  0,  400,  240,  BLACK);

  //display.drawBitmap(0, 0, logo, 400, 240, BLACK); // put logo - bitmap.h

  display.refresh(); // update the screen

}

void loop() {
  // put your main code here, to run repeatedly:

}
