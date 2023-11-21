/*
* Example code for 2.7" memoryLCD https://www.laskakit.cz/laskakit-2-7--400x240-lcd-memory-displej/ 
* with LaskaKit boards
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

// SPI LaskaKit ESP32-LPKit https://www.laskakit.cz/laskakit-esp32-lpkit-pcb-antenna/
//#define SHARP_SCK  18
//#define SHARP_MOSI 23
//#define SHARP_CS   5

// SPI uSUP LaskaKit ESP32-DEVKit https://www.laskakit.cz/laskakit-esp32-devkit/
//#define SHARP_SCK  14
//#define SHARP_MOSI 13
//#define SHARP_CS   15
//#define USUP_POWER 2  //uSUP connector power output pin

// SPI uSUP LaskaKit ESP32-S3-DEVKit https://www.laskakit.cz/laskakit-esp32-s3-devkit
#define SHARP_SCK  12
#define SHARP_MOSI 11
#define SHARP_CS   10
#define USUP_POWER 47 //uSUP connector power output pin

// definition of display and connection
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_CS, 400, 240);

#define BLACK 0
#define WHITE 1

void setup() {

  pinMode(2, OUTPUT);    // Set uSUP connector power transistor as output
  digitalWrite(2, HIGH); // Turn power ON uSUP connector
  delay(100);            // Delay so it has time to turn on

  WiFi.mode(WIFI_MODE_NULL); // disable Wi-Fi
  Serial.begin(115200); // Serial

  // start & clear the display
  display.begin();  // initialization
  display.setRotation(0); // rotation
  display.clearDisplay(); // clear display
  display.setCursor(0,0); // set cursor
  display.setTextColor(BLACK, WHITE); // set color

  display.drawBitmap(0, 0, logo, 400, 240, BLACK); // put logo - bitmap.h

  display.refresh(); // update the screen

}

void loop() {
  // put your main code here, to run repeatedly:

}
