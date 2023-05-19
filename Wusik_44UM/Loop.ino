/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void loop() 
{
  bool hasButtonDown = false;
  //
  #define WCHECKBUTTON(pin)\
    if (digitalRead(pin) == LOW && buttonsStatus[buttonsList[pin]] < 250)\
    { buttonsStatus[buttonsList[pin]]++; if (buttonsStatus[buttonsList[pin]] > 10) hasButtonDown = true; }\
    else if (buttonsStatus[buttonsList[pin]] > 0) buttonsStatus[buttonsList[pin]]--
  //
  WCHECKBUTTON(0);
  WCHECKBUTTON(1);
  WCHECKBUTTON(2);
  WCHECKBUTTON(3);
  WCHECKBUTTON(4);
  WCHECKBUTTON(5);
  WCHECKBUTTON(6);
  WCHECKBUTTON(7);
  WCHECKBUTTON(8);
  WCHECKBUTTON(9);
  WCHECKBUTTON(10);
  WCHECKBUTTON(14);
  WCHECKBUTTON(15);
  WCHECKBUTTON(16);
  WCHECKBUTTON(18);
  WCHECKBUTTON(19);
  WCHECKBUTTON(20);
  WCHECKBUTTON(21);
  //
  if (hasButtonDown)
  {
    Serial1.println("Button Down!");
  }
}
