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
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class IntroMenu  : public Component,
                   public juce::Button::Listener
{
public:
    //==============================================================================
    IntroMenu ();
    ~IntroMenu() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	TextButton* gettextButtonLaunch() { return textButtonLaunch.get(); };
	TextButton* gettextButtonEdit() { return textButtonEdit.get(); };

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* logo_png;
    static const int logo_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::TextButton> textButtonLaunch;
    std::unique_ptr<juce::TextButton> textButtonEdit;
    juce::Image cachedImage_logo_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IntroMenu)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

