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
    if (buttonsStruct[currentPage][xx + 2].colorOff[0] != kOff) strip.setPixelColor(rgbLEDsList[xx][0], getColor(buttonsStruct[currentPage][xx + 2].colorOff[0]));
    if (buttonsStruct[currentPage][xx + 2].colorOff[1] != kOff) strip.setPixelColor(rgbLEDsList[xx][1], getColor(buttonsStruct[currentPage][xx + 2].colorOff[1]));
  }
  //
  strip.show();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
uint32_t getColor(byte colorID)
{
  switch(colorID)
  {
    case kOff:        strip.Color(  0,     0,     0); break;
    case kWhite:      strip.Color(255,   255,   255); break;
    case kRed:        strip.Color(255,     0,     0); break;
    case kGreen:      strip.Color(  0,   255,     0); break;
    case kBlue:       strip.Color(  0,     0,   255); break;
    case kRed_Soft:   strip.Color( 55,     0,     0); break;
    case kGreen_Soft: strip.Color(  0,    55,     0); break;
    case kBlue_Soft:  strip.Color(  0,     0,    55); break;
  }
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
