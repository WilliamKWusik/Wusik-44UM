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

#include "PluginProcessor.h"
#include "PluginEditor.h"

//[/Headers]

#include "Options.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
WOptions::WOptions ()
{
    //[Constructor_pre] You can add your own custom stuff here..

	getLookAndFeel().setDefaultSansSerifTypefaceName("Verdana");

    //[/Constructor_pre]

    toggleButton_ShowGrid.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_ShowGrid.get());
    toggleButton_ShowGrid->addListener (this);

    toggleButton_ShowGrid->setBounds (35, 283, 150, 24);

    toggleButton_SnapToGrid.reset (new ToggleButton ("Snap To Grid"));
    addAndMakeVisible (toggleButton_SnapToGrid.get());
    toggleButton_SnapToGrid->addListener (this);

    toggleButton_SnapToGrid->setBounds (35, 317, 150, 24);

    label.reset (new Label ("new label",
                            TRANS("Grid Size")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (35, 355, 72, 24);

    label2.reset (new Label ("new label",
                             TRANS("Grid Colour")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (35, 398, 72, 24);

    textButton_Play.reset (new TextButton ("Play"));
    addAndMakeVisible (textButton_Play.get());
    textButton_Play->setTooltip (TRANS("Switch to Play mode. To exit hit Alt+F4 or (if enabled) F5."));
    textButton_Play->addListener (this);
    textButton_Play->setColour (TextButton::buttonColourId, Colour (0xff5c68a4));

    textButton_Play->setBounds (121, 24, 80, 40);

    textButton_CloseEditor.reset (new TextButton ("Close"));
    addAndMakeVisible (textButton_CloseEditor.get());
    textButton_CloseEditor->addListener (this);
    textButton_CloseEditor->setColour (TextButton::buttonColourId, Colour (0xff5c68a4));

    textButton_CloseEditor->setBounds (16, 24, 80, 40);

    comboBox_GridSize.reset (new ComboBox ("combo Grid Size"));
    addAndMakeVisible (comboBox_GridSize.get());
    comboBox_GridSize->setEditableText (false);
    comboBox_GridSize->setJustificationType (Justification::centred);
    comboBox_GridSize->setTextWhenNothingSelected (String());
    comboBox_GridSize->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_GridSize->addItem (TRANS("5"), 1);
    comboBox_GridSize->addItem (TRANS("10"), 2);
    comboBox_GridSize->addItem (TRANS("15"), 3);
    comboBox_GridSize->addItem (TRANS("20"), 4);
    comboBox_GridSize->addItem (TRANS("25"), 5);
    comboBox_GridSize->addItem (TRANS("30"), 6);
    comboBox_GridSize->addItem (TRANS("40"), 7);
    comboBox_GridSize->addItem (TRANS("50"), 8);
    comboBox_GridSize->addItem (TRANS("60"), 9);
    comboBox_GridSize->addItem (TRANS("70"), 10);
    comboBox_GridSize->addItem (TRANS("80"), 11);
    comboBox_GridSize->addItem (TRANS("90"), 12);
    comboBox_GridSize->addItem (TRANS("100"), 13);
    comboBox_GridSize->addItem (TRANS("125"), 14);
    comboBox_GridSize->addItem (TRANS("150"), 15);
    comboBox_GridSize->addItem (TRANS("175"), 16);
    comboBox_GridSize->addItem (TRANS("200"), 17);
    comboBox_GridSize->addItem (TRANS("250"), 18);
    comboBox_GridSize->addItem (TRANS("300"), 19);
    comboBox_GridSize->addItem (TRANS("350"), 20);
    comboBox_GridSize->addItem (TRANS("400"), 21);
    comboBox_GridSize->addListener (this);

    comboBox_GridSize->setBounds (111, 355, 80, 24);

    textButton_GridColour.reset (new TextButton ("button Grid Colour"));
    addAndMakeVisible (textButton_GridColour.get());
    textButton_GridColour->setButtonText (String());
    textButton_GridColour->addListener (this);
    textButton_GridColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_GridColour->setBounds (128, 399, 72, 24);

    label3.reset (new Label ("new label",
                             TRANS("Back Colour")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (35, 437, 80, 24);

    textButton_BackColour.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BackColour.get());
    textButton_BackColour->setButtonText (String());
    textButton_BackColour->addListener (this);
    textButton_BackColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BackColour->setBounds (128, 438, 72, 24);

    label4.reset (new Label ("new label",
                             TRANS("Back Image")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (35, 483, 80, 24);

    textButton_BackImage.reset (new TextButton ("button Back Image"));
    addAndMakeVisible (textButton_BackImage.get());
    textButton_BackImage->setButtonText (TRANS("none"));
    textButton_BackImage->addListener (this);
    textButton_BackImage->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BackImage->setBounds (128, 484, 72, 24);

    label5.reset (new Label ("new label",
                             TRANS("Font")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (35, 699, 72, 24);

    comboBox_Fonts.reset (new ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_Fonts.get());
    comboBox_Fonts->setEditableText (false);
    comboBox_Fonts->setJustificationType (Justification::centred);
    comboBox_Fonts->setTextWhenNothingSelected (String());
    comboBox_Fonts->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Fonts->addListener (this);

    comboBox_Fonts->setBounds (111, 699, 140, 24);

    label6.reset (new Label ("Screen",
                             TRANS("Screen")));
    addAndMakeVisible (label6.get());
    label6->setTooltip (TRANS("You have up to 4 screens to switch to. When you switch to a different screen the audio from the previous screen will not stop."));
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (144, 145, 64, 24);

    textButtonScreenA.reset (new TextButton ("Screen A"));
    addAndMakeVisible (textButtonScreenA.get());
    textButtonScreenA->setButtonText (TRANS("A"));
    textButtonScreenA->addListener (this);
    textButtonScreenA->setColour (TextButton::buttonColourId, Colour (0xff4d33e6));

    textButtonScreenA->setBounds (32, 178, 56, 32);

    textButtonScreenB.reset (new TextButton ("Screen B"));
    addAndMakeVisible (textButtonScreenB.get());
    textButtonScreenB->setButtonText (TRANS("B"));
    textButtonScreenB->addListener (this);
    textButtonScreenB->setColour (TextButton::buttonColourId, Colour (0xff4d33e6));

    textButtonScreenB->setBounds (104, 178, 56, 32);

    textButtonScreenC.reset (new TextButton ("Screen C"));
    addAndMakeVisible (textButtonScreenC.get());
    textButtonScreenC->setButtonText (TRANS("C"));
    textButtonScreenC->addListener (this);
    textButtonScreenC->setColour (TextButton::buttonColourId, Colour (0xff4d33e6));

    textButtonScreenC->setBounds (176, 178, 56, 32);

    textButtonScreenD.reset (new TextButton ("Screen D"));
    addAndMakeVisible (textButtonScreenD.get());
    textButtonScreenD->setButtonText (TRANS("D"));
    textButtonScreenD->addListener (this);
    textButtonScreenD->setColour (TextButton::buttonColourId, Colour (0xff4d33e6));

    textButtonScreenD->setBounds (248, 178, 56, 32);

    toggleButton_InternalClock.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_InternalClock.get());
    toggleButton_InternalClock->setTooltip (TRANS("Internal clock, otherwise it uses the host/daw clock settings, but it won\'t follow the external sequencer transport, just the tempo (BPM)"));
    toggleButton_InternalClock->addListener (this);

    toggleButton_InternalClock->setBounds (41, 824, 141, 24);

    label7.reset (new Label ("new label",
                             TRANS("BPM")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (41, 792, 45, 24);

    label8.reset (new Label ("new label",
                             TRANS("Measures")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (174, 792, 72, 24);

    textButton_BPM.reset (new TextButton ("button BPM"));
    addAndMakeVisible (textButton_BPM.get());
    textButton_BPM->setTooltip (TRANS("EXT = External Clock Source. In this case it will use the host/daw BPM settings, but it won\'t follow the external transport."));
    textButton_BPM->setButtonText (TRANS("EXT"));
    textButton_BPM->addListener (this);
    textButton_BPM->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BPM->setBounds (88, 792, 72, 24);

    toggleButton_AutoPlay.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_AutoPlay.get());
    toggleButton_AutoPlay->setButtonText (TRANS("Auto Play Audio On Load"));
    toggleButton_AutoPlay->addListener (this);

    toggleButton_AutoPlay->setBounds (35, 862, 229, 24);

    toggleButton_ImageStretch.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_ImageStretch.get());
    toggleButton_ImageStretch->setButtonText (TRANS("Stretch"));
    toggleButton_ImageStretch->addListener (this);

    toggleButton_ImageStretch->setBounds (215, 484, 81, 24);

    label10.reset (new Label ("new label",
                              TRANS("Flash Colour")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (35, 615, 80, 24);

    textButton_BeatFlash.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlash.get());
    textButton_BeatFlash->setTooltip (TRANS("2, 3 and 4 beats colour. This will flash using the decay period on the right (ms)"));
    textButton_BeatFlash->setButtonText (String());
    textButton_BeatFlash->addListener (this);
    textButton_BeatFlash->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BeatFlash->setBounds (128, 616, 72, 24);

    toggleButton_AutoStart.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_AutoStart.get());
    toggleButton_AutoStart->setTooltip (TRANS("When selecting any audio object the sequencer will start right away"));
    toggleButton_AutoStart->setButtonText (TRANS("Auto Start Clock"));
    toggleButton_AutoStart->addListener (this);

    toggleButton_AutoStart->setBounds (35, 896, 229, 24);

    textButton_BeatFlashDecay.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlashDecay.get());
    textButton_BeatFlashDecay->setTooltip (TRANS("For how long the colour should stay in ms."));
    textButton_BeatFlashDecay->setButtonText (String());
    textButton_BeatFlashDecay->addListener (this);
    textButton_BeatFlashDecay->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BeatFlashDecay->setBounds (274, 616, 38, 24);

    label11.reset (new Label ("new label",
                              TRANS("Decay (ms)")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (208, 615, 64, 24);

    textButton_ResetAll.reset (new TextButton ("Reset"));
    addAndMakeVisible (textButton_ResetAll.get());
    textButton_ResetAll->setTooltip (TRANS("Remove all objects."));
    textButton_ResetAll->addListener (this);
    textButton_ResetAll->setColour (TextButton::buttonColourId, Colour (0xff5c68a4));

    textButton_ResetAll->setBounds (224, 24, 80, 40);

    textButton_Measures.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_Measures.get());
    textButton_Measures->setTooltip (TRANS("How many measures the project should use. Any loaded audio must be equal or less than this setting. Keep in mind that 1 measure is 4 beats or 16 steps on a regular sequencer."));
    textButton_Measures->setButtonText (String());
    textButton_Measures->addListener (this);
    textButton_Measures->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Measures->setBounds (252, 792, 58, 24);

    label9.reset (new Label ("new label",
                             TRANS("First Beat Colour")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (35, 656, 93, 24);

    label12.reset (new Label ("new label",
                              TRANS("Measure")));
    addAndMakeVisible (label12.get());
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label12->setBounds (208, 656, 48, 24);

    textButton_BeatFlashMeasure.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlashMeasure.get());
    textButton_BeatFlashMeasure->setTooltip (TRANS("The colour for the first measure flash. This will be used on Beat #1 when the sequencer reaches the start of each measure."));
    textButton_BeatFlashMeasure->setButtonText (String());
    textButton_BeatFlashMeasure->addListener (this);
    textButton_BeatFlashMeasure->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BeatFlashMeasure->setBounds (259, 657, 53, 24);

    textButton_BeatFlashFirst.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlashFirst.get());
    textButton_BeatFlashFirst->setTooltip (TRANS("The first beat colour. Beat #1"));
    textButton_BeatFlashFirst->setButtonText (String());
    textButton_BeatFlashFirst->addListener (this);
    textButton_BeatFlashFirst->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BeatFlashFirst->setBounds (128, 657, 72, 24);

    toggleButton_DisableF5.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_DisableF5.get());
    toggleButton_DisableF5->setTooltip (TRANS("Disable the F5 key. It switches from Play to Edit mode directly."));
    toggleButton_DisableF5->setButtonText (TRANS("Disable F5 Play/Edit"));
    toggleButton_DisableF5->addListener (this);

    toggleButton_DisableF5->setBounds (35, 930, 229, 24);

    label13.reset (new Label ("new label",
                              TRANS("Templates")));
    addAndMakeVisible (label13.get());
    label13->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label13->setBounds (35, 242, 72, 24);

    comboBox_Templates.reset (new ComboBox ("combo Grid Size"));
    addAndMakeVisible (comboBox_Templates.get());
    comboBox_Templates->setEditableText (false);
    comboBox_Templates->setJustificationType (Justification::centred);
    comboBox_Templates->setTextWhenNothingSelected (TRANS("None"));
    comboBox_Templates->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Templates->addListener (this);

    comboBox_Templates->setBounds (111, 242, 185, 24);

    textButton_Export.reset (new TextButton ("Close Editor"));
    addAndMakeVisible (textButton_Export.get());
    textButton_Export->setTooltip (TRANS("Save everything into a single file"));
    textButton_Export->setButtonText (TRANS("Export"));
    textButton_Export->addListener (this);
    textButton_Export->setColour (TextButton::buttonColourId, Colour (0xff5c68a4));

    textButton_Export->setBounds (119, 91, 80, 24);

    textButton_Import.reset (new TextButton ("Close Editor"));
    addAndMakeVisible (textButton_Import.get());
    textButton_Import->setButtonText (TRANS("Import"));
    textButton_Import->addListener (this);
    textButton_Import->setColour (TextButton::buttonColourId, Colour (0xff5c68a4));

    textButton_Import->setBounds (207, 91, 80, 24);

    label14.reset (new Label ("new label",
                              TRANS("Project")));
    addAndMakeVisible (label14.get());
    label14->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label14->setBounds (42, 91, 80, 24);

    labelFadeState.reset (new Label ("new label",
                                     TRANS("Initial Envelope")));
    addAndMakeVisible (labelFadeState.get());
    labelFadeState->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelFadeState->setJustificationType (Justification::centredLeft);
    labelFadeState->setEditable (false, false, false);
    labelFadeState->setColour (TextEditor::textColourId, Colours::black);
    labelFadeState->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelFadeState->setBounds (35, 742, 117, 25);

    comboBox_EnvelopeState.reset (new ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_EnvelopeState.get());
    comboBox_EnvelopeState->setTooltip (TRANS("The master envelope status when starting the project. Low is Silent and High is Maximum Volume. This can be changed using a button action such as Fade In or Out."));
    comboBox_EnvelopeState->setEditableText (false);
    comboBox_EnvelopeState->setJustificationType (Justification::centred);
    comboBox_EnvelopeState->setTextWhenNothingSelected (String());
    comboBox_EnvelopeState->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_EnvelopeState->addItem (TRANS("Low"), 1);
    comboBox_EnvelopeState->addItem (TRANS("High"), 2);
    comboBox_EnvelopeState->addListener (this);

    comboBox_EnvelopeState->setBounds (159, 742, 103, 24);

    label15.reset (new Label ("new label",
                              TRANS("Scale")));
    addAndMakeVisible (label15.get());
    label15->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label15->setBounds (35, 523, 80, 24);

    textButton_BackImageScale.reset (new TextButton ("button Back Image"));
    addAndMakeVisible (textButton_BackImageScale.get());
    textButton_BackImageScale->setTooltip (TRANS("1.0 is original, 2.0 is double, 0.5 is half and so on."));
    textButton_BackImageScale->setButtonText (String());
    textButton_BackImageScale->addListener (this);
    textButton_BackImageScale->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BackImageScale->setBounds (128, 524, 72, 24);

    label16.reset (new Label ("new label",
                              TRANS("Master Volume")));
    addAndMakeVisible (label16.get());
    label16->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label16->setJustificationType (Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label16->setBounds (35, 968, 104, 25);

    textButton_Volume.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Volume.get());
    textButton_Volume->setButtonText (String());
    textButton_Volume->addListener (this);
    textButton_Volume->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Volume->setBounds (143, 969, 92, 24);

    toggleButton_VolumeAuto.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_VolumeAuto.get());
    toggleButton_VolumeAuto->setTooltip (TRANS("This will lower the master volume during the playback. And won\'t raise back up. So it\'s not a limiter."));
    toggleButton_VolumeAuto->setButtonText (TRANS("Auto"));
    toggleButton_VolumeAuto->addListener (this);

    toggleButton_VolumeAuto->setBounds (252, 969, 76, 24);

    label17.reset (new Label ("new label",
                              TRANS("Transparency")));
    addAndMakeVisible (label17.get());
    label17->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label17->setJustificationType (Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label17->setBounds (35, 564, 101, 25);

    textButton_ImageAlpha.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_ImageAlpha.get());
    textButton_ImageAlpha->setTooltip (TRANS("0.0 is none (fully opaque) and 1.0 is fully transparent"));
    textButton_ImageAlpha->setButtonText (String());
    textButton_ImageAlpha->addListener (this);
    textButton_ImageAlpha->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImageAlpha->setBounds (145, 566, 55, 24);

    toggleButton_Fullscreen.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_Fullscreen.get());
    toggleButton_Fullscreen->setButtonText (TRANS("Fullscreen"));
    toggleButton_Fullscreen->addListener (this);

    toggleButton_Fullscreen->setBounds (184, 283, 112, 24);


    //[UserPreSize]

	fontsArray = Font::findAllTypefaceNames();

	ARRAY_Iterator(fontsArray)
	{
		comboBox_Fonts->addItem(fontsArray[index], index + 1);
	}


	textButtonScreenA->setToggleState(false, NotificationType::dontSendNotification);
	textButtonScreenB->setToggleState(false, NotificationType::dontSendNotification);
	textButtonScreenC->setToggleState(false, NotificationType::dontSendNotification);
	textButtonScreenC->setToggleState(false, NotificationType::dontSendNotification);

    //[/UserPreSize]

    setSize (360, 1020);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

WOptions::~WOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    toggleButton_ShowGrid = nullptr;
    toggleButton_SnapToGrid = nullptr;
    label = nullptr;
    label2 = nullptr;
    textButton_Play = nullptr;
    textButton_CloseEditor = nullptr;
    comboBox_GridSize = nullptr;
    textButton_GridColour = nullptr;
    label3 = nullptr;
    textButton_BackColour = nullptr;
    label4 = nullptr;
    textButton_BackImage = nullptr;
    label5 = nullptr;
    comboBox_Fonts = nullptr;
    label6 = nullptr;
    textButtonScreenA = nullptr;
    textButtonScreenB = nullptr;
    textButtonScreenC = nullptr;
    textButtonScreenD = nullptr;
    toggleButton_InternalClock = nullptr;
    label7 = nullptr;
    label8 = nullptr;
    textButton_BPM = nullptr;
    toggleButton_AutoPlay = nullptr;
    toggleButton_ImageStretch = nullptr;
    label10 = nullptr;
    textButton_BeatFlash = nullptr;
    toggleButton_AutoStart = nullptr;
    textButton_BeatFlashDecay = nullptr;
    label11 = nullptr;
    textButton_ResetAll = nullptr;
    textButton_Measures = nullptr;
    label9 = nullptr;
    label12 = nullptr;
    textButton_BeatFlashMeasure = nullptr;
    textButton_BeatFlashFirst = nullptr;
    toggleButton_DisableF5 = nullptr;
    label13 = nullptr;
    comboBox_Templates = nullptr;
    textButton_Export = nullptr;
    textButton_Import = nullptr;
    label14 = nullptr;
    labelFadeState = nullptr;
    comboBox_EnvelopeState = nullptr;
    label15 = nullptr;
    textButton_BackImageScale = nullptr;
    label16 = nullptr;
    textButton_Volume = nullptr;
    toggleButton_VolumeAuto = nullptr;
    label17 = nullptr;
    textButton_ImageAlpha = nullptr;
    toggleButton_Fullscreen = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WOptions::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 18, y = 136, width = 304, height = 88;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 24, y = 80, width = 278, height = 47;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 30, y = 472, width = 273, height = 128;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 32, y = 784, width = 288, height = 72;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void WOptions::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void WOptions::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton_ShowGrid.get())
    {
        //[UserButtonCode_toggleButton_ShowGrid] -- add your button handler code here..

		processor->showGrid = toggleButton_ShowGrid->getToggleState();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ShowGrid]
    }
    else if (buttonThatWasClicked == toggleButton_SnapToGrid.get())
    {
        //[UserButtonCode_toggleButton_SnapToGrid] -- add your button handler code here..

		processor->snapToGrid = toggleButton_SnapToGrid->getToggleState();

        //[/UserButtonCode_toggleButton_SnapToGrid]
    }
    else if (buttonThatWasClicked == textButton_Play.get())
    {
        //[UserButtonCode_textButton_Play] -- add your button handler code here..

		processor->switchInterfaces = true;

        //[/UserButtonCode_textButton_Play]
    }
    else if (buttonThatWasClicked == textButton_CloseEditor.get())
    {
        //[UserButtonCode_textButton_CloseEditor] -- add your button handler code here..

		processor->mainWindow->closeButtonPressed();
		processor->sequencerClock.stop();
		setVisible(false);
		return;

        //[/UserButtonCode_textButton_CloseEditor]
    }
    else if (buttonThatWasClicked == textButton_GridColour.get())
    {
        //[UserButtonCode_textButton_GridColour] -- add your button handler code here..

		browseColour(&processor->gridColour, textButton_GridColour.get());

        //[/UserButtonCode_textButton_GridColour]
    }
    else if (buttonThatWasClicked == textButton_BackColour.get())
    {
        //[UserButtonCode_textButton_BackColour] -- add your button handler code here..

		browseColour(&processor->backColour, textButton_BackColour.get());

        //[/UserButtonCode_textButton_BackColour]
    }
    else if (buttonThatWasClicked == textButton_BackImage.get())
    {
        //[UserButtonCode_textButton_BackImage] -- add your button handler code here..

		if (processor->backImage.existsAsFile())
		{
			textButton_BackImage->setButtonText("None");
			processor->backImage = File();
			processor->backgroundImage = Image();
			processor->mainWindow->repaint();
		}
		else
		{
			FileChooser loadFile("Load Background Image", processor->lastBackImagePath, String("*"));
			if (loadFile.browseForFileToOpen())
			{
				processor->lastBackImagePath = loadFile.getResult().getParentDirectory().getFullPathName();
				processor->userSettings->setValue("Back Image Path", processor->lastBackImagePath.getFullPathName());
				processor->backImage = loadFile.getResult();
				processor->loadBackgroundImage();
				textButton_BackImage->setButtonText("Loaded");
				processor->backColour = processor->backColour.withAlpha(0.20f);
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_BackImage]
    }
    else if (buttonThatWasClicked == textButtonScreenA.get())
    {
        //[UserButtonCode_textButtonScreenA] -- add your button handler code here..

		processor->showingScreen = 0;
		updateValuesFromProcessor();
		((EditCompo*)processor->mainWindow->getContentComponent())->updateObjects();
		processor->mainWindow->repaint();

        //[/UserButtonCode_textButtonScreenA]
    }
    else if (buttonThatWasClicked == textButtonScreenB.get())
    {
        //[UserButtonCode_textButtonScreenB] -- add your button handler code here..

		processor->showingScreen = 1;
		updateValuesFromProcessor();
		((EditCompo*)processor->mainWindow->getContentComponent())->updateObjects();
		processor->mainWindow->repaint();

        //[/UserButtonCode_textButtonScreenB]
    }
    else if (buttonThatWasClicked == textButtonScreenC.get())
    {
        //[UserButtonCode_textButtonScreenC] -- add your button handler code here..

		processor->showingScreen = 2;
		updateValuesFromProcessor();
		((EditCompo*)processor->mainWindow->getContentComponent())->updateObjects();
		processor->mainWindow->repaint();

        //[/UserButtonCode_textButtonScreenC]
    }
    else if (buttonThatWasClicked == textButtonScreenD.get())
    {
        //[UserButtonCode_textButtonScreenD] -- add your button handler code here..

		processor->showingScreen = 3;
		updateValuesFromProcessor();
		((EditCompo*)processor->mainWindow->getContentComponent())->updateObjects();
		processor->mainWindow->repaint();

        //[/UserButtonCode_textButtonScreenD]
    }
    else if (buttonThatWasClicked == toggleButton_InternalClock.get())
    {
        //[UserButtonCode_toggleButton_InternalClock] -- add your button handler code here..

		processor->internalClock = toggleButton_InternalClock->getToggleState();
		updateValuesFromProcessor();

        //[/UserButtonCode_toggleButton_InternalClock]
    }
    else if (buttonThatWasClicked == textButton_BPM.get())
    {
        //[UserButtonCode_textButton_BPM] -- add your button handler code here..

		String theValue;
		AskValue("Internal BPM", "", String(processor->internalBPM), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->internalBPM = theValue.getIntValue();
			if (processor->internalClock) textButton_BPM->setButtonText(String(processor->internalBPM)); else textButton_BPM->setButtonText("EXT");
		}

        //[/UserButtonCode_textButton_BPM]
    }
    else if (buttonThatWasClicked == toggleButton_AutoPlay.get())
    {
        //[UserButtonCode_toggleButton_AutoPlay] -- add your button handler code here..

		processor->autoPlayAudioOnLoad = toggleButton_AutoPlay->getToggleState();

        //[/UserButtonCode_toggleButton_AutoPlay]
    }
    else if (buttonThatWasClicked == toggleButton_ImageStretch.get())
    {
        //[UserButtonCode_toggleButton_ImageStretch] -- add your button handler code here..

		processor->backgroundImageStretch = toggleButton_ImageStretch->getToggleState();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ImageStretch]
    }
    else if (buttonThatWasClicked == textButton_BeatFlash.get())
    {
        //[UserButtonCode_textButton_BeatFlash] -- add your button handler code here..

		browseColour(&processor->beatFlashColour, textButton_BeatFlash.get());

        //[/UserButtonCode_textButton_BeatFlash]
    }
    else if (buttonThatWasClicked == toggleButton_AutoStart.get())
    {
        //[UserButtonCode_toggleButton_AutoStart] -- add your button handler code here..

		processor->autoStartClock = toggleButton_AutoStart->getToggleState();

        //[/UserButtonCode_toggleButton_AutoStart]
    }
    else if (buttonThatWasClicked == textButton_BeatFlashDecay.get())
    {
        //[UserButtonCode_textButton_BeatFlashDecay] -- add your button handler code here..

		String theValue;
		AskValue("Beat Flash Decay in ms", "", String(processor->beatFlashDecayMS), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->beatFlashDecayMS = theValue.getIntValue();
			textButton_BeatFlashDecay->setButtonText(String(processor->beatFlashDecayMS));
		}

        //[/UserButtonCode_textButton_BeatFlashDecay]
    }
    else if (buttonThatWasClicked == textButton_ResetAll.get())
    {
        //[UserButtonCode_textButton_ResetAll] -- add your button handler code here..

		if (ConfirmBox("Delete All Objects", "Are you sure?"))
		{
			processor->stopAllSounds = true;
			if (processor->objectOptionsWindow != nullptr) processor->objectOptionsWindow->setVisible(false);
			if (processor->imageWindow != nullptr) processor->imageWindow->setVisible(false);
			EditCompo* edCompo = (EditCompo*)processor->mainWindow->getContentComponent();
			//
			while(edCompo->dasButtons.size() > 0)
			{
				removeChildComponent(edCompo->dasButtons.getLast());
				edCompo->dasButtons.getLast()->removeListener(edCompo);
				edCompo->dasButtons.removeLast();
			}
			//
			processor->deleteAllObjects = true;
			processor->mainWindow->repaint();
			return;
		}

        //[/UserButtonCode_textButton_ResetAll]
    }
    else if (buttonThatWasClicked == textButton_Measures.get())
    {
        //[UserButtonCode_textButton_Measures] -- add your button handler code here..

		String theValue;
		AskValue("Global number of measures", "(four 4/4 beats consists of a single measure)", String(processor->numberOfMeasures), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->numberOfMeasures = jlimit(1, 1024, theValue.getIntValue());
			textButton_Measures->setButtonText(String(processor->numberOfMeasures));
		}

        //[/UserButtonCode_textButton_Measures]
    }
    else if (buttonThatWasClicked == textButton_BeatFlashMeasure.get())
    {
        //[UserButtonCode_textButton_BeatFlashMeasure] -- add your button handler code here..

		browseColour(&processor->beatFlashFirstMeasureColour, textButton_BeatFlashMeasure.get());

        //[/UserButtonCode_textButton_BeatFlashMeasure]
    }
    else if (buttonThatWasClicked == textButton_BeatFlashFirst.get())
    {
        //[UserButtonCode_textButton_BeatFlashFirst] -- add your button handler code here..

		browseColour(&processor->beatFlashFirstBeatColour, textButton_BeatFlashFirst.get());

        //[/UserButtonCode_textButton_BeatFlashFirst]
    }
    else if (buttonThatWasClicked == toggleButton_DisableF5.get())
    {
        //[UserButtonCode_toggleButton_DisableF5] -- add your button handler code here..

		processor->disableF5SwitchKey = toggleButton_DisableF5->getToggleState();

        //[/UserButtonCode_toggleButton_DisableF5]
    }
    else if (buttonThatWasClicked == textButton_Export.get())
    {
        //[UserButtonCode_textButton_Export] -- add your button handler code here..

		#if WDEMONSTRATION_VERSION
			WCHEKCDEMOMESSAGE;
		#else
			FileChooser saveFile("Export Everything to a File", processor->dataPath + "Projects Exported", "*.WPR44");
			if (saveFile.browseForFileToSave(true))
			{
				MemoryBlock xdata;
				processor->getStateInformation(xdata);
				saveFile.getResult().replaceWithData(xdata.getData(), xdata.getSize());
			}
		#endif

        //[/UserButtonCode_textButton_Export]
    }
    else if (buttonThatWasClicked == textButton_Import.get())
    {
        //[UserButtonCode_textButton_Import] -- add your button handler code here..

		#if WDEMONSTRATION_VERSION
			WCHEKCDEMOMESSAGE;
		#else
			FileChooser loadFile("Import a File", processor->dataPath + "Projects Exported", String("*.WPR44"));
			if (loadFile.browseForFileToOpen())
			{
				MemoryBlock xdata;
				loadFile.getResult().loadFileAsData(xdata);
				processor->setStateInformation(xdata.getData(), xdata.getSize());
			}
		#endif

        //[/UserButtonCode_textButton_Import]
    }
    else if (buttonThatWasClicked == textButton_BackImageScale.get())
    {
        //[UserButtonCode_textButton_BackImageScale] -- add your button handler code here..

		String theValue;
		AskValue("Image Scale", "(1.0 is the default size)", String(processor->backImageScale), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->backImageScale = theValue.getFloatValue();
			textButton_BackImageScale->setButtonText(String(processor->backImageScale, 2));
			processor->mainWindow->repaint();
		}
        //[/UserButtonCode_textButton_BackImageScale]
    }
    else if (buttonThatWasClicked == textButton_Volume.get())
    {
        //[UserButtonCode_textButton_Volume] -- add your button handler code here..

		String theValue;
		AskValue("Master Volume in dB", "", Decibels::toString(Decibels::gainToDecibels(processor->masterVolume), 2, -100.0f, false), "(don't add dB to the value)", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty()) processor->masterVolume = Decibels::decibelsToGain(theValue.getFloatValue());
		//
		String dB = Decibels::toString(Decibels::gainToDecibels(processor->masterVolume));
		textButton_Volume->setButtonText(dB);

        //[/UserButtonCode_textButton_Volume]
    }
    else if (buttonThatWasClicked == toggleButton_VolumeAuto.get())
    {
        //[UserButtonCode_toggleButton_VolumeAuto] -- add your button handler code here..

		processor->masterVolumeAutoLower = toggleButton_VolumeAuto->getToggleState();

        //[/UserButtonCode_toggleButton_VolumeAuto]
    }
    else if (buttonThatWasClicked == textButton_ImageAlpha.get())
    {
        //[UserButtonCode_textButton_ImageAlpha] -- add your button handler code here..

		String theValue;
		AskValue("Background Transparency", "", String(processor->backTransparency, 2), "(0.0f is none (fully opaque) and 1.0 is fully transparent)", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->backTransparency = theValue.getFloatValue();
			if (processor->backTransparency == 0.0f) textButton_ImageAlpha->setButtonText("Off"); else textButton_ImageAlpha->setButtonText(String(processor->backTransparency, 2));
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_ImageAlpha]
    }
    else if (buttonThatWasClicked == toggleButton_Fullscreen.get())
    {
        //[UserButtonCode_toggleButton_Fullscreen] -- add your button handler code here..

		processor->fullscreenMode = toggleButton_Fullscreen->getToggleState();
		processor->changeScreenMode();
		//
		if (!processor->fullscreenMode)
		{
			processor->lastMainWindowSize = Rectangle<int>();
			processor->mainWindow->setBounds(200, 200, Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() / 2, Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2);
		}

        //[/UserButtonCode_toggleButton_Fullscreen]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void WOptions::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_GridSize.get())
    {
        //[UserComboBoxCode_comboBox_GridSize] -- add your combo box handling code here..

		int gridSize = comboBox_GridSize->getSelectedId();
		if (gridSize == 1) processor->gridSize = 5;
		else if (gridSize == 2) processor->gridSize = 10;
		else if (gridSize == 3) processor->gridSize = 15;
		else if (gridSize == 4) processor->gridSize = 20;
		else if (gridSize == 5) processor->gridSize = 25;
		else if (gridSize == 6) processor->gridSize = 30;
		else if (gridSize == 7) processor->gridSize = 40;
		else if (gridSize == 8) processor->gridSize = 50;
		else if (gridSize == 9) processor->gridSize = 60;
		else if (gridSize == 10) processor->gridSize = 70;
		else if (gridSize == 11) processor->gridSize = 80;
		else if (gridSize == 12) processor->gridSize = 90;
		else if (gridSize == 13) processor->gridSize = 100;
		else if (gridSize == 14) processor->gridSize = 125;
		else if (gridSize == 15) processor->gridSize = 150;
		else if (gridSize == 16) processor->gridSize = 175;
		else if (gridSize == 17) processor->gridSize = 200;
		else if (gridSize == 18) processor->gridSize = 250;
		else if (gridSize == 19) processor->gridSize = 300;
		else if (gridSize == 20) processor->gridSize = 350;
		else if (gridSize == 21) processor->gridSize = 400;

		processor->mainWindow->repaint();

        //[/UserComboBoxCode_comboBox_GridSize]
    }
    else if (comboBoxThatHasChanged == comboBox_Fonts.get())
    {
        //[UserComboBoxCode_comboBox_Fonts] -- add your combo box handling code here..

		processor->globalFontName = fontsArray[comboBox_Fonts->getSelectedId() - 1];
		processor->globalFont = Font(processor->globalFontName, 32.0f, 0);
		processor->mainWindow->repaint();

        //[/UserComboBoxCode_comboBox_Fonts]
    }
    else if (comboBoxThatHasChanged == comboBox_Templates.get())
    {
        //[UserComboBoxCode_comboBox_Templates] -- add your combo box handling code here..

		int iD = comboBox_Templates->getSelectedId();
		//
		if (iD == 1) // Save //
		{
			FileChooser saveFile("Save Template", processor->dataPath + "Templates", String("*.WPR44OptionsTemplate"));
			if (saveFile.browseForFileToSave(true))
			{
				MemoryBlock destData;
				MemoryOutputStream dataStream(destData, false);
				processor->getMainSettings(dataStream, true);
				dataStream.flush();
				saveFile.getResult().replaceWithData(destData.getData(), destData.getSize());
				//
				processor->selectedTemplate = saveFile.getResult().getFileNameWithoutExtension();
			}
		}
		else if (iD == 2) // Delete //
		{
			if (ConfirmBox("Delete Template", "Are you sure?"))
			{
				File(processor->dataPath + "Templates" + File::getSeparatorString() + processor->selectedTemplate + ".WPR44OptionsTemplate").deleteFile();
				processor->selectedTemplate = String();
			}
		}
		else if (iD >= 3) // Load Options Template //
		{
			processor->selectedTemplate = comboBox_Templates->getText();
			MemoryBlock xdata;
			File(processor->dataPath + "Templates" + File::getSeparatorString() + processor->selectedTemplate + ".WPR44OptionsTemplate").loadFileAsData(xdata);
			MemoryInputStream dataStream(xdata, false);
			processor->putMainSettings(dataStream, true);
			processor->loadBackgroundImage();
			processor->loadImages();
			processor->mainWindow->repaint();
			repaint();
		}
		//
		updateValuesFromProcessor();

        //[/UserComboBoxCode_comboBox_Templates]
    }
    else if (comboBoxThatHasChanged == comboBox_EnvelopeState.get())
    {
        //[UserComboBoxCode_comboBox_EnvelopeState] -- add your combo box handling code here..

		if (comboBox_EnvelopeState->getSelectedId() == 1) processor->initialMasterEnvelopeState = 0.0f; else processor->initialMasterEnvelopeState = 1.0f;
		processor->masterEnvelopeOutput = processor->initialMasterEnvelopeState;

        //[/UserComboBoxCode_comboBox_EnvelopeState]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


void WOptions::changeListenerCallback(ChangeBroadcaster* source)
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

bool OptionsWindow::keyPressed(const KeyPress &key)
{
	if (key.getKeyCode() == KeyPress::F4Key && key.getModifiers().isAltDown())
	{
		((WusikPr44AudioProcessor*)processor)->optionsWindow->closeButtonPressed();
		if (tooltipWindow->isVisible()) tooltipWindow->closeButtonPressed();
		return true;
	}
	else if (((WusikPr44AudioProcessor*)processor)->keyPressHandle(key)) return true;
	//
	return false;
}

void OptionsWindow::closeButtonPressed()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)processor;
	//
	setVisible(false);
	tooltipWindow->setVisible(false);
}


void WOptions::updateValuesFromProcessor()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	toggleButton_ShowGrid->setToggleState(processor->showGrid, NotificationType::dontSendNotification);
	toggleButton_SnapToGrid->setToggleState(processor->snapToGrid, NotificationType::dontSendNotification);
	toggleButton_ImageStretch->setToggleState(processor->backgroundImageStretch, NotificationType::dontSendNotification);
	//
	if (processor->gridSize == 5) comboBox_GridSize->setSelectedItemIndex(0, NotificationType::dontSendNotification);
	else if (processor->gridSize == 10) comboBox_GridSize->setSelectedItemIndex(1, NotificationType::dontSendNotification);
	else if (processor->gridSize == 15) comboBox_GridSize->setSelectedItemIndex(2, NotificationType::dontSendNotification);
	else if (processor->gridSize == 20) comboBox_GridSize->setSelectedItemIndex(3, NotificationType::dontSendNotification);
	else if (processor->gridSize == 25) comboBox_GridSize->setSelectedItemIndex(4, NotificationType::dontSendNotification);
	else if (processor->gridSize == 30) comboBox_GridSize->setSelectedItemIndex(5, NotificationType::dontSendNotification);
	else if (processor->gridSize == 40) comboBox_GridSize->setSelectedItemIndex(6, NotificationType::dontSendNotification);
	else if (processor->gridSize == 50) comboBox_GridSize->setSelectedItemIndex(7, NotificationType::dontSendNotification);
	else if (processor->gridSize == 60) comboBox_GridSize->setSelectedItemIndex(8, NotificationType::dontSendNotification);
	else if (processor->gridSize == 70) comboBox_GridSize->setSelectedItemIndex(9, NotificationType::dontSendNotification);
	else if (processor->gridSize == 80) comboBox_GridSize->setSelectedItemIndex(10, NotificationType::dontSendNotification);
	else if (processor->gridSize == 90) comboBox_GridSize->setSelectedItemIndex(11, NotificationType::dontSendNotification);
	else if (processor->gridSize == 100) comboBox_GridSize->setSelectedItemIndex(12, NotificationType::dontSendNotification);
	else if (processor->gridSize == 125) comboBox_GridSize->setSelectedItemIndex(13, NotificationType::dontSendNotification);
	else if (processor->gridSize == 150) comboBox_GridSize->setSelectedItemIndex(14, NotificationType::dontSendNotification);
	else if (processor->gridSize == 175) comboBox_GridSize->setSelectedItemIndex(15, NotificationType::dontSendNotification);
	else if (processor->gridSize == 200) comboBox_GridSize->setSelectedItemIndex(16, NotificationType::dontSendNotification);
	else if (processor->gridSize == 250) comboBox_GridSize->setSelectedItemIndex(17, NotificationType::dontSendNotification);
	else if (processor->gridSize == 300) comboBox_GridSize->setSelectedItemIndex(18, NotificationType::dontSendNotification);
	else if (processor->gridSize == 350) comboBox_GridSize->setSelectedItemIndex(19, NotificationType::dontSendNotification);
	else if (processor->gridSize == 400) comboBox_GridSize->setSelectedItemIndex(20, NotificationType::dontSendNotification);

	textButton_GridColour->setColour(TextButton::buttonColourId, processor->gridColour);
	textButton_BeatFlash->setColour(TextButton::buttonColourId, processor->beatFlashColour);
	textButton_BeatFlashFirst->setColour(TextButton::buttonColourId, processor->beatFlashFirstBeatColour);
	textButton_BeatFlashMeasure->setColour(TextButton::buttonColourId, processor->beatFlashFirstMeasureColour);
	textButton_BeatFlashDecay->setButtonText(String(processor->beatFlashDecayMS));
	textButton_BackImageScale->setButtonText(String(processor->backImageScale, 2));
	toggleButton_DisableF5->setToggleState(processor->disableF5SwitchKey, NotificationType::dontSendNotification);

	if (processor->backTransparency == 0.0f) textButton_ImageAlpha->setButtonText("Off"); else textButton_ImageAlpha->setButtonText(String(processor->backTransparency, 2));

	if (processor->initialMasterEnvelopeState == 0.0f) comboBox_EnvelopeState->setSelectedId(1); else comboBox_EnvelopeState->setSelectedId(2);
	if (processor->backImage.existsAsFile()) textButton_BackImage->setButtonText("Loaded"); else textButton_BackImage->setButtonText("None");

	ARRAY_Iterator(fontsArray)
	{
		if (processor->globalFontName.compareIgnoreCase(fontsArray[index]) == 0)
		{
			comboBox_Fonts->setSelectedId(index + 1, NotificationType::dontSendNotification);
			break;
		}
	}

	textButtonScreenA->setToggleState(processor->showingScreen == 0, NotificationType::dontSendNotification);
	textButtonScreenB->setToggleState(processor->showingScreen == 1, NotificationType::dontSendNotification);
	textButtonScreenC->setToggleState(processor->showingScreen == 2, NotificationType::dontSendNotification);
	textButtonScreenD->setToggleState(processor->showingScreen == 3, NotificationType::dontSendNotification);
	toggleButton_VolumeAuto->setToggleState(processor->masterVolumeAutoLower, NotificationType::dontSendNotification);

	String dB = Decibels::toString(Decibels::gainToDecibels(processor->masterVolume));
	textButton_Volume->setButtonText(dB);

	toggleButton_InternalClock->setToggleState(processor->internalClock, NotificationType::dontSendNotification);
	toggleButton_AutoPlay->setToggleState(processor->autoPlayAudioOnLoad, NotificationType::dontSendNotification);
	toggleButton_AutoStart->setToggleState(processor->autoStartClock, NotificationType::dontSendNotification);
	textButton_Measures->setButtonText(String(processor->numberOfMeasures));

	toggleButton_Fullscreen->setToggleState(processor->fullscreenMode, NotificationType::dontSendNotification);

	if (processor->internalClock) textButton_BPM->setButtonText(String(processor->internalBPM)); else textButton_BPM->setButtonText("EXT");

	comboBox_Templates->clear(NotificationType::dontSendNotification);
	comboBox_Templates->addItem("Save", 1);
	if (processor->selectedTemplate.isNotEmpty()) comboBox_Templates->addItem("Delete", 2);
	comboBox_Templates->setSelectedId(0, NotificationType::dontSendNotification);
	//
	bool isFirst = true;
	int iD = 3;
	ScopedPointer<DirectoryIterator> dirList = new DirectoryIterator(processor->dataPath + "Templates", false, "*.WPR44OptionsTemplate", File::findFiles);
	while (dirList->next())
	{
		if (isFirst)
		{
			isFirst = false;
			comboBox_Templates->addSeparator();
		}
		//
		comboBox_Templates->addItem(dirList->getFile().getFileNameWithoutExtension(), iD);
		if (processor->selectedTemplate.compareIgnoreCase(dirList->getFile().getFileNameWithoutExtension()) == 0) comboBox_Templates->setSelectedId(iD, NotificationType::dontSendNotification);
		iD++;
	}
}

void OptionsWindow::timerCallback()
{
	static WusikPr44AudioProcessor* _processor = (WusikPr44AudioProcessor*)processor;
	//
	stopTimer();
	//
	bool foundOneOver = false;
	const Array<Component*>& childrens = options->getChildren();
	//
	ARRAY_Iterator(childrens)
	{
		if (childrens[index]->isMouseOver())
		{
			foundOneOver = true;
			//
			if (tooltipWindow->componentOver == childrens[index])
			{
				if ((Time::getApproximateMillisecondCounter() - tooltipWindow->componentOverTime) > 1000)
				{
					String toolTip = _processor->getToolTipFor(*childrens[index]);
					if (toolTip.isNotEmpty())
					{
						//WMessageBox("Is Mouse Over!", toolTip);
						if (tooltipWindow == nullptr) tooltipWindow = new WToolTipWindow(_processor, this, true);
						tooltipWindow->textEditor->setText(toolTip, false);
						tooltipWindow->setVisible(true);
						tooltipWindow->repaint();
					}
				}
			}
			else
			{
				tooltipWindow->setVisible(false);
				tooltipWindow->componentOver = childrens[index];
				tooltipWindow->componentOverTime = Time::getApproximateMillisecondCounter();
			}
			//
			break;
		}
	}
	//
	if (!foundOneOver)
	{
		tooltipWindow->componentOver = nullptr;
		tooltipWindow->setVisible(false);
	}
	//
	startTimer(100);
}

OptionsWindow::OptionsWindow(void* _processor) : processor(_processor), DocumentWindow("Global Options", Colours::darkslategrey, DocumentWindow::closeButton)
{
	setUsingNativeTitleBar(true);
	setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() - 380, 40,
		332, (Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) - 80);
	//
	Viewport* viewPort = new Viewport("Options");
	viewPort->setBounds(0, 0, getWidth(), getHeight());
	viewPort->setScrollBarsShown(true, false);
	options = new WOptions;
	options->parent = processor;
	options->updateValuesFromProcessor();
	viewPort->setViewedComponent(options, true);
	setContentOwned(viewPort, false);
	//
	tooltipWindow = new WToolTipWindow(processor, this, true);
	//
	setVisible(true);
	setAlwaysOnTop(true);
	startTimer(100);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="WOptions" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="360" initialHeight="1020">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="18 136 304 88" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="24 80 278 47" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="30 472 273 128" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="32 784 288 72" fill="solid: 2a11126f" hasStroke="0"/>
  </BACKGROUND>
  <TOGGLEBUTTON name="Show Grid" id="16c752c71e0edd71" memberName="toggleButton_ShowGrid"
                virtualName="" explicitFocusOrder="0" pos="35 283 150 24" buttonText="Show Grid"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Snap To Grid" id="5c18c574ae3ca687" memberName="toggleButton_SnapToGrid"
                virtualName="" explicitFocusOrder="0" pos="35 317 150 24" buttonText="Snap To Grid"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="fd0bb25a7e3de4fe" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="35 355 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Grid Size" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="5a80a04003f5f63" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="35 398 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Grid Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Play" id="ed2d0654e5e222b8" memberName="textButton_Play"
              virtualName="" explicitFocusOrder="0" pos="121 24 80 40" tooltip="Switch to Play mode. To exit hit Alt+F4 or (if enabled) F5."
              bgColOff="ff5c68a4" buttonText="Play" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Close" id="53bb47ecce73b779" memberName="textButton_CloseEditor"
              virtualName="" explicitFocusOrder="0" pos="16 24 80 40" bgColOff="ff5c68a4"
              buttonText="Close" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="combo Grid Size" id="55e62a16e4511b99" memberName="comboBox_GridSize"
            virtualName="" explicitFocusOrder="0" pos="111 355 80 24" editable="0"
            layout="36" items="5&#10;10&#10;15&#10;20&#10;25&#10;30&#10;40&#10;50&#10;60&#10;70&#10;80&#10;90&#10;100&#10;125&#10;150&#10;175&#10;200&#10;250&#10;300&#10;350&#10;400"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="button Grid Colour" id="62b48a5ff4ebb1d2" memberName="textButton_GridColour"
              virtualName="" explicitFocusOrder="0" pos="128 399 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="e7f02b1a8c98769d" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="35 437 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="7c47ebb2dddbb2d4" memberName="textButton_BackColour"
              virtualName="" explicitFocusOrder="0" pos="128 438 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="f00f3efe49e19bcf" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="35 483 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back Image" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Image" id="7b0f43a82e38287" memberName="textButton_BackImage"
              virtualName="" explicitFocusOrder="0" pos="128 484 72 24" bgColOff="ff001da8"
              buttonText="none" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="d986862bd58d911d" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="35 699 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Font" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Fonts" id="e8313dbad97b079c" memberName="comboBox_Fonts"
            virtualName="" explicitFocusOrder="0" pos="111 699 140 24" editable="0"
            layout="36" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="Screen" id="a90dd556cd2bd4b6" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="144 145 64 24" tooltip="You have up to 4 screens to switch to. When you switch to a different screen the audio from the previous screen will not stop."
         edTextCol="ff000000" edBkgCol="0" labelText="Screen" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Screen A" id="be8a07b4fe0bb3fd" memberName="textButtonScreenA"
              virtualName="" explicitFocusOrder="0" pos="32 178 56 32" bgColOff="ff4d33e6"
              buttonText="A" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Screen B" id="b2794be75eed2982" memberName="textButtonScreenB"
              virtualName="" explicitFocusOrder="0" pos="104 178 56 32" bgColOff="ff4d33e6"
              buttonText="B" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Screen C" id="6da573f22d0a024c" memberName="textButtonScreenC"
              virtualName="" explicitFocusOrder="0" pos="176 178 56 32" bgColOff="ff4d33e6"
              buttonText="C" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="Screen D" id="7579b33dcc7885f5" memberName="textButtonScreenD"
              virtualName="" explicitFocusOrder="0" pos="248 178 56 32" bgColOff="ff4d33e6"
              buttonText="D" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="10371fedf845ce81" memberName="toggleButton_InternalClock"
                virtualName="" explicitFocusOrder="0" pos="41 824 141 24" tooltip="Internal clock, otherwise it uses the host/daw clock settings, but it won't follow the external sequencer transport, just the tempo (BPM)"
                buttonText="Internal Clock" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <LABEL name="new label" id="b535335857210f49" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="41 792 45 24" edTextCol="ff000000"
         edBkgCol="0" labelText="BPM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="72eac0d0747c71c7" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="174 792 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Measures" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button BPM" id="2588576442d1edad" memberName="textButton_BPM"
              virtualName="" explicitFocusOrder="0" pos="88 792 72 24" tooltip="EXT = External Clock Source. In this case it will use the host/daw BPM settings, but it won't follow the external transport."
              bgColOff="ff001da8" buttonText="EXT" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="b1046c57abc5f80f" memberName="toggleButton_AutoPlay"
                virtualName="" explicitFocusOrder="0" pos="35 862 229 24" buttonText="Auto Play Audio On Load"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="2acb8ef5b183ed05" memberName="toggleButton_ImageStretch"
                virtualName="" explicitFocusOrder="0" pos="215 484 81 24" buttonText="Stretch"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="8738de64d0b23960" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="35 615 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Flash Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="d86cd0eccc8efa80" memberName="textButton_BeatFlash"
              virtualName="" explicitFocusOrder="0" pos="128 616 72 24" tooltip="2, 3 and 4 beats colour. This will flash using the decay period on the right (ms)"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="e862af9a7baece31" memberName="toggleButton_AutoStart"
                virtualName="" explicitFocusOrder="0" pos="35 896 229 24" tooltip="When selecting any audio object the sequencer will start right away"
                buttonText="Auto Start Clock" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TEXTBUTTON name="button Back Colour" id="322f1b552387b0d2" memberName="textButton_BeatFlashDecay"
              virtualName="" explicitFocusOrder="0" pos="274 616 38 24" tooltip="For how long the colour should stay in ms."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="587ae4eadfa66a9b" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="208 615 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay (ms)" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="Reset" id="f1aa411f3b5888fd" memberName="textButton_ResetAll"
              virtualName="" explicitFocusOrder="0" pos="224 24 80 40" tooltip="Remove all objects."
              bgColOff="ff5c68a4" buttonText="Reset" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="f3244b6fc87b60ac" memberName="textButton_Measures"
              virtualName="" explicitFocusOrder="0" pos="252 792 58 24" tooltip="How many measures the project should use. Any loaded audio must be equal or less than this setting. Keep in mind that 1 measure is 4 beats or 16 steps on a regular sequencer."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="399a4a6b8c8e82df" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="35 656 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="First Beat Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="10fee8346c6447d1" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="208 656 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Measure" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="35115739654e74cf" memberName="textButton_BeatFlashMeasure"
              virtualName="" explicitFocusOrder="0" pos="259 657 53 24" tooltip="The colour for the first measure flash. This will be used on Beat #1 when the sequencer reaches the start of each measure."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="15b9dab5565aed4a" memberName="textButton_BeatFlashFirst"
              virtualName="" explicitFocusOrder="0" pos="128 657 72 24" tooltip="The first beat colour. Beat #1"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="6f74bcefaf1a53d3" memberName="toggleButton_DisableF5"
                virtualName="" explicitFocusOrder="0" pos="35 930 229 24" tooltip="Disable the F5 key. It switches from Play to Edit mode directly."
                buttonText="Disable F5 Play/Edit" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <LABEL name="new label" id="951a15ccb639686a" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="35 242 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Templates" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Grid Size" id="166d00ecbce8330b" memberName="comboBox_Templates"
            virtualName="" explicitFocusOrder="0" pos="111 242 185 24" editable="0"
            layout="36" items="" textWhenNonSelected="None" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="Close Editor" id="2329cbe11e2416d1" memberName="textButton_Export"
              virtualName="" explicitFocusOrder="0" pos="119 91 80 24" tooltip="Save everything into a single file"
              bgColOff="ff5c68a4" buttonText="Export" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Close Editor" id="90bfb6ac1f01d75f" memberName="textButton_Import"
              virtualName="" explicitFocusOrder="0" pos="207 91 80 24" bgColOff="ff5c68a4"
              buttonText="Import" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="78f5a9423d60c60" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="42 91 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Project" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="3d794cc5ba1f090e" memberName="labelFadeState"
         virtualName="" explicitFocusOrder="0" pos="35 742 117 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Fonts" id="aa3d460961b27134" memberName="comboBox_EnvelopeState"
            virtualName="" explicitFocusOrder="0" pos="159 742 103 24" tooltip="The master envelope status when starting the project. Low is Silent and High is Maximum Volume. This can be changed using a button action such as Fade In or Out."
            editable="0" layout="36" items="Low&#10;High" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="6c42a59e3aeab881" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="35 523 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Image" id="e0f99f1b7b680c4e" memberName="textButton_BackImageScale"
              virtualName="" explicitFocusOrder="0" pos="128 524 72 24" tooltip="1.0 is original, 2.0 is double, 0.5 is half and so on."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="e4d6075eaa667843" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="35 968 104 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Master Volume" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="38372fa77a626c07" memberName="textButton_Volume"
              virtualName="" explicitFocusOrder="0" pos="143 969 92 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="f20811a8770fc3f9" memberName="toggleButton_VolumeAuto"
                virtualName="" explicitFocusOrder="0" pos="252 969 76 24" tooltip="This will lower the master volume during the playback. And won't raise back up. So it's not a limiter."
                buttonText="Auto" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="new label" id="33517a34a1c3a9e" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="35 564 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Transparency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="9a7e6b456c1a5353" memberName="textButton_ImageAlpha"
              virtualName="" explicitFocusOrder="0" pos="145 566 55 24" tooltip="0.0 is none (fully opaque) and 1.0 is fully transparent"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Show Grid" id="1a842293d4c4ad97" memberName="toggleButton_Fullscreen"
                virtualName="" explicitFocusOrder="0" pos="184 283 112 24" buttonText="Fullscreen"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

