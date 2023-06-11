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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "EditCompo.h"
#include "PluginEditor.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
EditCompo::EditCompo ()
{
    //[Constructor_pre] You can add your own custom stuff here..

	ScopedPointer<WPR44LookAndFeel> wsLookAndFeel = new WPR44LookAndFeel;
	wsLookAndFeel->setDefaultSansSerifTypefaceName("Verdana");
	setLookAndFeel(wsLookAndFeel.release());

    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

EditCompo::~EditCompo()
{
    //[Destructor_pre]. You can add your own custom destruction code here..

	setLookAndFeel(nullptr);

	ARRAY_Iterator(dasButtons)
	{
		dasButtons[index]->removeListener(this);
	}

    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void EditCompo::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

	g.fillAll(processor->backColour);
	//
	if (processor->backgroundImage.isValid())
	{
		g.setColour(Colours::black);
		g.setOpacity(1.0f - processor->backTransparency);
		if (processor->backgroundImageStretch) g.drawImage(processor->backgroundImage, 0, 0, getWidth(), getHeight(), 0, 0, processor->backgroundImage.getWidth(), processor->backgroundImage.getHeight());
		else if (processor->backImageScale != 1.0f)
		{
			g.drawImage(processor->backgroundImage, 0, 0,
				int(processor->backImageScale * float(processor->backgroundImage.getWidth())),
				int(processor->backImageScale * float(processor->backgroundImage.getHeight())),
				0, 0, processor->backgroundImage.getWidth(), processor->backgroundImage.getHeight());

		}
		else g.drawImageAt(processor->backgroundImage, 0, 0);
		g.setOpacity(1.0f);
	}

	if (processor->flashTime > 0)
	{
		Colour useThisColour = processor->beatFlashColour;
		if (processor->sequencerClock.beat == 0) useThisColour = processor->beatFlashFirstBeatColour;
		if (processor->sequencerClock.measureJustStarted)
		{
			processor->sequencerClock.measureJustStarted = false;
			useThisColour = processor->beatFlashFirstMeasureColour;
		}
		//
		g.setColour(useThisColour);
		g.fillAll(useThisColour);
	}

	if (processor->isEditing)
	{
		if (processor->showGrid)
		{
			g.setColour(processor->gridColour);
			//
			for (int xx = 0; xx < getWidth(); xx += processor->gridSize)
			{
				for (int yy = 0; yy < getHeight(); yy += processor->gridSize)
				{
					g.drawLine(xx + 26, 0, xx + 26, getHeight());
					g.drawLine(0, yy + 26, getWidth(), yy + 26);
				}
			}
		}

		if (processor->leObjects.size() == 0)
		{
			g.setFont(processor->globalFont.withHeight(36.0f));
			g.setColour(Colours::orangered);
			//
			g.drawFittedText("Click on an empty area to add an object.", getLocalBounds(), Justification::centred, 1);
		}

		if (processor->loadingAudiosPosition != -1)
		{
			g.setFont(processor->globalFont.withHeight(36.0f));
			g.setColour(Colours::orangered);
			//
			g.drawFittedText("Loading Audio Data: " + String(processor->loadingAudiosPosition + 1) + "/" + String(processor->leObjects.size()), getLocalBounds(), Justification::centred, 1);
		}
	}

    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void EditCompo::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void EditCompo::filesDropped (const StringArray& filenames, int mouseX, int mouseY)
{
    //[UserCode_filesDropped] -- Add your code here...
    //[/UserCode_filesDropped]
}

void EditCompo::mouseMove (const MouseEvent& e)
{
    //[UserCode_mouseMove] -- Add your code here...

	//static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserCode_mouseMove]
}

void EditCompo::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (processor->isEditing)
	{
		if (processor->objectOptionsWindow != nullptr) processor->objectOptionsWindow->setVisible(false);
		if (processor->imageWindow != nullptr) processor->imageWindow->setVisible(false);
		if (processor->imageWindow != nullptr) processor->imageWindow->setVisible(false);
		//
		processor->selectedObject = nullptr;
		processor->mainWindow->repaint();
		//
		if (e.mods.isRightButtonDown())
		{
			if (processor->optionsWindow == nullptr) processor->optionsWindow = new OptionsWindow(parent);
			else processor->optionsWindow->setVisible(true);
			//
			/*ShowValue(1);
			if (processor->selectedObject != nullptr) ShowValue(999);*/
		}
		else
		{
			PopupMenu mm;
			mm.addItem(1, "Audio");
			mm.addItem(2, "Button");
			mm.addItem(3, "Image/Label");
			//
			mm.addSeparator();
			if (processor->optionsWindow == nullptr || !processor->optionsWindow->isVisible()) mm.addItem(9, "Open Options");
			mm.addItem(8, "Close Editor");
			//
			int result = mm.show();
			//
			if (result > 0)
			{
				if (result == 8)
				{
					processor->mainWindow->closeButtonPressed();
					processor->sequencerClock.stop();
					return;
				}
				else if (result == 9)
				{
					if (processor->optionsWindow == nullptr) processor->optionsWindow = new OptionsWindow(parent);
					else processor->optionsWindow->setVisible(true);
				}
				else
				{
					int creatingButtonType = result - 1;
					WPR44Object* cloneThis = nullptr;
					//
					ARRAY_Iterator(processor->leObjects)
					{
						if (processor->leObjects[index]->type == creatingButtonType) cloneThis = processor->leObjects[index];
					}
					//
					if (cloneThis != nullptr)
					{
						processor->duplicateObject(cloneThis, getSnapToGrid(e.position.getX() - (processor->gridSize / 2)), getSnapToGrid(e.position.getY() - (processor->gridSize / 2)));
						if (creatingButtonType == WPR44Object::kType_Sound)
						{
							if (processor->loadAudioDialog((WPR44SoundObject*)processor->leObjects.getLast()).isEmpty())
							{
								processor->selectedObject = nullptr;
								processor->leObjects.removeLast();
								dasButtons.removeLast();
								processor->objectOptionsWindow->setVisible(false);
							}
						}
					}
					else
					{
						leButton* creatingButton = new leButton((WusikPr44AudioProcessor*)parent);
						if (lastSize[0] == 0) lastSize[0] = lastSize[1] = processor->gridSize * 2;
						creatingButton->setBounds(getSnapToGrid(e.position.getX() - (processor->gridSize / 2)), getSnapToGrid(e.position.getY() - (processor->gridSize / 2)), lastSize[0], lastSize[1]);
						creatingButton->gridSize = &processor->gridSize;
						creatingButton->snapToGrid = &processor->snapToGrid;
						creatingButton->addListener(this);
						dasButtons.add(creatingButton);
						addAndMakeVisible(creatingButton);
						//
						processor->selectedObject = nullptr;
						//
						if (creatingButtonType == WPR44Object::kType_Sound)
						{
							processor->leObjects.add(new WPR44SoundObject(processor->numberOfMeasures, processor->lastBPM, processor->lastSampleRate, processor->isStereo));
							if (processor->loadAudioDialog((WPR44SoundObject*)processor->leObjects.getLast()).isEmpty())
							{
								processor->selectedObject = nullptr;
								processor->leObjects.removeLast();
								dasButtons.removeLast();
								processor->objectOptionsWindow->setVisible(false);
								repaint();
								return;
							}
						}
						else if (creatingButtonType == WPR44Object::kType_Button) processor->leObjects.add(new WPR44ButtonObject);
						else if (creatingButtonType == WPR44Object::kType_Image) processor->leObjects.add(new WPR44Object);
						else return;
						//
						String newName = "Object #" + String(processor->newObjectCounter);
						int appendChar = 'b';
						bool foundOne = true;
						while (foundOne)
						{
							foundOne = false;
							ARRAY_Iterator(processor->leObjects)
							{
								if (processor->leObjects[index]->name.compareIgnoreCase(newName) == 0)
								{
									foundOne = true;
									newName = "Object #" + String(processor->newObjectCounter) + String::charToString(appendChar);
									appendChar++;
								}
							}
						}
						//
						processor->leObjects.getLast()->name = newName;
						processor->newObjectCounter++;
						//
						dasButtons.getLast()->leObject = processor->leObjects.getLast();
						processor->selectedObject = dasButtons.getLast()->leObject;
						dasButtons.getLast()->leObject->screen = processor->showingScreen;
						processor->leObjects.getLast()->type = creatingButtonType;
						processor->selectedObject->justSelected = true;
						//
						File templateFile = processor->dataPath + "Templates" + File::getSeparatorString() + "Last" + String(creatingButtonType + 1) + ".WPR44LastTemplate";
						if (templateFile.existsAsFile())
						{
							MemoryBlock destData;
							templateFile.loadFileAsData(destData);
							MemoryInputStream dataStream2(destData.getData(), destData.getSize(), false);
							processor->putObjectSettings(dataStream2, processor->leObjects.getLast(), true);
							processor->loadImages();
						}
						//
						if (processor->objectOptionsWindow != nullptr) processor->objectOptionsWindow->setVisible(false);
						if (processor->imageWindow != nullptr) processor->imageWindow->setVisible(false);
						//
						if (creatingButtonType == WPR44Object::kType_Image) dasButtons.getLast()->toBack();
						//
						if (creatingButtonType == WPR44Object::kType_Sound || creatingButtonType == WPR44Object::kType_Button)
						{
							if (processor->objectOptionsWindow == nullptr) processor->objectOptionsWindow = new ObjectOptionsWindow(parent);
							else
							{
								processor->objectOptionsWindow->setVisible(true);
								processor->objectOptionsWindow->options->updateValuesFromProcessor();
							}
						}
						else if (creatingButtonType == WPR44Object::kType_Image)
						{
							if (processor->imageWindow == nullptr) processor->imageWindow = new ImageOptionsWindow(parent);
							else
							{
								processor->imageWindow->setVisible(true);
								processor->imageWindow->options->updateValuesFromProcessor();
							}
						}
						//
						repaint();
					}
				}
			}
		}
	}
	//
	repaint();
	//
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

int EditCompo::getSnapToGrid(int value)
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (processor->snapToGrid) return int(float(int(float(value) / processor->gridSize)) * processor->gridSize); else return value;
}


void EditCompo::updateObjects()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	ARRAY_Iterator(dasButtons)
	{
		dasButtons[index]->setVisible(dasButtons[index]->leObject->screen == processor->showingScreen);
	}
}

void EditCompo::buttonClicked(Button* buttonThatWasClicked)
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	processor->selectObject(((leButton*)buttonThatWasClicked)->leObject);
	//
	if (!((leButton*)buttonThatWasClicked)->wasOpenMenu)
	{
		if (((leButton*)buttonThatWasClicked)->leObject->type == WPR44Object::kType_Sound)
		{
			processor->stopAllSounds = true;
			WPR44SoundObject* sndObject = (WPR44SoundObject*)((leButton*)buttonThatWasClicked)->leObject;
			if (sndObject->voices.size() == 0) processor->queueSndPlaybacks.add(sndObject);
		}
	}
}

void EditCompo::createButtons()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	ARRAY_Iterator(processor->leObjects)
	{
		leButton* creatingButton = new leButton(processor);
		creatingButton->setBounds(processor->leObjects[index]->position);
		creatingButton->gridSize = &processor->gridSize;
		creatingButton->snapToGrid = &processor->snapToGrid;
		creatingButton->leObject = processor->leObjects[index];
		creatingButton->addListener(this);
		dasButtons.add(creatingButton);
		addAndMakeVisible(creatingButton);
	}
	//
	processor->newObjectCounter = processor->leObjects.size() + 1;
	//
	ARRAY_Iterator(dasButtons)
	{
		if (dasButtons[index]->leObject->type == WPR44Object::kType_Image) dasButtons[index]->toBack();
	}
	//
	ARRAY_Iterator(dasButtons)
	{
		if (dasButtons[index]->leObject->toBack) dasButtons[index]->toBack();
	}
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="EditCompo" componentName=""
                 parentClasses="public Component, public FileDragAndDropTarget, public Button::Listener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="600"
                 initialHeight="400">
  <METHODS>
    <METHOD name="filesDropped (const StringArray&amp; filenames, int mouseX, int mouseY)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
    <METHOD name="mouseMove (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

