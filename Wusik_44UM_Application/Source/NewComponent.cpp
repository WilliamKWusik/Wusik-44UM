/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "NewComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NewComponent::NewComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    comboBox_Page.reset (new juce::ComboBox ("comboBox_Page"));
    addAndMakeVisible (comboBox_Page.get());
    comboBox_Page->setEditableText (false);
    comboBox_Page->setJustificationType (juce::Justification::centredLeft);
    comboBox_Page->setTextWhenNothingSelected (TRANS("Page 1"));
    comboBox_Page->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Page->addItem (TRANS("Page 1"), 1);
    comboBox_Page->addItem (TRANS("Page 2"), 2);
    comboBox_Page->addItem (TRANS("Page 3"), 3);
    comboBox_Page->addItem (TRANS("Page 4"), 4);
    comboBox_Page->addItem (TRANS("Page 5"), 5);
    comboBox_Page->addItem (TRANS("Page 6"), 6);
    comboBox_Page->addItem (TRANS("Page 7"), 7);
    comboBox_Page->addListener (this);

    comboBox_Page->setBounds (560, 16, 88, 32);

    button_1.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_1.get());
    button_1->setButtonText (juce::String());
    button_1->addListener (this);
    button_1->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_1->setBounds (48, 72, 128, 40);

    button_2.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_2.get());
    button_2->setButtonText (juce::String());
    button_2->addListener (this);
    button_2->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_2->setBounds (200, 73, 128, 40);

    button_3.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_3.get());
    button_3->setButtonText (juce::String());
    button_3->addListener (this);
    button_3->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_3->setBounds (48, 133, 128, 112);

    button_4.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_4.get());
    button_4->setButtonText (juce::String());
    button_4->addListener (this);
    button_4->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_4->setBounds (200, 133, 128, 112);

    button_5.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_5.get());
    button_5->setButtonText (juce::String());
    button_5->addListener (this);
    button_5->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_5->setBounds (352, 133, 128, 112);

    button_6.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_6.get());
    button_6->setButtonText (juce::String());
    button_6->addListener (this);
    button_6->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_6->setBounds (504, 133, 128, 112);

    button_7.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_7.get());
    button_7->setButtonText (juce::String());
    button_7->addListener (this);
    button_7->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_7->setBounds (51, 273, 128, 112);

    button_8.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_8.get());
    button_8->setButtonText (juce::String());
    button_8->addListener (this);
    button_8->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_8->setBounds (203, 273, 128, 112);

    button_9.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_9.get());
    button_9->setButtonText (juce::String());
    button_9->addListener (this);
    button_9->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_9->setBounds (355, 273, 128, 112);

    button_10.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_10.get());
    button_10->setButtonText (juce::String());
    button_10->addListener (this);
    button_10->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_10->setBounds (507, 273, 128, 112);

    button_11.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_11.get());
    button_11->setButtonText (juce::String());
    button_11->addListener (this);
    button_11->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_11->setBounds (50, 406, 128, 112);

    button_12.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_12.get());
    button_12->setButtonText (juce::String());
    button_12->addListener (this);
    button_12->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_12->setBounds (202, 406, 128, 112);

    button_13.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_13.get());
    button_13->setButtonText (juce::String());
    button_13->addListener (this);
    button_13->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_13->setBounds (354, 406, 128, 112);

    button_14.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_14.get());
    button_14->setButtonText (juce::String());
    button_14->addListener (this);
    button_14->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_14->setBounds (506, 406, 128, 112);

    button_15.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_15.get());
    button_15->setButtonText (juce::String());
    button_15->addListener (this);
    button_15->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_15->setBounds (53, 546, 128, 112);

    button_16.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_16.get());
    button_16->setButtonText (juce::String());
    button_16->addListener (this);
    button_16->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_16->setBounds (205, 546, 128, 112);

    button_17.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_17.get());
    button_17->setButtonText (juce::String());
    button_17->addListener (this);
    button_17->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_17->setBounds (357, 546, 128, 112);

    button_18.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (button_18.get());
    button_18->setButtonText (juce::String());
    button_18->addListener (this);
    button_18->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c6ba4));

    button_18->setBounds (509, 546, 128, 112);

    textButton_File.reset (new juce::TextButton ("new button"));
    addAndMakeVisible (textButton_File.get());
    textButton_File->setButtonText (TRANS("File"));
    textButton_File->addListener (this);
    textButton_File->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c68a4));

    textButton_File->setBounds (456, 16, 91, 32);

    cachedImage_logo_w100_100_png_1 = juce::ImageCache::getFromMemory (logo_w100_100_png, logo_w100_100_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (420, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

NewComponent::~NewComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comboBox_Page = nullptr;
    button_1 = nullptr;
    button_2 = nullptr;
    button_3 = nullptr;
    button_4 = nullptr;
    button_5 = nullptr;
    button_6 = nullptr;
    button_7 = nullptr;
    button_8 = nullptr;
    button_9 = nullptr;
    button_10 = nullptr;
    button_11 = nullptr;
    button_12 = nullptr;
    button_13 = nullptr;
    button_14 = nullptr;
    button_15 = nullptr;
    button_16 = nullptr;
    button_17 = nullptr;
    button_18 = nullptr;
    textButton_File = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewComponent::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff03141c));

    {
        int x = 44, y = 4, width = 60, height = 56;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (juce::Colours::black);
        g.drawImage (cachedImage_logo_w100_100_png_1,
                     x, y, width, height,
                     0, 0, cachedImage_logo_w100_100_png_1.getWidth(), cachedImage_logo_w100_100_png_1.getHeight());
    }

    {
        float x = 28.0f, y = 60.0f, width = 628.0f, height = 612.0f;
        juce::Colour fillColour = juce::Colour (0xff474747);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 10.000f);
    }

    {
        int x = 84, y = 28, width = 84, height = 26;
        juce::String text (TRANS("44UM"));
        juce::Colour fillColour = juce::Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (juce::Font (20.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    juce::Justification::centred, true);
    }

    {
        int x = 0, y = 0, width = 1040, height = 688;
        juce::Colour strokeColour = juce::Colour (0x80808080);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 5);

    }

    {
        int x = 672, y = 0, width = 6, height = 688;
        juce::Colour strokeColour = juce::Colour (0x40808080);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (strokeColour);
        g.drawRect (x, y, width, height, 5);

    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NewComponent::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_Page.get())
    {
        //[UserComboBoxCode_comboBox_Page] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_Page]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void NewComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == button_1.get())
    {
        //[UserButtonCode_button_1] -- add your button handler code here..
        //[/UserButtonCode_button_1]
    }
    else if (buttonThatWasClicked == button_2.get())
    {
        //[UserButtonCode_button_2] -- add your button handler code here..
        //[/UserButtonCode_button_2]
    }
    else if (buttonThatWasClicked == button_3.get())
    {
        //[UserButtonCode_button_3] -- add your button handler code here..
        //[/UserButtonCode_button_3]
    }
    else if (buttonThatWasClicked == button_4.get())
    {
        //[UserButtonCode_button_4] -- add your button handler code here..
        //[/UserButtonCode_button_4]
    }
    else if (buttonThatWasClicked == button_5.get())
    {
        //[UserButtonCode_button_5] -- add your button handler code here..
        //[/UserButtonCode_button_5]
    }
    else if (buttonThatWasClicked == button_6.get())
    {
        //[UserButtonCode_button_6] -- add your button handler code here..
        //[/UserButtonCode_button_6]
    }
    else if (buttonThatWasClicked == button_7.get())
    {
        //[UserButtonCode_button_7] -- add your button handler code here..
        //[/UserButtonCode_button_7]
    }
    else if (buttonThatWasClicked == button_8.get())
    {
        //[UserButtonCode_button_8] -- add your button handler code here..
        //[/UserButtonCode_button_8]
    }
    else if (buttonThatWasClicked == button_9.get())
    {
        //[UserButtonCode_button_9] -- add your button handler code here..
        //[/UserButtonCode_button_9]
    }
    else if (buttonThatWasClicked == button_10.get())
    {
        //[UserButtonCode_button_10] -- add your button handler code here..
        //[/UserButtonCode_button_10]
    }
    else if (buttonThatWasClicked == button_11.get())
    {
        //[UserButtonCode_button_11] -- add your button handler code here..
        //[/UserButtonCode_button_11]
    }
    else if (buttonThatWasClicked == button_12.get())
    {
        //[UserButtonCode_button_12] -- add your button handler code here..
        //[/UserButtonCode_button_12]
    }
    else if (buttonThatWasClicked == button_13.get())
    {
        //[UserButtonCode_button_13] -- add your button handler code here..
        //[/UserButtonCode_button_13]
    }
    else if (buttonThatWasClicked == button_14.get())
    {
        //[UserButtonCode_button_14] -- add your button handler code here..
        //[/UserButtonCode_button_14]
    }
    else if (buttonThatWasClicked == button_15.get())
    {
        //[UserButtonCode_button_15] -- add your button handler code here..
        //[/UserButtonCode_button_15]
    }
    else if (buttonThatWasClicked == button_16.get())
    {
        //[UserButtonCode_button_16] -- add your button handler code here..
        //[/UserButtonCode_button_16]
    }
    else if (buttonThatWasClicked == button_17.get())
    {
        //[UserButtonCode_button_17] -- add your button handler code here..
        //[/UserButtonCode_button_17]
    }
    else if (buttonThatWasClicked == button_18.get())
    {
        //[UserButtonCode_button_18] -- add your button handler code here..
        //[/UserButtonCode_button_18]
    }
    else if (buttonThatWasClicked == textButton_File.get())
    {
        //[UserButtonCode_textButton_File] -- add your button handler code here..
        //[/UserButtonCode_textButton_File]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NewComponent" componentName=""
                 parentClasses="public juce::Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="420" initialHeight="480">
  <BACKGROUND backgroundColour="ff03141c">
    <IMAGE pos="44 4 60 56" resource="logo_w100_100_png" opacity="1.0" mode="0"/>
    <ROUNDRECT pos="28 60 628 612" cornerSize="10.0" fill="solid: ff474747"
               hasStroke="0"/>
    <TEXT pos="84 28 84 26" fill="solid: ffffffff" hasStroke="0" text="44UM"
          fontname="Default font" fontsize="20.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <RECT pos="0 0 1040 688" fill="solid: ff7600" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: 80808080"/>
    <RECT pos="672 0 6 688" fill="solid: ff7600" hasStroke="1" stroke="5, mitered, butt"
          strokeColour="solid: 40808080"/>
  </BACKGROUND>
  <COMBOBOX name="comboBox_Page" id="c3e6fcc7b3820d63" memberName="comboBox_Page"
            virtualName="" explicitFocusOrder="0" pos="560 16 88 32" editable="0"
            layout="33" items="Page 1&#10;Page 2&#10;Page 3&#10;Page 4&#10;Page 5&#10;Page 6&#10;Page 7"
            textWhenNonSelected="Page 1" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="new button" id="66db27d7aa3c261d" memberName="button_1"
              virtualName="" explicitFocusOrder="0" pos="48 72 128 40" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="cb73378c7e55abda" memberName="button_2"
              virtualName="" explicitFocusOrder="0" pos="200 73 128 40" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="69f993b30f946708" memberName="button_3"
              virtualName="" explicitFocusOrder="0" pos="48 133 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="67c7ed4f87f3f06d" memberName="button_4"
              virtualName="" explicitFocusOrder="0" pos="200 133 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="bd1f710ecef3bf60" memberName="button_5"
              virtualName="" explicitFocusOrder="0" pos="352 133 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="b0eba400c86298d9" memberName="button_6"
              virtualName="" explicitFocusOrder="0" pos="504 133 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="ba25e33593994046" memberName="button_7"
              virtualName="" explicitFocusOrder="0" pos="51 273 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d2c0c5b1aa83f72e" memberName="button_8"
              virtualName="" explicitFocusOrder="0" pos="203 273 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="8ffeb9a3766ee19f" memberName="button_9"
              virtualName="" explicitFocusOrder="0" pos="355 273 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e2ee5317161833bf" memberName="button_10"
              virtualName="" explicitFocusOrder="0" pos="507 273 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1132bfc1395f40b3" memberName="button_11"
              virtualName="" explicitFocusOrder="0" pos="50 406 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="530a7ca25c3e39d5" memberName="button_12"
              virtualName="" explicitFocusOrder="0" pos="202 406 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="fe0bd0478c22165b" memberName="button_13"
              virtualName="" explicitFocusOrder="0" pos="354 406 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6a2eb12280b97f83" memberName="button_14"
              virtualName="" explicitFocusOrder="0" pos="506 406 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="1dc4ac3d7b9673f0" memberName="button_15"
              virtualName="" explicitFocusOrder="0" pos="53 546 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d1e15447452281a5" memberName="button_16"
              virtualName="" explicitFocusOrder="0" pos="205 546 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="3222a9b98d7a1ec7" memberName="button_17"
              virtualName="" explicitFocusOrder="0" pos="357 546 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="edf101a2a227f9cc" memberName="button_18"
              virtualName="" explicitFocusOrder="0" pos="509 546 128 112" bgColOff="ff5c6ba4"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a6b474474542d949" memberName="textButton_File"
              virtualName="" explicitFocusOrder="0" pos="456 16 91 32" bgColOff="ff5c68a4"
              buttonText="File" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: logo_w100_100_png, 5568, "Logo_W100_100.png"
static const unsigned char resource_NewComponent_logo_w100_100_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,100,0,0,0,100,8,6,0,0,0,112,226,149,84,0,0,0,9,112,72,89,115,0,0,14,196,0,0,
14,196,1,149,43,14,27,0,0,0,7,116,73,77,69,7,227,5,13,18,40,43,136,205,180,213,0,0,0,7,116,69,88,116,65,117,116,104,111,114,0,169,174,204,72,0,0,0,10,116,69,88,116,67,111,112,121,114,105,103,104,116,0,
172,15,204,58,0,0,0,14,116,69,88,116,67,114,101,97,116,105,111,110,32,116,105,109,101,0,53,247,15,9,0,0,0,9,116,69,88,116,83,111,102,116,119,97,114,101,0,93,112,255,58,0,0,0,11,116,69,88,116,68,105,115,
99,108,97,105,109,101,114,0,183,192,180,143,0,0,0,8,116,69,88,116,87,97,114,110,105,110,103,0,192,27,230,135,0,0,0,7,116,69,88,116,83,111,117,114,99,101,0,245,255,131,235,0,0,0,8,116,69,88,116,67,111,
109,109,101,110,116,0,246,204,150,191,0,0,0,6,116,69,88,116,84,105,116,108,101,0,168,238,210,39,0,0,20,163,73,68,65,84,120,156,237,157,123,120,91,229,125,199,191,210,209,45,186,88,119,147,208,134,4,8,
33,176,238,210,110,107,195,186,194,198,214,62,236,217,90,250,60,3,210,208,46,133,60,91,129,180,77,87,110,33,41,37,36,113,98,7,91,33,25,233,96,73,160,97,93,7,109,97,208,134,130,37,57,225,90,238,118,210,
92,108,9,91,146,37,89,55,203,65,183,99,89,178,110,251,227,156,147,188,28,159,19,203,182,100,107,123,244,125,158,60,121,244,250,103,233,61,231,119,62,231,119,121,95,29,75,42,149,10,154,106,28,73,23,122,
2,77,125,82,77,135,52,152,154,14,105,48,53,29,210,96,106,58,164,193,212,116,72,131,169,233,144,6,83,211,33,13,166,166,67,26,76,77,135,52,152,154,14,105,48,53,29,210,96,106,58,164,193,212,116,72,131,169,
233,144,6,83,211,33,13,166,166,67,26,76,77,135,52,152,154,14,105,48,157,115,136,207,231,27,201,229,114,21,0,21,0,63,19,251,133,222,222,222,23,67,161,16,103,119,26,0,85,247,89,254,223,211,175,192,156,159,
10,128,19,16,57,71,249,124,254,62,194,46,7,16,14,25,30,30,238,10,4,2,220,203,155,1,92,33,244,38,129,64,96,183,207,231,43,23,10,5,0,248,3,0,55,214,228,16,254,159,200,227,241,92,13,224,235,196,80,59,128,
18,223,110,96,96,64,87,44,22,191,71,12,253,23,64,56,196,239,247,31,114,185,92,145,179,103,207,2,128,18,192,3,66,31,56,58,58,250,174,199,227,233,30,26,26,226,134,126,140,198,160,228,115,0,86,46,244,36,
10,133,194,102,0,50,246,229,41,0,207,11,217,77,78,78,222,46,149,74,47,225,94,2,216,13,16,14,185,237,182,219,104,159,207,215,117,230,204,25,110,232,155,16,160,228,142,59,238,168,68,34,145,54,151,203,85,
46,151,203,0,240,39,88,96,74,210,233,180,4,192,118,48,23,199,130,233,245,215,95,95,165,80,40,110,33,134,118,0,40,242,237,142,29,59,166,165,40,234,94,149,74,197,13,61,3,96,16,224,5,245,120,60,126,208,229,
114,133,195,225,48,112,1,74,178,217,236,187,126,191,191,231,244,233,211,220,208,131,88,64,74,162,209,232,23,0,252,29,128,91,0,92,181,80,243,80,40,20,91,244,122,189,130,125,121,2,192,11,66,118,20,69,173,
111,105,105,89,42,145,72,0,32,15,160,131,251,217,39,28,210,214,214,150,137,68,34,123,136,19,253,77,0,43,248,111,184,125,251,246,202,199,31,127,188,195,229,114,149,75,165,18,0,124,22,192,87,231,120,60,
179,150,223,239,191,55,22,139,73,1,40,0,108,89,136,57,56,157,206,171,90,90,90,214,24,141,70,110,168,13,2,116,56,28,14,173,70,163,185,215,108,54,115,67,207,2,112,113,47,166,164,189,153,76,230,192,208,208,
80,120,100,100,4,96,40,217,44,52,129,66,161,240,187,96,48,72,82,178,5,11,68,73,32,16,56,58,56,56,200,189,188,5,192,170,249,158,131,90,173,222,108,177,88,20,82,169,20,0,250,0,188,40,100,39,151,203,111,
55,155,205,75,53,26,13,192,196,142,118,242,231,83,28,210,213,213,149,137,70,163,255,70,156,232,111,65,128,146,246,246,246,74,50,153,220,225,114,185,42,44,37,127,6,224,239,103,127,72,179,87,44,22,123,106,
112,112,208,27,10,133,0,134,18,193,91,109,189,228,116,58,175,54,24,12,107,44,22,11,55,180,29,2,153,149,195,225,208,104,181,218,251,172,86,43,55,244,12,0,55,105,35,88,24,142,143,143,63,225,245,122,99,44,
37,10,136,80,178,99,199,142,183,70,70,70,122,216,68,64,130,5,138,37,91,182,108,201,135,195,225,78,226,34,186,21,192,149,243,245,249,106,181,122,179,213,106,85,80,20,5,0,189,0,94,18,178,147,201,100,183,
155,205,230,165,90,173,22,0,10,96,51,43,82,130,14,177,217,108,169,104,52,250,40,113,128,255,4,224,114,33,91,142,18,54,227,250,115,44,16,37,153,76,230,63,189,94,175,159,173,165,228,0,30,154,143,207,101,
233,184,133,136,9,219,32,64,135,221,110,215,234,116,58,146,142,95,2,24,224,219,137,182,78,120,148,200,33,18,44,139,197,226,91,193,96,240,213,133,206,184,58,58,58,178,163,163,163,100,218,62,47,25,23,143,
142,247,0,252,86,200,78,46,151,175,51,153,76,151,232,116,58,128,9,246,59,133,236,68,29,194,81,194,171,75,196,98,201,118,130,146,5,139,37,19,19,19,63,245,249,124,35,44,37,50,48,23,71,221,228,116,58,87,
241,232,216,1,160,204,183,115,56,28,106,157,78,119,111,107,107,43,55,244,11,8,208,1,76,211,92,28,31,31,127,194,227,241,140,177,193,82,9,224,62,33,187,98,177,248,198,200,200,200,171,243,24,75,62,15,64,
199,31,236,232,232,24,143,199,227,182,249,162,68,173,86,63,64,208,241,54,128,110,33,59,153,76,182,206,100,50,93,58,29,29,192,52,14,177,217,108,169,88,44,182,151,184,29,173,3,112,25,223,174,189,189,189,
146,72,36,118,12,12,12,212,61,150,228,114,57,41,0,27,128,187,132,126,62,49,49,113,208,235,245,6,253,126,63,192,80,82,151,234,189,167,167,231,74,163,209,184,150,165,163,2,241,204,74,173,211,233,238,171,
134,14,160,138,246,59,77,211,63,241,122,189,99,108,245,174,2,176,73,200,142,71,9,192,196,156,154,183,247,227,241,248,87,0,124,17,192,221,16,161,100,108,108,172,171,191,191,159,27,186,9,192,103,106,61,
15,174,238,32,232,112,10,217,177,116,92,198,210,81,2,175,238,224,107,218,19,102,179,217,146,209,104,116,47,47,227,18,162,164,156,72,36,118,18,177,228,243,0,110,152,238,253,103,162,238,238,110,105,40,20,
122,176,80,40,72,0,92,4,113,74,14,121,189,222,16,145,113,213,180,122,231,232,96,235,142,10,152,204,74,40,118,44,210,233,116,247,19,153,213,115,0,206,240,237,72,85,117,5,211,52,189,223,227,241,156,101,
41,89,4,113,74,94,11,6,131,111,178,87,167,4,204,237,162,102,148,164,82,169,74,52,26,205,179,49,13,0,238,1,160,229,219,117,116,116,100,199,198,198,200,140,235,38,48,75,5,53,17,175,42,127,3,192,81,33,59,
46,118,180,180,180,0,76,236,216,53,221,123,87,117,178,216,140,107,95,21,177,164,156,76,38,119,12,12,12,84,216,47,147,174,70,13,41,89,179,102,77,101,124,124,188,61,18,137,112,87,99,43,128,59,133,108,217,
88,18,169,53,37,61,61,61,171,120,177,67,48,179,178,219,237,139,116,58,221,38,130,142,231,1,156,156,238,253,171,190,122,105,154,254,9,65,137,104,44,41,20,10,199,130,193,224,27,196,213,249,16,24,90,106,
34,165,82,121,44,157,78,191,62,54,54,198,13,93,48,150,16,243,184,25,192,31,205,229,179,237,118,187,132,71,199,107,0,142,9,217,178,117,7,73,135,104,102,69,170,106,135,216,108,182,143,163,209,232,99,196,
1,138,198,146,100,50,217,230,114,185,56,74,184,214,248,156,20,12,6,175,113,185,92,215,223,116,211,77,101,138,162,30,142,197,98,220,85,185,4,192,119,132,126,103,98,98,226,128,215,235,141,176,25,215,156,
41,161,40,106,149,209,104,92,67,208,177,141,253,255,19,178,219,237,42,1,58,78,85,243,25,51,186,191,211,52,253,216,208,208,208,180,177,164,80,40,28,13,4,2,111,18,206,155,83,44,137,68,34,82,163,209,184,
125,249,242,229,91,195,225,176,84,171,213,190,153,72,36,28,4,37,247,64,152,18,58,30,143,63,66,204,227,31,1,252,225,108,230,96,183,219,37,26,141,230,62,139,197,162,100,233,120,21,76,252,152,34,185,92,254,
109,30,29,29,66,118,66,154,209,73,18,160,100,29,128,75,249,118,108,245,190,139,71,201,172,99,73,165,82,185,94,171,213,254,141,74,165,250,210,197,23,95,252,149,213,171,87,87,104,154,126,216,227,241,76,
75,73,46,151,59,228,243,249,70,136,186,228,71,179,153,131,76,38,91,105,48,24,200,216,241,48,170,163,227,215,96,22,171,170,210,140,175,90,154,166,247,19,148,168,32,210,234,46,20,10,206,64,32,240,14,81,
189,207,138,146,15,63,252,80,10,38,112,74,216,127,119,0,192,13,55,220,240,222,240,240,240,203,31,125,244,17,103,42,22,75,232,120,60,222,197,163,100,70,177,196,225,112,72,212,106,245,38,171,213,170,98,
233,112,2,120,83,200,118,182,177,131,211,140,79,144,205,102,59,27,141,70,159,32,14,240,219,0,150,243,237,184,140,203,229,114,113,87,209,23,0,252,237,76,63,175,84,42,125,77,169,84,174,38,134,206,109,26,
136,197,98,91,207,156,57,83,206,231,243,0,112,49,128,127,17,122,143,92,46,119,200,235,245,206,154,18,138,162,86,26,12,134,111,152,76,38,224,124,85,62,69,118,187,93,165,213,106,73,58,126,3,224,248,76,62,
107,86,247,117,154,166,247,14,13,13,37,35,145,8,112,225,85,69,251,92,40,113,58,157,50,185,92,190,131,173,114,1,224,100,169,84,250,37,247,98,227,198,141,125,126,191,255,55,68,58,126,47,132,235,18,126,198,
85,117,44,113,56,28,18,141,70,179,201,106,181,46,98,233,232,6,83,153,79,145,92,46,95,103,54,155,47,99,233,40,129,33,123,70,154,149,67,108,54,219,88,52,26,253,9,113,34,190,13,241,88,178,125,96,224,92,235,
230,139,152,1,37,20,69,173,213,235,245,159,81,40,184,125,3,104,163,40,106,146,180,73,36,18,109,131,131,131,37,150,146,11,197,146,39,189,94,239,200,240,240,48,192,52,62,171,234,4,203,100,178,43,13,6,195,
90,150,142,50,24,58,4,99,135,86,171,37,171,242,23,49,131,216,193,105,214,153,15,77,211,251,134,134,134,18,4,37,98,177,196,17,12,6,223,158,105,245,222,221,221,173,210,106,181,91,137,101,209,15,33,176,78,
189,109,219,182,222,120,60,126,132,88,83,23,171,222,105,94,143,107,218,88,194,197,14,139,197,194,197,142,87,192,172,121,76,145,92,46,191,213,100,50,93,206,210,81,70,21,85,185,144,102,237,16,155,205,22,
143,70,163,255,94,69,143,171,146,72,36,118,13,12,12,112,87,85,85,148,40,20,138,245,38,147,233,114,189,94,15,156,191,111,23,132,108,139,197,226,35,225,112,152,203,184,46,6,240,207,66,118,92,44,33,40,217,
122,161,57,176,116,112,177,163,4,113,58,148,26,141,102,19,209,209,125,9,204,70,135,25,107,78,125,38,150,146,52,75,201,133,234,146,87,2,129,192,251,213,82,210,221,221,173,211,233,116,155,137,3,252,29,128,
151,197,236,245,122,253,187,217,108,246,229,104,52,202,13,61,128,234,170,247,27,193,108,97,154,162,99,199,142,241,233,120,9,192,7,66,182,114,185,252,86,179,217,188,146,160,67,48,232,87,163,57,57,132,165,
228,241,42,59,193,109,213,198,18,165,82,185,193,108,54,127,154,61,64,174,34,158,178,214,224,241,120,244,125,125,125,95,90,191,126,125,69,161,80,180,141,142,142,114,54,23,65,164,199,197,213,37,211,197,
18,165,82,185,194,100,50,145,116,236,132,8,29,90,173,246,1,30,29,189,98,199,54,157,230,220,137,165,105,122,207,208,208,80,154,189,58,167,163,228,61,30,37,83,122,92,175,189,246,154,73,175,215,147,203,157,
61,16,233,23,153,76,166,59,47,187,236,178,142,225,225,97,202,104,52,190,159,78,167,143,84,81,189,243,41,249,26,152,125,193,231,52,56,56,40,49,26,141,247,95,116,209,69,28,29,191,6,19,195,166,136,141,29,
43,231,146,89,145,154,179,67,108,54,219,104,52,26,125,252,212,169,115,173,26,49,74,74,44,37,220,85,246,151,16,160,164,165,165,229,135,173,173,173,22,118,171,76,25,34,107,13,161,80,168,69,171,213,222,109,
48,24,174,89,182,108,217,87,174,185,230,154,202,196,196,196,14,159,207,87,13,37,7,125,62,95,200,235,245,2,2,117,137,209,104,92,177,120,241,226,111,177,241,171,4,102,23,162,88,236,32,233,248,45,68,28,87,
173,106,178,86,49,67,74,222,39,174,206,31,129,160,36,18,137,92,108,181,90,55,46,89,178,132,27,122,9,192,59,66,239,85,44,22,55,202,229,242,86,0,18,137,68,178,25,0,190,252,229,47,247,249,253,254,23,136,
234,253,30,0,45,252,223,237,232,232,200,198,227,113,114,31,215,141,56,79,137,196,98,177,108,50,153,76,220,78,232,23,33,82,220,201,229,242,181,188,216,49,163,170,92,72,53,113,8,75,201,19,188,245,146,229,
124,59,150,146,142,254,254,126,176,223,47,185,22,192,95,115,63,183,90,173,155,150,46,93,218,194,46,139,22,33,66,199,187,239,190,107,164,40,234,7,196,208,185,15,30,29,29,221,217,223,223,95,204,229,114,
0,67,201,119,133,230,156,203,229,14,122,189,222,208,201,147,39,1,38,150,112,148,92,1,102,163,29,192,100,117,130,183,32,187,221,174,208,104,52,155,137,186,227,21,136,4,253,153,168,102,171,121,108,245,158,
137,197,98,0,211,227,18,220,161,50,57,57,121,100,120,120,248,195,190,190,62,128,161,131,91,47,185,84,38,147,145,173,143,231,32,94,88,253,64,163,209,112,5,202,56,136,110,234,134,13,27,78,12,15,15,191,72,
220,66,255,21,128,129,255,6,187,119,239,206,142,142,142,118,158,56,113,2,236,222,179,175,1,248,83,0,247,131,161,28,0,254,7,192,239,133,38,32,147,201,110,53,155,205,43,167,187,173,205,84,53,115,136,205,
102,139,68,163,209,3,4,37,183,1,88,198,183,235,232,232,40,157,61,123,118,231,169,83,167,42,236,151,126,56,74,126,140,243,39,34,7,166,176,154,66,199,209,163,71,91,53,26,205,70,246,54,1,0,135,0,4,72,155,
120,60,222,54,48,48,80,202,100,50,0,179,170,40,186,246,238,241,120,70,62,248,224,3,140,142,142,202,0,236,7,176,150,253,49,119,146,167,168,187,187,91,161,213,106,73,58,186,33,82,48,206,84,53,221,21,146,
201,100,246,12,14,14,114,148,168,193,92,109,83,84,40,20,142,248,253,254,222,222,222,94,4,131,65,9,128,199,192,108,196,227,244,12,136,219,16,41,133,66,113,143,201,100,50,178,183,53,26,2,251,99,119,238,
220,249,251,96,48,248,2,113,113,8,82,242,232,163,143,142,159,61,123,182,171,191,191,31,199,143,31,71,58,157,94,205,206,27,96,182,235,8,206,65,46,151,175,53,153,76,28,29,101,212,136,14,160,198,14,177,217,
108,97,30,37,183,3,184,68,192,174,148,78,167,119,122,60,30,244,247,247,35,157,78,95,13,102,83,55,0,100,193,220,130,166,28,96,79,79,207,167,91,90,90,238,34,218,41,143,3,136,8,205,37,153,76,182,185,221,
238,105,41,153,156,156,60,20,137,68,70,220,110,55,220,110,55,146,201,36,38,39,39,11,165,82,73,140,14,185,86,171,221,66,100,86,162,237,148,217,168,230,251,166,50,153,204,30,34,150,136,102,92,18,137,228,
55,233,116,186,47,22,139,33,30,143,159,27,47,151,203,79,87,42,149,65,161,223,81,169,84,155,173,86,171,78,169,84,2,64,10,64,151,216,60,58,59,59,127,63,50,50,50,45,37,7,14,28,24,207,231,243,143,196,98,49,
248,253,126,132,195,97,36,147,201,95,82,20,37,184,153,141,171,59,8,58,218,81,35,58,128,58,56,196,102,179,133,35,145,200,83,68,106,187,30,192,82,190,221,222,189,123,203,114,185,188,189,92,46,163,80,40,
32,155,205,98,114,114,50,83,42,149,186,36,18,201,148,3,60,122,244,232,10,189,94,191,158,184,111,239,7,48,122,161,185,164,82,169,170,40,81,42,149,79,22,10,5,95,34,145,64,34,145,40,100,179,89,193,204,138,
139,29,188,162,85,176,21,63,91,213,229,193,1,153,76,166,107,112,112,112,156,200,184,4,59,193,22,139,229,184,209,104,44,45,90,180,8,149,74,5,165,82,233,41,0,62,33,91,149,74,181,213,106,181,170,228,114,
57,0,124,12,96,207,116,243,16,161,68,207,183,219,191,127,127,86,173,86,183,87,42,21,228,243,249,255,94,190,124,185,155,111,3,156,139,29,87,242,26,158,53,125,120,126,93,28,98,179,217,70,34,145,200,33,130,
146,219,33,144,113,93,114,201,37,247,47,91,182,140,50,24,12,144,74,165,41,137,68,178,71,46,151,11,209,241,199,122,189,254,27,68,236,216,11,198,41,211,42,149,74,237,116,187,221,197,233,40,89,188,120,241,
207,180,90,109,191,76,38,19,220,234,217,221,221,205,175,59,28,168,49,29,64,29,31,173,193,163,100,17,120,25,215,233,211,167,47,189,226,138,43,214,45,95,190,28,58,157,14,50,153,236,128,92,46,15,242,223,
199,233,116,74,84,42,213,118,171,213,42,147,201,100,0,115,155,218,95,237,60,58,59,59,79,132,66,161,23,167,163,228,206,59,239,204,45,94,188,248,171,215,94,123,173,40,29,102,179,249,74,131,193,0,156,223,
32,87,243,63,45,81,55,135,216,108,182,145,112,56,124,136,173,132,1,30,37,203,150,45,187,119,197,138,21,42,150,142,4,69,81,251,40,138,154,114,128,82,169,244,47,140,70,227,63,16,87,230,30,0,137,153,204,
37,153,76,146,148,136,246,184,174,191,254,122,175,208,56,75,199,3,196,28,156,96,150,4,106,174,186,62,124,38,147,201,116,185,221,238,9,143,199,3,48,148,112,213,251,50,157,78,119,27,241,197,249,131,82,169,
52,204,255,125,167,211,41,81,171,213,109,173,173,173,82,182,235,26,6,147,234,206,72,2,148,252,16,2,157,96,49,201,100,178,155,77,38,211,42,130,14,193,148,184,22,170,171,67,246,236,217,51,18,14,135,159,
234,237,237,69,34,145,0,206,83,114,31,206,23,96,41,0,251,32,128,191,84,42,189,193,96,48,252,21,241,13,165,46,0,233,217,204,69,128,18,193,88,194,215,43,175,188,194,175,59,94,5,240,214,108,230,80,141,234,
254,120,166,116,58,189,219,237,118,231,222,123,239,61,164,82,41,53,152,128,124,59,97,242,31,16,40,238,156,78,39,165,209,104,218,90,91,91,193,62,241,32,8,224,224,108,231,33,64,201,221,16,88,123,231,75,
38,147,173,53,153,76,87,215,59,118,112,170,187,67,246,239,223,31,140,70,163,79,158,60,121,18,199,143,31,71,54,155,253,58,206,211,145,4,227,160,41,7,72,81,212,205,70,163,241,115,4,29,29,96,90,37,179,86,
181,177,132,211,203,47,191,172,208,233,116,36,29,199,0,188,62,151,57,76,167,121,121,128,217,248,248,248,35,129,64,32,219,223,223,143,193,193,65,176,173,113,84,42,149,67,0,162,124,123,135,195,161,84,171,
213,91,137,32,234,171,84,42,63,157,235,60,88,74,158,39,58,193,23,164,132,171,59,230,139,14,96,158,28,114,248,240,225,0,77,211,135,67,161,16,124,62,31,66,161,16,18,137,68,38,159,207,11,198,14,138,162,214,
153,76,166,85,236,122,54,0,236,146,72,36,19,181,152,75,50,153,220,250,209,71,31,77,166,211,105,128,217,199,245,125,33,59,167,211,73,233,116,58,50,179,58,6,145,205,213,181,212,124,62,226,175,107,124,124,
60,23,143,199,49,54,54,6,154,166,15,151,74,165,16,223,200,225,112,168,53,26,205,143,136,19,49,88,169,84,68,159,112,55,83,117,118,118,186,67,161,208,179,211,245,184,212,106,245,141,22,139,101,21,251,48,
153,10,152,229,128,186,255,73,187,121,115,200,225,195,135,125,82,169,244,233,124,62,15,154,166,179,147,147,147,123,53,26,141,16,29,119,152,76,166,101,228,83,117,36,18,73,190,150,115,73,38,147,237,110,
183,187,144,74,165,0,129,234,221,227,241,80,22,139,229,65,98,41,249,13,48,95,206,169,187,230,245,33,152,6,131,97,183,76,38,155,40,151,203,191,40,149,74,83,122,86,118,187,93,175,209,104,200,175,16,15,84,
42,149,103,106,61,143,206,206,78,87,40,20,122,86,108,85,209,98,177,220,248,169,79,125,234,179,236,19,123,184,186,99,202,98,89,61,52,175,14,121,232,161,135,124,6,131,225,160,82,169,180,173,92,185,114,10,
29,50,153,236,187,102,179,121,9,27,68,1,96,187,68,34,17,220,173,56,87,165,82,169,93,46,151,171,200,110,242,35,41,161,244,122,253,143,217,93,47,192,5,190,212,89,15,205,251,99,98,151,44,89,242,128,94,175,
239,231,143,119,119,119,27,181,90,237,15,9,58,78,150,203,229,231,234,53,143,206,206,78,87,48,24,124,182,175,175,143,219,112,193,245,184,190,14,230,177,133,192,60,101,86,164,100,211,155,212,86,215,93,119,
157,96,182,68,81,212,70,147,201,100,97,91,219,0,176,77,42,149,78,121,34,91,45,149,76,38,119,245,247,247,175,49,24,12,242,213,171,87,183,178,59,89,110,34,76,222,128,200,38,189,122,169,33,30,164,124,228,
200,17,139,70,163,249,1,209,94,255,160,92,46,255,186,222,159,187,111,223,190,129,145,145,145,103,143,31,63,142,190,190,62,148,203,229,7,113,254,123,35,243,150,89,145,106,8,135,0,248,126,75,75,139,145,
160,99,187,84,42,157,178,151,183,30,162,105,186,221,235,245,22,78,158,60,9,183,219,45,39,254,88,243,59,16,121,92,70,61,181,224,14,249,249,207,127,110,144,74,165,223,211,104,52,92,207,234,157,82,169,36,
186,211,189,214,122,242,201,39,7,18,137,196,47,252,126,63,134,134,134,16,8,4,144,78,167,145,203,229,106,190,26,88,141,22,220,33,217,108,246,187,229,114,217,36,145,72,48,49,49,81,201,231,243,15,83,20,53,
47,41,38,167,114,185,220,158,74,165,38,163,209,40,98,177,24,82,169,212,219,249,124,126,222,233,0,22,216,33,143,63,254,184,52,151,203,125,135,45,22,65,211,244,235,133,66,161,103,190,231,241,244,211,79,
247,3,120,46,155,205,34,149,74,97,98,98,98,135,94,175,159,215,139,130,211,130,58,228,174,187,238,42,23,10,133,223,230,114,57,208,52,93,158,152,152,216,166,213,106,23,228,68,232,116,186,93,20,69,21,138,
197,226,219,165,82,201,177,16,115,0,26,224,150,165,82,169,118,74,165,210,108,161,80,56,86,44,22,235,218,218,190,144,218,218,218,206,232,245,250,95,41,149,202,157,87,93,117,213,130,92,20,64,3,56,100,195,
134,13,161,150,150,150,199,84,42,213,214,203,47,191,124,222,131,40,169,197,139,23,223,109,48,24,236,11,57,7,9,145,230,53,213,0,90,112,66,154,250,164,154,14,105,48,53,29,210,96,106,58,164,193,212,116,72,
131,169,233,144,6,83,211,33,13,166,166,67,26,76,77,135,52,152,154,14,105,48,53,29,210,96,106,58,164,193,212,116,72,131,169,233,144,6,83,211,33,13,166,255,5,103,29,227,116,204,37,137,203,0,0,0,0,73,69,
78,68,174,66,96,130,0,0};

const char* NewComponent::logo_w100_100_png = (const char*) resource_NewComponent_logo_w100_100_png;
const int NewComponent::logo_w100_100_pngSize = 5568;


//[EndFile] You can add extra defines here...
//[/EndFile]

