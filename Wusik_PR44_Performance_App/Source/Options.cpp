/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.1.6

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

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

    textButton_Play.reset (new juce::TextButton ("Play"));
    addAndMakeVisible (textButton_Play.get());
    textButton_Play->setTooltip (TRANS("Switch to Play mode. To exit hit Alt+F4 or (if enabled) F5."));
    textButton_Play->addListener (this);
    textButton_Play->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c68a4));

    textButton_Play->setBounds (121, 24, 80, 40);

    textButton_CloseEditor.reset (new juce::TextButton ("Close"));
    addAndMakeVisible (textButton_CloseEditor.get());
    textButton_CloseEditor->addListener (this);
    textButton_CloseEditor->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c68a4));

    textButton_CloseEditor->setBounds (16, 24, 80, 40);

    label3.reset (new juce::Label ("new label",
                                   TRANS("Back Colour")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (35, 237, 80, 24);

    textButton_BackColour.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BackColour.get());
    textButton_BackColour->setButtonText (juce::String());
    textButton_BackColour->addListener (this);
    textButton_BackColour->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BackColour->setBounds (128, 238, 72, 24);

    label4.reset (new juce::Label ("new label",
                                   TRANS("Back Image")));
    addAndMakeVisible (label4.get());
    label4->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (juce::Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label4->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label4->setBounds (35, 283, 80, 24);

    textButton_BackImage.reset (new juce::TextButton ("button Back Image"));
    addAndMakeVisible (textButton_BackImage.get());
    textButton_BackImage->setButtonText (TRANS("none"));
    textButton_BackImage->addListener (this);
    textButton_BackImage->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BackImage->setBounds (128, 284, 72, 24);

    label6.reset (new juce::Label ("Screen",
                                   TRANS("Screen")));
    addAndMakeVisible (label6.get());
    label6->setTooltip (TRANS("You have up to 4 screens to switch to. When you switch to a different screen the audio from the previous screen will not stop."));
    label6->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (juce::Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label6->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label6->setBounds (144, 145, 64, 24);

    textButtonScreenA.reset (new juce::TextButton ("Screen A"));
    addAndMakeVisible (textButtonScreenA.get());
    textButtonScreenA->setButtonText (TRANS("A"));
    textButtonScreenA->addListener (this);
    textButtonScreenA->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4d33e6));

    textButtonScreenA->setBounds (32, 178, 56, 32);

    textButtonScreenB.reset (new juce::TextButton ("Screen B"));
    addAndMakeVisible (textButtonScreenB.get());
    textButtonScreenB->setButtonText (TRANS("B"));
    textButtonScreenB->addListener (this);
    textButtonScreenB->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4d33e6));

    textButtonScreenB->setBounds (104, 178, 56, 32);

    textButtonScreenC.reset (new juce::TextButton ("Screen C"));
    addAndMakeVisible (textButtonScreenC.get());
    textButtonScreenC->setButtonText (TRANS("C"));
    textButtonScreenC->addListener (this);
    textButtonScreenC->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4d33e6));

    textButtonScreenC->setBounds (176, 178, 56, 32);

    textButtonScreenD.reset (new juce::TextButton ("Screen D"));
    addAndMakeVisible (textButtonScreenD.get());
    textButtonScreenD->setButtonText (TRANS("D"));
    textButtonScreenD->addListener (this);
    textButtonScreenD->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff4d33e6));

    textButtonScreenD->setBounds (248, 178, 56, 32);

    toggleButton_InternalClock.reset (new juce::ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_InternalClock.get());
    toggleButton_InternalClock->setTooltip (TRANS("Internal clock, otherwise it uses the host/daw clock settings, but it won\'t follow the external sequencer transport, just the tempo (BPM)"));
    toggleButton_InternalClock->addListener (this);

    toggleButton_InternalClock->setBounds (41, 592, 141, 24);

    label7.reset (new juce::Label ("new label",
                                   TRANS("BPM")));
    addAndMakeVisible (label7.get());
    label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (juce::Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label7->setBounds (41, 560, 45, 24);

    label8.reset (new juce::Label ("new label",
                                   TRANS("Measures")));
    addAndMakeVisible (label8.get());
    label8->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (juce::Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label8->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label8->setBounds (174, 560, 72, 24);

    textButton_BPM.reset (new juce::TextButton ("button BPM"));
    addAndMakeVisible (textButton_BPM.get());
    textButton_BPM->setTooltip (TRANS("EXT = External Clock Source. In this case it will use the host/daw BPM settings, but it won\'t follow the external transport."));
    textButton_BPM->setButtonText (TRANS("EXT"));
    textButton_BPM->addListener (this);
    textButton_BPM->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BPM->setBounds (88, 560, 72, 24);

    toggleButton_ImageStretch.reset (new juce::ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_ImageStretch.get());
    toggleButton_ImageStretch->setButtonText (TRANS("Stretch"));
    toggleButton_ImageStretch->addListener (this);

    toggleButton_ImageStretch->setBounds (215, 284, 81, 24);

    label10.reset (new juce::Label ("new label",
                                    TRANS("Flash Colour")));
    addAndMakeVisible (label10.get());
    label10->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (juce::Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label10->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label10->setBounds (35, 415, 80, 24);

    textButton_BeatFlash.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlash.get());
    textButton_BeatFlash->setTooltip (TRANS("2, 3 and 4 beats colour. This will flash using the decay period on the right (ms)"));
    textButton_BeatFlash->setButtonText (juce::String());
    textButton_BeatFlash->addListener (this);
    textButton_BeatFlash->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BeatFlash->setBounds (128, 416, 72, 24);

    toggleButton_AutoStart.reset (new juce::ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_AutoStart.get());
    toggleButton_AutoStart->setTooltip (TRANS("When selecting any audio object the sequencer will start right away"));
    toggleButton_AutoStart->setButtonText (TRANS("Auto Start Clock"));
    toggleButton_AutoStart->addListener (this);

    toggleButton_AutoStart->setBounds (35, 648, 229, 24);

    textButton_ResetAll.reset (new juce::TextButton ("Reset"));
    addAndMakeVisible (textButton_ResetAll.get());
    textButton_ResetAll->setTooltip (TRANS("Remove all objects."));
    textButton_ResetAll->addListener (this);
    textButton_ResetAll->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c68a4));

    textButton_ResetAll->setBounds (224, 24, 80, 40);

    textButton_Measures.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_Measures.get());
    textButton_Measures->setTooltip (TRANS("How many measures the project should use. Any loaded audio must be equal or less than this setting. Keep in mind that 1 measure is 4 beats or 16 steps on a regular sequencer."));
    textButton_Measures->setButtonText (juce::String());
    textButton_Measures->addListener (this);
    textButton_Measures->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_Measures->setBounds (252, 560, 58, 24);

    label9.reset (new juce::Label ("new label",
                                   TRANS("First Beat Colour")));
    addAndMakeVisible (label9.get());
    label9->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (juce::Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label9->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label9->setBounds (35, 456, 93, 24);

    label12.reset (new juce::Label ("new label",
                                    TRANS("Measure")));
    addAndMakeVisible (label12.get());
    label12->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (juce::Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label12->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label12->setBounds (208, 456, 48, 24);

    textButton_BeatFlashMeasure.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlashMeasure.get());
    textButton_BeatFlashMeasure->setTooltip (TRANS("The colour for the first measure flash. This will be used on Beat #1 when the sequencer reaches the start of each measure."));
    textButton_BeatFlashMeasure->setButtonText (juce::String());
    textButton_BeatFlashMeasure->addListener (this);
    textButton_BeatFlashMeasure->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BeatFlashMeasure->setBounds (259, 457, 53, 24);

    textButton_BeatFlashFirst.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BeatFlashFirst.get());
    textButton_BeatFlashFirst->setTooltip (TRANS("The first beat colour. Beat #1"));
    textButton_BeatFlashFirst->setButtonText (juce::String());
    textButton_BeatFlashFirst->addListener (this);
    textButton_BeatFlashFirst->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BeatFlashFirst->setBounds (128, 457, 72, 24);

    textButton_Export.reset (new juce::TextButton ("Close Editor"));
    addAndMakeVisible (textButton_Export.get());
    textButton_Export->setTooltip (TRANS("Save everything into a single file"));
    textButton_Export->setButtonText (TRANS("Export"));
    textButton_Export->addListener (this);
    textButton_Export->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c68a4));

    textButton_Export->setBounds (119, 91, 80, 24);

    textButton_Import.reset (new juce::TextButton ("Close Editor"));
    addAndMakeVisible (textButton_Import.get());
    textButton_Import->setButtonText (TRANS("Import"));
    textButton_Import->addListener (this);
    textButton_Import->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff5c68a4));

    textButton_Import->setBounds (207, 91, 80, 24);

    label14.reset (new juce::Label ("new label",
                                    TRANS("Project")));
    addAndMakeVisible (label14.get());
    label14->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label14->setJustificationType (juce::Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label14->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label14->setBounds (42, 91, 80, 24);

    labelFadeState.reset (new juce::Label ("new label",
                                           TRANS("Initial Envelope")));
    addAndMakeVisible (labelFadeState.get());
    labelFadeState->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    labelFadeState->setJustificationType (juce::Justification::centredLeft);
    labelFadeState->setEditable (false, false, false);
    labelFadeState->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    labelFadeState->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    labelFadeState->setBounds (35, 510, 117, 25);

    comboBox_EnvelopeState.reset (new juce::ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_EnvelopeState.get());
    comboBox_EnvelopeState->setTooltip (TRANS("The master envelope status when starting the project. Low is Silent and High is Maximum Volume. This can be changed using a button action such as Fade In or Out."));
    comboBox_EnvelopeState->setEditableText (false);
    comboBox_EnvelopeState->setJustificationType (juce::Justification::centred);
    comboBox_EnvelopeState->setTextWhenNothingSelected (juce::String());
    comboBox_EnvelopeState->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_EnvelopeState->addItem (TRANS("Low"), 1);
    comboBox_EnvelopeState->addItem (TRANS("High"), 2);
    comboBox_EnvelopeState->addListener (this);

    comboBox_EnvelopeState->setBounds (159, 510, 103, 24);

    label15.reset (new juce::Label ("new label",
                                    TRANS("Scale")));
    addAndMakeVisible (label15.get());
    label15->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label15->setJustificationType (juce::Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label15->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label15->setBounds (35, 323, 80, 24);

    textButton_BackImageScale.reset (new juce::TextButton ("button Back Image"));
    addAndMakeVisible (textButton_BackImageScale.get());
    textButton_BackImageScale->setTooltip (TRANS("1.0 is original, 2.0 is double, 0.5 is half and so on."));
    textButton_BackImageScale->setButtonText (juce::String());
    textButton_BackImageScale->addListener (this);
    textButton_BackImageScale->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BackImageScale->setBounds (128, 324, 72, 24);

    label16.reset (new juce::Label ("new label",
                                    TRANS("Master Volume")));
    addAndMakeVisible (label16.get());
    label16->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label16->setJustificationType (juce::Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label16->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label16->setBounds (35, 688, 104, 25);

    textButton_Volume.reset (new juce::TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Volume.get());
    textButton_Volume->setButtonText (juce::String());
    textButton_Volume->addListener (this);
    textButton_Volume->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_Volume->setBounds (143, 689, 92, 24);

    toggleButton_VolumeAuto.reset (new juce::ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_VolumeAuto.get());
    toggleButton_VolumeAuto->setTooltip (TRANS("This will lower the master volume during the playback. And won\'t raise back up. So it\'s not a limiter."));
    toggleButton_VolumeAuto->setButtonText (TRANS("Auto"));
    toggleButton_VolumeAuto->addListener (this);

    toggleButton_VolumeAuto->setBounds (252, 689, 76, 24);

    label17.reset (new juce::Label ("new label",
                                    TRANS("Transparency")));
    addAndMakeVisible (label17.get());
    label17->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label17->setJustificationType (juce::Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label17->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label17->setBounds (35, 364, 101, 25);

    textButton_ImageAlpha.reset (new juce::TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_ImageAlpha.get());
    textButton_ImageAlpha->setTooltip (TRANS("0.0 is none (fully opaque) and 1.0 is fully transparent"));
    textButton_ImageAlpha->setButtonText (juce::String());
    textButton_ImageAlpha->addListener (this);
    textButton_ImageAlpha->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_ImageAlpha->setBounds (145, 366, 55, 24);


    //[UserPreSize]

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

    textButton_Play = nullptr;
    textButton_CloseEditor = nullptr;
    label3 = nullptr;
    textButton_BackColour = nullptr;
    label4 = nullptr;
    textButton_BackImage = nullptr;
    label6 = nullptr;
    textButtonScreenA = nullptr;
    textButtonScreenB = nullptr;
    textButtonScreenC = nullptr;
    textButtonScreenD = nullptr;
    toggleButton_InternalClock = nullptr;
    label7 = nullptr;
    label8 = nullptr;
    textButton_BPM = nullptr;
    toggleButton_ImageStretch = nullptr;
    label10 = nullptr;
    textButton_BeatFlash = nullptr;
    toggleButton_AutoStart = nullptr;
    textButton_ResetAll = nullptr;
    textButton_Measures = nullptr;
    label9 = nullptr;
    label12 = nullptr;
    textButton_BeatFlashMeasure = nullptr;
    textButton_BeatFlashFirst = nullptr;
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


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void WOptions::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 18, y = 136, width = 304, height = 88;
        juce::Colour fillColour = juce::Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 24, y = 80, width = 278, height = 47;
        juce::Colour fillColour = juce::Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 29, y = 552, width = 288, height = 72;
        juce::Colour fillColour = juce::Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 29, y = 408, width = 288, height = 80;
        juce::Colour fillColour = juce::Colour (0x2a11126f);
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

void WOptions::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton_Play.get())
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

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void WOptions::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_EnvelopeState.get())
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
	toggleButton_ImageStretch->setToggleState(processor->backgroundImageStretch, NotificationType::dontSendNotification);
	//
	textButton_BeatFlash->setColour(TextButton::buttonColourId, processor->beatFlashColour);
	textButton_BeatFlashFirst->setColour(TextButton::buttonColourId, processor->beatFlashFirstBeatColour);
	textButton_BeatFlashMeasure->setColour(TextButton::buttonColourId, processor->beatFlashFirstMeasureColour);
	textButton_BackImageScale->setButtonText(String(processor->backImageScale, 2));

	if (processor->backTransparency == 0.0f) textButton_ImageAlpha->setButtonText("Off"); else textButton_ImageAlpha->setButtonText(String(processor->backTransparency, 2));

	if (processor->initialMasterEnvelopeState == 0.0f) comboBox_EnvelopeState->setSelectedId(1); else comboBox_EnvelopeState->setSelectedId(2);
	if (processor->backImage.existsAsFile()) textButton_BackImage->setButtonText("Loaded"); else textButton_BackImage->setButtonText("None");

	textButtonScreenA->setToggleState(processor->showingScreen == 0, NotificationType::dontSendNotification);
	textButtonScreenB->setToggleState(processor->showingScreen == 1, NotificationType::dontSendNotification);
	textButtonScreenC->setToggleState(processor->showingScreen == 2, NotificationType::dontSendNotification);
	textButtonScreenD->setToggleState(processor->showingScreen == 3, NotificationType::dontSendNotification);
	toggleButton_VolumeAuto->setToggleState(processor->masterVolumeAutoLower, NotificationType::dontSendNotification);

	String dB = Decibels::toString(Decibels::gainToDecibels(processor->masterVolume));
	textButton_Volume->setButtonText(dB);

	toggleButton_InternalClock->setToggleState(processor->internalClock, NotificationType::dontSendNotification);
	toggleButton_AutoStart->setToggleState(processor->autoStartClock, NotificationType::dontSendNotification);
	textButton_Measures->setButtonText(String(processor->numberOfMeasures));

	if (processor->internalClock) textButton_BPM->setButtonText(String(processor->internalBPM)); else textButton_BPM->setButtonText("EXT");
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
    <RECT pos="29 552 288 72" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="29 408 288 80" fill="solid: 2a11126f" hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="Play" id="ed2d0654e5e222b8" memberName="textButton_Play"
              virtualName="" explicitFocusOrder="0" pos="121 24 80 40" tooltip="Switch to Play mode. To exit hit Alt+F4 or (if enabled) F5."
              bgColOff="ff5c68a4" buttonText="Play" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="Close" id="53bb47ecce73b779" memberName="textButton_CloseEditor"
              virtualName="" explicitFocusOrder="0" pos="16 24 80 40" bgColOff="ff5c68a4"
              buttonText="Close" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="e7f02b1a8c98769d" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="35 237 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="7c47ebb2dddbb2d4" memberName="textButton_BackColour"
              virtualName="" explicitFocusOrder="0" pos="128 238 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="f00f3efe49e19bcf" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="35 283 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back Image" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Image" id="7b0f43a82e38287" memberName="textButton_BackImage"
              virtualName="" explicitFocusOrder="0" pos="128 284 72 24" bgColOff="ff001da8"
              buttonText="none" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
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
                virtualName="" explicitFocusOrder="0" pos="41 592 141 24" tooltip="Internal clock, otherwise it uses the host/daw clock settings, but it won't follow the external sequencer transport, just the tempo (BPM)"
                buttonText="Internal Clock" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <LABEL name="new label" id="b535335857210f49" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="41 560 45 24" edTextCol="ff000000"
         edBkgCol="0" labelText="BPM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="72eac0d0747c71c7" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="174 560 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Measures" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button BPM" id="2588576442d1edad" memberName="textButton_BPM"
              virtualName="" explicitFocusOrder="0" pos="88 560 72 24" tooltip="EXT = External Clock Source. In this case it will use the host/daw BPM settings, but it won't follow the external transport."
              bgColOff="ff001da8" buttonText="EXT" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="2acb8ef5b183ed05" memberName="toggleButton_ImageStretch"
                virtualName="" explicitFocusOrder="0" pos="215 284 81 24" buttonText="Stretch"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="8738de64d0b23960" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="35 415 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Flash Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="d86cd0eccc8efa80" memberName="textButton_BeatFlash"
              virtualName="" explicitFocusOrder="0" pos="128 416 72 24" tooltip="2, 3 and 4 beats colour. This will flash using the decay period on the right (ms)"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="e862af9a7baece31" memberName="toggleButton_AutoStart"
                virtualName="" explicitFocusOrder="0" pos="35 648 229 24" tooltip="When selecting any audio object the sequencer will start right away"
                buttonText="Auto Start Clock" connectedEdges="0" needsCallback="1"
                radioGroupId="0" state="0"/>
  <TEXTBUTTON name="Reset" id="f1aa411f3b5888fd" memberName="textButton_ResetAll"
              virtualName="" explicitFocusOrder="0" pos="224 24 80 40" tooltip="Remove all objects."
              bgColOff="ff5c68a4" buttonText="Reset" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="f3244b6fc87b60ac" memberName="textButton_Measures"
              virtualName="" explicitFocusOrder="0" pos="252 560 58 24" tooltip="How many measures the project should use. Any loaded audio must be equal or less than this setting. Keep in mind that 1 measure is 4 beats or 16 steps on a regular sequencer."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="399a4a6b8c8e82df" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="35 456 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="First Beat Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="10fee8346c6447d1" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="208 456 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Measure" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="35115739654e74cf" memberName="textButton_BeatFlashMeasure"
              virtualName="" explicitFocusOrder="0" pos="259 457 53 24" tooltip="The colour for the first measure flash. This will be used on Beat #1 when the sequencer reaches the start of each measure."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="15b9dab5565aed4a" memberName="textButton_BeatFlashFirst"
              virtualName="" explicitFocusOrder="0" pos="128 457 72 24" tooltip="The first beat colour. Beat #1"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
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
         virtualName="" explicitFocusOrder="0" pos="35 510 117 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial Envelope" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Fonts" id="aa3d460961b27134" memberName="comboBox_EnvelopeState"
            virtualName="" explicitFocusOrder="0" pos="159 510 103 24" tooltip="The master envelope status when starting the project. Low is Silent and High is Maximum Volume. This can be changed using a button action such as Fade In or Out."
            editable="0" layout="36" items="Low&#10;High" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="6c42a59e3aeab881" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="35 323 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Image" id="e0f99f1b7b680c4e" memberName="textButton_BackImageScale"
              virtualName="" explicitFocusOrder="0" pos="128 324 72 24" tooltip="1.0 is original, 2.0 is double, 0.5 is half and so on."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="e4d6075eaa667843" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="35 688 104 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Master Volume" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="38372fa77a626c07" memberName="textButton_Volume"
              virtualName="" explicitFocusOrder="0" pos="143 689 92 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="f20811a8770fc3f9" memberName="toggleButton_VolumeAuto"
                virtualName="" explicitFocusOrder="0" pos="252 689 76 24" tooltip="This will lower the master volume during the playback. And won't raise back up. So it's not a limiter."
                buttonText="Auto" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <LABEL name="new label" id="33517a34a1c3a9e" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="35 364 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Transparency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="9a7e6b456c1a5353" memberName="textButton_ImageAlpha"
              virtualName="" explicitFocusOrder="0" pos="145 366 55 24" tooltip="0.0 is none (fully opaque) and 1.0 is fully transparent"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

