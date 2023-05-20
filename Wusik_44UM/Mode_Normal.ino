/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_ButtonDown(byte button)
{
  if (button >= 2)
  {
    strip.setPixelColor(rgbLEDsList[button - 2][0], getColor(buttonsStruct[currentPage][button].colorOn));
    strip.setPixelColor(rgbLEDsList[button - 2][1], getColor(buttonsStruct[currentPage][button].colorOn));   
    strip.show();
  }
  //
  switch(buttonsStruct[currentPage][button].type)
  {
    case kNoteOnOff: midiSendNote(button, true); break;
    case kMIDI_CC: midiSendCC(button, 127); break;
    case kActionOnHold: normalMode_Action(buttonsStruct[currentPage][button].value1, button); break;
    //
    case kMIDI_CC_Flip: 
      if (buttonsStruct[currentPage][button].valueChar > 0) 
      {
        midiSendCC(button, 10);
        buttonsStruct[currentPage][button].valueChar = -1;
      }
      else
      {
        midiSendCC(button, 120);
        buttonsStruct[currentPage][button].valueChar = 1;
      }
      break;
  }
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_ButtonRelease(byte button)
{
  if (button >= 2)
  {
    strip.setPixelColor(rgbLEDsList[button - 2][0], getColor(buttonsStruct[currentPage][button].colorOff));
    strip.setPixelColor(rgbLEDsList[button - 2][1], getColor(buttonsStruct[currentPage][button].colorOff)); 
    strip.show();
  }
  //
  switch(buttonsStruct[currentPage][button].type)
  {
    case kActionOnRelease: normalMode_Action(buttonsStruct[currentPage][button].value1, button); break;
    case kNoteOnOff: midiSendNote(button, false); break;
    //
    case kActionOnHold: 
      if (buttonsStruct[currentPage][button].value1 == kGoToPage)
      {
        currentPage = buttonsStruct[currentPage][button].valueChar;
        updateButtonsOffColor();
      }
      break;
  }
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_Action(byte action, byte button)
{
  switch(action)
  {
    case kNextPage: if (currentPage < (MAX_PAGES - 1)) currentPage++; break;
    case kPreviousPage: if (currentPage > 0) currentPage--; break;
    case kGoToPage: currentPage = buttonsStruct[currentPage][button].value2; break;
  }
  //
  updateButtonsOffColor();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode()
{
  if (buttonsDown > 0)
  {
    for (byte bb = 0; bb < 18; bb++)
    {
      if (getVarBit(buttonsDown, bb))
      {
        normalMode_ButtonDown(bb);
      }
    }
  }
  //
  if (buttonsReleased > 0)
  {
    for (byte bb = 0; bb < 18; bb++)
    {
      if (getVarBit(buttonsReleased, bb)) 
      {
        normalMode_ButtonRelease(bb);
      }
    }
  }
  //
  if (buttonsHolding > 0)
  {
    #if HOLD_TOP_BUTTONS_SWAP_CONFIGURATION
      if (getVarBit(buttonsHolding, 0) && getVarBit(buttonsHolding, 1))
      {
        if (bothTopButtonsHold < 250)
        {
          bothTopButtonsHold++;
          if (bothTopButtonsHold > 10) delay(20);
          //
          if (bothTopButtonsHold == 250)
          {
            flashRed(6);
            colorPixelWhite(0);
            colorPixelWhite(1);
            colorPixelWhite(2);
            colorPixelWhite(3);
            currentMode = 1;
          }
        }
      }
      else if (bothTopButtonsHold > 0) bothTopButtonsHold--;  
    #endif
  }
}
