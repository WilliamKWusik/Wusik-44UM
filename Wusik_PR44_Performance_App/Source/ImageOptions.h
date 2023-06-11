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
                      public Button::Listener,
                      public ComboBox::Listener
{
public:
    //==============================================================================
    ImageOptions ();
    ~ImageOptions();

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
    std::unique_ptr<Label> label3;
    std::unique_ptr<TextButton> textButton_BackColour;
    std::unique_ptr<Label> label7;
    std::unique_ptr<Label> objectType;
    std::unique_ptr<TextButton> textButton_Image;
    std::unique_ptr<TextButton> textButton_Duplicate;
    std::unique_ptr<TextButton> textButton_Delete;
    std::unique_ptr<ComboBox> comboBox_Screen;
    std::unique_ptr<Label> label10;
    std::unique_ptr<TextButton> textButton_ImageScale;
    std::unique_ptr<Label> label11;
    std::unique_ptr<ToggleButton> toggleButton_ImageStretch;
    std::unique_ptr<ToggleButton> toggleButton_ImageToBack;
    std::unique_ptr<TextButton> textButton_Shadow;
    std::unique_ptr<Label> label12;
    std::unique_ptr<TextButton> textButton_RoundSquare;
    std::unique_ptr<Label> label2;
    std::unique_ptr<TextButton> textButton_ImageAlpha;
    std::unique_ptr<ToggleButton> toggleButton_ImageCut;
    std::unique_ptr<TextButton> textButton_Name;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Label> label6;
    std::unique_ptr<TextButton> textButton_FontColour;
    std::unique_ptr<Label> label8;
    std::unique_ptr<TextButton> textButton_HorizontalPos;
    std::unique_ptr<Label> label9;
    std::unique_ptr<TextButton> textButton_VerticalPos;
    std::unique_ptr<TextButton> textButton_FontSize;
    std::unique_ptr<Label> label4;
    std::unique_ptr<ToggleButton> toggleButton_ShowName;
    std::unique_ptr<TextEditor> textEditor_Multi;
    std::unique_ptr<Label> label13;


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

