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
  else
  {
    checkButtonBar(buttonsStruct[currentPage][button].colorOn);
  }
  //
  switch(buttonsStruct[currentPage][button].type)
  {
    case kNoteOnOff: midiSendNote(button, true); break;
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
  else
  {
    checkButtonBar(buttonsStruct[currentPage][button].colorOn);
  }
  //
  switch(buttonsStruct[currentPage][button].type)
  {
    case kActionOnRelease: normalMode_Action(buttonsStruct[currentPage][button].value1); break;
    case kNoteOnOff: midiSendNote(button, false); break;
  }
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode_Action(byte action)
{
  switch(action)
  {
    case kNextPage: if (currentPage < (MAX_PAGES - 1)) currentPage++; break;
    case kPreviousPage: if (currentPage > 0) currentPage--; break;
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
}
