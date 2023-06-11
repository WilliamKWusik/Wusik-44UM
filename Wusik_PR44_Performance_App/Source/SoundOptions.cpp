/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SoundOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

#include "PluginProcessor.h"
#include "EditCompo.h"

//[/MiscUserDefs]

//==============================================================================
SoundOptions::SoundOptions ()
{
    //[Constructor_pre] You can add your own custom stuff here..

	getLookAndFeel().setDefaultSansSerifTypefaceName("Verdana");

    //[/Constructor_pre]

    label2.reset (new Label ("new label",
                             TRANS("Playing Colour")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (24, 321, 112, 25);

    textButton_PlayingColour.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_PlayingColour.get());
    textButton_PlayingColour->setButtonText (String());
    textButton_PlayingColour->addListener (this);
    textButton_PlayingColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_PlayingColour->setBounds (151, 323, 53, 24);

    label3.reset (new Label ("new label",
                             TRANS("Queued Colour")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (24, 361, 112, 24);

    textButton_QueuedColour.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_QueuedColour.get());
    textButton_QueuedColour->setButtonText (String());
    textButton_QueuedColour->addListener (this);
    textButton_QueuedColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_QueuedColour->setBounds (151, 362, 53, 24);

    label6.reset (new Label ("new label",
                             TRANS("Group")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (24, 187, 93, 24);

    textButton_Group.reset (new TextButton ("button Font Colour"));
    addAndMakeVisible (textButton_Group.get());
    textButton_Group->setTooltip (TRANS("If you set a group and don\'t enable \'Multi In The Same Group\', only one sound will play per group."));
    textButton_Group->setButtonText (String());
    textButton_Group->addListener (this);
    textButton_Group->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Group->setBounds (131, 188, 149, 24);

    label4.reset (new Label ("new label",
                             TRANS("Group Stop")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (24, 227, 93, 24);

    textButton_GroupStop.reset (new TextButton ("button Font Colour"));
    addAndMakeVisible (textButton_GroupStop.get());
    textButton_GroupStop->setTooltip (TRANS("When this object starts playing it will stop all objects with this group name."));
    textButton_GroupStop->setButtonText (String());
    textButton_GroupStop->addListener (this);
    textButton_GroupStop->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_GroupStop->setBounds (131, 228, 149, 24);

    label5.reset (new Label ("new label",
                             TRANS("Back To")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (24, 268, 93, 24);

    textButton_BackTo.reset (new TextButton ("button Font Colour"));
    addAndMakeVisible (textButton_BackTo.get());
    textButton_BackTo->setTooltip (TRANS("When selecting this object, it will stop all other objects and after it finishes playing it will play the selectd group."));
    textButton_BackTo->setButtonText (String());
    textButton_BackTo->addListener (this);
    textButton_BackTo->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BackTo->setBounds (131, 269, 149, 24);

    comboBox_PlaybackType.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_PlaybackType.get());
    comboBox_PlaybackType->setEditableText (false);
    comboBox_PlaybackType->setJustificationType (Justification::centredLeft);
    comboBox_PlaybackType->setTextWhenNothingSelected (String());
    comboBox_PlaybackType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_PlaybackType->addItem (TRANS("Synced"), 1);
    comboBox_PlaybackType->addItem (TRANS("Poly Free"), 2);
    comboBox_PlaybackType->addListener (this);

    comboBox_PlaybackType->setBounds (131, 490, 133, 24);

    label10.reset (new Label ("new label",
                              TRANS("Playback Type")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (24, 490, 93, 24);

    toggleButton_MultiTrigger.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_MultiTrigger.get());
    toggleButton_MultiTrigger->setButtonText (TRANS("Multi In The Same Group"));
    toggleButton_MultiTrigger->addListener (this);

    toggleButton_MultiTrigger->setBounds (24, 569, 200, 24);

    toggleButton_Looped.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_Looped.get());
    toggleButton_Looped->setButtonText (TRANS("Is Looped"));
    toggleButton_Looped->addListener (this);

    toggleButton_Looped->setBounds (24, 603, 104, 24);

    textButton_Filename.reset (new TextButton ("button Font Colour"));
    addAndMakeVisible (textButton_Filename.get());
    textButton_Filename->setButtonText (TRANS("Sound File"));
    textButton_Filename->addListener (this);
    textButton_Filename->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Filename->setBounds (16, 63, 288, 24);

    toggleButton_Embedded.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_Embedded.get());
    toggleButton_Embedded->setTooltip (TRANS("Include the audio into the host project file. Keep in mind that some hosts has a file limitation for project files."));
    toggleButton_Embedded->setButtonText (TRANS("Embedded"));
    toggleButton_Embedded->addListener (this);

    toggleButton_Embedded->setBounds (208, 29, 96, 24);

    toggleButton_InstantStop.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_InstantStop.get());
    toggleButton_InstantStop->setButtonText (TRANS("Instant Stop"));
    toggleButton_InstantStop->addListener (this);

    toggleButton_InstantStop->setBounds (24, 637, 150, 24);

    textButton_ImagePlaying.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_ImagePlaying.get());
    textButton_ImagePlaying->setButtonText (TRANS("Image"));
    textButton_ImagePlaying->addListener (this);
    textButton_ImagePlaying->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImagePlaying->setBounds (216, 323, 72, 24);

    textButton_ImageQueued.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_ImageQueued.get());
    textButton_ImageQueued->setButtonText (TRANS("Image"));
    textButton_ImageQueued->addListener (this);
    textButton_ImageQueued->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImageQueued->setBounds (216, 362, 72, 24);

    label11.reset (new Label ("new label",
                              TRANS("Volume")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (24, 27, 61, 25);

    toggleButton_DragVolume.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_DragVolume.get());
    toggleButton_DragVolume->setButtonText (TRANS("Mouse Volume"));
    toggleButton_DragVolume->addListener (this);

    toggleButton_DragVolume->setBounds (24, 669, 128, 24);

    textButton_DragVolumeMin.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_DragVolumeMin.get());
    textButton_DragVolumeMin->setButtonText (String());
    textButton_DragVolumeMin->addListener (this);
    textButton_DragVolumeMin->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_DragVolumeMin->setBounds (168, 709, 92, 24);

    label12.reset (new Label ("new label",
                              TRANS("Min Vol")));
    addAndMakeVisible (label12.get());
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label12->setBounds (104, 709, 56, 24);

    textButton_DragVolumeMax.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_DragVolumeMax.get());
    textButton_DragVolumeMax->setButtonText (String());
    textButton_DragVolumeMax->addListener (this);
    textButton_DragVolumeMax->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_DragVolumeMax->setBounds (168, 748, 92, 24);

    label13.reset (new Label ("new label",
                              TRANS("Max Vol")));
    addAndMakeVisible (label13.get());
    label13->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label13->setBounds (104, 748, 56, 24);

    comboBox_RecordType.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_RecordType.get());
    comboBox_RecordType->setEditableText (false);
    comboBox_RecordType->setJustificationType (Justification::centredLeft);
    comboBox_RecordType->setTextWhenNothingSelected (TRANS("None"));
    comboBox_RecordType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_RecordType->addItem (TRANS("None"), 1);
    comboBox_RecordType->addItem (TRANS("Continuous"), 2);
    comboBox_RecordType->addItem (TRANS("Mix"), 3);
    comboBox_RecordType->addItem (TRANS("Replace"), 4);
    comboBox_RecordType->addItem (TRANS("PingPong"), 5);
    comboBox_RecordType->addListener (this);

    comboBox_RecordType->setBounds (139, 955, 133, 24);

    label14.reset (new Label ("new label",
                              TRANS("Record Type")));
    addAndMakeVisible (label14.get());
    label14->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label14->setBounds (32, 955, 88, 24);

    label15.reset (new Label ("new label",
                              TRANS("Measures")));
    addAndMakeVisible (label15.get());
    label15->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label15->setBounds (24, 529, 72, 24);

    textButton_Measures.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_Measures.get());
    textButton_Measures->setTooltip (TRANS("How many measures this audio has. Set to 0 for Project Settings."));
    textButton_Measures->setButtonText (String());
    textButton_Measures->addListener (this);
    textButton_Measures->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Measures->setBounds (131, 530, 72, 24);

    label16.reset (new Label ("new label",
                              TRANS("Queued to Stop")));
    addAndMakeVisible (label16.get());
    label16->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label16->setJustificationType (Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label16->setBounds (24, 401, 120, 24);

    textButton_QueuedStopColour.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_QueuedStopColour.get());
    textButton_QueuedStopColour->setButtonText (String());
    textButton_QueuedStopColour->addListener (this);
    textButton_QueuedStopColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_QueuedStopColour->setBounds (151, 402, 53, 24);

    textButton_ImageStop.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_ImageStop.get());
    textButton_ImageStop->setButtonText (TRANS("Image"));
    textButton_ImageStop->addListener (this);
    textButton_ImageStop->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImageStop->setBounds (216, 402, 72, 24);

    toggleButton_LoopedSynced.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_LoopedSynced.get());
    toggleButton_LoopedSynced->setTooltip (TRANS("Starts the audio only when the sequencer clock reaches the start of the measure"));
    toggleButton_LoopedSynced->setButtonText (TRANS("Synced"));
    toggleButton_LoopedSynced->addListener (this);

    toggleButton_LoopedSynced->setBounds (135, 603, 112, 24);

    comboBox_RecordSource.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_RecordSource.get());
    comboBox_RecordSource->setEditableText (false);
    comboBox_RecordSource->setJustificationType (Justification::centredLeft);
    comboBox_RecordSource->setTextWhenNothingSelected (TRANS("Audio Input"));
    comboBox_RecordSource->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_RecordSource->addListener (this);

    comboBox_RecordSource->setBounds (139, 995, 133, 24);

    label18.reset (new Label ("new label",
                              TRANS("Source")));
    addAndMakeVisible (label18.get());
    label18->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label18->setJustificationType (Justification::centredLeft);
    label18->setEditable (false, false, false);
    label18->setColour (TextEditor::textColourId, Colours::black);
    label18->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label18->setBounds (32, 995, 88, 24);

    label19.reset (new Label ("new label",
                              TRANS("Colour")));
    addAndMakeVisible (label19.get());
    label19->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label19->setJustificationType (Justification::centredLeft);
    label19->setEditable (false, false, false);
    label19->setColour (TextEditor::textColourId, Colours::black);
    label19->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label19->setBounds (32, 1074, 55, 25);

    textButton_RecordColour.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_RecordColour.get());
    textButton_RecordColour->setButtonText (String());
    textButton_RecordColour->addListener (this);
    textButton_RecordColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_RecordColour->setBounds (104, 1074, 53, 24);

    textButton_ImageRecord.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_ImageRecord.get());
    textButton_ImageRecord->setButtonText (TRANS("Image"));
    textButton_ImageRecord->addListener (this);
    textButton_ImageRecord->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImageRecord->setBounds (184, 1074, 72, 24);

    comboBox_MouseVolumeType.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_MouseVolumeType.get());
    comboBox_MouseVolumeType->setEditableText (false);
    comboBox_MouseVolumeType->setJustificationType (Justification::centredLeft);
    comboBox_MouseVolumeType->setTextWhenNothingSelected (String());
    comboBox_MouseVolumeType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_MouseVolumeType->addItem (TRANS("Click & Drag"), 1);
    comboBox_MouseVolumeType->addItem (TRANS("Right Click"), 2);
    comboBox_MouseVolumeType->addItem (TRANS("Double Click"), 3);
    comboBox_MouseVolumeType->addListener (this);

    comboBox_MouseVolumeType->setBounds (160, 669, 112, 24);

    comboBox_RecordMouse.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_RecordMouse.get());
    comboBox_RecordMouse->setEditableText (false);
    comboBox_RecordMouse->setJustificationType (Justification::centredLeft);
    comboBox_RecordMouse->setTextWhenNothingSelected (String());
    comboBox_RecordMouse->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_RecordMouse->addItem (TRANS("Click & Drag"), 1);
    comboBox_RecordMouse->addItem (TRANS("Right Click"), 2);
    comboBox_RecordMouse->addItem (TRANS("Double Click"), 3);
    comboBox_RecordMouse->addListener (this);

    comboBox_RecordMouse->setBounds (139, 1035, 133, 24);

    label20.reset (new Label ("new label",
                              TRANS("Mouse")));
    addAndMakeVisible (label20.get());
    label20->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label20->setJustificationType (Justification::centredLeft);
    label20->setEditable (false, false, false);
    label20->setColour (TextEditor::textColourId, Colours::black);
    label20->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label20->setBounds (32, 1035, 88, 24);

    labelFadeState.reset (new Label ("new label",
                                     TRANS("Initial Env. Fade State")));
    addAndMakeVisible (labelFadeState.get());
    labelFadeState->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelFadeState->setJustificationType (Justification::centredLeft);
    labelFadeState->setEditable (false, false, false);
    labelFadeState->setColour (TextEditor::textColourId, Colours::black);
    labelFadeState->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelFadeState->setBounds (24, 102, 152, 25);

    comboBox_FadeState.reset (new ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_FadeState.get());
    comboBox_FadeState->setEditableText (false);
    comboBox_FadeState->setJustificationType (Justification::centred);
    comboBox_FadeState->setTextWhenNothingSelected (String());
    comboBox_FadeState->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_FadeState->addItem (TRANS("Low"), 1);
    comboBox_FadeState->addItem (TRANS("High"), 2);
    comboBox_FadeState->addListener (this);

    comboBox_FadeState->setBounds (188, 102, 100, 24);

    toggleButton_StopOnEnvelopeEnd.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_StopOnEnvelopeEnd.get());
    toggleButton_StopOnEnvelopeEnd->setButtonText (TRANS("Stop on Env. Fade Out"));
    toggleButton_StopOnEnvelopeEnd->addListener (this);

    toggleButton_StopOnEnvelopeEnd->setBounds (24, 136, 192, 24);

    textButton_Volume.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Volume.get());
    textButton_Volume->setButtonText (String());
    textButton_Volume->addListener (this);
    textButton_Volume->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Volume->setBounds (92, 28, 92, 24);

    toggleButton_ColoursToFont.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_ColoursToFont.get());
    toggleButton_ColoursToFont->setTooltip (TRANS("Use the above colours for the object name font instead."));
    toggleButton_ColoursToFont->setButtonText (TRANS("Above Colours To Label"));
    toggleButton_ColoursToFont->addListener (this);

    toggleButton_ColoursToFont->setBounds (24, 438, 200, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 1088);


    //[Constructor] You can add your own custom stuff here..

	setSize(320, 940);

    //[/Constructor]
}

SoundOptions::~SoundOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label2 = nullptr;
    textButton_PlayingColour = nullptr;
    label3 = nullptr;
    textButton_QueuedColour = nullptr;
    label6 = nullptr;
    textButton_Group = nullptr;
    label4 = nullptr;
    textButton_GroupStop = nullptr;
    label5 = nullptr;
    textButton_BackTo = nullptr;
    comboBox_PlaybackType = nullptr;
    label10 = nullptr;
    toggleButton_MultiTrigger = nullptr;
    toggleButton_Looped = nullptr;
    textButton_Filename = nullptr;
    toggleButton_Embedded = nullptr;
    toggleButton_InstantStop = nullptr;
    textButton_ImagePlaying = nullptr;
    textButton_ImageQueued = nullptr;
    label11 = nullptr;
    toggleButton_DragVolume = nullptr;
    textButton_DragVolumeMin = nullptr;
    label12 = nullptr;
    textButton_DragVolumeMax = nullptr;
    label13 = nullptr;
    comboBox_RecordType = nullptr;
    label14 = nullptr;
    label15 = nullptr;
    textButton_Measures = nullptr;
    label16 = nullptr;
    textButton_QueuedStopColour = nullptr;
    textButton_ImageStop = nullptr;
    toggleButton_LoopedSynced = nullptr;
    comboBox_RecordSource = nullptr;
    label18 = nullptr;
    label19 = nullptr;
    textButton_RecordColour = nullptr;
    textButton_ImageRecord = nullptr;
    comboBox_MouseVolumeType = nullptr;
    comboBox_RecordMouse = nullptr;
    label20 = nullptr;
    labelFadeState = nullptr;
    comboBox_FadeState = nullptr;
    toggleButton_StopOnEnvelopeEnd = nullptr;
    textButton_Volume = nullptr;
    toggleButton_ColoursToFont = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SoundOptions::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 7, y = 16, width = 304, height = 152;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 23, y = 944, width = 269, height = 160;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 14, y = 312, width = 288, height = 160;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SoundOptions::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SoundOptions::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	if (processor->selectedObject == nullptr) return;
	WPR44SoundObject* soundObject = (WPR44SoundObject*)processor->selectedObject;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton_PlayingColour.get())
    {
        //[UserButtonCode_textButton_PlayingColour] -- add your button handler code here..

		browseColour(&soundObject->playingColour, textButton_PlayingColour.get());

        //[/UserButtonCode_textButton_PlayingColour]
    }
    else if (buttonThatWasClicked == textButton_QueuedColour.get())
    {
        //[UserButtonCode_textButton_QueuedColour] -- add your button handler code here..

		browseColour(&soundObject->queuedColour, textButton_QueuedColour.get());

        //[/UserButtonCode_textButton_QueuedColour]
    }
    else if (buttonThatWasClicked == textButton_Group.get())
    {
        //[UserButtonCode_textButton_Group] -- add your button handler code here..

		String theValue;
		AskValue("Group Name", "", soundObject->group, "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			soundObject->group = theValue;
			if (soundObject->group.isEmpty()) textButton_Group->setButtonText("None"); else textButton_Group->setButtonText(soundObject->group);
		}

        //[/UserButtonCode_textButton_Group]
    }
    else if (buttonThatWasClicked == textButton_GroupStop.get())
    {
        //[UserButtonCode_textButton_GroupStop] -- add your button handler code here..

		String theValue;
		AskValue("Group Stop Name", "", soundObject->groupStop, "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			soundObject->groupStop = theValue;
			if (soundObject->groupStop.isEmpty()) textButton_GroupStop->setButtonText("None"); else textButton_GroupStop->setButtonText(soundObject->groupStop);
		}

        //[/UserButtonCode_textButton_GroupStop]
    }
    else if (buttonThatWasClicked == textButton_BackTo.get())
    {
        //[UserButtonCode_textButton_BackTo] -- add your button handler code here..

		String theValue;
		AskValue("Group Back To Name", "", soundObject->groupStop, "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			soundObject->groupGoBackTo = theValue;
			if (soundObject->groupGoBackTo.isEmpty()) textButton_BackTo->setButtonText("None"); else textButton_BackTo->setButtonText(soundObject->groupGoBackTo);
		}

        //[/UserButtonCode_textButton_BackTo]
    }
    else if (buttonThatWasClicked == toggleButton_MultiTrigger.get())
    {
        //[UserButtonCode_toggleButton_MultiTrigger] -- add your button handler code here..

		soundObject->multiTrigger = toggleButton_MultiTrigger->getToggleState();

        //[/UserButtonCode_toggleButton_MultiTrigger]
    }
    else if (buttonThatWasClicked == toggleButton_Looped.get())
    {
        //[UserButtonCode_toggleButton_Looped] -- add your button handler code here..

		soundObject->isLooped = toggleButton_Looped->getToggleState();

        //[/UserButtonCode_toggleButton_Looped]
    }
    else if (buttonThatWasClicked == textButton_Filename.get())
    {
        //[UserButtonCode_textButton_Filename] -- add your button handler code here..

		if (soundObject->recordingType != WPR44Object::kRecordingType_None)
		{
			if (ConfirmBox("Disable Audio Recording And Load Sound File", "Are you sure?"))
			{
				soundObject->recordingType = WPR44Object::kRecordingType_None;
				updateValuesFromProcessor();
			}
			else return;
		}
		//
		if (soundObject->soundFilename.isNotEmpty())
		{
			soundObject->soundFilename = String();
			textButton_Filename->setButtonText("Load Audio");
			soundObject->reloadAudio = true;
			processor->loadAudios();
			processor->objectOptionsWindow->repaint();
		}
		else
		{
			String theFilename = processor->loadAudioDialog(soundObject);
			if (theFilename.isNotEmpty()) textButton_Filename->setButtonText(theFilename); else textButton_Filename->setButtonText("Load Audio");
		}

        //[/UserButtonCode_textButton_Filename]
    }
    else if (buttonThatWasClicked == toggleButton_Embedded.get())
    {
        //[UserButtonCode_toggleButton_Embedded] -- add your button handler code here..

		soundObject->embeddedAudio = toggleButton_Embedded->getToggleState();

        //[/UserButtonCode_toggleButton_Embedded]
    }
    else if (buttonThatWasClicked == toggleButton_InstantStop.get())
    {
        //[UserButtonCode_toggleButton_InstantStop] -- add your button handler code here..

		soundObject->instantStop = toggleButton_InstantStop->getToggleState();

        //[/UserButtonCode_toggleButton_InstantStop]
    }
    else if (buttonThatWasClicked == textButton_ImagePlaying.get())
    {
        //[UserButtonCode_textButton_ImagePlaying] -- add your button handler code here..

		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Playing].isNotEmpty())
		{
			processor->selectedObject->imagesFilename[WPR44Object::kImage_Playing] = String();
			processor->selectedObject->images[WPR44Object::kImage_Playing] = nullptr;
			processor->loadImages();
			textButton_ImagePlaying->setButtonText("Image");
			processor->objectOptionsWindow->repaint();
			processor->mainWindow->repaint();
		}
		else
		{
			FileChooser loadFile("Load Playing Image", processor->lastBackImagePath, String("*"));
			if (loadFile.browseForFileToOpen())
			{
				processor->lastBackImagePath = loadFile.getResult().getParentDirectory();
				processor->userSettings->setValue("Image Path", processor->lastBackImagePath.getFullPathName());
				textButton_ImagePlaying->setButtonText("(*)Image");
				processor->selectedObject->imagesFilename[WPR44Object::kImage_Playing] = loadFile.getResult().getFullPathName();
				processor->loadImages();
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_ImagePlaying]
    }
    else if (buttonThatWasClicked == textButton_ImageQueued.get())
    {
        //[UserButtonCode_textButton_ImageQueued] -- add your button handler code here..

		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Queued].isNotEmpty())
		{
			processor->selectedObject->imagesFilename[WPR44Object::kImage_Queued] = String();
			processor->selectedObject->images[WPR44Object::kImage_Queued] = nullptr;
			processor->loadImages();
			textButton_ImageQueued->setButtonText("Image");
			processor->objectOptionsWindow->repaint();
			processor->mainWindow->repaint();
		}
		else
		{
			FileChooser loadFile("Load Queued Image", processor->lastBackImagePath, String("*"));
			if (loadFile.browseForFileToOpen())
			{
				processor->lastBackImagePath = loadFile.getResult().getParentDirectory();
				processor->userSettings->setValue("Image Path", processor->lastBackImagePath.getFullPathName());
				textButton_ImageQueued->setButtonText("(*)Image");
				processor->selectedObject->imagesFilename[WPR44Object::kImage_Queued] = loadFile.getResult().getFullPathName();
				processor->loadImages();
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_ImageQueued]
    }
    else if (buttonThatWasClicked == toggleButton_DragVolume.get())
    {
        //[UserButtonCode_toggleButton_DragVolume] -- add your button handler code here..

		soundObject->mouseDragToVolume = toggleButton_DragVolume->getToggleState();

        //[/UserButtonCode_toggleButton_DragVolume]
    }
    else if (buttonThatWasClicked == textButton_DragVolumeMin.get())
    {
        //[UserButtonCode_textButton_DragVolumeMin] -- add your button handler code here..

		String theValue;
		AskValue("Min Drag Volume in dB", "", Decibels::toString(Decibels::gainToDecibels(soundObject->mouseDragToVolumeMin), 2, -100.0f, false), "(don't add dB to the value)", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty()) soundObject->mouseDragToVolumeMin = Decibels::decibelsToGain(theValue.getFloatValue());
		//
		String dB = Decibels::toString(Decibels::gainToDecibels(soundObject->mouseDragToVolumeMin));
		textButton_DragVolumeMin->setButtonText(dB);

        //[/UserButtonCode_textButton_DragVolumeMin]
    }
    else if (buttonThatWasClicked == textButton_DragVolumeMax.get())
    {
        //[UserButtonCode_textButton_DragVolumeMax] -- add your button handler code here..

		String theValue;
		AskValue("Max Drag Volume in dB", "", Decibels::toString(Decibels::gainToDecibels(soundObject->mouseDragToVolumeMax), 2, -100.0f, false), "(don't add dB to the value)", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty()) soundObject->mouseDragToVolumeMax = Decibels::decibelsToGain(theValue.getFloatValue());
		//
		String dB = Decibels::toString(Decibels::gainToDecibels(soundObject->mouseDragToVolumeMax));
		textButton_DragVolumeMax->setButtonText(dB);

        //[/UserButtonCode_textButton_DragVolumeMax]
    }
    else if (buttonThatWasClicked == textButton_Measures.get())
    {
        //[UserButtonCode_textButton_Measures] -- add your button handler code here..

		String theValue;
		AskValue("Number of measures\n(use 0 for the default global value)", "(four 4/4 beats consists of a single measure)", String(soundObject->measures), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			soundObject->measures = jlimit(0, 1024, theValue.getIntValue());
			if (soundObject->measures <= 0) textButton_Measures->setButtonText("Default"); else textButton_Measures->setButtonText(String(soundObject->measures));
		}

        //[/UserButtonCode_textButton_Measures]
    }
    else if (buttonThatWasClicked == textButton_QueuedStopColour.get())
    {
        //[UserButtonCode_textButton_QueuedStopColour] -- add your button handler code here..

		browseColour(&soundObject->stopColour, textButton_QueuedStopColour.get());

        //[/UserButtonCode_textButton_QueuedStopColour]
    }
    else if (buttonThatWasClicked == textButton_ImageStop.get())
    {
        //[UserButtonCode_textButton_ImageStop] -- add your button handler code here..

		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Stop].isNotEmpty())
		{
			processor->selectedObject->imagesFilename[WPR44Object::kImage_Stop] = String();
			processor->selectedObject->images[WPR44Object::kImage_Stop] = nullptr;
			processor->loadImages();
			textButton_ImageStop->setButtonText("Image");
			processor->objectOptionsWindow->repaint();
			processor->mainWindow->repaint();
		}
		else
		{
			FileChooser loadFile("Load Queued to Stop Image", processor->lastBackImagePath, String("*"));
			if (loadFile.browseForFileToOpen())
			{
				processor->lastBackImagePath = loadFile.getResult().getParentDirectory();
				processor->userSettings->setValue("Image Path", processor->lastBackImagePath.getFullPathName());
				textButton_ImageStop->setButtonText("(*)Image");
				processor->selectedObject->imagesFilename[WPR44Object::kImage_Stop] = loadFile.getResult().getFullPathName();
				processor->loadImages();
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_ImageStop]
    }
    else if (buttonThatWasClicked == toggleButton_LoopedSynced.get())
    {
        //[UserButtonCode_toggleButton_LoopedSynced] -- add your button handler code here..

		soundObject->isLoopedSynced = toggleButton_LoopedSynced->getToggleState();

        //[/UserButtonCode_toggleButton_LoopedSynced]
    }
    else if (buttonThatWasClicked == textButton_RecordColour.get())
    {
        //[UserButtonCode_textButton_RecordColour] -- add your button handler code here..
        //[/UserButtonCode_textButton_RecordColour]
    }
    else if (buttonThatWasClicked == textButton_ImageRecord.get())
    {
        //[UserButtonCode_textButton_ImageRecord] -- add your button handler code here..

		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Recording].isNotEmpty())
		{
			processor->selectedObject->imagesFilename[WPR44Object::kImage_Recording] = String();
			processor->selectedObject->images[WPR44Object::kImage_Recording] = nullptr;
			processor->loadImages();
			textButton_ImageRecord->setButtonText("Image");
			processor->objectOptionsWindow->repaint();
			processor->mainWindow->repaint();
		}
		else
		{
			FileChooser loadFile("Load Recording Image", processor->lastBackImagePath, String("*"));
			if (loadFile.browseForFileToOpen())
			{
				processor->lastBackImagePath = loadFile.getResult().getParentDirectory();
				processor->userSettings->setValue("Image Path", processor->lastBackImagePath.getFullPathName());
				textButton_ImageRecord->setButtonText("(*)Image");
				processor->selectedObject->imagesFilename[WPR44Object::kImage_Recording] = loadFile.getResult().getFullPathName();
				processor->loadImages();
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_ImageRecord]
    }
    else if (buttonThatWasClicked == toggleButton_StopOnEnvelopeEnd.get())
    {
        //[UserButtonCode_toggleButton_StopOnEnvelopeEnd] -- add your button handler code here..

		soundObject->envelopeOutStopSoundOnEnd = toggleButton_StopOnEnvelopeEnd->getToggleState();

        //[/UserButtonCode_toggleButton_StopOnEnvelopeEnd]
    }
    else if (buttonThatWasClicked == textButton_Volume.get())
    {
        //[UserButtonCode_textButton_Volume] -- add your button handler code here..

		String theValue;
		AskValue("Volume in dB", "", Decibels::toString(Decibels::gainToDecibels(soundObject->audioVolume), 2, -100.0f, false), "(don't add dB to the value)", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty()) soundObject->audioVolume = Decibels::decibelsToGain(theValue.getFloatValue());
		//
		String dB = Decibels::toString(Decibels::gainToDecibels(soundObject->audioVolume));
		textButton_Volume->setButtonText(dB);

        //[/UserButtonCode_textButton_Volume]
    }
    else if (buttonThatWasClicked == toggleButton_ColoursToFont.get())
    {
        //[UserButtonCode_toggleButton_ColoursToFont] -- add your button handler code here..

		soundObject->coloursToFont = toggleButton_ColoursToFont->getToggleState();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ColoursToFont]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void SoundOptions::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	if (processor->selectedObject == nullptr) return;
	WPR44SoundObject* soundObject = (WPR44SoundObject*)processor->selectedObject;

    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_PlaybackType.get())
    {
        //[UserComboBoxCode_comboBox_PlaybackType] -- add your combo box handling code here..

		soundObject->playbackType = comboBox_PlaybackType->getSelectedId() - 1;

        //[/UserComboBoxCode_comboBox_PlaybackType]
    }
    else if (comboBoxThatHasChanged == comboBox_RecordType.get())
    {
        //[UserComboBoxCode_comboBox_RecordType] -- add your combo box handling code here..

		soundObject->recordingType = comboBox_RecordType->getSelectedId() - 1;

		soundObject->soundFilename = String();
		if (soundObject->recordingType != WPR44Object::kRecordingType_None) textButton_Filename->setButtonText("Audio Recording Enabled"); else textButton_Filename->setButtonText("Load Audio");
		soundObject->reloadAudio = true;
		processor->loadAudios();
		processor->objectOptionsWindow->repaint();

        //[/UserComboBoxCode_comboBox_RecordType]
    }
    else if (comboBoxThatHasChanged == comboBox_RecordSource.get())
    {
        //[UserComboBoxCode_comboBox_RecordSource] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox_RecordSource]
    }
    else if (comboBoxThatHasChanged == comboBox_MouseVolumeType.get())
    {
        //[UserComboBoxCode_comboBox_MouseVolumeType] -- add your combo box handling code here..

		soundObject->mouseDragToVolumeMouseType = comboBox_MouseVolumeType->getSelectedId() - 1;

        //[/UserComboBoxCode_comboBox_MouseVolumeType]
    }
    else if (comboBoxThatHasChanged == comboBox_RecordMouse.get())
    {
        //[UserComboBoxCode_comboBox_RecordMouse] -- add your combo box handling code here..

		soundObject->recordingMouseType = comboBox_RecordMouse->getSelectedId() - 1;

        //[/UserComboBoxCode_comboBox_RecordMouse]
    }
    else if (comboBoxThatHasChanged == comboBox_FadeState.get())
    {
        //[UserComboBoxCode_comboBox_FadeState] -- add your combo box handling code here..

		if (comboBox_FadeState->getSelectedId() == 1) soundObject->initialFadeState = 0.0f; else soundObject->initialFadeState = 1.0f;

        //[/UserComboBoxCode_comboBox_FadeState]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void SoundOptions::updateValuesFromProcessor()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (processor->selectedObject != nullptr)
	{
		WPR44SoundObject* soundObject = (WPR44SoundObject*)processor->selectedObject;
		//
		textButton_PlayingColour->setColour(TextButton::buttonColourId, soundObject->playingColour);
		textButton_QueuedColour->setColour(TextButton::buttonColourId, soundObject->queuedColour);
		//
		if (soundObject->group.isEmpty()) textButton_Group->setButtonText("None"); else textButton_Group->setButtonText(soundObject->group);
		if (soundObject->groupStop.isEmpty()) textButton_GroupStop->setButtonText("None"); else textButton_GroupStop->setButtonText(soundObject->groupStop);
		if (soundObject->groupGoBackTo.isEmpty()) textButton_BackTo->setButtonText("None"); else textButton_BackTo->setButtonText(soundObject->groupGoBackTo);
		//
		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Playing].isEmpty()) textButton_ImagePlaying->setButtonText("Image"); else textButton_ImagePlaying->setButtonText("(*)Image");
		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Queued].isEmpty()) textButton_ImageQueued->setButtonText("Image"); else textButton_ImageQueued->setButtonText("(*)Image");
		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Stop].isEmpty()) textButton_ImageStop->setButtonText("Image"); else textButton_ImageStop->setButtonText("(*)Image");
		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Recording].isEmpty()) textButton_ImageRecord->setButtonText("Image"); else textButton_ImageRecord->setButtonText("(*)Image");
		//
		comboBox_PlaybackType->setSelectedId(soundObject->playbackType + 1, NotificationType::dontSendNotification);
		comboBox_RecordType->setSelectedId(soundObject->recordingType + 1, NotificationType::dontSendNotification);
		toggleButton_MultiTrigger->setToggleState(soundObject->multiTrigger, NotificationType::dontSendNotification);
		toggleButton_Looped->setToggleState(soundObject->isLooped, NotificationType::dontSendNotification);
		toggleButton_Embedded->setToggleState(soundObject->embeddedAudio, NotificationType::dontSendNotification);
		toggleButton_InstantStop->setToggleState(soundObject->instantStop, NotificationType::dontSendNotification);
		toggleButton_DragVolume->setToggleState(soundObject->mouseDragToVolume, NotificationType::dontSendNotification);
		toggleButton_LoopedSynced->setToggleState(soundObject->isLoopedSynced, NotificationType::dontSendNotification);
		comboBox_MouseVolumeType->setSelectedId(soundObject->mouseDragToVolumeMouseType + 1, NotificationType::dontSendNotification);
		comboBox_RecordMouse->setSelectedId(soundObject->recordingMouseType + 1, NotificationType::dontSendNotification);
		toggleButton_StopOnEnvelopeEnd->setToggleState(soundObject->envelopeOutStopSoundOnEnd, NotificationType::dontSendNotification);
		if (soundObject->initialFadeState > 0.9f) comboBox_FadeState->setSelectedId(2, NotificationType::dontSendNotification); else comboBox_FadeState->setSelectedId(1, NotificationType::dontSendNotification);
		toggleButton_ColoursToFont->setToggleState(soundObject->coloursToFont, NotificationType::dontSendNotification);
		//
		if (soundObject->measures <= 0) textButton_Measures->setButtonText("Default"); else textButton_Measures->setButtonText(String(soundObject->measures));
		//
		String dB = Decibels::toString(Decibels::gainToDecibels(soundObject->audioVolume));
		textButton_Volume->setButtonText(dB);
		//
		dB = Decibels::toString(Decibels::gainToDecibels(soundObject->mouseDragToVolumeMin));
		textButton_DragVolumeMin->setButtonText(dB);
		//
		dB = Decibels::toString(Decibels::gainToDecibels(soundObject->mouseDragToVolumeMax));
		textButton_DragVolumeMax->setButtonText(dB);
		//
		if (soundObject->recordingType == WPR44Object::kRecordingType_None)
		{
			if (soundObject->soundFilename.isEmpty()) textButton_Filename->setButtonText("Load Audio");
			else textButton_Filename->setButtonText(File(soundObject->soundFilename).getFileName());
		}
		else
		{
			textButton_Filename->setButtonText("Audio Recording Enabled");
		}
	}
}

void SoundOptions::changeListenerCallback(ChangeBroadcaster* source)
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (auto* cs = dynamic_cast<ColourSelector*> (source))
	{
		if (edColour != nullptr)
		{
			*edColour = cs->getCurrentColour();
			processor->mainWindow->repaint();
			edButton->setColour(TextButton::buttonColourId, *edColour);
			repaint();
		}
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SoundOptions" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="320" initialHeight="1088">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="7 16 304 152" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="23 944 269 160" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="14 312 288 160" fill="solid: 2a11126f" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="5a80a04003f5f63" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="24 321 112 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Playing Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="62b48a5ff4ebb1d2" memberName="textButton_PlayingColour"
              virtualName="" explicitFocusOrder="0" pos="151 323 53 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="e7f02b1a8c98769d" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="24 361 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Queued Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="7c47ebb2dddbb2d4" memberName="textButton_QueuedColour"
              virtualName="" explicitFocusOrder="0" pos="151 362 53 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="fdfb5910eec3f6cc" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="24 187 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Group" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Font Colour" id="b1e0c26c645f5e99" memberName="textButton_Group"
              virtualName="" explicitFocusOrder="0" pos="131 188 149 24" tooltip="If you set a group and don't enable 'Multi In The Same Group', only one sound will play per group."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="51accd34033b00a3" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="24 227 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Group Stop" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Font Colour" id="99d7aa3447c82058" memberName="textButton_GroupStop"
              virtualName="" explicitFocusOrder="0" pos="131 228 149 24" tooltip="When this object starts playing it will stop all objects with this group name."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="8c25b5b665612721" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="24 268 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back To" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Font Colour" id="19b6b2770920034a" memberName="textButton_BackTo"
              virtualName="" explicitFocusOrder="0" pos="131 269 149 24" tooltip="When selecting this object, it will stop all other objects and after it finishes playing it will play the selectd group."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="c3cba96534f107c7" memberName="comboBox_PlaybackType"
            virtualName="" explicitFocusOrder="0" pos="131 490 133 24" editable="0"
            layout="33" items="Synced&#10;Poly Free" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="8217d615b5215d2b" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="24 490 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Playback Type" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="Show Grid" id="16c752c71e0edd71" memberName="toggleButton_MultiTrigger"
                virtualName="" explicitFocusOrder="0" pos="24 569 200 24" buttonText="Multi In The Same Group"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Show Grid" id="2096be5f44b9332c" memberName="toggleButton_Looped"
                virtualName="" explicitFocusOrder="0" pos="24 603 104 24" buttonText="Is Looped"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="button Font Colour" id="64f53f6154336871" memberName="textButton_Filename"
              virtualName="" explicitFocusOrder="0" pos="16 63 288 24" bgColOff="ff001da8"
              buttonText="Sound File" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Show Grid" id="1cdc4d0ccf79eab8" memberName="toggleButton_Embedded"
                virtualName="" explicitFocusOrder="0" pos="208 29 96 24" tooltip="Include the audio into the host project file. Keep in mind that some hosts has a file limitation for project files."
                buttonText="Embedded" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TOGGLEBUTTON name="Show Grid" id="c3b68a792b58a18a" memberName="toggleButton_InstantStop"
                virtualName="" explicitFocusOrder="0" pos="24 637 150 24" buttonText="Instant Stop"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="button Back Colour" id="600b32191c9cdb9f" memberName="textButton_ImagePlaying"
              virtualName="" explicitFocusOrder="0" pos="216 323 72 24" bgColOff="ff001da8"
              buttonText="Image" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="6d87031b9a61c098" memberName="textButton_ImageQueued"
              virtualName="" explicitFocusOrder="0" pos="216 362 72 24" bgColOff="ff001da8"
              buttonText="Image" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="e4d6075eaa667843" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="24 27 61 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Volume" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="Show Grid" id="f58d060a33a8e783" memberName="toggleButton_DragVolume"
                virtualName="" explicitFocusOrder="0" pos="24 669 128 24" buttonText="Mouse Volume"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="button Back Colour" id="be3202e89c4b76f0" memberName="textButton_DragVolumeMin"
              virtualName="" explicitFocusOrder="0" pos="168 709 92 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="ff2a716919d69e61" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="104 709 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Min Vol" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="4fa41e5cf7fbfdc7" memberName="textButton_DragVolumeMax"
              virtualName="" explicitFocusOrder="0" pos="168 748 92 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="7f28354dd6cf2a4e" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="104 748 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Max Vol" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="9b0694b9dc95aaae" memberName="comboBox_RecordType"
            virtualName="" explicitFocusOrder="0" pos="139 955 133 24" editable="0"
            layout="33" items="None&#10;Continuous&#10;Mix&#10;Replace&#10;PingPong"
            textWhenNonSelected="None" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="f423d5545eb6721f" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="32 955 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Record Type" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="72eac0d0747c71c7" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="24 529 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Measures" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="f3244b6fc87b60ac" memberName="textButton_Measures"
              virtualName="" explicitFocusOrder="0" pos="131 530 72 24" tooltip="How many measures this audio has. Set to 0 for Project Settings."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="da0dc37a7c4e4abe" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="24 401 120 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Queued to Stop" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="a2b8ebb22c72d56b" memberName="textButton_QueuedStopColour"
              virtualName="" explicitFocusOrder="0" pos="151 402 53 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="dbbc196381b79663" memberName="textButton_ImageStop"
              virtualName="" explicitFocusOrder="0" pos="216 402 72 24" bgColOff="ff001da8"
              buttonText="Image" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Show Grid" id="35a6d8c00c730dd9" memberName="toggleButton_LoopedSynced"
                virtualName="" explicitFocusOrder="0" pos="135 603 112 24" tooltip="Starts the audio only when the sequencer clock reaches the start of the measure"
                buttonText="Synced" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <COMBOBOX name="new combo box" id="dca34edc94196edc" memberName="comboBox_RecordSource"
            virtualName="" explicitFocusOrder="0" pos="139 995 133 24" editable="0"
            layout="33" items="" textWhenNonSelected="Audio Input" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="189feaaea86aa546" memberName="label18" virtualName=""
         explicitFocusOrder="0" pos="32 995 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Source" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="ab10f9cd62463d70" memberName="label19" virtualName=""
         explicitFocusOrder="0" pos="32 1074 55 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Colour" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="b3ec02e0f21e2725" memberName="textButton_RecordColour"
              virtualName="" explicitFocusOrder="0" pos="104 1074 53 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="1cf3c727119af780" memberName="textButton_ImageRecord"
              virtualName="" explicitFocusOrder="0" pos="184 1074 72 24" bgColOff="ff001da8"
              buttonText="Image" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="132161ef3ef1f2ce" memberName="comboBox_MouseVolumeType"
            virtualName="" explicitFocusOrder="0" pos="160 669 112 24" editable="0"
            layout="33" items="Click &amp; Drag&#10;Right Click&#10;Double Click"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="819efba61f94424e" memberName="comboBox_RecordMouse"
            virtualName="" explicitFocusOrder="0" pos="139 1035 133 24" editable="0"
            layout="33" items="Click &amp; Drag&#10;Right Click&#10;Double Click"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="f61009cacdc7cf9c" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="32 1035 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mouse" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="3d794cc5ba1f090e" memberName="labelFadeState"
         virtualName="" explicitFocusOrder="0" pos="24 102 152 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial Env. Fade State" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Fonts" id="aa3d460961b27134" memberName="comboBox_FadeState"
            virtualName="" explicitFocusOrder="0" pos="188 102 100 24" editable="0"
            layout="36" items="Low&#10;High" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TOGGLEBUTTON name="Show Grid" id="517020ca5ce6cfa7" memberName="toggleButton_StopOnEnvelopeEnd"
                virtualName="" explicitFocusOrder="0" pos="24 136 192 24" buttonText="Stop on Env. Fade Out"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="button Border Colour" id="38372fa77a626c07" memberName="textButton_Volume"
              virtualName="" explicitFocusOrder="0" pos="92 28 92 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Show Grid" id="44972d2da11ff9a1" memberName="toggleButton_ColoursToFont"
                virtualName="" explicitFocusOrder="0" pos="24 438 200 24" tooltip="Use the above colours for the object name font instead."
                buttonText="Above Colours To Label" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

