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

#include "ObjectOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

#include "SoundOptions.h"
#include "ObjectButtonOptions.h"

//[/MiscUserDefs]

//==============================================================================
ObjectOptions::ObjectOptions ()
{
    //[Constructor_pre] You can add your own custom stuff here..

	getLookAndFeel().setDefaultSansSerifTypefaceName("Verdana");

    //[/Constructor_pre]

    label3.reset (new juce::Label ("new label",
                                   TRANS("Back Colour")));
    addAndMakeVisible (label3.get());
    label3->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (juce::Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label3->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label3->setBounds (27, 117, 93, 24);

    textButton_BackColour.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BackColour.get());
    textButton_BackColour->setButtonText (juce::String());
    textButton_BackColour->addListener (this);
    textButton_BackColour->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_BackColour->setBounds (134, 118, 72, 24);

    label7.reset (new juce::Label ("new label",
                                   TRANS("Screen")));
    addAndMakeVisible (label7.get());
    label7->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (juce::Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label7->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label7->setBounds (27, 193, 93, 24);

    objectType.reset (new juce::Label ("new label",
                                       TRANS("label text")));
    addAndMakeVisible (objectType.get());
    objectType->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Bold"));
    objectType->setJustificationType (juce::Justification::centred);
    objectType->setEditable (false, false, false);
    objectType->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    objectType->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    objectType->setBounds (16, 77, 288, 24);

    textButton_Duplicate.reset (new juce::TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Duplicate.get());
    textButton_Duplicate->setButtonText (TRANS("Duplicate"));
    textButton_Duplicate->addListener (this);
    textButton_Duplicate->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_Duplicate->setBounds (63, 24, 88, 24);

    textButton_Delete.reset (new juce::TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Delete.get());
    textButton_Delete->setButtonText (TRANS("Delete"));
    textButton_Delete->addListener (this);
    textButton_Delete->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_Delete->setBounds (176, 24, 88, 24);

    comboBox_Screen.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_Screen.get());
    comboBox_Screen->setTooltip (TRANS("Which screen this object should show on"));
    comboBox_Screen->setEditableText (false);
    comboBox_Screen->setJustificationType (juce::Justification::centredLeft);
    comboBox_Screen->setTextWhenNothingSelected (juce::String());
    comboBox_Screen->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Screen->addItem (TRANS("A"), 1);
    comboBox_Screen->addItem (TRANS("B"), 2);
    comboBox_Screen->addItem (TRANS("C"), 3);
    comboBox_Screen->addItem (TRANS("D"), 4);
    comboBox_Screen->addListener (this);

    comboBox_Screen->setBounds (134, 193, 90, 28);

    textButton_AnimationColour.reset (new juce::TextButton ("button Font Colour"));
    addAndMakeVisible (textButton_AnimationColour.get());
    textButton_AnimationColour->setTooltip (TRANS("Playing Postion Animation"));
    textButton_AnimationColour->setButtonText (juce::String());
    textButton_AnimationColour->addListener (this);
    textButton_AnimationColour->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_AnimationColour->setBounds (134, 153, 50, 24);

    label14.reset (new juce::Label ("new label",
                                    TRANS("Anim. Colour")));
    addAndMakeVisible (label14.get());
    label14->setTooltip (TRANS("Playing Postion Animation"));
    label14->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label14->setJustificationType (juce::Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label14->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label14->setBounds (27, 152, 93, 24);

    comboBox_AnimType.reset (new juce::ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_AnimType.get());
    comboBox_AnimType->setTooltip (TRANS("Progress Playing Animation Type"));
    comboBox_AnimType->setEditableText (false);
    comboBox_AnimType->setJustificationType (juce::Justification::centredLeft);
    comboBox_AnimType->setTextWhenNothingSelected (juce::String());
    comboBox_AnimType->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_AnimType->addItem (TRANS("Regular"), 1);
    comboBox_AnimType->addItem (TRANS("Measure"), 2);
    comboBox_AnimType->addItem (TRANS("Beat"), 3);
    comboBox_AnimType->addListener (this);

    comboBox_AnimType->setBounds (200, 153, 96, 24);

    label20.reset (new juce::Label ("new label",
                                    TRANS("MIDI Key")));
    addAndMakeVisible (label20.get());
    label20->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    label20->setJustificationType (juce::Justification::centredLeft);
    label20->setEditable (false, false, false);
    label20->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    label20->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    label20->setBounds (27, 237, 93, 24);

    textButton_MIDIkey.reset (new juce::TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_MIDIkey.get());
    textButton_MIDIkey->setTooltip (TRANS("Learn a MIDI Key to be used to trigger this event."));
    textButton_MIDIkey->setButtonText (juce::String());
    textButton_MIDIkey->addListener (this);
    textButton_MIDIkey->setColour (juce::TextButton::buttonColourId, juce::Colour (0xff001da8));

    textButton_MIDIkey->setBounds (134, 238, 72, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 300);


    //[Constructor] You can add your own custom stuff here..

	theHeigth = getHeight();

    //[/Constructor]
}

ObjectOptions::~ObjectOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label3 = nullptr;
    textButton_BackColour = nullptr;
    label7 = nullptr;
    objectType = nullptr;
    textButton_Duplicate = nullptr;
    textButton_Delete = nullptr;
    comboBox_Screen = nullptr;
    textButton_AnimationColour = nullptr;
    label14 = nullptr;
    comboBox_AnimType = nullptr;
    label20 = nullptr;
    textButton_MIDIkey = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ObjectOptions::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    {
        int x = 24, y = 8, width = 272, height = 56;
        juce::Colour fillColour = juce::Colour (0x3000001c);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 25, y = 276, width = 272, height = 12;
        juce::Colour fillColour = juce::Colour (0x3000001c);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ObjectOptions::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ObjectOptions::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton_BackColour.get())
    {
        //[UserButtonCode_textButton_BackColour] -- add your button handler code here..

		browseColour(&processor->selectedObject->backgroundColour, textButton_BackColour.get());

        //[/UserButtonCode_textButton_BackColour]
    }
    else if (buttonThatWasClicked == textButton_Duplicate.get())
    {
        //[UserButtonCode_textButton_Duplicate] -- add your button handler code here..

		processor->duplicateObject(processor->selectedObject);

        //[/UserButtonCode_textButton_Duplicate]
    }
    else if (buttonThatWasClicked == textButton_Delete.get())
    {
        //[UserButtonCode_textButton_Delete] -- add your button handler code here..

		if (ConfirmBox("Delete Object", "Are you sure?"))
		{
			processor->stopAllSounds = true;
			processor->objectOptionsWindow->setVisible(false);
			EditCompo* edCompo = (EditCompo*)processor->mainWindow->getContentComponent();
			//
			ARRAY_Iterator(edCompo->dasButtons)
			{
				if (edCompo->dasButtons[index]->leObject == processor->selectedObject)
				{
					removeChildComponent(edCompo->dasButtons[index]);
					edCompo->dasButtons[index]->removeListener(edCompo);
					edCompo->dasButtons.remove(index);
					break;
				}
			}
			//
			processor->deleteSelectedObject = true;
			processor->mainWindow->repaint();
			return;
		}

        //[/UserButtonCode_textButton_Delete]
    }
    else if (buttonThatWasClicked == textButton_AnimationColour.get())
    {
        //[UserButtonCode_textButton_AnimationColour] -- add your button handler code here..

		browseColour(&processor->selectedObject->animationColour, textButton_AnimationColour.get());

        //[/UserButtonCode_textButton_AnimationColour]
    }
    else if (buttonThatWasClicked == textButton_MIDIkey.get())
    {
        //[UserButtonCode_textButton_MIDIkey] -- add your button handler code here..

		if (processor->learnMIDI || processor->selectedObject->midiKey != -1)
		{
			processor->selectedObject->midiKey = -1;
			processor->learnMIDI = false;
			stopTimer();
			updateValuesFromProcessor();
		}
		else
		{
			processor->learnMIDIKey = -1;
			processor->learnMIDI = true;
			midiLearn = 1;
			WMessageBox("Click OK and send the MIDI Key (note) you want to use", "(press a key on your MIDI Controller)");
			textButton_MIDIkey->setButtonText("Learning");
			startTimer(250);
		}


        //[/UserButtonCode_textButton_MIDIkey]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ObjectOptions::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_Screen.get())
    {
        //[UserComboBoxCode_comboBox_Screen] -- add your combo box handling code here..

		processor->selectedObject->screen = comboBox_Screen->getSelectedId() - 1;
		((EditCompo*)processor->mainWindow->getContentComponent())->updateObjects();
		processor->mainWindow->repaint();

        //[/UserComboBoxCode_comboBox_Screen]
    }
    else if (comboBoxThatHasChanged == comboBox_AnimType.get())
    {
        //[UserComboBoxCode_comboBox_AnimType] -- add your combo box handling code here..

		processor->selectedObject->animationType = comboBox_AnimType->getSelectedId() - 1;

        //[/UserComboBoxCode_comboBox_AnimType]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


void ObjectOptionsWindow::closeButtonPressed()
{
	static WusikPr44AudioProcessor* _processor = (WusikPr44AudioProcessor*)processor;
	//
	setVisible(false);
	_processor->sequencerClock.stop();
	_processor->selectedObject = nullptr;
	if (tooltipWindow->isVisible()) tooltipWindow->closeButtonPressed();
}

void ObjectOptions::updateValuesFromProcessor()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (processor->selectedObject != nullptr)
	{
		if (processor->selectedObject->midiKey == -1) textButton_MIDIkey->setButtonText("Off"); else textButton_MIDIkey->setButtonText(String(processor->selectedObject->midiKey));
		//
		comboBox_Screen->setSelectedItemIndex(processor->selectedObject->screen);
		textButton_AnimationColour->setColour(TextButton::buttonColourId, processor->selectedObject->animationColour);
		//
		comboBox_AnimType->setSelectedId(processor->selectedObject->animationType + 1);
		//
		String theText;
		//
		if (processor->selectedObject->type == WPR44Object::kType_Sound) theText = "Sound";
		else if (processor->selectedObject->type == WPR44Object::kType_Button) theText = "Button";
		//
		objectType->setText("Type: " + theText, NotificationType::dontSendNotification);
		//
		if (sndInterface != nullptr) ((SoundOptions*)sndInterface)->setVisible(false);
		if (buttonInterface != nullptr) ((ObjectButtonOptions*)buttonInterface)->setVisible(false);
		//
		if (processor->selectedObject->type == WPR44Object::kType_Sound)
		{
			if (sndInterface == nullptr)
			{
				sndInterface = new SoundOptions;
				((SoundOptions*)sndInterface)->parent = parent;
				((SoundOptions*)sndInterface)->updateValuesFromProcessor();
				((SoundOptions*)sndInterface)->setBounds(0, theHeigth, 320, 940); // 1088);
				addAndMakeVisible((SoundOptions*)sndInterface);
			}
			else
			{
				((SoundOptions*)sndInterface)->updateValuesFromProcessor();
				((SoundOptions*)sndInterface)->setVisible(true);
			}
			//
			setSize(320, theHeigth + 940); // 1088);
		}
		else if (processor->selectedObject->type == WPR44Object::kType_Button)
		{
			if (buttonInterface == nullptr)
			{
				buttonInterface = new ObjectButtonOptions;
				((ObjectButtonOptions*)buttonInterface)->parent = parent;
				((ObjectButtonOptions*)buttonInterface)->updateValuesFromProcessor();
				((ObjectButtonOptions*)buttonInterface)->setBounds(0, theHeigth, 320, 320);
				addAndMakeVisible((ObjectButtonOptions*)buttonInterface);
			}
			else
			{
				((ObjectButtonOptions*)buttonInterface)->updateValuesFromProcessor();
				((ObjectButtonOptions*)buttonInterface)->setVisible(true);
			}
			//
			setSize(320, theHeigth + 320);
		}

		repaint();
	}
}

bool ObjectOptionsWindow::keyPressed(const KeyPress &key)
{
	if (key.getKeyCode() == KeyPress::F4Key && key.getModifiers().isAltDown())
	{
		((WusikPr44AudioProcessor*)processor)->objectOptionsWindow->closeButtonPressed();
		if (tooltipWindow->isVisible()) tooltipWindow->closeButtonPressed();
		return true;
	}
	else if (((WusikPr44AudioProcessor*)processor)->keyPressHandle(key)) return true;
	//
	return false;
}


void ObjectOptions::changeListenerCallback(ChangeBroadcaster* source)
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

void ObjectOptionsWindow::timerCallback()
{
	static WusikPr44AudioProcessor* _processor = (WusikPr44AudioProcessor*)processor;
	//
	stopTimer();
	//
	bool foundOneOver = false;
	if (tooltipWindow == nullptr) tooltipWindow = new WToolTipWindow(_processor, this, false);
	//
	for (int tt = 0; tt < 3; tt++)
	{
		Component* const* childrensData;
		int arraySize = 0;
		//
		if (tt == 0)
		{
			if (options->sndInterface != nullptr)
			{
				childrensData = ((SoundOptions*)options->sndInterface)->getChildren().getRawDataPointer();
				arraySize = ((SoundOptions*)options->sndInterface)->getChildren().size();
			}
		}
		else if (tt == 1)
		{
			if (options->buttonInterface != nullptr)
			{
				childrensData = ((ObjectButtonOptions*)options->buttonInterface)->getChildren().getRawDataPointer();
				arraySize = ((ObjectButtonOptions*)options->buttonInterface)->getChildren().size();
			}
		}
		else if (tt == 2)
		{
			childrensData = options->getChildren().getRawDataPointer();
			arraySize = options->getChildren().size();
		}
		//
		for (int index = 0; index < arraySize; index++)
		{
			if (childrensData[index]->isMouseOver())
			{
				//WMessageBox("Is Mouse Over!", childrensData[index]->getName());
				//
				foundOneOver = true;
				//
				if (tooltipWindow->componentOver == childrensData[index])
				{
					if ((Time::getApproximateMillisecondCounter() - tooltipWindow->componentOverTime) > 1000)
					{
						String toolTip = _processor->getToolTipFor(*childrensData[index]);
						if (toolTip.isNotEmpty())
						{
							tooltipWindow->textEditor->setText(toolTip, false);
							tooltipWindow->setVisible(true);
							tooltipWindow->repaint();
						}
					}
				}
				else
				{
					tooltipWindow->setVisible(false);
					tooltipWindow->componentOver = childrensData[index];
					tooltipWindow->componentOverTime = Time::getApproximateMillisecondCounter();
				}
				//
				break;
			}
		}
		//
		if (foundOneOver) break;
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

ObjectOptionsWindow::ObjectOptionsWindow(void* _processor) : processor(_processor), DocumentWindow("Object Options", Colours::darkslategrey, DocumentWindow::closeButton)
{
	setUsingNativeTitleBar(true);
	//
	setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() - 380,
		(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) + 40,
		332, (Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) - 80);
	//
	Viewport* viewPort = new Viewport("Options");
	viewPort->setBounds(0, 0, getWidth(), getHeight());
	viewPort->setScrollBarsShown(true, false);
	options = new ObjectOptions;
	options->parent = processor;
	options->updateValuesFromProcessor();
	viewPort->setViewedComponent(options, true);
	setContentOwned(viewPort, false);
	//
	tooltipWindow = new WToolTipWindow(processor, this, false);
	//
	setVisible(true);
	setAlwaysOnTop(true);
	startTimer(100);
}

void ObjectOptions::timerCallback()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	stopTimer();
	//
	if (midiLearn >= 0 && !processor->learnMIDI)
	{
		WPR44SoundObject* soundObject = (WPR44SoundObject*)processor->selectedObject;
		//
		if (midiLearn == 0) soundObject->midiCC = processor->learnMIDICC;
		else soundObject->midiKey = processor->learnMIDIKey;
		//
		updateValuesFromProcessor();
		midiLearn = -1;
		return;
	}
	//
	if (keyPressLearn && processor->lastKeyPressed.isValid())
	{
		WPR44SoundObject* soundObject = (WPR44SoundObject*)processor->selectedObject;
		//
		soundObject->pcKeyPress = processor->lastKeyPressed;
		updateValuesFromProcessor();
		keyPressLearn = false;
		return;
	}
	//
	startTimer(250);
}

// ------------------------------------------------------------------------------------------------------------------------------------
bool ObjectOptions::keyPressed(const KeyPress &key)
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	processor->lastKeyPressed = key;
	if (key.getKeyCode() == KeyPress::escapeKey)
	{
		processor->stopAllSounds = true;
		return true;
	}
	else if (((WusikPr44AudioProcessor*)processor)->keyPressHandle(key)) return true;
	//
	return false;
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ObjectOptions" componentName=""
                 parentClasses="public Component, public ChangeListener, public Timer"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="320"
                 initialHeight="300">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="24 8 272 56" fill="solid: 3000001c" hasStroke="0"/>
    <RECT pos="25 276 272 12" fill="solid: 3000001c" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="e7f02b1a8c98769d" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="27 117 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="7c47ebb2dddbb2d4" memberName="textButton_BackColour"
              virtualName="" explicitFocusOrder="0" pos="134 118 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="8217d615b5215d2b" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="27 193 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Screen" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="505de9703595e854" memberName="objectType"
         virtualName="" explicitFocusOrder="0" pos="16 77 288 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="1" italic="0" justification="36" typefaceStyle="Bold"/>
  <TEXTBUTTON name="button Border Colour" id="c90921e9976578e3" memberName="textButton_Duplicate"
              virtualName="" explicitFocusOrder="0" pos="63 24 88 24" bgColOff="ff001da8"
              buttonText="Duplicate" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Border Colour" id="bf4fc7211130fa4" memberName="textButton_Delete"
              virtualName="" explicitFocusOrder="0" pos="176 24 88 24" bgColOff="ff001da8"
              buttonText="Delete" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="c3cba96534f107c7" memberName="comboBox_Screen"
            virtualName="" explicitFocusOrder="0" pos="134 193 90 28" tooltip="Which screen this object should show on"
            editable="0" layout="33" items="A&#10;B&#10;C&#10;D" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="button Font Colour" id="69a310c2301021f3" memberName="textButton_AnimationColour"
              virtualName="" explicitFocusOrder="0" pos="134 153 50 24" tooltip="Playing Postion Animation"
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="7da446d509dfb521" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="27 152 93 24" tooltip="Playing Postion Animation"
         edTextCol="ff000000" edBkgCol="0" labelText="Anim. Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="5007fe68fcd8e611" memberName="comboBox_AnimType"
            virtualName="" explicitFocusOrder="0" pos="200 153 96 24" tooltip="Progress Playing Animation Type"
            editable="0" layout="33" items="Regular&#10;Measure&#10;Beat"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="6c26e9c76611dc78" memberName="label20" virtualName=""
         explicitFocusOrder="0" pos="27 237 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="MIDI Key" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="64faa0af109b3d59" memberName="textButton_MIDIkey"
              virtualName="" explicitFocusOrder="0" pos="134 238 72 24" tooltip="Learn a MIDI Key to be used to trigger this event."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

