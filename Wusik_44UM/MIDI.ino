/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void midiReceive()
{
  if (midiRX.header == 0x9) // Note On //
  {
    if (midiRX.byte2 == 34) { turnOffButtonLEDs = false; updateButtonsOffColor(); }
    else if (midiRX.byte2 == 35) { if (turnOffButtonLEDs) clearPixels(); else updateButtonsOffColor(); }
    else if (midiRX.byte2 == 36) colorPixels(strip.Color(255,   255,   255));
    else if (midiRX.byte2 == 37) colorPixels(strip.Color(255,   0,   0));
    else if (midiRX.byte2 == 38) colorPixels(strip.Color(0,   255,   0));
    else if (midiRX.byte2 == 39) colorPixels(strip.Color(0,   0,   255));
    else if (midiRX.byte2 == 40) { currentPage = 0; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 41) { currentPage = 1; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 42) { currentPage = 2; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 43) { currentPage = 3; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 44) { currentPage = 4; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 45) { currentPage = 5; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 46) { currentPage = 6; if (!turnOffButtonLEDs) updateButtonsOffColor(); }
    else if (midiRX.byte2 == 47) { flashRed(1); turnOffButtonLEDs = true; }
    else if (midiRX.byte2 >= 48 && midiRX.byte2 <= (48 + 15))
    {
      colorPixelWhite(midiRX.byte2 - 48);
    }
    else if (midiRX.byte2 >= (48 + 16) && midiRX.byte2 <= (48 + 15 + 16))
    {
      colorPixel(midiRX.byte2 - 48 - 16, strip.Color(255,   0,   0));
    }
    else if (midiRX.byte2 >= (48 + 32) && midiRX.byte2 <= (48 + 15 + 32))
    {
      colorPixel(midiRX.byte2 - 48 - 32, strip.Color(0,   255,   0));
    }
    else if (midiRX.byte2 >= (48 + 48) && midiRX.byte2 <= (48 + 15 + 48))
    {
      colorPixel(midiRX.byte2 - 48 - 48, strip.Color(0,   0,   255));
    }
  }
  else if (midiRX.header == 0x8) // Note Off //
  {
    if (midiRX.byte2 >= 48 && midiRX.byte2 <= (48 + 15)) colorPixelClear(midiRX.byte2 - 48);
    if (midiRX.byte2 >= (48 + 16) && midiRX.byte2 <= (48 + 15 + 16)) colorPixelClear(midiRX.byte2 - 48 - 16);
    if (midiRX.byte2 >= (48 + 32) && midiRX.byte2 <= (48 + 15 + 32)) colorPixelClear(midiRX.byte2 - 48 - 32);
    if (midiRX.byte2 >= (48 + 48) && midiRX.byte2 <= (48 + 15 + 48)) colorPixelClear(midiRX.byte2 - 48 - 48);
  }
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void midiSendNote(byte button, bool isNoteOn)
{
  if (!isNoteOn)
  {
    data[0] = 0x8;
    data[1] = 0x80;
    data[2] = buttonsStruct[currentPage][button].value1;
    data[3] = 0;
    MidiUSB.write(data, 4);
  }
  else
  {
    data[0] = 0x9;
    data[1] = 0x90;
    data[2] = buttonsStruct[currentPage][button].value1;
    data[3] = buttonsStruct[currentPage][button].value2;
    MidiUSB.write(data, 4);
  }
  //
  flushMIDI = true;
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void midiSendCC(byte button, byte value)
{
  data[0] = 0xB;
  data[1] = 0xB0;
  data[2] = buttonsStruct[currentPage][button].value1;
  data[3] = value;
  MidiUSB.write(data, 4);
  flushMIDI = true;
}
