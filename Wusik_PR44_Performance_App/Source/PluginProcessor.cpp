/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
#include "PluginProcessor.h"
#include "PluginEditor.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
WusikPr44AudioProcessor::WusikPr44AudioProcessor() : sequencerClock(numberOfMeasures, lastBPM, lastSampleRate, flashBeat)
{
	dataPath = File::addTrailingSeparator(readGlobalSettings("Data Path", ""));
	//
	if (dataPath.isNotEmpty() && File(dataPath).exists() && File(dataPath + "Projects Exported").exists())
	{
		loadData();
	}
	else
	{
		dataPath = String();
		initErrorMessage = "Click here to find the location of the Data folder.\n(it should contain the Projects Exported folder)";
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::loadData()
{
	PropertiesFile::Options propOptions;
	propOptions.applicationName = "Wusik PR44";
	userSettings = new PropertiesFile(File(dataPath + "Wusik PR44 Settings.xml"), propOptions);
	//
	if (userSettings == nullptr)
	{
		initErrorMessage = "Fatal error loading/creating the settings file:\n\n" + dataPath + "Settings.xml";
		dataPath = String();
	}
	else
	{
		audioFormatManager.registerBasicFormats();
		//
		if (!userSettings->getBoolValue("Complete Settings"))
		{
			userSettings->setValue("Background Colour", "#FF444444");
			userSettings->setValue("Beat Flash Colour", "#44FF0000");
			userSettings->setValue("Beat First Flash Colour", "#66FF6666");
			userSettings->setValue("Measure Flash Colour", "#666666FF");
			userSettings->setValue("Grid Colour", "#06FFFFFF");
			userSettings->setValue("Grid Size", 50.0);
			userSettings->setValue("Snap To Grid", true);
			userSettings->setValue("Show Grid", true);
			userSettings->setValue("Auto Start Clock", true);
			userSettings->setValue("Global Font Name", "Verdana");
			userSettings->setValue("Auto Flash Decay", 120);
			userSettings->setValue("Disable F5 Switch Key", false);
			userSettings->setValue("Back Image Path", dataPath + "Images");
			userSettings->setValue("Image Path", dataPath + "Images");
			//
			userSettings->setValue("Complete Settings", true);
		}
		//
		snapToGrid = userSettings->getBoolValue("Snap To Grid");
		gridSize = userSettings->getDoubleValue("Grid Size");
		showGrid = userSettings->getBoolValue("Show Grid");
		autoStartClock = userSettings->getBoolValue("Auto Start Clock");
		gridColour = Colour::fromString(userSettings->getValue("Grid Colour"));
		backColour = Colour::fromString(userSettings->getValue("Background Colour"));
		beatFlashColour = Colour::fromString(userSettings->getValue("Beat Flash Colour"));
		beatFlashFirstBeatColour = Colour::fromString(userSettings->getValue("Beat First Flash Colour"));
		beatFlashFirstMeasureColour = Colour::fromString(userSettings->getValue("Measure Flash Colour"));
		lastBackImagePath = userSettings->getValue("Back Image Path");
		lastLoadedAudioPath = userSettings->getValue("Audio Path");
		lastLoadedImage = userSettings->getValue("Image Path");
		globalFontName = "Verdana";
		globalFont = Font(globalFontName, 32.0f, 0);
		beatFlashDecayMS = userSettings->getIntValue("Auto Flash Decay");
		disableF5SwitchKey = userSettings->getBoolValue("Disable F5 Switch Key");
		//
		dataLoaded = true;
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::loadBackgroundImage()
{
	if (!dataLoaded) return;
	//
	backgroundImage = Image();
	if (backImage.existsAsFile())
	{
		backgroundImage = ImageFileFormat::loadFrom(backImage);
	}
	else
	{
		String theImage = backImage.getFileName();
		ScopedPointer<DirectoryIterator> findImage = new DirectoryIterator(dataPath + "Images", true, "*", File::findFiles);
		while (findImage->next())
		{
			if (findImage->getFile().getFileName().compareIgnoreCase(theImage) == 0)
			{
				backImage = findImage->getFile();
				backgroundImage = ImageFileFormat::loadFrom(backImage); 
				break;
			}
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
String WusikPr44AudioProcessor::loadAudioDialog(WPR44SoundObject* soundObject)
{
	String theBPM = String(internalBPM);
	if (!internalClock) theBPM = "Host/" + String(lastBPM);
	//
	FileChooser loadFile("IMPORTANT! Audio must be in the same SampleRate and BPM as the project! Project Sample Rate: " + String(lastSampleRate) + " | BPM: " + theBPM, lastLoadedAudioPath, String("*"));
	if (loadFile.browseForFileToOpen())
	{
		lastLoadedAudioPath = loadFile.getResult().getParentDirectory();
		userSettings->setValue("Audio Path", lastLoadedAudioPath.getFullPathName());
		soundObject->soundFilename = loadFile.getResult().getFullPathName();
		soundObject->reloadAudio = true;
		soundObject->playOnLoad = autoPlayAudioOnLoad;
		loadAudios();
		mainWindow->repaint();
		//
		return soundObject->soundFilename;
	}
	//
	return String();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
bool WusikPr44AudioProcessor::keyPressHandle(const KeyPress &key)
{
	if (key.getKeyCode() == key.F5Key && !disableF5SwitchKey)
	{
		switchInterfaces = true;
		return true;
	}
	else
	{
		ARRAY_Iterator(leObjects)
		{
			if (leObjects[index]->pcKeyPress.isValid() && leObjects[index]->pcKeyPress == key)
			{
				objectTriggered(leObjects[index]);
			}
		}
	}
	//
	return false;
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::objectStopGroup(String groupName, WPR44Object* ignoreThis)
{
	ARRAY_Iterator(leObjects)
	{
		if (leObjects[index] != ignoreThis && leObjects[index]->type == WPR44Object::kType_Sound)
		{
			WPR44SoundObject* soundObject = (WPR44SoundObject*)leObjects[index];
			//
			if (soundObject->group.compareIgnoreCase(groupName) == 0)
			{
				soundObject->envelopeTarget = 0.0f;
				soundObject->envelopeRate = 0.01f;
				//
				if (mainWindow != nullptr)
				{
					EditCompo* edCompo = (EditCompo*)mainWindow->getContentComponent();
					//
					ARRAY_Iterator(edCompo->dasButtons)
					{
						if (edCompo->dasButtons[index]->leObject == soundObject)
						{
							edCompo->dasButtons[index]->repaint();
							break;
						}
					}
				}
			}
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::objectTriggered(WPR44Object* object)
{
	leButton* button = nullptr;
	//
	if (mainWindow != nullptr)
	{
		EditCompo* edCompo = (EditCompo*)mainWindow->getContentComponent();
		//
		ARRAY_Iterator(edCompo->dasButtons)
		{
			if (edCompo->dasButtons[index]->leObject == object)
			{
				button = edCompo->dasButtons[index];
				break;
			}
		}
	}
	//
	if (object->type == WPR44Object::kType_Button)
	{
		WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)object;
		//
		if (buttonObject->action == WPR44Object::kAction_Panic)
		{
			queueSndPlaybacks.clear();
			useThisFadeRate = buttonObject->fadeRate;
			stopAllSounds = true;
			//
			ARRAY_Iterator(leObjects)
			{
				if (leObjects[index]->type == WPR44Object::kType_Sound)
				{
					WPR44SoundObject* soundObject = (WPR44SoundObject*)leObjects[index];
					soundObject->isQueuedToPlay = false;
					soundObject->isQueuedToPlayMulti = false;
					soundObject->isQueuedToStop = false;
				}
			}
		}
		else if (buttonObject->action == WPR44Object::kAction_MultiStarter)
		{
			selectingMultipleObjectsToPlay = !selectingMultipleObjectsToPlay;
		}
		else if (buttonObject->action == WPR44Object::kAction_CloseApp_Confirm)
		{
			if (JUCEApplication::isStandaloneApp())
			{
				if (ConfirmBox("Quit Application?", "")) JUCEApplication::quit();
			}
			else
			{
				if (ConfirmBox("Close Window?", ""))
				{
					mainWindow->closeButtonPressed();
					sequencerClock.stop();
					return;
				}
			}
		}
		else if (buttonObject->action == WPR44Object::kAction_CloseApp)
		{
			if (JUCEApplication::isStandaloneApp()) JUCEApplication::quit();
			else
			{
				mainWindow->closeButtonPressed();
				sequencerClock.stop();
				return;
			}
		}
		else if (buttonObject->action == WPR44Object::kAction_SendMIDICC)
		{
			midiOutFromActionButtons.addEvent(MidiMessage::controllerEvent(buttonObject->midiValues[0], buttonObject->midiValues[1], buttonObject->midiValues[2]), 0);
		}
		else if (buttonObject->action == WPR44Object::kAction_SendMIDINote)
		{
			midiOutFromActionButtons.addEvent(MidiMessage::noteOn(buttonObject->midiValues[0], buttonObject->midiValues[1], (uint8) buttonObject->midiValues[2]), 0);
			midiOutFromActionButtonsNoteOff[1].addEvent(MidiMessage::noteOff(buttonObject->midiValues[0], buttonObject->midiValues[1], (uint8)buttonObject->midiValues[2]), 0);
		}
		else if (buttonObject->action >= WPR44Object::kAction_ScreenA && buttonObject->action <= WPR44Object::kAction_ScreenD)
		{
			showingScreen = buttonObject->action - WPR44Object::kAction_ScreenA;
			((EditCompo*)mainWindow->getContentComponent())->updateObjects();
			mainWindow->repaint();
			if (isEditing && optionsWindow != nullptr && optionsWindow->options != nullptr) optionsWindow->options->updateValuesFromProcessor();
		}
		else
		{
			buttonActions.add((WPR44ButtonObject*)object);
		}
		//
		// ------------------------- //
		//
		if (buttonObject->action == WPR44Object::kAction_MultiStarter)
		{
			if (selectingMultipleObjectsToPlay && button != nullptr) ((leButton*)button)->clickColour = buttonObject->clickColour; else ((leButton*)button)->clickColour = Colours::transparentBlack;
		}
		else
		{
			if (button != nullptr)
			{
				((leButton*)button)->clickColour = buttonObject->clickColour;
				((leButton*)button)->startTimer(buttonObject->clickDecay);
			}
		}
		//
		if (button != nullptr) ((leButton*)button)->repaint();
	}
	else if (object->type == WPR44Object::kType_Sound)
	{
		WPR44SoundObject* soundObject = (WPR44SoundObject*)object;
		//
		if (!soundObject->mouseDragToVolume)
		{
			bool hasQueuedAlready = false;
			//
			ARRAY_Iterator(queueSndPlaybacks)
			{
				if (queueSndPlaybacks[index] == soundObject)
				{
					hasQueuedAlready = true;
					break;
				}
			}
			//
			if (hasQueuedAlready)
			{
				bool foundOne = true;
				while (foundOne)
				{
					foundOne = false;
					ARRAY_Iterator(queueSndPlaybacks)
					{
						if (queueSndPlaybacks[index] == soundObject)
						{
							foundOne = true;
							queueSndPlaybacks.remove(index);
							break;
						}
					}
				}
			}
			else
			{
				if (soundObject->isQueuedToPlay) soundObject->isQueuedToPlay = false;
				else
				{
					queueSndPlaybacks.add(soundObject);
					if (selectingMultipleObjectsToPlay) soundObject->isQueuedToPlayMulti = true;
				}
			}
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::changeScreenMode()
{
	if (mainWindow != nullptr)
	{
		if (fullscreenMode)
		{
			mainWindow->setFullScreen(true);
			mainWindow->setResizable(false, false);
		}
		else
		{
			mainWindow->setFullScreen(false);
			mainWindow->setResizable(true, true);
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
WusikPr44AudioProcessor::~WusikPr44AudioProcessor()
{
	if (!dataLoaded) return;
	userSettings->saveIfNeeded();
	//
	for (int kk = 0; kk < WPR44Object::kType_Total; kk++)
	{
		WPR44Object* cloneThis = nullptr;
		ARRAY_Iterator(leObjects) { if (leObjects[index]->type == kk) cloneThis = leObjects[index]; }
		//
		if (cloneThis != nullptr)
		{
			File templateFile = dataPath + "Templates" + File::getSeparatorString() + "Last" + String(kk + 1) + ".WPR44LastTemplate";
			templateFile.deleteFile();
			//
			MemoryBlock destData;
			ScopedPointer<MemoryOutputStream> dataStream = new MemoryOutputStream(destData, false);
			getObjectSettings(*dataStream, cloneThis, true);
			dataStream->flush();
			dataStream = nullptr;
			//
			templateFile.replaceWithData(destData.getData(), destData.getSize());
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	//
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
AudioProcessorEditor* WusikPr44AudioProcessor::createEditor()
{
    return new WusikPr44AudioProcessorEditor (*this);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new WusikPr44AudioProcessor();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::loadAudios()
{
	if (!dataLoaded) return;
	//
	suspendProcessing(true);
	loadingAudiosPosition = 0;
	//
	ARRAY_Iterator(leObjects)
	{
		loadingAudiosPosition = index;
		//
		if (leObjects[index]->type == WPR44Object::kType_Sound)
		{
			WPR44SoundObject* soundObject = (WPR44SoundObject*)leObjects[index];
			soundObject->voices.clear();
			//
			if (!soundObject->embeddedAudio)
			{
				if (soundObject->soundFilename.isEmpty()) soundObject->audio.setSize(0, 0);
				else if (soundObject->reloadAudio || soundObject->audio.getNumSamples() == 0)
				{
					ScopedPointer<AudioFormatReader> audioReader = audioFormatManager.createReaderFor(checkFileSampleRate(File(soundObject->soundFilename), lastSampleRate));
					if (audioReader == nullptr)
					{
						WMessageBox("Error Load Audio File", soundObject->soundFilename);
					}
					else
					{
						if (lastSampleRate != audioReader->sampleRate)
						{
							WMessageBox("File is not in the right SampleRate. An internal conversion failed! Sample rate should be: " + String(lastSampleRate) + "\nBut is: " + String(int(audioReader->sampleRate)), soundObject->soundFilename);
						}
						else
						{
							soundObject->sampleRate = audioReader->sampleRate;
							//
							soundObject->audio.setSize(audioReader->numChannels, audioReader->lengthInSamples);
							audioReader->read(&soundObject->audio, 0, audioReader->lengthInSamples, 0, true, true);
						}
						//
						if (soundObject->playOnLoad)
						{
							soundObject->playOnLoad = false;
							soundObject->voices.clear();
							soundObject->newVoice();
						}
					}
					//
					soundObject->reloadAudio = false;
				}
			}
			//
			if (lastSampleRate != soundObject->sampleRate) soundObject->reloadAudio = true;
		}
	}
	//
	suspendProcessing(false);
	loadingAudiosPosition = -1;
	if (mainWindow != nullptr) mainWindow->repaint();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::loadImages()
{
	if (!dataLoaded) return;
	//
	ARRAY_Iterator(leObjects)
	{
		for (int ii = 0; ii < WPR44Object::kImage_Total; ii++)
		{
			if (leObjects[index]->imagesFilename[ii].isNotEmpty())
			{
				bool foundImage = false;
				ARRAY__Iterator(imagesDatabase, dbase)
				{
					if (imagesDatabase[dbase]->filename.compareIgnoreCase(leObjects[index]->imagesFilename[ii]) == 0)
					{
						leObjects[index]->images[ii] = &imagesDatabase[dbase]->image;
						foundImage = true;
						break;
					}
				}
				//
				if (!foundImage)
				{
					if (!File(leObjects[index]->imagesFilename[ii]).existsAsFile())
					{
						String theImage = File(leObjects[index]->imagesFilename[ii]).getFileName();
						ScopedPointer<DirectoryIterator> findImage = new DirectoryIterator(dataPath + "Images", true, "*", File::findFiles);
						while (findImage->next())
						{
							if (findImage->getFile().getFileName().compareIgnoreCase(theImage) == 0)
							{
								leObjects[index]->imagesFilename[ii] = findImage->getFile().getFullPathName();
								break;
							}
						}
					}
					//
					if (File(leObjects[index]->imagesFilename[ii]).existsAsFile())
					{
						imagesDatabase.add(new WPR44ImagesDatabase);
						imagesDatabase.getLast()->image = ImageFileFormat::loadFrom(leObjects[index]->imagesFilename[ii]);
						imagesDatabase.getLast()->filename = leObjects[index]->imagesFilename[ii];
						leObjects[index]->images[ii] = &imagesDatabase.getLast()->image;
					}
					else WMessageBox("Error Loading Image (file not found)!", leObjects[index]->imagesFilename[ii]);
				}
			}
		}
	}
	//
	// Now Check UnUsed Images //
	ARRAY_Iterator(imagesDatabase)
	{
		bool foundOne = false;
		ARRAY__Iterator(leObjects, obj)
		{
			for (int ii = 0; ii < WPR44Object::kImage_Total; ii++)
			{
				if (leObjects[obj]->imagesFilename[ii].compareIgnoreCase(imagesDatabase[index]->filename) == 0)
				{
					foundOne = true;
					break;
				}
			}
			//
			if (foundOne) break;
		}
		//
		if (!foundOne)
		{
			imagesDatabase[index]->image = Image();
			imagesDatabase[index]->filename = String();
		}
	}
	//
	bool foundToDelete = true;
	while (foundToDelete)
	{
		foundToDelete = false;
		//
		ARRAY_Iterator(imagesDatabase)
		{
			if (imagesDatabase[index]->filename.isEmpty())
			{
				foundToDelete = true;
				imagesDatabase.remove(index);
				break;
			}
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::selectObject(WPR44Object* object)
{
	EditCompo* edCompo = (EditCompo*) mainWindow->getContentComponent();
	//
	if (selectedObject != nullptr) selectedObject->justSelected = false;
	selectedObject = object;
	selectedObject->justSelected = true;
	//
	if (objectOptionsWindow != nullptr) objectOptionsWindow->setVisible(false);
	if (imageWindow != nullptr) imageWindow->setVisible(false);
	//
	if (selectedObject->type == WPR44Object::kType_Sound || selectedObject->type == WPR44Object::kType_Button)
	{
		if (objectOptionsWindow == nullptr) objectOptionsWindow = new ObjectOptionsWindow(this);
		else
		{
			objectOptionsWindow->setVisible(true);
			objectOptionsWindow->options->updateValuesFromProcessor();
		}
	}
	else if (selectedObject->type == WPR44Object::kType_Image)
	{
		if (imageWindow == nullptr) imageWindow = new ImageOptionsWindow(this);
		else
		{
			imageWindow->setVisible(true);
			imageWindow->options->updateValuesFromProcessor();
		}
	}
	//
	mainWindow->repaint();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::duplicateObject(WPR44Object* object, int posX, int posY)
{
	if (objectOptionsWindow != nullptr) objectOptionsWindow->setVisible(false);
	EditCompo* edCompo = (EditCompo*)mainWindow->getContentComponent();
	//
	while (edCompo->dasButtons.size() > 0)
	{
		edCompo->removeChildComponent(edCompo->dasButtons.getLast());
		edCompo->dasButtons.getLast()->removeListener(edCompo);
		edCompo->dasButtons.removeLast();
	}
	//
	mainWindow->getContentComponent()->deleteAllChildren();
	//
	MemoryBlock destData;
	ScopedPointer<MemoryOutputStream> dataStream = new MemoryOutputStream(destData, false);
	getObjectSettings(*dataStream, object, true);
	dataStream->flush();
	dataStream = nullptr;
	//
	if (object->type == WPR44Object::kType_Sound) leObjects.add(new WPR44SoundObject(numberOfMeasures, lastBPM, lastSampleRate, isStereo));
	else if (object->type == WPR44Object::kType_Image) leObjects.add(new WPR44Object);
	else if (object->type == WPR44Object::kType_Button) leObjects.add(new WPR44ButtonObject);
	else return;
	//
	newObjectCounter++;
	//
	leObjects.getLast()->name = object->name.upToFirstOccurrenceOf("#", false, false) + "#" + String(newObjectCounter);
	leObjects.getLast()->type = object->type;
	leObjects.getLast()->screen = object->screen;
	//
	MemoryInputStream dataStream2(destData.getData(), destData.getSize(), false);
	putObjectSettings(dataStream2, leObjects.getLast(), true);
	//
	leObjects.getLast()->position = object->position;
	//
	if (posY == -1)
	{
		leObjects.getLast()->position.setX(leObjects.getLast()->position.getX() + 80);
		leObjects.getLast()->position.setY(leObjects.getLast()->position.getY() + 80);
	}
	else
	{
		leObjects.getLast()->position.setX(posX);
		leObjects.getLast()->position.setY(posY);
	}
	//
	loadAudios();
	loadImages();
	//
	edCompo->createButtons();
	edCompo->updateObjects();
	edCompo->repaint();
	//
	selectObject(leObjects.getLast());
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::getMainSettings(MemoryOutputStream& dataStream, bool isTemplate)
{
	#if WDEMONSTRATION_VERSION
		return;
	#else
		//
		if (!dataLoaded) return;
		//
		if (isTemplate) dataStream.writeString("Wusik PR44 Template (c) William Kalfelz"); else dataStream.writeString("Wusik PR44 (c) William Kalfelz");
		dataStream.writeInt(1); // Version
		if (!isTemplate) dataStream.writeInt(lastSampleRate);
		if (!isTemplate) dataStream.writeInt(lastBPM);
		dataStream.writeBool(snapToGrid);
		dataStream.writeFloat(gridSize);
		dataStream.writeBool(showGrid);
		dataStream.writeBool(internalClock);
		dataStream.writeInt(numberOfMeasures);
		dataStream.writeInt(internalBPM);
		dataStream.writeString(gridColour.toString());
		dataStream.writeString(backColour.toString());
		dataStream.writeString(beatFlashColour.toString());
		dataStream.writeString(beatFlashFirstBeatColour.toString());
		dataStream.writeString(beatFlashFirstMeasureColour.toString());
		dataStream.writeString(globalFontName);
		dataStream.writeString(backImage.getFullPathName());
		dataStream.writeBool(autoPlayAudioOnLoad);
		dataStream.writeBool(backgroundImageStretch);
		dataStream.writeBool(autoStartClock);
		dataStream.writeInt(beatFlashDecayMS);
		dataStream.writeFloat(backImageScale);
		dataStream.writeFloat(backTransparency);
		//
		if (!isTemplate)
		{
			dataStream.writeBool(fullscreenMode);
			dataStream.writeString(lastMainWindowSize.toString());
		}
		//
		if (!isTemplate)
		{
			dataStream.writeBool(disableF5SwitchKey);
			dataStream.writeString(selectedTemplate);
			dataStream.writeFloat(initialMasterEnvelopeState);
			dataStream.writeFloat(masterVolume);
			dataStream.writeBool(masterVolumeAutoLower);
		}
	#endif
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::getObjectSettings(MemoryOutputStream& dataStream, WPR44Object* theObject, bool isTemplate)
{
	if (!dataLoaded) return;
	//
	if (isTemplate) dataStream.writeString("Wusik PR44 Template (c) William Kalfelz"); else dataStream.writeString("OBJ");
	dataStream.writeInt(4); // version
	if (!isTemplate) dataStream.writeInt(theObject->screen);
	if (!isTemplate) dataStream.writeString(theObject->position.toString());
	dataStream.writeString(theObject->borderColour.toString());
	dataStream.writeString(theObject->backgroundColour.toString());
	dataStream.writeString(theObject->fontColour.toString());
	dataStream.writeInt(theObject->borderWidth);
	dataStream.writeInt(theObject->namePosition[0]);
	dataStream.writeInt(theObject->namePosition[1]);
	dataStream.writeFloat(theObject->fontSize);
	dataStream.writeFloat(theObject->imageScale);
	dataStream.writeBool(theObject->toBack);
	dataStream.writeBool(theObject->showName);
	for (int ii = 0; ii < WPR44Object::kImage_Total; ii++) { dataStream.writeString(theObject->imagesFilename[ii]); }
	dataStream.writeBool(theObject->imageStretch);
	dataStream.writeBool(theObject->fill);
	dataStream.writeFloat(theObject->roundCorners);
	dataStream.writeFloat(theObject->thickness);
	//
	dataStream.writeBool(theObject->shadowEffectOn);
	dataStream.writeBool(theObject->cutImageUsingBackground);
	dataStream.writeInt(theObject->shadowSettings.radius);
	dataStream.writeString(theObject->shadowSettings.colour.toString());
	dataStream.writeString(theObject->shadowSettings.offset.toString());
	dataStream.writeBool(theObject->borderToFront);
	dataStream.writeBool(theObject->coloursToFont);
	dataStream.writeString(theObject->animationColour.toString());
	dataStream.writeFloat(theObject->backgroundTransparency);
	dataStream.writeString(theObject->zoomColour.toString());
	dataStream.writeInt(theObject->animationType);
	dataStream.writeInt(theObject->zoomType);
	//
	if (!isTemplate)
	{
		dataStream.writeString(theObject->pcKeyPress.getTextDescription());
		dataStream.writeInt(theObject->midiCC);
		dataStream.writeInt(theObject->midiKey);
		dataStream.writeString(theObject->multiLine);
	}
	//
	if (theObject->type == WPR44Object::kType_Image)
	{
		; // Nothing Yet //
	}
	else if (theObject->type == WPR44Object::kType_Button)
	{
		WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)theObject;
		//
		if (!isTemplate)
		{
			dataStream.writeInt(buttonObject->action);
			dataStream.writeInt(buttonObject->midiValues[0]);
			dataStream.writeInt(buttonObject->midiValues[1]);
			dataStream.writeInt(buttonObject->midiValues[2]);
			dataStream.writeString(buttonObject->targetName);
			dataStream.writeInt(buttonObject->clickDecay);
			dataStream.writeInt(buttonObject->fadeRate);
			dataStream.writeBool(buttonObject->isSynced);
			dataStream.writeFloat(buttonObject->initialFadeState);
		}
		//
		dataStream.writeString(buttonObject->clickColour.toString());
	}
	else if (theObject->type == WPR44Object::kType_Sound)
	{
		WPR44SoundObject* soundObject = (WPR44SoundObject*)theObject;
		//
		dataStream.writeString(soundObject->playingColour.toString());
		dataStream.writeString(soundObject->queuedColour.toString());
		dataStream.writeString(soundObject->stopColour.toString());
		//
		if (!isTemplate)
		{
			dataStream.writeString(soundObject->group);
			dataStream.writeString(soundObject->groupStop);
			dataStream.writeString(soundObject->groupGoBackTo);
			dataStream.writeInt(soundObject->playbackType);
			dataStream.writeBool(soundObject->multiTrigger);
			dataStream.writeBool(soundObject->isLooped);
			dataStream.writeBool(soundObject->isLoopedSynced);
			dataStream.writeFloat(soundObject->audioVolume);
			dataStream.writeBool(soundObject->embeddedAudio);
			dataStream.writeBool(soundObject->instantStop);
			dataStream.writeFloat(soundObject->initialFadeState);
		}
		//
		if (!isTemplate)
		{
			dataStream.writeBool(soundObject->mouseDragToVolume);
			dataStream.writeInt(soundObject->mouseDragToVolumeMouseType);
			dataStream.writeFloat(soundObject->mouseDragToVolumeMin);
			dataStream.writeFloat(soundObject->mouseDragToVolumeMax);
			dataStream.writeString(soundObject->soundFilename);
			dataStream.writeInt(soundObject->recordingType);
			dataStream.writeInt(soundObject->measures);
			dataStream.writeString(soundObject->selectedTemplate);
			dataStream.writeBool(soundObject->envelopeOutStopSoundOnEnd);
			//
			if (soundObject->embeddedAudio)
			{
				dataStream.writeInt(sizeof(float)); // Sample Size //
				dataStream.writeInt(soundObject->audio.getNumChannels());
				dataStream.writeInt(soundObject->audio.getNumSamples());
				//
				for (int cc = 0; cc < soundObject->audio.getNumChannels(); cc++)
				{
					dataStream.write(soundObject->audio.getReadPointer(cc), soundObject->audio.getNumSamples() * sizeof(float));
				}
			}
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::getStateInformation (MemoryBlock& destData)
{
	#if WDEMONSTRATION_VERSION
		return;
	#endif
	//
	if (!dataLoaded) return;
	//
	MemoryOutputStream dataStream(destData, false);
	getMainSettings(dataStream, false);
	//
	dataStream.writeInt64(leObjects.size());
	ARRAY_Iterator(leObjects)
	{
		dataStream.writeString(leObjects[index]->name);
		dataStream.writeInt(leObjects[index]->type);
		getObjectSettings(dataStream, leObjects[index], false);
	}
	//
	dataStream.flush();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::putMainSettings(MemoryInputStream& dataStream, bool isTemplate)
{
	#if WDEMONSTRATION_VERSION
		return;
	#else
		//
		if (!dataLoaded) return;
		//
		String header = dataStream.readString();
		int version = dataStream.readInt();
		if (!isTemplate) lastSampleRate = dataStream.readInt();
		if (!isTemplate) lastBPM = dataStream.readInt();
		snapToGrid = dataStream.readBool();
		gridSize = dataStream.readFloat();
		showGrid = dataStream.readBool();
		internalClock = dataStream.readBool();
		numberOfMeasures = dataStream.readInt();
		internalBPM = dataStream.readInt();
		gridColour = Colour::fromString(dataStream.readString());
		backColour = Colour::fromString(dataStream.readString());
		beatFlashColour = Colour::fromString(dataStream.readString());
		beatFlashFirstBeatColour = Colour::fromString(dataStream.readString());
		beatFlashFirstMeasureColour = Colour::fromString(dataStream.readString());
		globalFontName = dataStream.readString();
		backImage = File(dataStream.readString());
		globalFont = Font(globalFontName, 32.0f, 0);
		autoPlayAudioOnLoad = dataStream.readBool();
		backgroundImageStretch = dataStream.readBool();
		autoStartClock = dataStream.readBool();
		beatFlashDecayMS = dataStream.readInt();
		backImageScale = dataStream.readFloat();
		backTransparency = dataStream.readFloat();
		//
		if (!isTemplate)
		{
			fullscreenMode = dataStream.readBool();
			lastMainWindowSize = Rectangle<int>::fromString(dataStream.readString());
		}
		//
		if (!isTemplate)
		{
			disableF5SwitchKey = dataStream.readBool();
			selectedTemplate = dataStream.readString();
			initialMasterEnvelopeState = dataStream.readFloat();
			masterEnvelopeOutput = initialMasterEnvelopeState;
			masterVolume = dataStream.readFloat();
			masterVolumeAutoLower = dataStream.readBool();
		}
	#endif
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::putObjectSettings(MemoryInputStream& dataStream, WPR44Object* theObject, bool isTemplate)
{
	String header = dataStream.readString();
	int version = dataStream.readInt();
	if (!isTemplate) theObject->screen = dataStream.readInt();
	if (!isTemplate) theObject->position = Rectangle<int>::fromString(dataStream.readString());
	theObject->borderColour = Colour::fromString(dataStream.readString());
	theObject->backgroundColour = Colour::fromString(dataStream.readString());
	theObject->fontColour = Colour::fromString(dataStream.readString());
	theObject->borderWidth = dataStream.readInt();
	theObject->namePosition[0] = dataStream.readInt();
	theObject->namePosition[1] = dataStream.readInt();
	theObject->fontSize = dataStream.readFloat();
	theObject->imageScale = dataStream.readFloat();
	theObject->toBack = dataStream.readBool();
	theObject->showName = dataStream.readBool();
	for (int ii = 0; ii < WPR44Object::kImage_Total; ii++) 
	{ 
		theObject->images[ii] = nullptr;
		theObject->imagesFilename[ii] = dataStream.readString(); 
	}
	theObject->imageStretch = dataStream.readBool();
	theObject->fill = dataStream.readBool();
	theObject->roundCorners = dataStream.readFloat();
	theObject->thickness = dataStream.readFloat();
	//
	theObject->shadowEffectOn = dataStream.readBool();
	theObject->cutImageUsingBackground = dataStream.readBool();
	theObject->shadowSettings.radius = dataStream.readInt();
	theObject->shadowSettings.colour = Colour::fromString(dataStream.readString());
	String xYPoins = dataStream.readString();
	theObject->shadowSettings.offset.x = xYPoins.upToFirstOccurrenceOf(",", false, false).getIntValue();
	theObject->shadowSettings.offset.y = xYPoins.fromFirstOccurrenceOf(",", false, false).getIntValue();
	theObject->borderToFront = dataStream.readBool();
	theObject->coloursToFont = dataStream.readBool();
	theObject->animationColour = Colour::fromString(dataStream.readString());
	theObject->backgroundTransparency = dataStream.readFloat();
	theObject->zoomColour = Colour::fromString(dataStream.readString());
	theObject->animationType = dataStream.readInt();
	theObject->zoomType = dataStream.readInt();
	//
	if (version >= 2 && !isTemplate)
	{
		theObject->pcKeyPress = KeyPress::createFromDescription(dataStream.readString());
		theObject->midiCC = dataStream.readInt();
		theObject->midiKey = dataStream.readInt();
	}
	//
	if (version >= 4 && !isTemplate)
	{
		theObject->multiLine = dataStream.readString();
	}
	//
	if (theObject->type == WPR44Object::kType_Image)
	{
		;	// Nothing Yet //
	}
	else if (theObject->type == WPR44Object::kType_Button)
	{
		WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)theObject;
		//
		if (!isTemplate)
		{
			buttonObject->action = dataStream.readInt();;
			buttonObject->midiValues[0] = dataStream.readInt();
			buttonObject->midiValues[1] = dataStream.readInt();
			buttonObject->midiValues[2] = dataStream.readInt();
			buttonObject->targetName = dataStream.readString();
			buttonObject->clickDecay = dataStream.readInt();
			buttonObject->fadeRate = dataStream.readInt();
			buttonObject->isSynced = dataStream.readBool();
			buttonObject->initialFadeState = dataStream.readFloat();
		}
		//
		buttonObject->clickColour = Colour::fromString(dataStream.readString());
	}
	else if (theObject->type == WPR44Object::kType_Sound)
	{
		WPR44SoundObject* soundObject = (WPR44SoundObject*)theObject;
		//
		soundObject->playingColour = Colour::fromString(dataStream.readString());
		soundObject->queuedColour = Colour::fromString(dataStream.readString());
		soundObject->stopColour = Colour::fromString(dataStream.readString());
		//
		if (!isTemplate)
		{
			soundObject->group = dataStream.readString();
			soundObject->groupStop = dataStream.readString();
			soundObject->groupGoBackTo = dataStream.readString();
			soundObject->playbackType = dataStream.readInt();
			soundObject->multiTrigger = dataStream.readBool();
			soundObject->isLooped = dataStream.readBool();
			soundObject->isLoopedSynced = dataStream.readBool();
			soundObject->audioVolume = dataStream.readFloat();
			soundObject->embeddedAudio = dataStream.readBool();
			soundObject->instantStop = dataStream.readBool();
			soundObject->initialFadeState = dataStream.readFloat();
		}
		//
		if (!isTemplate)
		{
			soundObject->mouseDragToVolume = dataStream.readBool();
			soundObject->mouseDragToVolumeMouseType = dataStream.readInt();
			soundObject->mouseDragToVolumeMin = dataStream.readFloat();
			soundObject->mouseDragToVolumeMax = dataStream.readFloat();
			soundObject->soundFilename = dataStream.readString();
			soundObject->recordingType = dataStream.readInt();
			soundObject->measures = dataStream.readInt();
			soundObject->selectedTemplate = dataStream.readString();
			soundObject->envelopeOutStopSoundOnEnd = dataStream.readBool();
			//
			if (soundObject->embeddedAudio)
			{
				int sampleSize = dataStream.readInt();
				int nChannels = dataStream.readInt();
				int nSamples = dataStream.readInt();
				soundObject->audio.setSize(nChannels, nSamples);
				//
				for (int cc = 0; cc < nChannels; cc++)
				{
					dataStream.read(soundObject->audio.getWritePointer(cc), sampleSize * nSamples);
				}
			}
		}
	}
}
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	#if WDEMONSTRATION_VERSION
		return;
	#endif
	//
	if (!dataLoaded) return;
	//return;
	//
	if (mainWindow != nullptr)
	{
		if (objectOptionsWindow != nullptr) objectOptionsWindow->setVisible(false);
		if (imageWindow != nullptr) imageWindow->setVisible(false);
		EditCompo* edCompo = (EditCompo*)mainWindow->getContentComponent();
		//
		while (edCompo->dasButtons.size() > 0)
		{
			edCompo->removeChildComponent(edCompo->dasButtons.getLast());
			edCompo->dasButtons.getLast()->removeListener(edCompo);
			edCompo->dasButtons.removeLast();
		}
		//
		mainWindow->getContentComponent()->deleteAllChildren();
	}
	//
	stopAllSounds = true;
	leObjects.clear();
	//
	MemoryInputStream dataStream(data, sizeInBytes, false);
	putMainSettings(dataStream, false);
	//
	int nObjects = dataStream.readInt64();
	for (int nn = 0; nn < nObjects; nn++)
	{
		WPR44Object* TheObject = nullptr;
		dataStream.readString();
		String objName = String();
		int objType = dataStream.readInt();
		//
		if (objType == WPR44Object::kType_Sound) TheObject = new WPR44SoundObject(numberOfMeasures, lastBPM, lastSampleRate, isStereo);
		else if (objType == WPR44Object::kType_Button) TheObject = new WPR44ButtonObject;
		else if (objType == WPR44Object::kType_Image) TheObject = new WPR44Object;
		//
		TheObject->type = objType;
		TheObject->name = objName;
		//
		putObjectSettings(dataStream, TheObject, false);
		if (TheObject != nullptr) leObjects.add(TheObject);
	}
	//
	newObjectCounter = leObjects.size() + 1;
	loadBackgroundImage();
	loadAudios();
	loadImages();
	//
	if (mainWindow != nullptr)
	{
		EditCompo* editCompo = (EditCompo*)mainWindow->getContentComponent();
		editCompo->createButtons();
		editCompo->updateObjects();
		editCompo->repaint();
		mainWindow->repaint();
		if (optionsWindow != nullptr && optionsWindow->options != nullptr) optionsWindow->options->updateValuesFromProcessor();
	}
}