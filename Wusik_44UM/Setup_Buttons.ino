/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void setupButtons(bool readFromEEPROM)
{
  #if !ENABLE_BUTTON_CONFIG_STARTUP
    EEPROM.get(0, buttonsList);
  #else
    if (readFromEEPROM)
    {
      EEPROM.get(0, buttonsList);
    }
    else
    {
      // Setup buttons by pressing them in order //
      //
      flashRed(6);
      while (digitalRead(holdButtonStartup) == LOW) { ; }
      //
      for (byte xx = 0; xx < 18; xx++)
      {
        clearPixels();
        //
        if (xx == 0) colorBarWhite(8);
        else if (xx == 1) colorBarWhite(0);
        else colorPixelWhite(xx - 2);
        //
        while (1)
        {
          #define W2CHECKBUTTON(pin) if (digitalRead(pin) == LOW) { delay(20); if (digitalRead(pin) == LOW) { \
            clearPixels();\
            flashRed(1);\
            while (digitalRead(pin) == LOW) { ; }\
            buttonsList[pin] = xx;\
            break;\
            } }
          //
          W2CHECKBUTTON(0)
          W2CHECKBUTTON(1)
          W2CHECKBUTTON(2)
          W2CHECKBUTTON(3)
          W2CHECKBUTTON(4)
          W2CHECKBUTTON(5)
          W2CHECKBUTTON(6)
          W2CHECKBUTTON(7)
          W2CHECKBUTTON(8)
          W2CHECKBUTTON(9)
          W2CHECKBUTTON(10)
          W2CHECKBUTTON(14)
          W2CHECKBUTTON(15)
          W2CHECKBUTTON(16)
          W2CHECKBUTTON(18)
          W2CHECKBUTTON(19)
          W2CHECKBUTTON(20)
          W2CHECKBUTTON(21)        
        }
      }
      //
      EEPROM.put(0, buttonsList);
      flashRed(3);
    }
  #endif
}
