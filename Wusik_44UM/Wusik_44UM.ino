/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
#include <Adafruit_NeoPixel.h>
#define LED_PIN    30
#define LED_COUNT 32
//
// ------------------------------------------------------------------------------------------------------------------------------------
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
//
// ------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  #define WSETPIN(pin) pinMode(pin, INPUT); digitalWrite(pin, HIGH)
  //
  WSETPIN(0);
  WSETPIN(1);
  WSETPIN(2);
  WSETPIN(3);
  WSETPIN(4);
  WSETPIN(5);
  WSETPIN(6);
  WSETPIN(7);
  WSETPIN(8);
  WSETPIN(9);
  WSETPIN(10);
  WSETPIN(14);
  WSETPIN(15);
  WSETPIN(16);
  WSETPIN(18);
  WSETPIN(19);
  WSETPIN(20);
  WSETPIN(21);
  //
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  //
  //colorWipe(strip.Color(20,   20,   20)); // Red
  //
  Serial1.begin(9600);
  Serial1.println("Startup!");
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
  #define WCHECKBUTTON(pin)\ 
    if (digitalRead(pin) == LOW)\
    {\
      delay(5);\
      if (digitalRead(pin) == LOW)\
      {\
        Serial.println(pin, DEC);\
        delay(10);\
      }\
    }
  //
  WCHECKBUTTON(0);
  WCHECKBUTTON(1);
  WCHECKBUTTON(2);
  WCHECKBUTTON(3);
  WCHECKBUTTON(4);
  WCHECKBUTTON(5);
  WCHECKBUTTON(6);
  WCHECKBUTTON(7);
  WCHECKBUTTON(8);
  WCHECKBUTTON(9);
  WCHECKBUTTON(10);
  WCHECKBUTTON(14);
  WCHECKBUTTON(15);
  WCHECKBUTTON(16);
  WCHECKBUTTON(18);
  WCHECKBUTTON(19);
  WCHECKBUTTON(20);
  WCHECKBUTTON(21);

}
//
// ------------------------------------------------------------------------------------------------------------------------------------
/*void colorWipe(uint32_t color)
{
  for(int i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, color);
    strip.show();
  }
}*/
