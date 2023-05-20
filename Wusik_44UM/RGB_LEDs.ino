/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void updateButtonsOffColor()
{
  strip.clear();
  //
  for (byte xx = 0; xx < 16; xx++)
  {
    strip.setPixelColor(rgbLEDsList[xx][0], getColor(buttonsStruct[currentPage][xx + 2].colorOff));
    strip.setPixelColor(rgbLEDsList[xx][1], getColor(buttonsStruct[currentPage][xx + 2].colorOff));
  }
  //
  checkButtonBar(buttonsStruct[currentPage][0].colorOff);
  checkButtonBar(buttonsStruct[currentPage][1].colorOff);
  //
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
uint32_t getColor(byte colorID)
{
  uint32_t returnColor = 0;
  //
  switch(colorID)
  {
    case kOff:        returnColor = strip.Color(  0,     0,     0); break;
    case kWhite:      returnColor = strip.Color(255,   255,   255); break;
    case kRed:        returnColor = strip.Color(255,     0,     0); break;
    case kGreen:      returnColor = strip.Color(  0,   255,     0); break;
    case kBlue:       returnColor = strip.Color(  0,     0,   255); break;
    case kRed_Soft:   returnColor = strip.Color( 25,     0,     0); break;
    case kGreen_Soft: returnColor = strip.Color(  0,    25,     0); break;
    case kBlue_Soft:  returnColor = strip.Color(  0,     0,    25); break;
  }
  //
  return returnColor;
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorPixels(uint32_t color)
{
  for(int i=0; i<strip.numPixels(); i++) 
  {
    strip.setPixelColor(i, color);
  }
  //
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void clearPixels()
{
  strip.clear();
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorPixelWhite(byte pixel)
{
  strip.setPixelColor(rgbLEDsList[pixel][0], strip.Color(255,   255,   255));
  strip.setPixelColor(rgbLEDsList[pixel][1], strip.Color(255,   255,   255));
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorPixelClear(byte pixel)
{
  strip.setPixelColor(rgbLEDsList[pixel][0], strip.Color(0,   0,   0));
  strip.setPixelColor(rgbLEDsList[pixel][1], strip.Color(0,   0,   0));
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorPixel(byte pixel, uint32_t color)
{
  strip.setPixelColor(rgbLEDsList[pixel][0], color);
  strip.setPixelColor(rgbLEDsList[pixel][1], color);
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorPixelNoShow(byte pixel, uint32_t color)
{
  strip.setPixelColor(rgbLEDsList[pixel][0], color);
  strip.setPixelColor(rgbLEDsList[pixel][1], color);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void flashRed(byte times)
{
  for (byte xx = 0; xx < times; xx++)
  {
    colorPixels(strip.Color(255,   0,   0)); // Red
    delay(50);
    colorPixels(strip.Color(255,   255,   255)); // White
    delay(50);
    colorPixels(strip.Color(0,   0,   0)); // Off
    delay(50);
  }
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorBarWhite(byte offset)
{
  for (byte bb = 0; bb < 8; bb++)
  {
    strip.setPixelColor(32 + bb + offset, strip.Color(255,   255,   255));
  }
  //
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void colorBarOff(byte offset)
{
  for (byte bb = 0; bb < 8; bb++)
  {
    strip.setPixelColor(32 + bb + offset, strip.Color(0,   0,   0));
  }
  //
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void checkButtonBar(byte type)
{
  switch (type)
  {
    case kLeftBars_White: colorBarWhite(0); break;
    case kRightBars_White: colorBarWhite(8); break;
    case kLeftBars_Off: colorBarOff(0); break;
    case kRightBars_Off: colorBarOff(8); break;
  } 
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
#if INTRO_ANIMATION
  void pixelsIntroAnimation()
  {
    for (byte xx = 0; xx < 16; xx++)
    {
      colorPixelWhite(rgbsIntroAnimation[xx]);
      delay(80);
    }
    //
    colorBarWhite(0);
    colorBarWhite(8);
    delay(400);
    //
    for (byte xx = 0; xx < 16; xx++)
    {
      colorPixelClear(rgbsIntroAnimation[xx]);
      delay(60);
    }   
    //
    clearPixels();
  }
#endif
