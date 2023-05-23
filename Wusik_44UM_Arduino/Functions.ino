/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
inline void setVarBit(__uint24& variable, byte thebit, bool thevalue)
{
  if (thevalue) bitSet(variable, thebit); else bitClear(variable, thebit);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
inline bool getVarBit(__uint24& variable, byte thebit)
{
  return bitRead(variable, thebit) == 1;
}
