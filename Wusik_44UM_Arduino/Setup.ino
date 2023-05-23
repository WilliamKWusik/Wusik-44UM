/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  #define WSETPIN(pin) pinMode(pin, INPUT); digitalWrite(pin, HIGH) // Pullup Resistor //
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
  memset(buttonsCounter, 0, sizeof(buttonsCounter));
  memset(customColors, 0, sizeof(customColors));
  memset(rgbBlinkColor, 0, sizeof(rgbBlinkColor));
  memset(specialFullColorMidiNote, 0, sizeof(specialFullColorMidiNote));
  //
  // Initialize RGB LEDs //
  //
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  //
  #if FACTORY_RESET
    factoryReset(); // Clear EEPROM and reset everything - Wait for buttons to be pressed in order //
  #endif
  //
  clearPixels();
  readEEPROM();
  //
  #if INTRO_ANIMATION
    pixelsIntroAnimation();
  #endif
  //
  // Reset ValueChar to 0 As Its Used By Things Like NoteOnOff Latch and MIDICC Flip //
  //
  for (byte xx = 0; xx < 18; xx++)
  {
    for (byte yy = 0; yy < MAX_PAGES; yy++)
    {
      buttonsStruct[yy][xx].valueChar = 0;
    }
  } 
  //
  updateButtonsOffColor();
}
