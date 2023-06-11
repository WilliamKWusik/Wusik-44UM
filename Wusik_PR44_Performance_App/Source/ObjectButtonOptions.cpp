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

//[/Headers]

#include "ObjectButtonOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ObjectButtonOptions::ObjectButtonOptions ()
{
    //[Constructor_pre] You can add your own custom stuff here..

	getLookAndFeel().setDefaultSansSerifTypefaceName("Verdana");

    //[/Constructor_pre]

    label5.reset (new Label ("new label",
                             TRANS("Action")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (24, 100, 72, 24);

    comboBox_Action.reset (new ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_Action.get());
    comboBox_Action->setEditableText (false);
    comboBox_Action->setJustificationType (Justification::centred);
    comboBox_Action->setTextWhenNothingSelected (String());
    comboBox_Action->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Action->addItem (TRANS("None"), 1);
    comboBox_Action->addItem (TRANS("Start/Stop"), 2);
    comboBox_Action->addItem (TRANS("Start"), 3);
    comboBox_Action->addItem (TRANS("Stop"), 4);
    comboBox_Action->addItem (TRANS("Panic"), 5);
    comboBox_Action->addItem (TRANS("Close App/Window"), 6);
    comboBox_Action->addItem (TRANS("Close App/Window (confirm)"), 7);
    comboBox_Action->addItem (TRANS("Stop Sound"), 8);
    comboBox_Action->addItem (TRANS("Stop Group"), 9);
    comboBox_Action->addItem (TRANS("Send MIDI Note"), 10);
    comboBox_Action->addItem (TRANS("Send MIDI CC"), 11);
    comboBox_Action->addItem (TRANS("Fade Sound"), 12);
    comboBox_Action->addItem (TRANS("Fade Group"), 13);
    comboBox_Action->addItem (TRANS("Fade Sound (flipflop)"), 14);
    comboBox_Action->addItem (TRANS("Fade Group (flipflop)"), 15);
    comboBox_Action->addItem (TRANS("Fade Out All and Stop"), 16);
    comboBox_Action->addItem (TRANS("Fade In All"), 17);
    comboBox_Action->addItem (TRANS("Fade All (flipflop)"), 18);
    comboBox_Action->addItem (TRANS("Multi Starter"), 19);
    comboBox_Action->addItem (TRANS("ScreenA"), 20);
    comboBox_Action->addItem (TRANS("ScreenB"), 21);
    comboBox_Action->addItem (TRANS("ScreenC"), 22);
    comboBox_Action->addItem (TRANS("ScreenD"), 23);
    comboBox_Action->addListener (this);

    comboBox_Action->setBounds (100, 100, 180, 24);

    label7.reset (new Label ("new label",
                             TRANS("MIDI")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (24, 142, 48, 24);

    textButton_MIDI1.reset (new TextButton ("button BPM"));
    addAndMakeVisible (textButton_MIDI1.get());
    textButton_MIDI1->setButtonText (String());
    textButton_MIDI1->addListener (this);
    textButton_MIDI1->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_MIDI1->setBounds (91, 142, 56, 24);

    textButton_MIDI2.reset (new TextButton ("button BPM"));
    addAndMakeVisible (textButton_MIDI2.get());
    textButton_MIDI2->setButtonText (String());
    textButton_MIDI2->addListener (this);
    textButton_MIDI2->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_MIDI2->setBounds (160, 142, 56, 24);

    midiDataLabel1.reset (new Label ("new label",
                                     TRANS("A")));
    addAndMakeVisible (midiDataLabel1.get());
    midiDataLabel1->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    midiDataLabel1->setJustificationType (Justification::centred);
    midiDataLabel1->setEditable (false, false, false);
    midiDataLabel1->setColour (TextEditor::textColourId, Colours::black);
    midiDataLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    midiDataLabel1->setBounds (95, 170, 48, 24);

    midiDataLabel2.reset (new Label ("new label",
                                     TRANS("B")));
    addAndMakeVisible (midiDataLabel2.get());
    midiDataLabel2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    midiDataLabel2->setJustificationType (Justification::centred);
    midiDataLabel2->setEditable (false, false, false);
    midiDataLabel2->setColour (TextEditor::textColourId, Colours::black);
    midiDataLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    midiDataLabel2->setBounds (164, 170, 48, 24);

    textButton_MIDI3.reset (new TextButton ("button BPM"));
    addAndMakeVisible (textButton_MIDI3.get());
    textButton_MIDI3->setButtonText (String());
    textButton_MIDI3->addListener (this);
    textButton_MIDI3->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_MIDI3->setBounds (228, 142, 56, 24);

    midiDataLabel3.reset (new Label ("new label",
                                     TRANS("C")));
    addAndMakeVisible (midiDataLabel3.get());
    midiDataLabel3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    midiDataLabel3->setJustificationType (Justification::centred);
    midiDataLabel3->setEditable (false, false, false);
    midiDataLabel3->setColour (TextEditor::textColourId, Colours::black);
    midiDataLabel3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    midiDataLabel3->setBounds (232, 170, 48, 24);

    comboBox_Names.reset (new ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_Names.get());
    comboBox_Names->setEditableText (false);
    comboBox_Names->setJustificationType (Justification::centred);
    comboBox_Names->setTextWhenNothingSelected (String());
    comboBox_Names->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Names->addListener (this);

    comboBox_Names->setBounds (100, 143, 180, 24);

    labelClickColour.reset (new Label ("new label",
                                       TRANS("Click Colour")));
    addAndMakeVisible (labelClickColour.get());
    labelClickColour->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelClickColour->setJustificationType (Justification::centredLeft);
    labelClickColour->setEditable (false, false, false);
    labelClickColour->setColour (TextEditor::textColourId, Colours::black);
    labelClickColour->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelClickColour->setBounds (24, 18, 88, 25);

    textButton_ClickColour.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_ClickColour.get());
    textButton_ClickColour->setButtonText (String());
    textButton_ClickColour->addListener (this);
    textButton_ClickColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ClickColour->setBounds (113, 18, 56, 24);

    labelClickColourDecay.reset (new Label ("new label",
                                            TRANS("Decay")));
    addAndMakeVisible (labelClickColourDecay.get());
    labelClickColourDecay->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelClickColourDecay->setJustificationType (Justification::centredLeft);
    labelClickColourDecay->setEditable (false, false, false);
    labelClickColourDecay->setColour (TextEditor::textColourId, Colours::black);
    labelClickColourDecay->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelClickColourDecay->setBounds (24, 58, 56, 25);

    textButton_ClickColourDecay.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_ClickColourDecay.get());
    textButton_ClickColourDecay->setButtonText (String());
    textButton_ClickColourDecay->addListener (this);
    textButton_ClickColourDecay->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ClickColourDecay->setBounds (91, 58, 54, 24);

    labelFadeOut.reset (new Label ("new label",
                                   TRANS("Fade Rate")));
    addAndMakeVisible (labelFadeOut.get());
    labelFadeOut->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelFadeOut->setJustificationType (Justification::centredLeft);
    labelFadeOut->setEditable (false, false, false);
    labelFadeOut->setColour (TextEditor::textColourId, Colours::black);
    labelFadeOut->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelFadeOut->setBounds (24, 198, 64, 25);

    textButton_FadeOut.reset (new TextButton ("button BPM"));
    addAndMakeVisible (textButton_FadeOut.get());
    textButton_FadeOut->setButtonText (String());
    textButton_FadeOut->addListener (this);
    textButton_FadeOut->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_FadeOut->setBounds (91, 199, 56, 24);

    textButton_Image.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_Image.get());
    textButton_Image->setButtonText (TRANS("Image"));
    textButton_Image->addListener (this);
    textButton_Image->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Image->setBounds (184, 18, 62, 24);

    toggleButton_Synced.reset (new ToggleButton ("Show Grid"));
    addAndMakeVisible (toggleButton_Synced.get());
    toggleButton_Synced->setButtonText (TRANS("Synced"));
    toggleButton_Synced->addListener (this);

    toggleButton_Synced->setBounds (160, 58, 112, 24);

    labelFadeState.reset (new Label ("new label",
                                     TRANS("Initial Fade State")));
    addAndMakeVisible (labelFadeState.get());
    labelFadeState->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelFadeState->setJustificationType (Justification::centredLeft);
    labelFadeState->setEditable (false, false, false);
    labelFadeState->setColour (TextEditor::textColourId, Colours::black);
    labelFadeState->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    labelFadeState->setBounds (24, 235, 128, 25);

    comboBox_FadeState.reset (new ComboBox ("combo Fonts"));
    addAndMakeVisible (comboBox_FadeState.get());
    comboBox_FadeState->setEditableText (false);
    comboBox_FadeState->setJustificationType (Justification::centred);
    comboBox_FadeState->setTextWhenNothingSelected (String());
    comboBox_FadeState->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_FadeState->addItem (TRANS("Low"), 1);
    comboBox_FadeState->addItem (TRANS("High"), 2);
    comboBox_FadeState->addListener (this);

    comboBox_FadeState->setBounds (152, 235, 88, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ObjectButtonOptions::~ObjectButtonOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label5 = nullptr;
    comboBox_Action = nullptr;
    label7 = nullptr;
    textButton_MIDI1 = nullptr;
    textButton_MIDI2 = nullptr;
    midiDataLabel1 = nullptr;
    midiDataLabel2 = nullptr;
    textButton_MIDI3 = nullptr;
    midiDataLabel3 = nullptr;
    comboBox_Names = nullptr;
    labelClickColour = nullptr;
    textButton_ClickColour = nullptr;
    labelClickColourDecay = nullptr;
    textButton_ClickColourDecay = nullptr;
    labelFadeOut = nullptr;
    textButton_FadeOut = nullptr;
    textButton_Image = nullptr;
    toggleButton_Synced = nullptr;
    labelFadeState = nullptr;
    comboBox_FadeState = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ObjectButtonOptions::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ObjectButtonOptions::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ObjectButtonOptions::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)processor->selectedObject;

    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_Action.get())
    {
        //[UserComboBoxCode_comboBox_Action] -- add your combo box handling code here..

		buttonObject->action = comboBox_Action->getSelectedId() - 1;
		buttonObject->targetName = String();
		//
		if (buttonObject->action == WPR44Object::kAction_SendMIDICC)
		{
			buttonObject->midiValues[0] = 1;
			buttonObject->midiValues[1] = 1;
			buttonObject->midiValues[2] = 127;
		}
		else if (buttonObject->action == WPR44Object::kAction_SendMIDINote)
		{
			buttonObject->midiValues[0] = 1;
			buttonObject->midiValues[1] = 60;
			buttonObject->midiValues[2] = 120;
		}
		//
		updateValuesFromProcessor();

        //[/UserComboBoxCode_comboBox_Action]
    }
    else if (comboBoxThatHasChanged == comboBox_Names.get())
    {
        //[UserComboBoxCode_comboBox_Names] -- add your combo box handling code here..

		if (comboBox_Names->getSelectedId() == 1) buttonObject->targetName = String();
		else buttonObject->targetName = theNames[comboBox_Names->getSelectedId() - 1];

        //[/UserComboBoxCode_comboBox_Names]
    }
    else if (comboBoxThatHasChanged == comboBox_FadeState.get())
    {
        //[UserComboBoxCode_comboBox_FadeState] -- add your combo box handling code here..

		if (comboBox_FadeState->getSelectedId() == 1) buttonObject->initialFadeState = 0.0f; else buttonObject->initialFadeState = 1.0f;

        //[/UserComboBoxCode_comboBox_FadeState]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void ObjectButtonOptions::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)processor->selectedObject;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton_MIDI1.get())
    {
        //[UserButtonCode_textButton_MIDI1] -- add your button handler code here..

		String theValue;
		AskValue("MIDI Channel (1 to 16)", "", String(buttonObject->midiValues[0]), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			buttonObject->midiValues[0] = jlimit(1, 16, theValue.getIntValue());
			updateValuesFromProcessor();
		}

        //[/UserButtonCode_textButton_MIDI1]
    }
    else if (buttonThatWasClicked == textButton_MIDI2.get())
    {
        //[UserButtonCode_textButton_MIDI2] -- add your button handler code here..

		String theValue;
		AskValue("MIDI Value (0 to 127)", "", String(buttonObject->midiValues[1]), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			buttonObject->midiValues[1] = jlimit(0, 127, theValue.getIntValue());
			updateValuesFromProcessor();
		}

        //[/UserButtonCode_textButton_MIDI2]
    }
    else if (buttonThatWasClicked == textButton_MIDI3.get())
    {
        //[UserButtonCode_textButton_MIDI3] -- add your button handler code here..

		String theValue;
		AskValue("MIDI Value (0 to 127)", "", String(buttonObject->midiValues[2]), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			buttonObject->midiValues[2] = jlimit(0, 127, theValue.getIntValue());
			updateValuesFromProcessor();
		}

        //[/UserButtonCode_textButton_MIDI3]
    }
    else if (buttonThatWasClicked == textButton_ClickColour.get())
    {
        //[UserButtonCode_textButton_ClickColour] -- add your button handler code here..

		browseColour(&buttonObject->clickColour, textButton_ClickColour.get());

        //[/UserButtonCode_textButton_ClickColour]
    }
    else if (buttonThatWasClicked == textButton_ClickColourDecay.get())
    {
        //[UserButtonCode_textButton_ClickColourDecay] -- add your button handler code here..

		String theValue;
		AskValue("Click Decay (ms)", "(how long it takes for the click colour to vanish)", String(buttonObject->clickDecay), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			buttonObject->clickDecay = theValue.getIntValue();
			textButton_ClickColourDecay->setButtonText(String(buttonObject->clickDecay));
		}

        //[/UserButtonCode_textButton_ClickColourDecay]
    }
    else if (buttonThatWasClicked == textButton_FadeOut.get())
    {
        //[UserButtonCode_textButton_FadeOut] -- add your button handler code here..

		String theValue;
		AskValue("Sound Fade Out (ms)", "(how long it takes for the sound to fade out)", String(buttonObject->fadeRate), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			buttonObject->fadeRate = theValue.getIntValue();
			textButton_FadeOut->setButtonText(String(buttonObject->fadeRate));
		}

        //[/UserButtonCode_textButton_FadeOut]
    }
    else if (buttonThatWasClicked == textButton_Image.get())
    {
        //[UserButtonCode_textButton_Image] -- add your button handler code here..

		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Click].isNotEmpty())
		{
			processor->selectedObject->imagesFilename[WPR44Object::kImage_Click] = String();
			processor->selectedObject->images[WPR44Object::kImage_Click] = nullptr;
			processor->loadImages();
			textButton_Image->setButtonText("Image");
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
				textButton_Image->setButtonText("(*)Image");
				processor->selectedObject->imagesFilename[WPR44Object::kImage_Click] = loadFile.getResult().getFullPathName();
				processor->loadImages();
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_Image]
    }
    else if (buttonThatWasClicked == toggleButton_Synced.get())
    {
        //[UserButtonCode_toggleButton_Synced] -- add your button handler code here..

		buttonObject->isSynced = toggleButton_Synced->getToggleState();

        //[/UserButtonCode_toggleButton_Synced]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void ObjectButtonOptions::updateValuesFromProcessor()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (processor->selectedObject != nullptr)
	{
		WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)processor->selectedObject;
		//
		comboBox_Action->setSelectedId(buttonObject->action + 1, NotificationType::dontSendNotification);
		textButton_ClickColour->setColour(TextButton::buttonColourId, buttonObject->clickColour);
		textButton_ClickColourDecay->setButtonText(String(buttonObject->clickDecay));
		textButton_FadeOut->setButtonText(String(buttonObject->fadeRate));
		toggleButton_Synced->setToggleState(buttonObject->isSynced, NotificationType::dontSendNotification);
		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Click].isEmpty()) textButton_Image->setButtonText("Image"); else textButton_Image->setButtonText("(*)Image");
		if (buttonObject->initialFadeState > 0.9f) comboBox_FadeState->setSelectedId(2, NotificationType::dontSendNotification); else comboBox_FadeState->setSelectedId(1, NotificationType::dontSendNotification);
		//
		comboBox_Names->setVisible(false);
		label7->setVisible(false);
		textButton_MIDI1->setVisible(false);
		textButton_MIDI2->setVisible(false);
		textButton_MIDI3->setVisible(false);
		midiDataLabel1->setVisible(false);
		midiDataLabel2->setVisible(false);
		midiDataLabel3->setVisible(false);
		textButton_FadeOut->setVisible(false);
		labelFadeOut->setVisible(false);
		labelFadeState->setVisible(false);
		comboBox_FadeState->setVisible(false);
		//
		if (buttonObject->action == WPR44Object::kAction_SendMIDICC || buttonObject->action == WPR44Object::kAction_SendMIDINote)
		{
			if (buttonObject->action == WPR44Object::kAction_SendMIDICC)
			{
				midiDataLabel1->setText("CH", NotificationType::dontSendNotification);
				midiDataLabel2->setText("CC", NotificationType::dontSendNotification);
				midiDataLabel3->setText("Value", NotificationType::dontSendNotification);
			}
			else
			{
				midiDataLabel1->setText("CH", NotificationType::dontSendNotification);
				midiDataLabel2->setText("Note", NotificationType::dontSendNotification);
				midiDataLabel3->setText("Velocity", NotificationType::dontSendNotification);
			}
			//
			textButton_MIDI1->setButtonText(String(buttonObject->midiValues[0]));
			textButton_MIDI2->setButtonText(String(buttonObject->midiValues[1]));
			textButton_MIDI3->setButtonText(String(buttonObject->midiValues[2]));
			//
			label7->setText("MIDI", NotificationType::dontSendNotification);
			label7->setVisible(true);
			textButton_MIDI1->setVisible(true);
			textButton_MIDI2->setVisible(true);
			textButton_MIDI3->setVisible(true);
			midiDataLabel1->setVisible(true);
			midiDataLabel2->setVisible(true);
			midiDataLabel3->setVisible(true);
			comboBox_Names->setVisible(false);
		}
		else if (buttonObject->action == WPR44Object::kAction_Panic || buttonObject->action == WPR44Object::kAction_FadeOutAllAndStop ||
			buttonObject->action == WPR44Object::kAction_FadeInAll || buttonObject->action == WPR44Object::kAction_FadeAll_FlipFlop)
		{
			textButton_FadeOut->setVisible(true);
			labelFadeOut->setVisible(true);
		}
		else if (buttonObject->action == WPR44Object::kAction_StopGroup || buttonObject->action == WPR44Object::kAction_StopSound ||
				buttonObject->action == WPR44Object::kAction_FadeGroup || buttonObject->action == WPR44Object::kAction_FadeSound ||
			buttonObject->action == WPR44Object::kAction_FadeGroup_FlipFlop || buttonObject->action == WPR44Object::kAction_FadeSound_FlipFlop)
		{
			textButton_FadeOut->setVisible(true);
			labelFadeOut->setVisible(true);
			//
			if (buttonObject->action == WPR44Object::kAction_FadeGroup || buttonObject->action == WPR44Object::kAction_FadeSound)
			{
				labelFadeState->setVisible(true);
				comboBox_FadeState->setVisible(true);
			}
			//
			label7->setText("Name", NotificationType::dontSendNotification);
			label7->setVisible(true);
			theNames.clear();
			//
			ARRAY_Iterator(processor->leObjects)
			{
				if (processor->leObjects[index]->type == WPR44Object::kType_Sound)
				{
					WPR44SoundObject* soundObject = (WPR44SoundObject*)processor->leObjects[index];
					//
					if ((buttonObject->action == WPR44Object::kAction_StopGroup || buttonObject->action == WPR44Object::kAction_FadeGroup ||
						buttonObject->action == WPR44Object::kAction_FadeGroup_FlipFlop) && soundObject->group.isNotEmpty())
					{
						theNames.addIfNotAlreadyThere(soundObject->group);
					}
					else if ((buttonObject->action == WPR44Object::kAction_StopSound || buttonObject->action == WPR44Object::kAction_FadeSound ||
						buttonObject->action == WPR44Object::kAction_FadeSound_FlipFlop) && soundObject->name.isNotEmpty())
					{
						theNames.addIfNotAlreadyThere(soundObject->name);
					}
				}
			}
			//
			theNames.sort(true);
			theNames.insert(0, "None");
			comboBox_Names->clear(NotificationType::dontSendNotification);
			//
			ARRAY_Iterator(theNames)
			{
				comboBox_Names->addItem(theNames[index], index + 1);
				if (buttonObject->targetName.compareIgnoreCase(theNames[index]) == 0) comboBox_Names->setSelectedId(index + 1);
			}
			//
			if (buttonObject->targetName.isEmpty()) comboBox_Names->setSelectedId(1);
			//
			comboBox_Names->setVisible(true);
			textButton_MIDI1->setVisible(false);
			textButton_MIDI2->setVisible(false);
			textButton_MIDI3->setVisible(false);
			midiDataLabel1->setVisible(false);
			midiDataLabel2->setVisible(false);
			midiDataLabel3->setVisible(false);
		}
	}
}

void ObjectButtonOptions::changeListenerCallback(ChangeBroadcaster* source)
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

<JUCER_COMPONENT documentType="Component" className="ObjectButtonOptions" componentName=""
                 parentClasses="public Component, public ChangeListener" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="320" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <LABEL name="new label" id="d986862bd58d911d" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="24 100 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Action" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Fonts" id="e8313dbad97b079c" memberName="comboBox_Action"
            virtualName="" explicitFocusOrder="0" pos="100 100 180 24" editable="0"
            layout="36" items="None&#10;Start/Stop&#10;Start&#10;Stop&#10;Panic&#10;Close App/Window&#10;Close App/Window (confirm)&#10;Stop Sound&#10;Stop Group&#10;Send MIDI Note&#10;Send MIDI CC&#10;Fade Sound&#10;Fade Group&#10;Fade Sound (flipflop)&#10;Fade Group (flipflop)&#10;Fade Out All and Stop&#10;Fade In All&#10;Fade All (flipflop)&#10;Multi Starter&#10;ScreenA&#10;ScreenB&#10;ScreenC&#10;ScreenD"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="b535335857210f49" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="24 142 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button BPM" id="2588576442d1edad" memberName="textButton_MIDI1"
              virtualName="" explicitFocusOrder="0" pos="91 142 56 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button BPM" id="3018cac3aeb54589" memberName="textButton_MIDI2"
              virtualName="" explicitFocusOrder="0" pos="160 142 56 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="80455a2de47c7b86" memberName="midiDataLabel1"
         virtualName="" explicitFocusOrder="0" pos="95 170 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="A" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="6c3a289f06b6e588" memberName="midiDataLabel2"
         virtualName="" explicitFocusOrder="0" pos="164 170 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="B" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="button BPM" id="60600cda513649ef" memberName="textButton_MIDI3"
              virtualName="" explicitFocusOrder="0" pos="228 142 56 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="4ce71a99af27e657" memberName="midiDataLabel3"
         virtualName="" explicitFocusOrder="0" pos="232 170 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="C" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="combo Fonts" id="c68a5c1d0569d6f7" memberName="comboBox_Names"
            virtualName="" explicitFocusOrder="0" pos="100 143 180 24" editable="0"
            layout="36" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="5a80a04003f5f63" memberName="labelClickColour"
         virtualName="" explicitFocusOrder="0" pos="24 18 88 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Click Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="62b48a5ff4ebb1d2" memberName="textButton_ClickColour"
              virtualName="" explicitFocusOrder="0" pos="113 18 56 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="934f335fc5d953d4" memberName="labelClickColourDecay"
         virtualName="" explicitFocusOrder="0" pos="24 58 56 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="8d3e384233a41afb" memberName="textButton_ClickColourDecay"
              virtualName="" explicitFocusOrder="0" pos="91 58 54 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="ceb4c74488a3c42" memberName="labelFadeOut"
         virtualName="" explicitFocusOrder="0" pos="24 198 64 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Fade Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button BPM" id="7346e4f9d0c0bd0f" memberName="textButton_FadeOut"
              virtualName="" explicitFocusOrder="0" pos="91 199 56 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Back Colour" id="dbbc196381b79663" memberName="textButton_Image"
              virtualName="" explicitFocusOrder="0" pos="184 18 62 24" bgColOff="ff001da8"
              buttonText="Image" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Show Grid" id="35a6d8c00c730dd9" memberName="toggleButton_Synced"
                virtualName="" explicitFocusOrder="0" pos="160 58 112 24" buttonText="Synced"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="3d794cc5ba1f090e" memberName="labelFadeState"
         virtualName="" explicitFocusOrder="0" pos="24 235 128 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Initial Fade State" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="combo Fonts" id="aa3d460961b27134" memberName="comboBox_FadeState"
            virtualName="" explicitFocusOrder="0" pos="152 235 88 24" editable="0"
            layout="36" items="Low&#10;High" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

