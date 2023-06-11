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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ObjectButtonOptions  : public Component,
                             public ChangeListener,
                             public ComboBox::Listener,
                             public Button::Listener
{
public:
    //==============================================================================
    ObjectButtonOptions ();
    ~ObjectButtonOptions();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void* parent = nullptr;
	void updateValuesFromProcessor();
	StringArray theNames;
	Colour* edColour = nullptr;
	Button* edButton = nullptr;
	//
	void changeListenerCallback(ChangeBroadcaster* source) override;
	void browseColour(Colour* _colour, Button* _button)
	{
		edColour = _colour;
		edButton = _button;
		//
		auto* colourSelector = new ColourSelector();
		colourSelector->setName("Colour");
		colourSelector->setCurrentColour(*_colour);
		colourSelector->addChangeListener(this);
		colourSelector->setColour(ColourSelector::backgroundColourId, Colours::transparentBlack);
		colourSelector->setSize(300, 400);
		CallOutBox::launchAsynchronously(colourSelector, getScreenBounds(), nullptr);
	}

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label5;
    std::unique_ptr<ComboBox> comboBox_Action;
    std::unique_ptr<Label> label7;
    std::unique_ptr<TextButton> textButton_MIDI1;
    std::unique_ptr<TextButton> textButton_MIDI2;
    std::unique_ptr<Label> midiDataLabel1;
    std::unique_ptr<Label> midiDataLabel2;
    std::unique_ptr<TextButton> textButton_MIDI3;
    std::unique_ptr<Label> midiDataLabel3;
    std::unique_ptr<ComboBox> comboBox_Names;
    std::unique_ptr<Label> labelClickColour;
    std::unique_ptr<TextButton> textButton_ClickColour;
    std::unique_ptr<Label> labelClickColourDecay;
    std::unique_ptr<TextButton> textButton_ClickColourDecay;
    std::unique_ptr<Label> labelFadeOut;
    std::unique_ptr<TextButton> textButton_FadeOut;
    std::unique_ptr<TextButton> textButton_Image;
    std::unique_ptr<ToggleButton> toggleButton_Synced;
    std::unique_ptr<Label> labelFadeState;
    std::unique_ptr<ComboBox> comboBox_FadeState;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ObjectButtonOptions)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

