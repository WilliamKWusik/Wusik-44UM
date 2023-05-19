/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>
#include "MIDIUSB.h"
#include <EEPROM.h>
#include "Config.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
Adafruit_NeoPixel strip(RGBLEDS_COUNT, RGBLEDS_PIN, NEO_GRB + NEO_KHZ800);
//
#if INTRO_ANIMATION
  byte rgbsIntroAnimation[16] = { 0, 1, 2, 3, 7, 11, 15, 14, 13, 12, 8, 4, 5, 6, 10, 9 };
#endif
//
#if ENABLE_BUTTON_CONFIG_STARTUP 
  byte holdButtonStartup = 0;
#endif
//
struct ButtonsStruct
{
  byte type = kNothing;
  byte colorOn[2] = { kWhite, kWhite };
  byte colorOff[2] = { kOff, kOff };
  byte colorSidesOn[2] = { kWhite, kWhite };
  byte colorSidesOff[2] = { kOff, kOff };
  byte value1 = 0; // depends on type //
  byte value2 = 0; // depends on type //
  char valueChar = 0; // depends on type //
  byte channel = 0; // MIDI Channel //
  byte velocity = 127;
};
//
byte currentMode = 0;
byte currentPage = 0;
byte buttonsCounter[18];
__uint24 buttonsDown = 0;
__uint24 buttonsReleased = 0;
ButtonsStruct buttonsStruct[MAX_PAGES][18];
byte buttonsList[MAX_BUTTON_PIN + 1];
byte rgbLEDsList[16][2] = {{7,6},{5,4},{3,2},{1,0},{8,9},{10,11},{12,13},{14,15},{23,22},{21,20},{19,18},{17,16},{24,25},{26,27},{28,29},{30,31}};
