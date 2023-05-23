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
    machineID = 0;
    flashRed(2);
    //
    for (byte xx = 0; xx < 18; xx++)
    {
      clearPixels();
      //
      if (xx == 0) { colorPixelWhite(0); colorPixelWhite(4); colorPixelWhite(8); colorPixelWhite(12); }
      else if (xx == 1) { colorPixelWhite(3); colorPixelWhite(7); colorPixelWhite(11); colorPixelWhite(15); }
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
    buttonsHoldTop.type = kActionOnRelease;
    buttonsHoldTop.value1 = kPanic;
    //
    for (byte xx = 0; xx < MAX_PAGES; xx++)
    {
      buttonsStruct[xx][0].type = kActionOnRelease;
      buttonsStruct[xx][0].value1 = kPreviousPage;
      buttonsStruct[xx][0].value2 = 0;
      buttonsStruct[xx][0].valueChar = 0;
      //
      buttonsStruct[xx][1].type = kActionOnRelease;
      buttonsStruct[xx][1].value1 = kNextPage;
      buttonsStruct[xx][1].value2 = 0;
      buttonsStruct[xx][1].valueChar = 0;
      //
      for (byte yy = 0; yy < 16; yy++)
      {
        buttonsStruct[xx][yy + 2].type = kMIDI_CC_Flip;
        buttonsStruct[xx][yy + 2].value1 = 1 + (xx * 16) + yy;      
        buttonsStruct[xx][yy + 2].value2 = 0;
        buttonsStruct[xx][yy + 2].valueChar = 0;
        //
        if (xx == 1) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
        else if (xx == 2) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kGreen_Soft;
        else if (xx == 3) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kBlue_Soft;
        else if (xx == 4 && (yy == 0 || yy == 3 || yy == 15 || yy == 12)) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
        else if (xx == 5 && (yy == 0 || yy == 3 || yy == 15 || yy == 12)) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kGreen_Soft;
        else if (xx == 6 && (yy == 0 || yy == 3 || yy == 15 || yy == 12)) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kBlue_Soft;
      }
    }    
    //
    saveEEPROM();
    delay(200);
    flashRed(6);
  }
#endif
