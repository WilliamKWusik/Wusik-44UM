/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#if FACTORY_RESET
  void factoryReset()
  {
    // Setup buttons by pressing them in order //
    //
    flashRed(2);
    //
    for (byte xx = 0; xx < 18; xx++)
    {
      clearPixels();
      //
      if (xx == 0) colorBarWhite(8);
      else if (xx == 1) colorBarWhite(0);
      else colorPixelWhite(xx - 2);
      //
      while (1)
      {
        #define W2CHECKBUTTON(pin) if (digitalRead(pin) == LOW) { delay(20); if (digitalRead(pin) == LOW) { \
          clearPixels();\
          flashRed(1);\
          while (digitalRead(pin) == LOW) { ; }\
          buttonsList[pin] = xx;\
          break;\
          } }
        //
        W2CHECKBUTTON(0)
        W2CHECKBUTTON(1)
        W2CHECKBUTTON(2)
        W2CHECKBUTTON(3)
        W2CHECKBUTTON(4)
        W2CHECKBUTTON(5)
        W2CHECKBUTTON(6)
        W2CHECKBUTTON(7)
        W2CHECKBUTTON(8)
        W2CHECKBUTTON(9)
        W2CHECKBUTTON(10)
        W2CHECKBUTTON(14)
        W2CHECKBUTTON(15)
        W2CHECKBUTTON(16)
        W2CHECKBUTTON(18)
        W2CHECKBUTTON(19)
        W2CHECKBUTTON(20)
        W2CHECKBUTTON(21)        
      }
    }
    //
    flashRed(2);
    //
    for (byte xx = 0; xx < MAX_PAGES; xx++)
    {
      buttonsStruct[xx][0].type = kActionOnRelease;
      buttonsStruct[xx][0].value1 = kPreviousPage;
      buttonsStruct[xx][0].colorOn = kRightBars_White;
      buttonsStruct[xx][0].colorOff = kRightBars_Off;
      //
      buttonsStruct[xx][1].type = kActionOnRelease;
      buttonsStruct[xx][1].value1 = kNextPage;
      buttonsStruct[xx][1].colorOn = kLeftBars_White;
      buttonsStruct[xx][1].colorOff = kLeftBars_Off;
      //
      for (byte yy = 0; yy < 16; yy++)
      {
        #if DEFAULT_EEPROM_NOTES_ONOFF
          buttonsStruct[xx][yy + 2].type = kNoteOnOff;
          buttonsStruct[xx][yy + 2].value1 = 36 + (xx * DEFAULT_NOTES_OFFSET_PER_PAGE) + yy;
          buttonsStruct[xx][yy + 2].value2 = 127;
        #else
          buttonsStruct[xx][yy + 2].type = kMIDI_CC;
          buttonsStruct[xx][yy + 2].value1 = 1 + (xx * 16) + yy;
        #endif
        //
        if (xx == 1) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
        else if (xx == 2) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kGreen_Soft;
        else if (xx == 3) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kBlue_Soft;
        else if (xx == 4 && (yy == 0 || yy == 3 || yy == 15 || yy == 12)) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
      }
    }    
    //
    saveEEPROM();
    delay(100);
    flashRed(6);
  }
#endif
