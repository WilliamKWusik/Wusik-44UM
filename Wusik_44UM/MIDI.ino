/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void midiSendNote(byte button, bool isNoteOn)
{
  if (!isNoteOn)
  {
    /*midiEvent.header = 0x8;
    midiEvent.byte1 = 0x80;
    midiEvent.byte2 = buttonsStruct[currentPage][button].value1;
    midiEvent.byte3 = 0;*/
    MIDI.sendNoteOff(buttonsStruct[currentPage][button].value1, 0, 1);
  }
  else
  {
    /*midiEvent.header = 0x9;
    midiEvent.byte1 = 0x90;
    midiEvent.byte2 = buttonsStruct[currentPage][button].value1;
    midiEvent.byte3 = buttonsStruct[currentPage][button].value2;*/
    MIDI.sendNoteOn(buttonsStruct[currentPage][button].value1, buttonsStruct[currentPage][button].value2, 1);
  }
  //
  //MidiUSB.sendMIDI(midiEvent);
  flushMIDI = true;
}
//
//  midiEventPacket_t controller = {0xB, 0xB0, getMIDICCValue(button), controllValue};
