/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void setup() 
{
  #define WSETPIN(pin) pinMode(pin, INPUT); digitalWrite(pin, HIGH) // Pullup Resistor //
  //
  WSETPIN(0);
  WSETPIN(1);
  WSETPIN(2);
  WSETPIN(3);
  WSETPIN(4);
  WSETPIN(5);
  WSETPIN(6);
  WSETPIN(7);
  WSETPIN(8);
  WSETPIN(9);
  WSETPIN(10);
  WSETPIN(14);
  WSETPIN(15);
  WSETPIN(16);
  WSETPIN(18);
  WSETPIN(19);
  WSETPIN(20);
  WSETPIN(21);
  //
  // Initialize RGB LEDs //
  //
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  //
  #if ENABLE_BUTTON_CONFIG_STARTUP
    // Check if any button is held during initialization. If so, configure buttons ordering. Otherwise, read from EEPROM.
    //
    bool readFromEEPROM = true;
    #define WINITCHECKBUTTON(pin) if (digitalRead(pin) == LOW) { delay(5); if (digitalRead(pin) == LOW) { readFromEEPROM = false; holdButtonStartup = pin; } }
    //
    WINITCHECKBUTTON(0)
    WINITCHECKBUTTON(1)
    WINITCHECKBUTTON(2)
    WINITCHECKBUTTON(3)
    WINITCHECKBUTTON(4)
    WINITCHECKBUTTON(5)
    WINITCHECKBUTTON(6)
    WINITCHECKBUTTON(7)
    WINITCHECKBUTTON(8)
    WINITCHECKBUTTON(9)
    WINITCHECKBUTTON(10)
    WINITCHECKBUTTON(14)
    WINITCHECKBUTTON(15)
    WINITCHECKBUTTON(16)
    WINITCHECKBUTTON(18)
    WINITCHECKBUTTON(19)
    WINITCHECKBUTTON(20)
    WINITCHECKBUTTON(21)
    //
    setupButtons(readFromEEPROM);
  #else 
    setupButtons(true);
  #endif
  //
  #if SERIAL1_DEBUG
    // Initialize Serial1 (computer side) for debugin messages //
    //
    Serial1.begin(9600);
    Serial1.println("Startup!");
  #endif
  //
  memset(buttonsStatus, 0, sizeof(buttonsStatus));
  //
  clearPixels();
  //
  #if INTRO_ANIMATION
    pixelsIntroAnimation();
  #endif
}
