/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
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
