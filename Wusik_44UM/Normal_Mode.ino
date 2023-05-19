/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void normalMode()
{
  if (buttonsDown > 0)
  {
    for (byte bb = 0; bb < 18; bb++)
    {
      if (bb >= 2 && getVarBit(buttonsDown, bb)) 
      {
        colorPixelWhite(bb - 2);
      }
    }
  }
  //
  if (buttonsReleased > 0)
  {
    for (byte bb = 0; bb < 18; bb++)
    {
      if (bb >= 2 && getVarBit(buttonsReleased, bb)) 
      {
        colorPixelClear(bb - 2);
      }
    }
  } 
}
