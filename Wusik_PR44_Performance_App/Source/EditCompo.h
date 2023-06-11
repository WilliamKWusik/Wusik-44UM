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
#include "Options.h"''
#include "LeButton.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class EditCompo  : public Component,
                   public FileDragAndDropTarget,
                   public Button::Listener
{
public:
    //==============================================================================
    EditCompo ();
    ~EditCompo();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void* parent;
	bool isInterestedInFileDrag(const StringArray &files) override { return true; };
	void createButtons();
	int getSnapToGrid(int value);
	void updateObjects();
	void buttonClicked(Button* buttonThatWasClicked) override;
	bool keyPressed(const KeyPress &key) 
	{
		if (!((WusikPr44AudioProcessor*)parent)->isEditing && key.getKeyCode() == KeyPress::F4Key && key.getModifiers().isAltDown())
		{
			if (ConfirmBox("Close The Window (stops the audio/sequencer)", "Are you sure?")) ((WusikPr44AudioProcessor*)parent)->mainWindow->closeButtonPressed();
			return true;
		}
		else if (((WusikPr44AudioProcessor*)parent)->isEditing && key.getKeyCode() == KeyPress::F4Key && key.getModifiers().isAltDown())
		{
			((WusikPr44AudioProcessor*)parent)->mainWindow->closeButtonPressed();
			return true;
		}
		else if (((WusikPr44AudioProcessor*)parent)->keyPressHandle(key)) return true;
		//
		return false;
	}
	//
	OwnedArray<leButton> dasButtons;
	OwnedArray<WZoomCompo> zoomCompos;
	int lastSize[2] = { 0, 0 };

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void filesDropped (const StringArray& filenames, int mouseX, int mouseY) override;
    void mouseMove (const MouseEvent& e) override;
    void mouseUp (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (EditCompo)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

