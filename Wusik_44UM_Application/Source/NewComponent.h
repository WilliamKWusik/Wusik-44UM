/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 7.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class NewComponent  : public juce::Component,
                      public juce::ComboBox::Listener,
                      public juce::Button::Listener
{
public:
    //==============================================================================
    NewComponent ();
    ~NewComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* logo_w100_100_png;
    static const int logo_w100_100_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::ComboBox> comboBox_Page;
    std::unique_ptr<juce::TextButton> button_1;
    std::unique_ptr<juce::TextButton> button_2;
    std::unique_ptr<juce::TextButton> button_3;
    std::unique_ptr<juce::TextButton> button_4;
    std::unique_ptr<juce::TextButton> button_5;
    std::unique_ptr<juce::TextButton> button_6;
    std::unique_ptr<juce::TextButton> button_7;
    std::unique_ptr<juce::TextButton> button_8;
    std::unique_ptr<juce::TextButton> button_9;
    std::unique_ptr<juce::TextButton> button_10;
    std::unique_ptr<juce::TextButton> button_11;
    std::unique_ptr<juce::TextButton> button_12;
    std::unique_ptr<juce::TextButton> button_13;
    std::unique_ptr<juce::TextButton> button_14;
    std::unique_ptr<juce::TextButton> button_15;
    std::unique_ptr<juce::TextButton> button_16;
    std::unique_ptr<juce::TextButton> button_17;
    std::unique_ptr<juce::TextButton> button_18;
    std::unique_ptr<juce::TextButton> textButton_File;
    juce::Image cachedImage_logo_w100_100_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

