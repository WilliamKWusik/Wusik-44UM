/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
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
