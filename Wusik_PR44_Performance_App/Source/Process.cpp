/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
#include "PluginProcessor.h"
#include "PluginEditor.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::checkButtonActions(bool checkSynced)
{
	bool foundOne = true;
	while (foundOne)
	{
		foundOne = false;
		//
		ARRAY_Iterator(buttonActions)
		{
			if (buttonActions[index]->isSynced == checkSynced || !sequencerClock.playing)
			{
				foundOne = true;
				//
				if (buttonActions[index]->action == WPR44Object::kAction_FadeOutAllAndStop)
				{
					stopAllOnEnvelopeDown = true;
					masterEnvelopeOutput = 1.0f;
					masterEnvelopeRate = -1.0f / ((float(lastSampleRate) / 1000.0f) * float(buttonActions[index]->fadeRate));
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_FadeInAll)
				{
					masterEnvelopeOutput = 0.0f;
					masterEnvelopeRate = 1.0f / ((float(lastSampleRate) / 1000.0f) * float(buttonActions[index]->fadeRate));
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_FadeAll_FlipFlop)
				{
					masterEnvelopeRate = 1.0f / ((float(lastSampleRate) / 1000.0f) * float(buttonActions[index]->fadeRate));
					if (masterEnvelopeOutput != 0.0f) masterEnvelopeRate *= -1.0f;
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_StartStop)
				{
					if (sequencerClock.playing)
					{
						sequencerClock.stop();
						stopLoopingSounds();
					}
					else
					{
						sequencerClock.start();
						masterEnvelopeOutput = initialMasterEnvelopeState;
					}
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_Start)
				{
					sequencerClock.start();
					masterEnvelopeOutput = initialMasterEnvelopeState;
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_Stop)
				{
					sequencerClock.stop();
					stopLoopingSounds();
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_StopSound || buttonActions[index]->action == WPR44Object::kAction_StopGroup)
				{
					ARRAY__Iterator(leObjects, obj)
					{
						if (leObjects[obj]->type == WPR44Object::kType_Sound)
						{
							String compareName = leObjects[obj]->name;
							if (buttonActions[index]->action == WPR44Object::kAction_StopGroup) compareName = ((WPR44SoundObject*)leObjects[obj])->group;
							//
							if (compareName.compareIgnoreCase(buttonActions[index]->targetName) == 0)
							{
								useThisFadeRate = buttonActions[index]->fadeRate;
								stopSounds((WPR44SoundObject*)leObjects[obj]);
								if (buttonActions[index]->action == WPR44Object::kAction_StopSound) break;
							}
						}
					}
				}
				else if (buttonActions[index]->action == WPR44Object::kAction_FadeSound || buttonActions[index]->action == WPR44Object::kAction_FadeSound_FlipFlop ||
					buttonActions[index]->action == WPR44Object::kAction_FadeGroup || buttonActions[index]->action == WPR44Object::kAction_FadeGroup_FlipFlop)
				{
					ARRAY__Iterator(leObjects, obj)
					{
						if (leObjects[obj]->type == WPR44Object::kType_Sound)
						{
							String compareName = leObjects[obj]->name;
							if (buttonActions[index]->action == WPR44Object::kAction_FadeGroup ||
								buttonActions[index]->action == WPR44Object::kAction_FadeGroup_FlipFlop) compareName = ((WPR44SoundObject*)leObjects[obj])->group;
							//
							if (compareName.compareIgnoreCase(buttonActions[index]->targetName) == 0)
							{
								WPR44SoundObject* sndObject = (WPR44SoundObject*)leObjects[obj];
								//
								if (buttonActions[index]->action == WPR44Object::kAction_FadeSound ||
									buttonActions[index]->action == WPR44Object::kAction_FadeGroup)
								{
									if (buttonActions[index]->initialFadeState > 0.9f)
									{
										sndObject->envelopeTarget = 0.000001f;
										sndObject->envelopeOut = 1.0f;
									}
									else
									{
										sndObject->envelopeTarget = 1.0f;
										sndObject->envelopeOut = 0.000001f;
									}
								}
								else
								{
									if (sndObject->envelopeTarget > 0.9f) sndObject->envelopeTarget = 0.000001f; else sndObject->envelopeTarget = 1.0f;
								}
								//
								sndObject->envelopeRate = 1.0f / ((float(lastSampleRate) / 1000.0f) * float(buttonActions[index]->fadeRate));
								//
								if (buttonActions[index]->action == WPR44Object::kAction_FadeSound_FlipFlop ||
									buttonActions[index]->action == WPR44Object::kAction_FadeSound) break;
							}
						}
					}
				}
			}
			//
			if (foundOne)
			{
				buttonActions.remove(index);
				break;
			}
		}
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;
	lastSampleRate = getSampleRate();
	AudioPlayHead::CurrentPositionInfo curPosInfo;
	lastBPM = int(curPosInfo.bpm);
	if (lastBPM == 0) lastBPM = 120;
	if (internalClock) lastBPM = internalBPM;
	//
	buffer.clear();
	float* channelData1 = buffer.getWritePointer(0);
	float* channelData2 = channelData1;
	isStereo = false;
	//
	if (buffer.getNumChannels() > 1)
	{
		channelData2 = buffer.getWritePointer(1);
		isStereo = true;
	}
	//
	if (!connectedToDevice && connectDevice == 0)
	{
		const uint8_t SysEx[4] = { 0xB, 0xC, 0, 4 };
		//
		MidiBuffer tempBuffer;
		tempBuffer.addEvent(MidiMessage::createSysExMessage((void*)&SysEx, sizeof(SysEx)), 0);
		midiMessages.clear();
		midiMessages.addEvents(tempBuffer, 0, buffer.getNumSamples(), 0);
		//
		connectDevice = 1;
		connectDeviceTime = Time::getMillisecondCounter() + 2000UL;
		return;
	}
	//
	int sampPos = 0;
	MidiMessage mm;
	MidiBuffer::Iterator mIterator(midiMessages);
	while (mIterator.getNextEvent(mm, sampPos))
	{
		if (!connectedToDevice && connectDevice == 1)
		{
			if (mm.isController())
			{
				if (mm.getControllerNumber() == 11 && mm.getControllerValue() == 100)
				{
					connectedToDevice = true;
					((WusikPr44AudioProcessorEditor*)getActiveEditor())->createInterface();
					return;
				}
			}
		}
		else if (learnMIDI)
		{
			if (mm.isController())
			{
				learnMIDICC = mm.getControllerNumber();
				learnMIDI = false;
				break;
			}
			else if (mm.isPitchWheel())
			{
				learnMIDICC = WPR44Object::kMIDI_PitchBend;
				learnMIDI = false;
				break;
			}
			else if (mm.isAftertouch())
			{
				learnMIDICC = WPR44Object::kMIDI_Aftertouch;
				learnMIDI = false;
				break;
			}
			else if (mm.isNoteOnOrOff())
			{
				learnMIDIKey = mm.getNoteNumber();
				learnMIDI = false;
				break;
			}
		}
		else
		{
			ARRAY_Iterator(leObjects)
			{
				if (mm.isController() && leObjects[index]->midiCC >= 0 && leObjects[index]->midiCC == mm.getControllerNumber())
				{
					objectTriggered(leObjects[index]);
				}
				//
				if (mm.isPitchWheel() && leObjects[index]->midiCC == WPR44Object::kMIDI_PitchBend)
				{
					objectTriggered(leObjects[index]);
				}
				//
				if (mm.isAftertouch() && leObjects[index]->midiCC == WPR44Object::kMIDI_Aftertouch)
				{
					objectTriggered(leObjects[index]);
				}
				//
				if (mm.isNoteOn() && leObjects[index]->midiKey != -1 && leObjects[index]->midiKey == mm.getNoteNumber())
				{
					objectTriggered(leObjects[index]);
				}
			}
		}
	}
	//
	midiMessages.clear();
	if (!connectedToDevice) return;
	//
	if (midiOutFromActionButtonsNoteOff[0].getNumEvents() > 0)
	{
		midiMessages.addEvents(midiOutFromActionButtonsNoteOff[0], 0, buffer.getNumSamples(), 0);
		midiOutFromActionButtonsNoteOff[0].clear();
	}
	//
	if (midiOutFromActionButtonsNoteOff[1].getNumEvents() > 0)
	{
		midiOutFromActionButtonsNoteOff[0].addEvents(midiOutFromActionButtonsNoteOff[1], 0, buffer.getNumSamples(), 0);
		midiOutFromActionButtonsNoteOff[1].clear();
	}
	//
	if (midiOutFromActionButtons.getNumEvents() > 0)
	{
		midiMessages.addEvents(midiOutFromActionButtons, 0, buffer.getNumSamples(), 0);
		midiOutFromActionButtons.clear();
	}
	//
	if (isEditing)
	{
		sequencerClock.stop();
		//
		if (deleteSelectedObject)
		{
			deleteSelectedObject = false;
			leObjects.removeObject(selectedObject);
			selectedObject = nullptr;
		}
		//
		if (deleteAllObjects)
		{
			selectedObject = nullptr;
			leObjects.clear();
			deleteAllObjects = false;
		}
		//
		ARRAY_Iterator(leObjects)
		{
			if (leObjects[index]->type == WPR44Object::kType_Sound)
			{
				WPR44SoundObject* objectSND = (WPR44SoundObject*)leObjects[index];
				if (objectSND->voices.size() == 0) objectSND->isPlaying = false;
			}
		}
	}
	//
	// ----------------------------------------------------------------
	// ----------------------------------------------------------------
	//
	checkButtonActions(false);
	//
	if (stopAllSounds)
	{
		ARRAY_Iterator(leObjects)
		{
			if (leObjects[index]->type == WPR44Object::kType_Sound)
			{
				WPR44SoundObject* objectSND = (WPR44SoundObject*)leObjects[index];
				stopSounds(objectSND);
			}
		}
		//
		if (mainWindow != nullptr) mainWindow->repaint();
		stopAllSounds = false;
		useThisFadeRate = -1;
	}
	//
	if (!selectingMultipleObjectsToPlay)
	{
		if (!isEditing && autoStartClock && !sequencerClock.playing && queueSndPlaybacks.size() > 0)
		{
			// Sequencer Off, Start Sequencer If Required //
			sequencerClock.start();
			sequencerClock.ignoreFirst = true;
			masterEnvelopeOutput = initialMasterEnvelopeState;
			//
			ARRAY_Iterator(queueSndPlaybacks)
			{
				queueSndPlaybacks[index]->newVoice();
				queueSndPlaybacks[index]->markToRemoveFromQueue = true;
			}
			//
			if (mainWindow != nullptr) mainWindow->repaint();
		}
		else
		{
			ARRAY_Iterator(queueSndPlaybacks)
			{
				if (queueSndPlaybacks[index]->recordingType == WPR44Object::kRecordingType_None && queueSndPlaybacks[index]->audio.getNumSamples() == 0)
				{
					queueSndPlaybacks[index]->markToRemoveFromQueue = true;
					if (mainWindow != nullptr) mainWindow->repaint();
				}
				else if (queueSndPlaybacks[index]->recordingType != WPR44Object::kRecordingType_None &&
					(queueSndPlaybacks[index]->recordBuffer == nullptr || queueSndPlaybacks[index]->recordBuffer->getNumSamples() == 0))
				{
					queueSndPlaybacks[index]->markToRemoveFromQueue = true;
					if (mainWindow != nullptr) mainWindow->repaint();
				}
				else if (isEditing)
				{
					queueSndPlaybacks[index]->newVoice();
					queueSndPlaybacks[index]->markToRemoveFromQueue = true;
					if (mainWindow != nullptr) mainWindow->repaint();
				}
				else
				{
					// Sequencer Playing //
					// Polyphonic Hits  //
					if (queueSndPlaybacks[index]->playbackType == WPR44Object::kPlay_Poly)
					{
						queueSndPlaybacks[index]->newVoice();
						//
						if (!queueSndPlaybacks[index]->multiTrigger && queueSndPlaybacks[index]->group.isNotEmpty()) objectStopGroup(queueSndPlaybacks[index]->group, queueSndPlaybacks[index]);
						if (queueSndPlaybacks[index]->groupStop.isNotEmpty()) objectStopGroup(queueSndPlaybacks[index]->groupStop, queueSndPlaybacks[index]);
					}
					else
					{
						// Sound Is Also Playing //
						if (queueSndPlaybacks[index]->isPlaying)
						{
							if (queueSndPlaybacks[index]->instantStop)
							{
								queueSndPlaybacks[index]->isPlaying = queueSndPlaybacks[index]->isQueuedToPlay = queueSndPlaybacks[index]->isQueuedToStop = false;
								stopSounds(queueSndPlaybacks[index]);
							}
							else
							{
								if (queueSndPlaybacks[index]->playbackType == WPR44Object::kPlay_Synced)
								{
									queueSndPlaybacks[index]->isQueuedToStop = !queueSndPlaybacks[index]->isQueuedToStop;
								}
							}
						}
						else
						{
							// Sound Not Playing - Queue To Play //
							if (queueSndPlaybacks[index]->playbackType == WPR44Object::kPlay_Synced)
							{
								queueSndPlaybacks[index]->isQueuedToPlay = true;
							}
						}
					}
					//
					queueSndPlaybacks[index]->markToRemoveFromQueue = true;
					if (mainWindow != nullptr) mainWindow->repaint();
				}
			}
		}
		//
		bool foundQueuedToDelete = true;
		while (foundQueuedToDelete)
		{
			foundQueuedToDelete = false;
			//
			ARRAY_Iterator(queueSndPlaybacks)
			{
				if (queueSndPlaybacks[index]->markToRemoveFromQueue)
				{
					queueSndPlaybacks[index]->markToRemoveFromQueue = false;
					foundQueuedToDelete = true;
					queueSndPlaybacks.remove(index);
					break;
				}
			}
		}
	}
	//
	// The Sequencer ---------------------------- //
	for (int ss = 0; ss < buffer.getNumSamples(); ss++)
	{
		bool firstMeasure = false;
		//
		if (sequencerClock.process()) // Returns true when Measures has reached the end and it's back at the start //
		{
			firstMeasure = true;
			//
			ARRAY_Iterator(leObjects)
			{
				if (leObjects[index]->type == WPR44Object::kType_Sound)
				{
					WPR44SoundObject* objectSND = (WPR44SoundObject*)leObjects[index];
					//
					if (objectSND->isQueuedToPlay)
					{
						objectSND->newVoice();
						//
						if (!objectSND->multiTrigger && objectSND->group.isNotEmpty()) objectStopGroup(objectSND->group, objectSND);
						if (objectSND->groupStop.isNotEmpty()) objectStopGroup(objectSND->groupStop, objectSND);
					}
				}
			}
		}
		//
		if (flashBeat)
		{
			flashBeat = false;
			Colour useThisColour = beatFlashColour;
			if (sequencerClock.beat == 0) useThisColour = beatFlashFirstMeasureColour;
			if (sequencerClock.measureJustStarted) useThisColour = beatFlashFirstBeatColour; 
			sequencerClock.measureJustStarted = false;
			//
			uint8_t SysEx[10] = { 0xB, 0xC, 0, 5 };
			//
			SysEx[4] = useThisColour.getRed() >> 4;
			SysEx[5] = useThisColour.getRed() & 0xF;
			SysEx[6] = useThisColour.getGreen() >> 4;
			SysEx[7] = useThisColour.getGreen() & 0xF;
			SysEx[8] = useThisColour.getBlue() >> 4;
			SysEx[9] = useThisColour.getBlue() & 0xF;
			//
			MidiBuffer tempBuffer;
			tempBuffer.addEvent(MidiMessage::createSysExMessage((void*)&SysEx, sizeof(SysEx)), 0);
			midiMessages.addEvents(tempBuffer, 0, buffer.getNumSamples(), 0);
		}
		//
		/*if (flashBeat && flashTime == 0 && beatFlashDecayMS > 0)
		{
			flashBeat = false;
			flashTime = int((double(lastSampleRate) / 1000.0) * double(beatFlashDecayMS));
			flashTimeCounter = 0;
			if (mainWindow != nullptr) mainWindow->repaint();
		}
		//
		if (flashTime > 0)
		{
			flashTimeCounter++;
			if (flashTimeCounter >= flashTime)
			{
				flashTime = flashTimeCounter = 0;
				if (mainWindow != nullptr) mainWindow->repaint();
			}
		}*/
		//
		// The Sounds ------------------------------- //
		ARRAY_Iterator(leObjects)
		{
			if (leObjects[index]->type == WPR44Object::kType_Sound)
			{
				WPR44SoundObject* objectSND = (WPR44SoundObject*)leObjects[index];
				//
				if (objectSND->process(ss, isEditing, channelData1, channelData2))
				{
					bool foundOne = true;
					while (foundOne)
					{
						foundOne = false;
						//
						ARRAY__Iterator(objectSND->voices, vv)
						{
							if (objectSND->voices[vv]->audioPosition == -1)
							{
								foundOne = true;
								//
								if (objectSND->groupGoBackTo.isNotEmpty())
								{
									ARRAY__Iterator(leObjects, oo)
									{
										if (leObjects[oo]->type == WPR44Object::kType_Sound)
										{
											WPR44SoundObject* objectSND2 = (WPR44SoundObject*)leObjects[oo];
											//
											if (objectSND2->group.compareIgnoreCase(objectSND->groupGoBackTo) == 0)
											{
												if (objectSND2->voices.size() == 0) objectSND2->newVoice();
											}
										}
									}
								}
								//
								objectSND->voices.remove(vv);
								if (mainWindow != nullptr) mainWindow->repaint();
								break;
							}
						}
					}
				}
			}
		}
		//
		if (!isEditing)
		{
			channelData1[ss] *= masterEnvelopeOutput;
			channelData2[ss] *= masterEnvelopeOutput;
		}
		//
		if (masterEnvelopeRate != 0.0f)
		{
			masterEnvelopeOutput += masterEnvelopeRate;
			if (masterEnvelopeOutput < 0.0f)
			{
				masterEnvelopeOutput = 0.0f;
				masterEnvelopeRate = 0.0f;
				//
				if (stopAllOnEnvelopeDown)
				{
					sequencerClock.stop();
					stopAllSounds = true;
					stopAllOnEnvelopeDown = false;
				}
			}
			else if (masterEnvelopeOutput > 1.0f)
			{
				masterEnvelopeOutput = 1.0f;
				masterEnvelopeRate = 0.0f;
			}
		}
		//
		if (firstMeasure) checkButtonActions(true);
	}
	//
	if (masterVolumeAutoLower)
	{
		float prevVolume = masterVolume;
		//
		for (int ss = 0; ss < buffer.getNumSamples(); ss++)
		{
			for (int cc = 0; cc < buffer.getNumChannels(); cc++)
			{
				if (cc == 0 && (fabs(channelData1[ss]) * masterVolume) >= 1.0f) masterVolume = 1.0f / fabs(channelData1[ss]);
				if (cc == 1 && (fabs(channelData2[ss]) * masterVolume) >= 1.0f) masterVolume = 1.0f / fabs(channelData2[ss]);
			}
		}
		//
		if (isEditing && prevVolume != masterVolume)
		{
			String dB = Decibels::toString(Decibels::gainToDecibels(masterVolume));
			optionsWindow->options->getTextButton_Volume()->setButtonText(dB);
		}
	}
	//
	if (masterVolume != 1.0f) buffer.applyGain(masterVolume);
	//
	if (prevShowingScreen != showingScreen)
	{
		prevShowingScreen = showingScreen;
		//
		const uint8_t SysEx[5] = { 0xB, 0xC, 0, 2, showingScreen };
		MidiBuffer tempBuffer;
		tempBuffer.addEvent(MidiMessage::createSysExMessage((void*)&SysEx, sizeof(SysEx)), 0);
		midiMessages.addEvents(tempBuffer, 0, buffer.getNumSamples(), 0);
	}
}