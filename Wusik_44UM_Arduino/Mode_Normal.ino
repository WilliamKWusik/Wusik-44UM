/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_ButtonDown(byte button)
{
  if (button >= 2 && !turnOffButtonLEDs)
  {
    if (buttonsStruct[currentPage][button].type == kNoteOnOffLatch)
    {
      if (buttonsStruct[currentPage][button].valueChar == 0)
      {
        strip.setPixelColor(rgbLEDsList[button - 2][0], getColor(buttonsStruct[currentPage][button].colorOn));
        strip.setPixelColor(rgbLEDsList[button - 2][1], getColor(buttonsStruct[currentPage][button].colorOn));   
      }
      else
      {
        strip.setPixelColor(rgbLEDsList[button - 2][0], getColor(buttonsStruct[currentPage][button].colorOff));
        strip.setPixelColor(rgbLEDsList[button - 2][1], getColor(buttonsStruct[currentPage][button].colorOff));        
      }
      //
      strip.show();
    }
    else
    {
      strip.setPixelColor(rgbLEDsList[button - 2][0], getColor(buttonsStruct[currentPage][button].colorOn));
      strip.setPixelColor(rgbLEDsList[button - 2][1], getColor(buttonsStruct[currentPage][button].colorOn));   
      strip.show();
    }
  }
  //
  switch(buttonsStruct[currentPage][button].type)
  {
    case kNoteOnOff: midiSendNote(buttonsStruct[currentPage][button].value1, buttonsStruct[currentPage][button].value2, true); break;
    case kMIDI_CC: midiSendCC(button, 127); break;
    case kActionOnHold: normalMode_Action(buttonsStruct[currentPage][button].value1, button); break;
    case kAudioLoop: midiSendAudioLoop(button, true);
    //
    case kNoteOnOffLatch: 
      if (buttonsStruct[currentPage][button].valueChar == 0) 
      {
        buttonsStruct[currentPage][button].valueChar = 1; 
        midiSendNote(buttonsStruct[currentPage][button].value1, buttonsStruct[currentPage][button].value2, true);
      }
      else
      {
        buttonsStruct[currentPage][button].valueChar = 0;
        midiSendNote(buttonsStruct[currentPage][button].value1, buttonsStruct[currentPage][button].value2, false);
      }
      break;
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
  if (button >= 2 && !turnOffButtonLEDs && buttonsStruct[currentPage][button].type != kNoteOnOffLatch)
  {
    strip.setPixelColor(rgbLEDsList[button - 2][0], getColor(buttonsStruct[currentPage][button].colorOff));
    strip.setPixelColor(rgbLEDsList[button - 2][1], getColor(buttonsStruct[currentPage][button].colorOff)); 
    strip.show();
  }
  //
  if (buttonsStruct[currentPage][button].type == kAudioLoop) midiSendAudioLoop(button, false);
  else normalMode_ButtonReleaseType(buttonsStruct[currentPage][button].type, buttonsStruct[currentPage][button].value1, buttonsStruct[currentPage][button].value2, buttonsStruct[currentPage][button].valueChar);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_ButtonReleaseType(byte type, byte &value1, byte &value2, char &valueChar)
{
  switch(type)
  {
    case kActionOnRelease: normalMode_Action(value1, value2); break;
    case kNoteOnOff: midiSendNote(value1, value2, false); break;
    //
    case kActionOnHold: 
      if (value1 == kGoToPage)
      {
        currentPage = valueChar;
        updateButtonsOffColor();
      }
      break;
  }  
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_Action(byte action, byte value)
{
  switch(action)
  {
    case kNextPage: 
      if (remoteMode)
      {
        if (currentPage < 3) currentPage++; 
      }
      else
      {
        if (currentPage < (MAX_PAGES - 1)) currentPage++; 
      }
      break;
    case kPreviousPage: if (currentPage > 0) currentPage--; break;
    case kGoToPage: currentPage = value; break;
    //
    case kPanic:
      flashRed(1);
      //
      for (byte yy = 0; yy < MAX_PAGES; yy++)
      {
        for (byte xx = 0; xx < 18; xx++)
        {
          buttonsStruct[yy][xx].valueChar = 0;
        }
      }
      //
      for (byte xx = 0; xx < 127; xx++)
      {
        midiSendNote(xx, 0, false);
      }
      //
      flashRed(1);
      updateButtonsOffColor();
      break;
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
    if (getVarBit(buttonsHolding, 0) && getVarBit(buttonsHolding, 1))
    {
      if (bothTopButtonsHold < 252)
      {
        bothTopButtonsHold++;
        if (bothTopButtonsHold > 10) delay(20);
        //
        #if HOLD_TOP_BUTTONS_SWAP_CONFIGURATION
          if (bothTopButtonsHold == 252)
          {
            flashRed(6);
            colorPixelWhite(0);
            colorPixelWhite(1);
            colorPixelWhite(2);
            colorPixelWhite(3);
            colorPixelWhite(4);
            currentMode = 1;
          }
        #endif
        //
        if (bothTopButtonsHold == 30)
        {
          normalMode_ButtonReleaseType(buttonsHoldTop.type, buttonsHoldTop.value1, buttonsHoldTop.value2, buttonsHoldTop.valueChar);
        }      
      }
    }
    else if (bothTopButtonsHold > 0) bothTopButtonsHold--;  
  }
}
