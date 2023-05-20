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
          if (bb == 2 || bb == 3 || bb == 4)
          {
            for (byte xx = 0; xx < MAX_PAGES; xx++)
            {
              for (byte yy = 0; yy < 16; yy++)
              {
                if (bb == 2)
                {
                  buttonsStruct[xx][yy + 2].type = kNoteOnOff;
                  buttonsStruct[xx][yy + 2].value1 = 36 + (xx * DEFAULT_NOTES_OFFSET_PER_PAGE) + yy;
                  buttonsStruct[xx][yy + 2].value2 = 127;
                }
                else if (bb == 3)
                {
                  buttonsStruct[xx][yy + 2].type = kMIDI_CC;
                  buttonsStruct[xx][yy + 2].value1 = 1 + (xx * 16) + yy;
                }
                else
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
