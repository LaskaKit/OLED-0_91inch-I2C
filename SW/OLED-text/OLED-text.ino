/*
* This example code for LaskaKit 0.91" SSD1306 (SSD1315) OLED i2c display
* is used with ESP32 DEVkit board.
*
*
* Made by (c) laskakit.cz 2022
*
* Libraries
* https://github.com/adafruit/Adafruit-GFX-Library
* https://github.com/adafruit/Adafruit_SH110X
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>     // https://github.com/adafruit/Adafruit-GFX-Library
#include <Adafruit_SSD1306.h>

//For LaskaKit ESP32 DEVKit
#define PIN_ON 2       // Power pin on LaskaKit ESP32-DEVKit
#define PIN_SCL 22
#define PIN_SDA 21

//For LaskaKit ESP32-S3 DEVKit
//#define PIN_ON 47       // Power pin on LaskaKit ESP32-DEVKit
//#define PIN_SCL 2
//#define PIN_SDA 42

//For LaskaKit LaskaKit C6-LPkit
//#define PIN_ON 11
//#define PIN_SCL 5
//#define PIN_SDA 4

#define DELAYTIME 1000
#define i2c_Address 0x3c

Adafruit_SSD1306 display(128, 32, &Wire, -1);


void setup() {
  Serial.begin(115200);
  pinMode(PIN_ON, OUTPUT);
  digitalWrite(PIN_ON, HIGH);

  Wire.begin(PIN_SDA, PIN_SCL);

  while(!Serial);    // time to get serial running
           
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, i2c_Address)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  display.clearDisplay(); 
  display.setTextColor(SSD1306_WHITE);        // Draw white text
  display.setTextSize(1); 
}

void loop() {
  // put your main code here, to run repeatedly:
   display.setCursor(0,0);
   display.println((String)"Teplota: 25C");
   display.println((String)"Tlak: 950hPa");
   display.println((String)"Vlhkost: 65%");
   display.println((String)"Nadmorska vyska: 554m");
   display.display(); 
   delay(500);
   display.clearDisplay();
}  
