/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void recieveSysEx(byte byte2, byte byte3)
{
  if (byte2 == 0xF7 || byte3 == 0xF7) return; // End Of SysEx //
  //
  if (byte2 == 0x78) // 'w' //
  {
    if (byte3 == 0x68) // 'k' //
    {
      byte ssbuffer[MAX_SYSEX_BUFFER];
      byte sspos = 0;
      bool fullbuffer = false;
      //
      while (1)
      {
        midiRX = MidiUSB.read();
        if (midiRX.header != 0)
        {
          if (midiRX.byte1 == 0xF7) break;
          else ssbuffer[sspos++] = midiRX.byte1;
          //
          if (midiRX.byte2 == 0xF7) break;
          else ssbuffer[sspos++] = midiRX.byte1;
          //
          if (midiRX.byte3 == 0xF7) break;
          else ssbuffer[sspos++] = midiRX.byte1;
          //
          if (sspos >= MAX_SYSEX_BUFFER)
          {
            sspos = 0;
            fullbuffer = true;
          }
        }
      }
      //
      if (sspos > 0 && !fullbuffer && ssbuffer[0] == machineID)
      {
        if (ssbuffer[1] == 0) // RGB LED //
        {
          byte ssp = 2;
          colorPixel(ssbuffer[ssp++], strip.Color(
                    (ssbuffer[ssp++] << 4) | ssbuffer[ssp++], // Get 1 byte from 2 4bit values //
                    (ssbuffer[ssp++] << 4) | ssbuffer[ssp++],
                    (ssbuffer[ssp++] << 4) | ssbuffer[ssp++]));
        }
        else if (ssbuffer[1] == 1) // Button Config //
        {
          byte ssp = 4;
          byte page = ssbuffer[2];
          byte button = ssbuffer[3];
          //
          buttonsStruct[page][button].type = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
          buttonsStruct[page][button].colorOn = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
          buttonsStruct[page][button].colorOff = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
          buttonsStruct[page][button].value1 = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
          buttonsStruct[page][button].value2 = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
          buttonsStruct[page][button].valueChar = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
          buttonsStruct[page][button].channel = (ssbuffer[ssp++] << 4) | ssbuffer[ssp++];
        }
        else if (ssbuffer[1] == 2) // Extra Actions //
        {
          if (ssbuffer[2] == 0) // Change Page //
          {
            currentPage = ssbuffer[3]; 
            if (!turnOffButtonLEDs) updateButtonsOffColor();
          }
          else if (ssbuffer[2] == 1) // Save Configuration //
          {
            saveEEPROM();
            delay(200);
            flashRed(2);
          }
        }
      }
    }
  }
  else // Other SysEx - Ignore //
  {
    while (1)
    {
      midiRX = MidiUSB.read();
      if (midiRX.header != 0)
      {
        if (midiRX.byte1 == 0xF7 || midiRX.byte2 == 0xF7 || midiRX.byte3 == 0xF7) break;
      }
    }
  }
}
