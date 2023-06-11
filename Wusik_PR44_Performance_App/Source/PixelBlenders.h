#ifndef __JUCE_PIXELBLENDERS_JUCEHEADER__
#define __JUCE_PIXELBLENDERS_JUCEHEADER__

/*
  All color components listed below refer to color component information pre-multiplied by the corresponding alpha value.  
  The following identifiers have the attached meaning in the equations below:

  Sc  - The source element color value.
  Sa  - The source element alpha value.
  Dc  - The canvas color value prior to compositing.
  Da  - The canvas alpha value prior to compositing.
  Dc' - The canvas color value post compositing.
  Da' - The canvas alpha value post compositing.

  see http://www.w3.org/TR/2002/WD-SVG11-20020215/masking.html
*/ 

//=======================================================
struct JUCE_API DefaultPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    dst.blend(src);
  }
};

//=======================================================
//Porter-Duff Compositing operators
/**
  Both the color and the alpha of the destination are cleared. Neither the source nor the destination are used as input.

  Dc' = 0
  Da' = 0
*/
struct JUCE_API ClearPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    dst.setARGB(0, 0, 0, 0);
  }
};

/**
  The source is copied to the destination. The destination is not used as input.

  Dc' = Sc
  Da' = Sa
*/
struct JUCE_API SrcPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    dst.set(src);
  }
};

/**
  The destination is left untouched.

  Dc' = Dc
  Da' = Da
*/
struct JUCE_API DstPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    // nothing to do
  }
};

/**
  The source is composited over the destination.

  Dc' = Sc + Dc·(1 - Sa)
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API SrcOverPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();
    const uint32 s1a = 0x000000ff - sa;

    const uint8 r = 0x000000ff & (sr + ((dr*s1a+0xff)>>8));
    const uint8 g = 0x000000ff & (sg + ((dg*s1a+0xff)>>8));
    const uint8 b = 0x000000ff & (sb + ((db*s1a+0xff)>>8));
    const uint8 a = (sa + da - ((sa*da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  The destination is composited over the source and the result replaces the destination.

  Dc' = Sc·(1 - Da) + Dc
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API DstOverPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();
    const uint32 d1a = 0x000000ff - da;

    const uint8 r = ((sr*d1a+0xff)>>8) + dr;
    const uint8 g = ((sg*d1a+0xff)>>8) + dg;
    const uint8 b = ((sb*d1a+0xff)>>8) + db;
    const uint8 a = (sa + da - ((sa*da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the source lying inside of the destination replaces the destination.

  Dc' = Sc·Da
  Da' = Sa·Da
*/
struct JUCE_API SrcInPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();

    const uint8 r = ((sr*da+0xff)>>8);
    const uint8 g = ((sg*da+0xff)>>8);
    const uint8 b = ((sb*da+0xff)>>8);
    const uint8 a = ((sa*da+0xff)>>8);

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the destination lying inside of the source replaces the destination.

  Dc' = Dc·Sa
  Da' = Sa·Da
*/
struct JUCE_API DstInPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();

    const uint8 r = ((dr*sa+0xff)>>8);
    const uint8 g = ((dg*sa+0xff)>>8);
    const uint8 b = ((db*sa+0xff)>>8);
    const uint8 a = ((sa*da+0xff)>>8);

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the source lying outside of the destination replaces the destination.

  Dc' = Sc·(1 - Da)
  Da' = Sa - Sa·Da
*/
struct JUCE_API SrcOutPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();
    const uint32 d1a = 0x000000ff - da;

    const uint8 r = (sr*d1a+0xff)>>8;
    const uint8 g = (sg*d1a+0xff)>>8;
    const uint8 b = (sb*d1a+0xff)>>8;
    const uint8 a = sa - ((sa*da)>>8);

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the destination lying outside of the source replaces the destination.

  // from AGG
  Dca' = Dca.(1 - Sa) 
  Da'  = Da.(1 - Sa) 
*/
struct JUCE_API DstOutPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();
    const uint32 s1a = 0x000000ff - sa;

    const uint8 r = (dr*s1a+0xff)>>8;
    const uint8 g = (dg*s1a+0xff)>>8;
    const uint8 b = (db*s1a+0xff)>>8;
    const uint8 a = (da*s1a+0xff)>>8;

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the source lying inside of the destination is composited onto the destination.

  Dc' = Sc·Da + Dc(1 - Sa)
  Da' = Da
*/
struct JUCE_API SrcAtopPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();
    const uint32 s1a = 0x000000ff - sa;

    const uint8 r = (sr*da + dr*s1a+0xff)>>8;
    const uint8 g = (sg*da + dg*s1a+0xff)>>8;
    const uint8 b = (sb*da + db*s1a+0xff)>>8;
    const uint8 a = da;

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the destination lying inside of the source is composited over the source and replaces the destination.

  Dc' = Sc·(1 - Da) + Dc·Sa
  Da' = Sa
*/
struct JUCE_API DstAtopPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa  = src.getAlpha();
    const uint32 sr  = src.getRed();
    const uint32 sg  = src.getGreen();
    const uint32 sb  = src.getBlue();
    const uint32 da  = dst.getAlpha();
    const uint32 dr  = dst.getRed();
    const uint32 dg  = dst.getGreen();
    const uint32 db  = dst.getBlue();
    const uint32 d1a = 0x000000ff - da;

    const uint8 r = (sr*d1a + dr*sa+0xff)>>8;
    const uint8 g = (sg*d1a + dg*sa+0xff)>>8;
    const uint8 b = (sb*d1a + db*sa+0xff)>>8;
    const uint8 a = sa;

    dst.setARGB(a, r, g, b);
  }
};

/**
  The part of the source that lies outside of the destination is combined with the part of the destination that lies outside of the source.

  Dc' = Sc·(1 - Da) + Dc·(1 - Sa)
  Da' = Sa + Da - 2·Sa·Da
*/
struct JUCE_API XorPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();
    const uint32 d1a  = 0x000000ff-da;
    const uint32 s1a  = 0x000000ff-sa;

    const uint8 r = 0x000000ff & ((sr*d1a + dr*s1a) >> 8);
    const uint8 g = 0x000000ff & ((sg*d1a + dg*s1a) >> 8);
    const uint8 b = 0x000000ff & ((sb*d1a + db*s1a) >> 8);
    const uint8 a = 0x000000ff & (sa + da - ((2*sa*da+0xff)>>8));

    dst.setARGB(a, r, g, b);
  }
};

//===========================================================
/*
  The following compositing operators add blending of source and destination colors 
  beyond the base 12 Porter-Duff operations. 
  The behaviour of these operators necessitates clamping of the output values after compositing
*/


/**
  The source is added to the destination and replaces the destination. 
  This operator is useful for animating a dissolve between two images.

  Dc' = Sc + Dc
  Da' = Sa + Da
*/
struct JUCE_API PlusPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();
    const uint32 clip = 0x000000ff;

    const uint8 r = std::min(clip,(sr+dr));
    const uint8 g = std::min(clip,(sg+dg));
    const uint8 b = std::min(clip,(sb+db));
    const uint8 a = std::min(clip,(sa+da));

    dst.setARGB(a, r, g, b);
  }
};

/**
  The source is substracted from the destination and replaces the destination. 
  This operator is useful for animating a dissolve between two images.

  Dca' = Dca - Sca
  Da' = 1 - (1 - Sa).(1 - Da)
*/
struct JUCE_API MinusPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const int32 sr   = src.getRed();
    const int32 sg   = src.getGreen();
    const int32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const int32 dr   = dst.getRed();
    const int32 dg   = dst.getGreen();
    const int32 db   = dst.getBlue();

    const uint8 r = std::max(0,(dr-sr));
    const uint8 g = std::max(0,(dg-sg));
    const uint8 b = std::max(0,(db-db));
    const uint8 a = (sa + da - ((sa*da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  The source is multiplied by the destination and replaces the destination. 
  The resultant color is always at least as dark as either of the two constituent colors. 
  Multiplying any color with black produces black. 
  Multiplying any color with white leaves the original color unchanged.

  Dc' = Sc·(1 - Da) + Dc·(1 - Sa) + Sc·Dc
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API MultiplyPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();
    const uint32 s1a  = 0xff - sa;
    const uint32 d1a  = 0xff - da;

    const uint8 r = 0x000000ff & ((sr * dr + sr * d1a + dr * s1a + 0xff) >> 8);
    const uint8 g = 0x000000ff & ((sg * dg + sg * d1a + dg * s1a + 0xff) >> 8);
    const uint8 b = 0x000000ff & ((sb * db + sb * d1a + db * s1a + 0xff) >> 8);
    const uint8 a = 0x000000ff & (sa + da - ((sa * da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  The source and destination are complemented and then multiplied and then replace the destination. 
  The resultant color is always at least as light as either of the two constituent colors. 
  Screening any color with white produces white. 
  Screening any color with black leaves the original color unchanged.

  Dc' = Sc + Dc - Sc·Dc
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API ScreenPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();
    const uint32 clip = 0x000000ff;

    const uint8 r = std::min(clip, (sr + dr - ((sr * dr + 0xff) >> 8)));
    const uint8 g = std::min(clip, (sg + dg - ((sg * dg + 0xff) >> 8)));
    const uint8 b = std::min(clip, (sb + db - ((sb * db + 0xff) >> 8)));
    const uint8 a = std::min(clip, (sa + da - ((sa * da + 0xff) >> 8)));

    dst.setARGB(a, r, g, b);
  }
};

/**
  Multiplies or screens the colors, dependent on the destination color. 
  Source colors overlay the destination whilst preserving its highlights and shadows. 
  The destination color is not replaced, but is mixed with the source color to reflect the lightness or darkness of the destination.
*/
struct JUCE_API OverlayPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();
    const uint32 clip = 0x000000ff;

    const uint32 d1a  = 0x000000ff - da;
    const uint32 s1a  = 0x000000ff - sa;
    const uint32 sada = sa*da;
    
    //from AGG
    const uint8 r = (((2*dr < da) ? 2*sr*dr + sr*d1a + dr*s1a : 
                                    sada - 2*(da - dr)*(sa - sr) + sr*d1a + dr*s1a + 0xff) >> 8);

    const uint8 g = (((2*dg < da) ? 2*sg*dg + sg*d1a + dg*s1a : 
                                    sada - 2*(da - dg)*(sa - sg) + sg*d1a + dg*s1a + 0xff) >> 8);

    const uint8 b = (((2*db < da) ? 2*sb*db + sb*d1a + db*s1a : 
                                    sada - 2*(da - db)*(sa - sb) + sb*d1a + db*s1a + 0xff) >> 8);

    const uint8 a = (sa + da - ((sa * da + 0xff) >> 8));
  
    dst.setARGB(a, r, g, b);
  }
};

/**
  Selects the darker of the destination and source colors. 
  The destination is replaced with the source when the source is darker, otherwise it is left unchanged.

  Dc' = Sc·(1 - Da) + Dc·(1 - Sa) + min(Sc, Dc)
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API DarkenPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();

    const uint32 d1a  = 0x000000ff - da;
    const uint32 s1a  = 0x000000ff - sa;

    const uint8 r = 0x000000ff & (((sr*d1a + dr*s1a+0xff)>>8) + std::min(sr,dr));
    const uint8 g = 0x000000ff & (((sg*d1a + dg*s1a+0xff)>>8) + std::min(sg,dg));
    const uint8 b = 0x000000ff & (((sb*d1a + db*s1a+0xff)>>8) + std::min(sb,db));
    const uint8 a = 0x000000ff & (sa + da - ((sa*da+0xff)>>8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  Selects the lighter of the destination and source colors. 
  The destination is replaced with the source when the source is lighter, otherwise it is left unchanged.

  Dc' = Sc·(1 - Da) + Dc·(1 - Sa) + max(Sc, Dc)
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API LightenPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();

    const uint32 d1a  = 0x000000ff - da;
    const uint32 s1a  = 0x000000ff - sa;

    const uint32 clip = 0x000000ff;

    const uint8 r = ((std::max(sr * da, dr * sa) + sr * d1a + dr * s1a + 0xff) >> 8);
    const uint8 g = ((std::max(sg * da, dg * sa) + sg * d1a + dg * s1a + 0xff) >> 8);
    const uint8 b = ((std::max(sb * da, db * sa) + sb * d1a + db * s1a + 0xff) >> 8);
    const uint8 a = (sa + da - ((sa * da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};


/**
  Brightens the destination color to reflect the source color. 
  Painting with black produces no change.

  Dc' = min(1, 256 / (256 - 255 · Dc)·Sc)
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API ColorDodgePixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();

    const uint32 d1a  = 0x000000ff - da;
    const uint32 s1a  = 0x000000ff - sa;

    const uint32 drsa = dr * sa;
    const uint32 dgsa = dg * sa;
    const uint32 dbsa = db * sa;
    const uint32 srda = sr * da;
    const uint32 sgda = sg * da;
    const uint32 sbda = sb * da;
    const uint32 sada = sa * da;

    const uint8 r = ((srda + drsa >= sada) ? (sada + sr * d1a + dr * s1a + 0xff) >> 8 :
                                              drsa / (0xff - (sr << 8) / sa) + ((sr * d1a + dr * s1a + 0xff) >> 8));

    const uint8 g = ((sgda + dgsa >= sada) ? (sada + sg * d1a + dg * s1a + 0xff) >> 8 :
                                              dgsa / (0xff - (sg << 8) / sa) + ((sg * d1a + dg * s1a + 0xff) >> 8));

    const uint8 b = ((sbda + dbsa >= sada) ? (sada + sb * d1a + db * s1a + 0xff) >> 8 :
                                              dbsa / (0xff - (sb << 8) / sa) + ((sb * d1a + db * s1a + 0xff) >> 8));

    const uint8 a = (sa + da - ((sa * da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  Darkens the destination color to reflect the source color. 
  Painting with white produces no change.

  if Sc + Dc is less than 1
  then Dc' = 0
  otherwise
  (
    if Sc is equal to 0
    then Dc' = 1
    otherwise Dc' = 1 - (1 - Dc) / Sc
  )

  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API ColorBurnPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();

    const uint32 d1a  = 0x000000ff - da;
    const uint32 s1a  = 0x000000ff - sa;

    const uint32 drsa = dr * sa;
    const uint32 dgsa = dg * sa;
    const uint32 dbsa = db * sa;
    const uint32 srda = sr * da;
    const uint32 sgda = sg * da;
    const uint32 sbda = sb * da;
    const uint32 sada = sa * da;

    const uint8 r = (((srda + drsa <= sada) ? sr * d1a + dr * s1a :
                                              sa * (srda + drsa - sada) / sr + sr * d1a + dr * s1a + 0xff) >> 8);

    const uint8 g = (((sgda + dgsa <= sada) ? sg * d1a + dg * s1a :
                                              sa * (sgda + dgsa - sada) / sg + sg * d1a + dg * s1a + 0xff) >> 8);

    const uint8 b = (((sbda + dbsa <= sada) ? sb * d1a + db * s1a :
                                              sa * (sbda + dbsa - sada) / sb + sb * d1a + db * s1a + 0xff) >> 8);

    const uint8 a = (sa + da - ((sa * da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};


/**
  Multiplies or screens the colors, dependent on the source color value. 
  If the source color is lighter than 0.5, the destination is lightened as if it were screened. 
  If the source color is darker than 0.5, the destination is darkened, as if it were multiplied. 
  The degree of lightening or darkening is proportional to the difference between the source colour and 0.5. 
  If it is equal to 0.5 the destination is unchanged. 
  Painting with pure black or white produces black or white.

  if Sc is less than 0.5
  then Dc' = 2·(Sc·(1 - Da) + Dc·(1 - Sa) + Sc·Dc)
  otherwise Dc' = 2·(Sc + Dc - Sc·Dc) - 1

  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API HardLightPixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();

    const uint32 d1a  = 0x000000ff - da;
    const uint32 s1a  = 0x000000ff - sa;
    const uint32 sada = sa * da;

    const uint8 r = (((2*sr < sa) ? 2*sr*dr + sr*d1a + dr*s1a : 
                                    sada - 2*(da - dr)*(sa - sr) + sr*d1a + dr*s1a + 0xff) >> 8);

    const uint8 g = (((2*sg < sa) ? 2*sg*dg + sg*d1a + dg*s1a : 
                                    sada - 2*(da - dg)*(sa - sg) + sg*d1a + dg*s1a + 0xff) >> 8);

    const uint8 b = (((2*sb < sa) ? 2*sb*db + sb*d1a + db*s1a : 
                                    sada - 2*(da - db)*(sa - sb) + sb*d1a + db*s1a + 0xff) >> 8);

    const uint8 a = (sa + da - ((sa * da + 0xff) >> 8));

    dst.setARGB(a, r, g, b);
  }
};

/**
  Subtracts the darker of the two constituent colors from the lighter. 
  Painting with white inverts the destination color. 
  Painting with black produces no change.

  Dc' = Sc + Dc - 2·min(Sc·Da, Dc·Sa)
  Da' = Sa + Da - Sa·Da
*/
struct JUCE_API DifferencePixelBlender
{
  template <class Pixel1, class Pixel2>
  static forcedinline void blend(Pixel1 &dst, const Pixel2& src)
  {
    const uint32 sa   = src.getAlpha();
    const uint32 sr   = src.getRed();
    const uint32 sg   = src.getGreen();
    const uint32 sb   = src.getBlue();
    const uint32 da   = dst.getAlpha();
    const uint32 dr   = dst.getRed();
    const uint32 dg   = dst.getGreen();
    const uint32 db   = dst.getBlue();

    const uint8 r = 0x000000ff & (sr + dr - 2*((std::min(sr*da, dr*sa)+0xff)>>8));
    const uint8 g = 0x000000ff & (sg + dg - 2*((std::min(sg*da, dg*sa)+0xff)>>8));
    const uint8 b = 0x000000ff & (sb + db - 2*((std::min(sb*da, db*sa)+0xff)>>8));
    const uint8 a = 0x000000ff & (sa + da - ((sa*da+0xff)>>8));

    dst.setARGB(a, r, g, b);
  }
};

// ---------------------------------------------------------------------------------------------------------------------------------------------------------
template<class PixelBlender>
inline void BlendPixel(PixelARGB &dst, const PixelARGB &src)
{
	PixelBlender::blend(dst, src);
}
//
// ---------------------------------------------------------------------------------------------------------------------------------------------------------
template<class PixelBlender>
static void BlendRow(PixelARGB *dst, const PixelARGB *src, int numPixels)
{
	while (--numPixels)
		BlendPixel<PixelBlender>(*dst++, *src++);
}
//
// ---------------------------------------------------------------------------------------------------------------------------------------------------------
template<class PixelBlender>
static void Blend(Image &dstImage, const Image& srcImage)
{
	Image::BitmapData dstBitmap(dstImage, Image::BitmapData::readWrite);
	Image::BitmapData srcBitmap(srcImage, Image::BitmapData::readOnly);
	//
	const int w = srcImage.getWidth();
	const int h = srcImage.getHeight();
	//
	for (int ll = 0; ll < h; ll++)
	{
		for (int rr = 0; rr < w; rr++)
		{
			const PixelARGB src = srcBitmap.getPixelColour(rr, ll).getPixelARGB();
			PixelARGB dst = dstBitmap.getPixelColour(rr, ll).getPixelARGB();
			//
			BlendPixel<PixelBlender>(dst, src);
			//
			dstBitmap.setPixelColour(rr, ll, Colour(dst));
		}
	}
}

#endif   // __JUCE_PIXELBLENDERS_JUCEHEADER__