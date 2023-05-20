/*
   Created by William Kalfelz @ Wusik.com (c) 2023
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
inline void checkButton(byte pin)
{
  if (digitalRead(pin) == LOW)
  {
    if (buttonsCounter[buttonsList[pin]] < 100) buttonsCounter[buttonsList[pin]]++;
    if (buttonsCounter[buttonsList[pin]] == 10) setVarBit(buttonsDown, buttonsList[pin], true);
  }
  else if (buttonsCounter[buttonsList[pin]] > 0)
  {
    buttonsCounter[buttonsList[pin]]--;
    if (buttonsCounter[buttonsList[pin]] == 9) setVarBit(buttonsReleased, buttonsList[pin], true);
  }
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void loop()
{
  checkButton(0);
  checkButton(1);
  checkButton(2);
  checkButton(3);
  checkButton(4);
  checkButton(5);
  checkButton(6);
  checkButton(7);
  checkButton(8);
  checkButton(9);
  checkButton(10);
  checkButton(14);
  checkButton(15);
  checkButton(16);
  checkButton(18);
  checkButton(19);
  checkButton(20);
  checkButton(21);
  //
  if (currentMode == 0) normalMode();
  //if (flushMIDI) { MidiUSB.flush(); flushMIDI = false; }
  //
  buttonsDown = buttonsReleased = 0;
}
