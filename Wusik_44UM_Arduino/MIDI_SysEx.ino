/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void recieveSysEx(byte byte2, byte byte3) 
{
  if (byte2 == 0xF7 || byte3 == 0xF7) return;  // End Of SysEx //
  //
  if (byte2 == 0xB)
  {
    if (byte3 == 0xC)
    {
      byte ssbuffer[MAX_SYSEX_BUFFER];
      byte sspos = 0;
      bool fullbuffer = false;
      //
      while (1) {
        midiRX = MidiUSB.read();
        if (midiRX.header != 0) {
          if (midiRX.byte1 == 0xF7) break;
          else ssbuffer[sspos++] = midiRX.byte1;
          //
          if (midiRX.byte2 == 0xF7) break;
          else ssbuffer[sspos++] = midiRX.byte2;
          //
          if (midiRX.byte3 == 0xF7) break;
          else ssbuffer[sspos++] = midiRX.byte3;
          //
          if (sspos >= MAX_SYSEX_BUFFER) {
            sspos = 0;
            fullbuffer = true;
          }
        }
      }
      //
      if (sspos > 0 && !fullbuffer && ssbuffer[0] == machineID) 
      {
        if (ssbuffer[1] == 0)  // RGB LED //
        {
          byte ssp = 2;
          colorPixel(ssbuffer[ssp++], strip.Color(
                                        (ssbuffer[ssp++] << 4) | ssbuffer[ssp++],  // Get 1 byte from 2 4bit values //
                                        (ssbuffer[ssp++] << 4) | ssbuffer[ssp++],
                                        (ssbuffer[ssp++] << 4) | ssbuffer[ssp++]));
        }
        else if (ssbuffer[1] == 1)  // Button Config //
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
        else if (ssbuffer[1] == 2)  // Change Page //
        {
          currentPage = ssbuffer[2];
          if (!turnOffButtonLEDs) updateButtonsOffColor();
        } 
        else if (ssbuffer[1] == 3)  // Save Configuration //
        {
          saveEEPROM();
          delay(200);
          flashRed(2);
        }
        else if (ssbuffer[1] == 4)  // Enter Remote Mode Using Wusik PR44 Application //
        {
          clearPixels();
          flashRed(1);
          //
          remoteMode = true;
          currentPage = 0;
          //
          buttonsHoldTop.type = kActionOnRelease;
          buttonsHoldTop.value1 = kPanic;
          //
          for (byte xx = 0; xx < 4; xx++)
          {
            buttonsStruct[xx][0].type = kNoteOnOff;
            buttonsStruct[xx][0].value1 = xx;
            buttonsStruct[xx][0].value2 = 127;
            //
            buttonsStruct[xx][1].type = kNoteOnOff;
            buttonsStruct[xx][1].value1 = 6 + xx;
            buttonsStruct[xx][1].value2 = 127;
            //
            for (byte yy = 0; yy < 16; yy++)
            {
              buttonsStruct[xx][yy + 2].type = kNoteOnOff;
              buttonsStruct[xx][yy + 2].value1 = 36 + (xx * 12) + yy;
              buttonsStruct[xx][yy + 2].value2 = 127;
              //
              if (xx == 1) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
              else if (xx == 2) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kGreen_Soft;
              else if (xx == 3) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kBlue_Soft;
              else if (xx == 4 && (yy == 0 || yy == 3 || yy == 15 || yy == 12)) buttonsStruct[xx][yy + 2].colorOff = buttonsStruct[xx][yy + 2].colorOff = kRed_Soft;
            }
          }
          //
          flashRed(1);
          //
          data[0] = 0xB;
          data[1] = 0xB0;
          data[2] = 11;
          data[3] = 100;
          MidiUSB.write(data, 4);
          flushMIDI = true;
        }
        else if (ssbuffer[1] == 5)  // FLASH RGB LED //
        {
          byte ssp = 2;
          colorPixels(strip.Color((ssbuffer[ssp++] << 4) | ssbuffer[ssp++],  // Get 1 byte from 2 4bit values //
                                  (ssbuffer[ssp++] << 4) | ssbuffer[ssp++],
                                  (ssbuffer[ssp++] << 4) | ssbuffer[ssp++]));
          updateFromFlash = 255;
        }
      }
    }
  } else  // Other SysEx - Ignore //
  {
    while (1) {
      midiRX = MidiUSB.read();
      if (midiRX.header != 0) {
        if (midiRX.byte1 == 0xF7 || midiRX.byte2 == 0xF7 || midiRX.byte3 == 0xF7) break;
      }
    }
  }
}
