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
#include "PluginProcessor.h"

class WToolTipWindow;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class WOptions  : public Component,
                  public ChangeListener,
                  public juce::Button::Listener,
                  public juce::ComboBox::Listener
{
public:
    //==============================================================================
    WOptions ();
    ~WOptions() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	Colour* edColour = nullptr;
	Button* edButton = nullptr;
	StringArray fontsArray;

	void* parent;
	void updateValuesFromProcessor();
	void changeListenerCallback(ChangeBroadcaster* source) override;
	TextButton* getTextButton_Volume() { return textButton_Volume.get(); };
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
    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> textButton_Play;
    std::unique_ptr<juce::TextButton> textButton_CloseEditor;
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::TextButton> textButton_BackColour;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::TextButton> textButton_BackImage;
    std::unique_ptr<juce::Label> label6;
    std::unique_ptr<juce::TextButton> textButtonScreenA;
    std::unique_ptr<juce::TextButton> textButtonScreenB;
    std::unique_ptr<juce::TextButton> textButtonScreenC;
    std::unique_ptr<juce::TextButton> textButtonScreenD;
    std::unique_ptr<juce::ToggleButton> toggleButton_InternalClock;
    std::unique_ptr<juce::Label> label7;
    std::unique_ptr<juce::Label> label8;
    std::unique_ptr<juce::TextButton> textButton_BPM;
    std::unique_ptr<juce::ToggleButton> toggleButton_ImageStretch;
    std::unique_ptr<juce::Label> label10;
    std::unique_ptr<juce::TextButton> textButton_BeatFlash;
    std::unique_ptr<juce::ToggleButton> toggleButton_AutoStart;
    std::unique_ptr<juce::TextButton> textButton_ResetAll;
    std::unique_ptr<juce::TextButton> textButton_Measures;
    std::unique_ptr<juce::Label> label9;
    std::unique_ptr<juce::Label> label12;
    std::unique_ptr<juce::TextButton> textButton_BeatFlashMeasure;
    std::unique_ptr<juce::TextButton> textButton_BeatFlashFirst;
    std::unique_ptr<juce::TextButton> textButton_Export;
    std::unique_ptr<juce::TextButton> textButton_Import;
    std::unique_ptr<juce::Label> label14;
    std::unique_ptr<juce::Label> labelFadeState;
    std::unique_ptr<juce::ComboBox> comboBox_EnvelopeState;
    std::unique_ptr<juce::Label> label15;
    std::unique_ptr<juce::TextButton> textButton_BackImageScale;
    std::unique_ptr<juce::Label> label16;
    std::unique_ptr<juce::TextButton> textButton_Volume;
    std::unique_ptr<juce::ToggleButton> toggleButton_VolumeAuto;
    std::unique_ptr<juce::Label> label17;
    std::unique_ptr<juce::TextButton> textButton_ImageAlpha;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WOptions)
};

//[EndFile] You can add extra defines here...

// ------------------------------------------------------------------------------------------------------------------------------------
class OptionsWindow : public DocumentWindow, public Timer
{
public:
	OptionsWindow(void* _processor);
	void closeButtonPressed() override;
	bool keyPressed(const KeyPress &key) override;
	void timerCallback() override;
	//
	ScopedPointer<WToolTipWindow> tooltipWindow;
	void* processor;
	WOptions* options = nullptr;
	//
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OptionsWindow)
};

//[/EndFile]

