/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#define RGBLEDS_PIN 30
#define RGBLEDS_COUNT 48
#define ENABLE_BUTTON_CONFIG_STARTUP 0
#define INTRO_ANIMATION 0
#define MAX_BUTTON_PIN 21
#define SET_DEFAULT_EEPROM 1
#define DEFAULT_EEPROM_NOTES_ONOFF 1
#define MAX_PAGES 4
#define DEFAULT_NOTES_OFFSET_PER_PAGE 12
//
// ------------------------------------------------------------------------------------------------------------------------------------
enum
{
  kOff = 0, kWhite, kRed, kGreen, kBlue, kRed_Soft, kGreen_Soft, kBlue_Soft,
  kNothing = 0, kNoteOnOff, kMIDI_CC, kPitchBend, AfterTouch, kActionOnRelease, kMIDI_CC_Value_Up, kMIDI_CC_Value_Down,
  kNextPage = 0, kPreviousPage, kPanic
};
