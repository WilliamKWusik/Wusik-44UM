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
class ImageOptions  : public Component,
                      public ChangeListener,
                      TextEditor::Listener,
                      public juce::Button::Listener,
                      public juce::ComboBox::Listener
{
public:
    //==============================================================================
    ImageOptions ();
    ~ImageOptions() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	Colour* edColour = nullptr;
	Button* edButton = nullptr;
	void* sndInterface = nullptr;
	void* buttonInterface = nullptr;
	//
	void* parent = nullptr;
	void updateValuesFromProcessor();
	void changeListenerCallback(ChangeBroadcaster* source) override;
	void textEditorTextChanged(TextEditor& txtEditor) override;
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
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::TextButton> textButton_BackColour;
    std::unique_ptr<juce::Label> label7;
    std::unique_ptr<juce::Label> objectType;
    std::unique_ptr<juce::TextButton> textButton_Image;
    std::unique_ptr<juce::TextButton> textButton_Duplicate;
    std::unique_ptr<juce::TextButton> textButton_Delete;
    std::unique_ptr<juce::ComboBox> comboBox_Screen;
    std::unique_ptr<juce::Label> label10;
    std::unique_ptr<juce::TextButton> textButton_ImageScale;
    std::unique_ptr<juce::Label> label11;
    std::unique_ptr<juce::ToggleButton> toggleButton_ImageStretch;
    std::unique_ptr<juce::ToggleButton> toggleButton_ImageToBack;
    std::unique_ptr<juce::TextButton> textButton_Shadow;
    std::unique_ptr<juce::Label> label12;
    std::unique_ptr<juce::TextButton> textButton_RoundSquare;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::TextButton> textButton_ImageAlpha;
    std::unique_ptr<juce::ToggleButton> toggleButton_ImageCut;
    std::unique_ptr<juce::TextButton> textButton_Name;
    std::unique_ptr<juce::Label> label5;
    std::unique_ptr<juce::Label> label6;
    std::unique_ptr<juce::TextButton> textButton_FontColour;
    std::unique_ptr<juce::Label> label8;
    std::unique_ptr<juce::TextButton> textButton_HorizontalPos;
    std::unique_ptr<juce::Label> label9;
    std::unique_ptr<juce::TextButton> textButton_VerticalPos;
    std::unique_ptr<juce::TextButton> textButton_FontSize;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::ToggleButton> toggleButton_ShowName;
    std::unique_ptr<juce::TextEditor> textEditor_Multi;
    std::unique_ptr<juce::Label> label13;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImageOptions)
};

//[EndFile] You can add extra defines here...


// ------------------------------------------------------------------------------------------------------------------------------------
class ImageOptionsWindow : public DocumentWindow, public Timer
{
public:
	ImageOptionsWindow(void* _processor);
	ImageOptions* options = nullptr;
	ScopedPointer<WToolTipWindow> tooltipWindow;
	void closeButtonPressed() override;
	bool keyPressed(const KeyPress &key) override;
	void timerCallback() override;
	//
	void* processor;
	//
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImageOptionsWindow)
};

//[/EndFile]

