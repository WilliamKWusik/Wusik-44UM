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
                             public juce::ComboBox::Listener,
                             public juce::Button::Listener
{
public:
    //==============================================================================
    ObjectButtonOptions ();
    ~ObjectButtonOptions() override;

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
		auto* colourSelector = new ColourSelector(15 ^ ColourSelector::showAlphaChannel);
		colourSelector->setName("Colour");
		colourSelector->setCurrentColour(*_colour);
		colourSelector->addChangeListener(this);
		colourSelector->setColour(ColourSelector::backgroundColourId, Colours::transparentBlack);
		colourSelector->setSize(300, 400);
		CallOutBox::launchAsynchronously(colourSelector, getScreenBounds(), nullptr);
	}

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Label> label5;
    std::unique_ptr<juce::ComboBox> comboBox_Action;
    std::unique_ptr<juce::Label> label7;
    std::unique_ptr<juce::TextButton> textButton_MIDI1;
    std::unique_ptr<juce::TextButton> textButton_MIDI2;
    std::unique_ptr<juce::Label> midiDataLabel1;
    std::unique_ptr<juce::Label> midiDataLabel2;
    std::unique_ptr<juce::TextButton> textButton_MIDI3;
    std::unique_ptr<juce::Label> midiDataLabel3;
    std::unique_ptr<juce::ComboBox> comboBox_Names;
    std::unique_ptr<juce::Label> labelClickColour;
    std::unique_ptr<juce::TextButton> textButton_ClickColour;
    std::unique_ptr<juce::Label> labelClickColourDecay;
    std::unique_ptr<juce::TextButton> textButton_ClickColourDecay;
    std::unique_ptr<juce::Label> labelFadeOut;
    std::unique_ptr<juce::TextButton> textButton_FadeOut;
    std::unique_ptr<juce::TextButton> textButton_Image;
    std::unique_ptr<juce::ToggleButton> toggleButton_Synced;
    std::unique_ptr<juce::Label> labelFadeState;
    std::unique_ptr<juce::ComboBox> comboBox_FadeState;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ObjectButtonOptions)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

