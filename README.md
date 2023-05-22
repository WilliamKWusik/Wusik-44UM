# Wusik 44UM
 4x4 USB MIDI Controller With RGB LEDs

USB MIDI Controller Using the Arduino Pro Micro (small Leonardo) ATMega32u4
Fully Programable with Windows, MAC and Linux direct support (no drivers needed). Just plug into the computer and use. By default it sends notes for each button.

Featuring:

- 32 x RGB LEDs (2 per button, on the left and right sides);
- 18 x Buttons (no matrix, so any combination of buttons can be detected);
- 3D Printed Case and Buttons. Unit size: 15 x 15 x 20 cm (rubber feet excluded);
- Windows, MAC and Linux USB MIDI HID Device Compatible (no drivers needed);
- Windows and MAC App for customizing buttons and leds. Using this app you can configure everything and save into the unit's EEPROM memory;
- Multiple options for setting the device directly: MIDICC, Note On/Off, Note On/Off Latch. Just press and hold both top buttons for a few seconds to enter the configuration swap option;
- The unit also receives MIDI which can be used to set the RGB LEDs using note on/off. This is great for when you want to change LEDs with a sequencer or create your own App to handle LEDs. One particular note will turn on and off the unit hanlding of LEDs and will only react to input notes to set leds.

Support this project by ordering a full unit from the Wusik.com site.

Using MIDI Input to set the RGB LEDs:

On MIDI Channel 1 - Note:

    34: enable LEDs using the internal configuration. Will still react to MIDI input, but will also override when you press a button;
    35: disable internal LED configuration and only react to LED changes by using MIDI notes;
    36: set all LEDs to white;
    37: set all LEDs to Red;
    38: set all LEDs to Green;
    39: set all LEDs to Blue;
    40: go to page 1;
    41: go to page 2;
    42: go to page 3;
    43: go to page 4;
    44: go to page 5;
    45: go to page 6;
    46: go to page 7;
    47: flash all LEDs red (one time);
    48~: set individual LEDs white;
    64~: set individual LEDs red;
    80~: set individual LEDs green;
    96~: set individual LEDs blue;

On MIDI Channel 2 - Note:

    36~: blink slow individual LEDs white;
    52~: blink fast individual LEDs white;

On MIDI Channel 3:

Here you can set RGB values for each LED individualy, using 3 notes velocity. Each note velocity will set the RGB value of the LED. Translating the 0 ~ 127 value to 0 ~ 255 of the color. Notes 36 to 51 will set the R (red) channel. Notes 52 to 67 will set the G (green) channel and above will set the B (blue) channel and update the LED. The R and G channels doesn't update the LED. This way you can set any color that you want for each LED.