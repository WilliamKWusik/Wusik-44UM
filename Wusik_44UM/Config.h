/*
 * Created by William Kalfelz @ Wusik.com (c) 2023
 */
//
// ------------------------------------------------------------------------------------------------------------------------------------
#define FACTORY_RESET 0 // When you set this, upon startup the unit will ask the buttons to be pressed in this order: small-top-left, small-top-right, large-top-right to large-top-left, continue on the next line left and so on //
//
#define CURRENT_DATA_VERSION 1
#define RGBLEDS_PIN 30
#define RGBLEDS_COUNT 32
#define INTRO_ANIMATION 1
#define INTRO_ANIMATION_SPEED 40
#define INTRO_ANIMATION_SPEED_HOLD 200
#define MAX_BUTTON_PIN 21
#define MAX_PAGES 7
#define MAX_CUSTOM_COLORS 16
#define HOLD_TOP_BUTTONS_SWAP_CONFIGURATION 1
#define BUTTON_DEBOUCE_COUNTER 60
#define RGB_BLINK_SLOW 1220
#define RGB_BLINK_FAST 720
//
// ------------------------------------------------------------------------------------------------------------------------------------
enum
{
  kOff = 0, kWhite, kRed, kGreen, kBlue, kRed_Soft, kGreen_Soft, kBlue_Soft, kCustom1,
  kNothing = 0, kNoteOnOff, kNoteOnOffLatch, kMIDI_CC, kActionOnRelease, kMIDI_CC_Flip, kActionOnHold,
  kNextPage = 0, kPreviousPage, kPanic, kGoToPage
};
