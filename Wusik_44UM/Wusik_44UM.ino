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
byte buttonsStatus[18];
byte buttonsList[22];
byte holdButtonStartup = 0;
byte rgbLEDsList[16][2] = {  {  7,  6 }, {  5,  4 }, {  3,  2 }, {  1,  0 },
                             {  8,  9 }, { 10, 11 }, { 12, 13 }, { 14, 15 },
                             { 23, 22 }, { 21, 20 }, { 19, 18 }, { 17, 16 },
                             { 24, 25 }, { 26, 27 }, { 28, 29 }, { 30, 31 } };

//  midiEventPacket_t controller = {0xB, 0xB0, getMIDICCValue(button), controllValue};
//  MidiUSB.sendMIDI(controller);
//  MidiUSB.flush();
