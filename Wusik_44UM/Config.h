/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#define CURRENT_DATA_VERSION 1
#define RGBLEDS_PIN 30
#define RGBLEDS_COUNT 48
#define INTRO_ANIMATION 0
#define INTRO_RANDOM 1
#define MAX_BUTTON_PIN 21
#define DEFAULT_EEPROM_NOTES_ONOFF 1
#define MAX_PAGES 5
#define DEFAULT_NOTES_OFFSET_PER_PAGE 12
#define FACTORY_RESET 0
#define MAX_CUSTOM_COLORS 24
#define HOLD_TOP_BUTTONS_SWAP_CONFIGURATION 1
#define BUTTON_DEBOUCE_COUNTER 60
//
// ------------------------------------------------------------------------------------------------------------------------------------
enum
{
  kOff = 0, kWhite, kRed, kGreen, kBlue, kRed_Soft, kGreen_Soft, kBlue_Soft, kLeftBars_White, kRightBars_White, kLeftBars_Off, kRightBars_Off, kCustom1,
  kNothing = 0, kNoteOnOff, kMIDI_CC, kPitchBend, AfterTouch, kActionOnRelease, kMIDI_CC_Value_Up, kMIDI_CC_Value_Down, kMIDI_CC_Flip,
  kNextPage = 0, kPreviousPage, kPanic
};
