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
class SoundOptions  : public Component,
                      public ChangeListener,
                      public Button::Listener,
                      public ComboBox::Listener
{
public:
    //==============================================================================
    SoundOptions ();
    ~SoundOptions();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

// ------------------------------------------------------------------------------------------------------------------------------------

	Colour* edColour = nullptr;
	Button* edButton = nullptr;
	//
	void* parent = nullptr;
	void updateValuesFromProcessor();
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
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextButton> textButton_PlayingColour;
    std::unique_ptr<Label> label3;
    std::unique_ptr<TextButton> textButton_QueuedColour;
    std::unique_ptr<Label> label6;
    std::unique_ptr<TextButton> textButton_Group;
    std::unique_ptr<Label> label4;
    std::unique_ptr<TextButton> textButton_GroupStop;
    std::unique_ptr<Label> label5;
    std::unique_ptr<TextButton> textButton_BackTo;
    std::unique_ptr<ComboBox> comboBox_PlaybackType;
    std::unique_ptr<Label> label10;
    std::unique_ptr<ToggleButton> toggleButton_MultiTrigger;
    std::unique_ptr<ToggleButton> toggleButton_Looped;
    std::unique_ptr<TextButton> textButton_Filename;
    std::unique_ptr<ToggleButton> toggleButton_Embedded;
    std::unique_ptr<ToggleButton> toggleButton_InstantStop;
    std::unique_ptr<TextButton> textButton_ImagePlaying;
    std::unique_ptr<TextButton> textButton_ImageQueued;
    std::unique_ptr<Label> label11;
    std::unique_ptr<ToggleButton> toggleButton_DragVolume;
    std::unique_ptr<TextButton> textButton_DragVolumeMin;
    std::unique_ptr<Label> label12;
    std::unique_ptr<TextButton> textButton_DragVolumeMax;
    std::unique_ptr<Label> label13;
    std::unique_ptr<ComboBox> comboBox_RecordType;
    std::unique_ptr<Label> label14;
    std::unique_ptr<Label> label15;
    std::unique_ptr<TextButton> textButton_Measures;
    std::unique_ptr<Label> label16;
    std::unique_ptr<TextButton> textButton_QueuedStopColour;
    std::unique_ptr<TextButton> textButton_ImageStop;
    std::unique_ptr<ToggleButton> toggleButton_LoopedSynced;
    std::unique_ptr<ComboBox> comboBox_RecordSource;
    std::unique_ptr<Label> label18;
    std::unique_ptr<Label> label19;
    std::unique_ptr<TextButton> textButton_RecordColour;
    std::unique_ptr<TextButton> textButton_ImageRecord;
    std::unique_ptr<ComboBox> comboBox_MouseVolumeType;
    std::unique_ptr<ComboBox> comboBox_RecordMouse;
    std::unique_ptr<Label> label20;
    std::unique_ptr<Label> labelFadeState;
    std::unique_ptr<ComboBox> comboBox_FadeState;
    std::unique_ptr<ToggleButton> toggleButton_StopOnEnvelopeEnd;
    std::unique_ptr<TextButton> textButton_Volume;
    std::unique_ptr<ToggleButton> toggleButton_ColoursToFont;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SoundOptions)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

