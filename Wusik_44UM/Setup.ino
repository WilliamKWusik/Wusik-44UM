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
  // Initialize RGB LEDs //
  //
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  //
  #if ENABLE_BUTTON_CONFIG_STARTUP
    // Check if any button is held during initialization. If so, configure buttons ordering. Otherwise, read from EEPROM.
    //
    bool readFromEEPROM = true;
    #define WINITCHECKBUTTON(pin) if (digitalRead(pin) == LOW) { delay(5); if (digitalRead(pin) == LOW) { readFromEEPROM = false; holdButtonStartup = pin; } }
    //
    WINITCHECKBUTTON(0)
    WINITCHECKBUTTON(1)
    WINITCHECKBUTTON(2)
    WINITCHECKBUTTON(3)
    WINITCHECKBUTTON(4)
    WINITCHECKBUTTON(5)
    WINITCHECKBUTTON(6)
    WINITCHECKBUTTON(7)
    WINITCHECKBUTTON(8)
    WINITCHECKBUTTON(9)
    WINITCHECKBUTTON(10)
    WINITCHECKBUTTON(14)
    WINITCHECKBUTTON(15)
    WINITCHECKBUTTON(16)
    WINITCHECKBUTTON(18)
    WINITCHECKBUTTON(19)
    WINITCHECKBUTTON(20)
    WINITCHECKBUTTON(21)
    //
    setupButtons(readFromEEPROM);
  #else 
    setupButtons(true);
  #endif
  //
  memset(buttonsCounter, 0, sizeof(buttonsCounter));
  //
  #if SET_DEFAULT_EEPROM
    for (byte xx = 0; xx < MAX_PAGES; xx++)
    {
      buttonsStruct[xx][0].type = kActionOnRelease;
      buttonsStruct[xx][0].value1 = kPreviousPage;
      //
      buttonsStruct[xx][1].type = kActionOnRelease;
      buttonsStruct[xx][1].value1 = kNextPage;
      //
      for (byte yy = 0; yy < 16; yy++)
      {
        #if DEFAULT_EEPROM_NOTES_ONOFF
          buttonsStruct[xx][yy + 2].type = kNoteOnOff;
          buttonsStruct[xx][yy + 2].value1 = 36 + (xx * DEFAULT_NOTES_OFFSET_PER_PAGE) + yy;
        #else
          buttonsStruct[xx][yy + 2].type = kMIDI_CC;
          buttonsStruct[xx][yy + 2].value1 = 1 + (xx * 16) + yy;
        #endif
        //
        if (xx == 1) buttonsStruct[xx][yy + 2].colorOff[0] = buttonsStruct[xx][yy + 2].colorOff[1] = kRed_Soft;
        else if (xx == 2) buttonsStruct[xx][yy + 2].colorOff[0] = buttonsStruct[xx][yy + 2].colorOff[1] = kGreen_Soft;
        else if (xx == 3) buttonsStruct[xx][yy + 2].colorOff[0] = buttonsStruct[xx][yy + 2].colorOff[1] = kBlue_Soft;
      }
    }
  #endif
  //
  clearPixels();
  //
  #if INTRO_ANIMATION
    pixelsIntroAnimation();
  #endif
  //
  updateButtonsOffColor();
}
