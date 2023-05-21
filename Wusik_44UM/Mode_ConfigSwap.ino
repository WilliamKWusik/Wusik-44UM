/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#if HOLD_TOP_BUTTONS_SWAP_CONFIGURATION
  void swapConfigurationMode()
  {
    if (buttonsDown > 0)
    {
      for (byte bb = 0; bb < 18; bb++)
      {
        if (getVarBit(buttonsDown, bb))
        {     
          if (bb == 2 || bb == 3 || bb == 4 || bb == 5 || bb == 6)
          {
            buttonsHoldTop.type = kActionOnRelease;
            buttonsHoldTop.value1 = kPanic;
            //
            for (byte xx = 0; xx < MAX_PAGES; xx++)
            {
              if (bb == 5)
              {
                buttonsStruct[xx][0].type = kActionOnHold;
                buttonsStruct[xx][0].value1 = kGoToPage;
                buttonsStruct[xx][0].value2 = 1;
                buttonsStruct[xx][0].valueChar = 0;
                //
                buttonsStruct[xx][1].type = kActionOnHold;
                buttonsStruct[xx][1].value1 = kGoToPage;
                buttonsStruct[xx][1].value2 = 2;
                buttonsStruct[xx][1].valueChar = 0;
              }
              else
              {
                buttonsStruct[xx][0].type = kActionOnRelease;
                buttonsStruct[xx][0].value1 = kPreviousPage;
                //
                buttonsStruct[xx][1].type = kActionOnRelease;
                buttonsStruct[xx][1].value1 = kNextPage;
              }
              //
              for (byte yy = 0; yy < 16; yy++)
              {
                if (bb == 2)
                {
                  buttonsStruct[xx][yy + 2].type = kNoteOnOff;
                  buttonsStruct[xx][yy + 2].value1 = 36 + (xx * 12) + yy;
                  buttonsStruct[xx][yy + 2].value2 = 127;
                }
                else if (bb == 6)
                {
                  buttonsStruct[xx][yy + 2].type = kNoteOnOffLatch;
                  buttonsStruct[xx][yy + 2].value1 = 36 + (xx * 12) + yy;
                  buttonsStruct[xx][yy + 2].value2 = 127;
                }
                else if (bb == 3)
                {
                  buttonsStruct[xx][yy + 2].type = kMIDI_CC;
                  buttonsStruct[xx][yy + 2].value1 = 1 + (xx * 16) + yy;
                }
                else if (bb == 4 || bb == 5)
                {
                  buttonsStruct[xx][yy + 2].type = kMIDI_CC_Flip;
                  buttonsStruct[xx][yy + 2].value1 = 1 + (xx * 16) + yy;
                }
                //
                if (xx == 1) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
                else if (xx == 2) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kGreen_Soft;
                else if (xx == 3) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kBlue_Soft;
                else if (xx == 4 && (yy == 0 || yy == 3 || yy == 15 || yy == 12)) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
              }
            }    
            //
            saveEEPROM();            
            flashRed(2);
          }
          //
          currentMode = 0;
          updateButtonsOffColor();         
        }
      }
    }
  }
#endif
