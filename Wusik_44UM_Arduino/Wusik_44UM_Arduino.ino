/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 * 
 * Version 1.0.0 (BETA 04) 06/10/2023 14:00
 * 
 * Important note: in order to disable the TX (Transmit) LED Blink on RGB LED #4 (in green) you need to edit the following arduino file:
 * \Users\USERNAME\AppData\Local\Arduino15\packages\arduino\hardware\avr\1.X.X\variants\leonardo\pins_arduino.h
 * And change the definitions below to "blank". Restart the Arduino IDE once you have done that.
 * #define TX_RX_LED_INIT ***REMOVE***
 * #define TXLED0 ***REMOVE***
 * #define TXLED1 ***REMOVE***
 * Otherwise, every time you send any MIDI data the top-right led will go green as that's the TX send.
 *
 * Another thing you need to change, in the following folder:
 * \Users\USERNAME\AppData\local\Arduino15\packages\arduino\hardware\avr\1.X.X
 * The filename: boards.txt
 * Add the following for the board Wusik 44UM and use this board instead.
 *
 ##############################################################

leonardo.name=Wusik 44UM
leonardo.vid.0=0x2341
leonardo.pid.0=0x0036
leonardo.vid.1=0x2341
leonardo.pid.1=0x8036
leonardo.vid.2=0x2A03
leonardo.pid.2=0x0036
leonardo.vid.3=0x2A03
leonardo.pid.3=0x8036
leonardo.upload_port.0.vid=0x2341
leonardo.upload_port.0.pid=0x0036
leonardo.upload_port.1.vid=0x2341
leonardo.upload_port.1.pid=0x8036
leonardo.upload_port.2.vid=0x2A03
leonardo.upload_port.2.pid=0x0036
leonardo.upload_port.3.vid=0x2A03
leonardo.upload_port.3.pid=0x8036
leonardo.upload_port.4.board=leonardo

leonardo.upload.tool=avrdude
leonardo.upload.tool.default=avrdude
leonardo.upload.tool.network=arduino_ota
leonardo.upload.protocol=avr109
leonardo.upload.maximum_size=28672
leonardo.upload.maximum_data_size=2560
leonardo.upload.speed=57600
leonardo.upload.disable_flushing=true
leonardo.upload.use_1200bps_touch=true
leonardo.upload.wait_for_upload_port=true

leonardo.bootloader.tool=avrdude
leonardo.bootloader.tool.default=avrdude
leonardo.bootloader.low_fuses=0xff
leonardo.bootloader.high_fuses=0xd8
leonardo.bootloader.extended_fuses=0xcb
leonardo.bootloader.file=caterina/Caterina-Leonardo.hex
leonardo.bootloader.unlock_bits=0x3F
leonardo.bootloader.lock_bits=0x2F

leonardo.build.mcu=atmega32u4
leonardo.build.f_cpu=16000000L
leonardo.build.vid=0x2341
leonardo.build.pid=0x8038
leonardo.build.usb_product="Wusik 44UM"
leonardo.build.board=AVR_LEONARDO
leonardo.build.core=arduino
leonardo.build.variant=leonardo
leonardo.build.extra_flags={build.usb_flags}
 * 
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#include <Adafruit_NeoPixel.h>
#include "MIDIUSB.h"
#include <EEPROM.h>
#include "Config.h"
//
struct ButtonsStruct
{
  byte type = kNothing;
  byte colorOn = kWhite;
  byte colorOff = kOff;
  byte value1 = 0; // depends on type //
  byte value2 = 0; // depends on type //
  char valueChar = 0; // depends on type //
  byte channel = 0; // MIDI Channel //
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
Adafruit_NeoPixel strip(RGBLEDS_COUNT, RGBLEDS_PIN, NEO_GRB + NEO_KHZ800);
//
#if INTRO_ANIMATION
  byte rgbsIntroAnimation[16] = { 0, 1, 2, 3, 7, 11, 15, 14, 13, 12, 8, 4, 5, 6, 10, 9 };
#endif
//
midiEventPacket_t midiRX;
byte machineID = 0;
byte bothTopButtonsHold = 0;
bool turnOffButtonLEDs = false; // Can be used to handle all leds via MIDI instead //
uint8_t data[8];
bool flushMIDI = false;
byte eepromVersion = 1;
byte currentMode = 0;
byte currentPage = 0;
byte buttonsCounter[18];
byte rgbBlinkColor[16];
byte updateFromFlash = 0;
int rgbBlinkCounter = 0;
int rgbBlinkCounterFast = 0;
bool rgbBlinkStatus = false;
bool rgbBlinkStatusFast = false;
bool remoteMode = false;
byte specialFullColorMidiNote[16][3];
__uint24 rgbBlink = 0;
__uint24 rgbBlinkFast = 0;
__uint24 buttonsDown = 0;
__uint24 buttonsReleased = 0;
__uint24 buttonsHolding = 0;
byte customColors[MAX_CUSTOM_COLORS][3];
ButtonsStruct buttonsStruct[MAX_PAGES][18];
ButtonsStruct buttonsHoldTop;
byte buttonsList[MAX_BUTTON_PIN + 1];
byte rgbLEDsList[16][2] = {{7,6},{5,4},{3,2},{1,0},{8,9},{10,11},{12,13},{14,15},{23,22},{21,20},{19,18},{17,16},{24,25},{26,27},{28,29},{30,31}};
