/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
void saveEEPROM()
{
  int address = 0;
  EEPROM.update(address++, CURRENT_DATA_VERSION);
  //
  for (byte xx = 0; xx < (MAX_BUTTON_PIN + 1); xx++)
  {
    EEPROM.update(address++, buttonsList[xx]);
  }
  //
  for (byte xx = 0; xx < MAX_CUSTOM_COLORS; xx++)
  {
    for (byte yy = 0; yy < 3; yy++)
    {
      EEPROM.update(address++, customColors[xx][yy]);
    }
  }
  //
  for (byte xx = 0; xx < MAX_PAGES; xx++)
  {
    for (byte yy = 0; yy < 18; yy++)
    {
      EEPROM.update(address++, buttonsStruct[xx][yy].type);
      EEPROM.update(address++, buttonsStruct[xx][yy].colorOn);
      EEPROM.update(address++, buttonsStruct[xx][yy].colorOff);
      EEPROM.update(address++, buttonsStruct[xx][yy].value1);
      EEPROM.update(address++, buttonsStruct[xx][yy].value2);
      EEPROM.update(address++, buttonsStruct[xx][yy].valueChar);
      EEPROM.update(address++, buttonsStruct[xx][yy].channel);
    }
  }
  //
  EEPROM.update(address++, buttonsHoldTop.type);
  EEPROM.update(address++, buttonsHoldTop.colorOn);
  EEPROM.update(address++, buttonsHoldTop.colorOff);
  EEPROM.update(address++, buttonsHoldTop.value1);
  EEPROM.update(address++, buttonsHoldTop.value2);
  EEPROM.update(address++, buttonsHoldTop.valueChar);
  EEPROM.update(address++, buttonsHoldTop.channel);
  //
  if (address >= 1024) flashRed(200);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void readEEPROM()
{
  int address = 0;
  byte version = EEPROM.read(address++);
  //
  for (byte xx = 0; xx < (MAX_BUTTON_PIN + 1); xx++)
  {
    buttonsList[xx] = EEPROM.read(address++);
  }
  //
  for (byte xx = 0; xx < MAX_CUSTOM_COLORS; xx++)
  {
    for (byte yy = 0; yy < 3; yy++)
    {
      customColors[xx][yy] = EEPROM.read(address++);
    }
  }
  //
  for (byte xx = 0; xx < MAX_PAGES; xx++)
  {
    for (byte yy = 0; yy < 18; yy++)
    {
      buttonsStruct[xx][yy].type = EEPROM.read(address++);
      buttonsStruct[xx][yy].colorOn = EEPROM.read(address++);
      buttonsStruct[xx][yy].colorOff = EEPROM.read(address++);
      buttonsStruct[xx][yy].value1 = EEPROM.read(address++);
      buttonsStruct[xx][yy].value2 = EEPROM.read(address++);
      buttonsStruct[xx][yy].valueChar = EEPROM.read(address++);
      buttonsStruct[xx][yy].channel = EEPROM.read(address++);
    }
  }
  //
  buttonsHoldTop.type = EEPROM.read(address++);
  buttonsHoldTop.colorOn = EEPROM.read(address++);
  buttonsHoldTop.colorOff = EEPROM.read(address++);
  buttonsHoldTop.value1 = EEPROM.read(address++);
  buttonsHoldTop.value2 = EEPROM.read(address++);
  buttonsHoldTop.valueChar = EEPROM.read(address++);
  buttonsHoldTop.channel = EEPROM.read(address++);
}
