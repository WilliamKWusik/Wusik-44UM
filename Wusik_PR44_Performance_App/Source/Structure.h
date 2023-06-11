/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WPR44Clock
{
public:
	WPR44Clock(int &_measures, int &_BPM, int &_samplerate, bool &_flashBeat) : flashBeat(_flashBeat), measures(_measures), BPM(_BPM), samplerate(_samplerate) { reset(); };
	//
	void reset()
	{
		beat = 0;
		position = 0;
		beatPosition = 0;
		flashBeat = false;
		totalSamplesForAllMeasures = int(((60.0 / double(BPM)) * 4.0 * double(measures)) * double(samplerate));
		totalSamplesPerBeat = int((((60.0 / double(BPM)) * 4.0) * double(samplerate)) / 4.0);
	};
	//
	void start()
	{
		reset();
		playing = true;
		justStarted = true;
		measureJustStarted = true;
		flashBeat = true;
		ignoreFirst = false;
	};
	//
	bool stop()
	{
		flashBeat = false;
		bool wasPlaying = playing;
		playing = false;
		reset();
		return wasPlaying;
	};
	//
	bool process()
	{
		if (!playing) return false;
		//
		bool returnBool = justStarted;
		//
		beatPosition++;
		if (beatPosition >= totalSamplesPerBeat)
		{
			beatPosition = 0;
			beat++;
			flashBeat = true;
			if (beat >= 4) beat = 0;
		}
		//
		position++;
		if (position >= totalSamplesForAllMeasures)
		{
			returnBool = true;
			position = 0;
			measureJustStarted = true;
		}
		//
		justStarted = false;
		if (ignoreFirst)
		{
			ignoreFirst = false;
			returnBool = false;
		}
		//
		return returnBool;
	};
	//
	bool measureJustStarted = true;
	bool justStarted = true;
	int beat = 0;
	int beatPosition = 0;
	int position = 0;
	int totalSamplesForAllMeasures = 0;
	int totalSamplesPerBeat = 0;
	bool playing = false;
	int &measures;
	int &BPM;
	int &samplerate;
	bool &flashBeat;
	bool ignoreFirst = false;
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WPR44Object
{
public:
	WPR44Object()
	{
		shadowSettings.colour = Colours::black.withAlpha(0.62f);
		shadowSettings.offset = Point<int>(6, 6);
		shadowSettings.radius = 10.0f;
		//
		for (int ii = 0; ii < kImage_Total; ii++)
		{
			images[ii] = nullptr;
		}
	};
	//
	enum
	{
		kType_Sound = 0,
		kType_Button,
		kType_Image,
		kType_Total,
		//
		//kPlay_Instant_OnTime = 0,
		//kPlay_Instant_Free,
		//kPlay_Gate_OnTime,
		//kPlay_Gate_Free,
		kPlay_Synced = 0,
		kPlay_Poly,
		//
		kScreenA = 0,
		kScreenB,
		kScreenC,
		kScreenD,
		//
		kImage_Background = 0,
		kImage_Playing,
		kImage_Queued,
		kImage_Stop,
		kImage_Recording,
		kImage_Click,
		kImage_Total,
		//
		kRecordingType_None = 0,
		kRecordingType_Continuous,
		kRecordingType_Mix,
		kRecordingType_Replace,
		kRecordingType_PingPong,
		//
		kAction_None = 0,
		kAction_StartStop,
		kAction_Start,
		kAction_Stop,
		kAction_Panic,
		kAction_CloseApp,
		kAction_CloseApp_Confirm,
		kAction_StopSound,
		kAction_StopGroup,
		kAction_SendMIDINote,
		kAction_SendMIDICC,
		kAction_FadeSound,
		kAction_FadeGroup,
		kAction_FadeSound_FlipFlop,
		kAction_FadeGroup_FlipFlop,
		kAction_FadeOutAllAndStop,
		kAction_FadeInAll,
		kAction_FadeAll_FlipFlop,
		kAction_MultiStarter,
		kAction_ScreenA,
		kAction_ScreenB,
		kAction_ScreenC,
		kAction_ScreenD,
		//
		kDisplay_Measure = 0,
		kDisplay_Beat,
		kDisplay_Playing,
		//
		kMouse_ClickAndDrag = 0,
		kMouse_RightClick,
		kMouse_DoubleClick,
		//
		kAnimation_Regular = 0,
		kAnimation_Measure,
		kAnimation_Beat,
		//
		kZoom_Off = 0,
		kZoom_Slow,
		kZoom_Normal,
		kZoom_Fast,
		//
		kMIDI_None = -1,
		kMIDI_PitchBend = -2,
		kMIDI_Aftertouch = -3
	};
	//
	Colour borderColour = Colours::white;
	Colour backgroundColour = Colours::grey;
	Colour fontColour = Colours::black;
	int borderWidth = 4;
	Rectangle<int> position;
	String name = "UnNamed";
	String multiLine = "Disabled";
	int namePosition[2] = { -1, -1 };
	int type = 0;
	int screen = kScreenA;
	float fontSize = 30.0f;
	bool showName = true;
	String imagesFilename[kImage_Total];
	Image* images[kImage_Total];
	bool imageStretch = false;
	String selectedTemplate;
	float imageScale = 1.0f;
	bool toBack = false;
	bool fill = true;
	float thickness = 2.0f;
	float roundCorners = 12.0f;
	bool cutImageUsingBackground = true;
	bool shadowEffectOn = true;
	bool justSelected = false;
	bool borderToFront = true;
	bool coloursToFont = true;
	Colour animationColour = Colours::white.withAlpha(0.24f);
	Colour zoomColour = Colours::white.withAlpha(0.24f);
	float backgroundTransparency = 0.0f;
	int animationType = kAnimation_Beat;
	int zoomType = kZoom_Fast;
	KeyPress pcKeyPress;
	int midiCC = kMIDI_None;
	int midiKey = -1;
	//
	DropShadow shadowSettings;
	DropShadowEffect shadowEffect;
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WPR44SoundObject : public WPR44Object
{
public:
	class WVoice
	{
	public:
		WVoice(WPR44SoundObject& _sndObject, int _measuresSamples) : measuresSamples(_measuresSamples), sndObject(_sndObject) { };
		//
		bool process(int ss, bool isEditing, float* channelData1, float* channelData2)
		{
			bool hasVoiceToBeDeleted = false;
			//
			if (audioPosition >= 0)
			{
				if (sndObject.audio.getNumSamples() == 0)
				{
					audioPosition = -1;
					return true;
				}
				//
				int theAudioPosition = jlimit(0, sndObject.audio.getNumSamples() - 1, audioPosition);
				float audioVolume = sndObject.envelopeOut * sndObject.audioVolume;
				if (isEditing) audioVolume = sndObject.audioVolume;
				//
				if (theAudioPosition <= (sndObject.audio.getNumSamples() - 1))
				{
					const float* audioData1 = sndObject.audio.getReadPointer(0);
					const float* audioData2 = nullptr;
					if (sndObject.audio.getNumChannels() > 1) audioData2 = sndObject.audio.getReadPointer(1);
					//
					// Sample Data //
					channelData1[ss] += audioData1[theAudioPosition] * audioVolume;
					if (sndObject.isStereo)
					{
						if (audioData2 == nullptr) channelData2[ss] += channelData1[ss];
						else channelData2[ss] += audioData2[theAudioPosition] * audioVolume;;
					}
				}
				//
				// Sample Position //
				audioPosition++;
				//
				if (!isEditing  && sndObject.envelopeOutStopSoundOnEnd &&
					sndObject.envelopeTarget < 0.0001f && sndObject.envelopeOut < 0.0001f &&
					audioPosition >= (sndObject.audio.getNumSamples() - 1))
				{
					audioPosition = -1;
					hasVoiceToBeDeleted = true;
					sndObject.stopLooping = true;
					sndObject.isPlaying = false;
				}
				//
				if (isEditing || !sndObject.isLooped ||
					(sndObject.envelopeOut == 0.0f && sndObject.envelopeTarget == 0.0f))
				{
					if (sndObject.envelopeOut == 0.0f && sndObject.envelopeTarget == 0.0f)
					{
						audioPosition = -1;
						hasVoiceToBeDeleted = true;
					}
					else if (audioPosition >= (sndObject.audio.getNumSamples() - 1))
					{
						audioPosition = -1;
						hasVoiceToBeDeleted = true;
					}
				}
				else
				{
					if (sndObject.isLooped && !sndObject.stopLooping && sndObject.playbackType != WPR44Object::kPlay_Poly)
					{
						if (audioPosition == measuresSamples)
						{
							if (sndObject.isQueuedToStop)
							{
								sndObject.isQueuedToStop = false;
								sndObject.stopLooping = true;
							}
							else
							{
								sndObject.newVoice();
							}
						}
					}
					//
					if (audioPosition >= (sndObject.audio.getNumSamples() - 1))
					{
						if (sndObject.stopLooping)
						{
							audioPosition = -1;
							hasVoiceToBeDeleted = true;
						}
						else if (sndObject.isLooped)
						{
							if (sndObject.playbackType == WPR44Object::kPlay_Poly) audioPosition = 0;
						}
						else
						{
							audioPosition = -1;
							hasVoiceToBeDeleted = true;
						}
					}
				}
			}
			//
			return hasVoiceToBeDeleted;
		}
		//
		int audioPosition = 0; // set to -1 to delete the voice //
		int measuresSamples = 0;
		WPR44SoundObject& sndObject;
	};
	//
	WPR44SoundObject(int &_globalMeasures, int &_BPM, int &_samplerate, bool &_isStereo)
		: WPR44Object(), globalMeasures(_globalMeasures), BPM(_BPM), samplerate(_samplerate), isStereo(_isStereo) { };
	//
	void newVoice()
	{
		if (voices.size() == 0)
		{
			if (initialFadeState == 0.0f) initialFadeState = 0.000001f;
			envelopeOut = envelopeTarget = initialFadeState;
		}
		//
		stopLooping = false;
		isQueuedToStop = false;
		isQueuedToPlay = false;
		isQueuedToPlayMulti = false;
		isPlaying = true;
		//
		int xmeasures = 0;
		if (measures == 0) xmeasures = int(((60.0 / double(BPM)) * 4.0 * double(globalMeasures)) * double(samplerate));
			else xmeasures = int(((60.0 / double(BPM)) * 4.0 * double(measures)) * double(samplerate));
		//
		voices.add(new WVoice(*this, xmeasures));
	}
	//
	bool process(int ss, bool isEditing, float* channelData1, float* channelData2)
	{
		bool returnBool = false;
		//
		// Envelope //
		if (envelopeOut > envelopeTarget)
		{
			envelopeOut -= envelopeRate;
			if (envelopeOut < envelopeTarget) envelopeOut = envelopeTarget;
		}
		else if (envelopeOut < envelopeTarget)
		{
			envelopeOut += envelopeRate;
			if (envelopeOut > envelopeTarget) envelopeOut = envelopeTarget;
		}
		//
		ARRAY__Iterator(voices, vv)
		{
			if (voices[vv]->process(ss, isEditing, channelData1, channelData2)) returnBool = true;
		}
		//
		if (voices.size() == 0) isPlaying = false;
		return returnBool;
	}
	//
	Colour playingColour = Colours::red.withAlpha(0.52f);
	Colour queuedColour = Colours::red;
	Colour stopColour = Colours::blue.withAlpha(0.52f);
	String group;
	String groupStop;
	String groupGoBackTo;
	bool envelopeOutStopSoundOnEnd = false;
	float envelopeOut = 1.0f;
	float envelopeTarget = 1.0f;
	float envelopeRate = 0.0f;
	float initialFadeState = 1.0f;
	bool embeddedAudio = false;
	int playbackType = kPlay_Synced;
	bool multiTrigger = false;
	bool isLooped = true;
	bool isLoopedSynced = true;
	bool momentaryMute = false;
	bool isQueuedToPlay = false;
	bool isQueuedToPlayMulti = false;
	bool isQueuedToStop = false;
	bool isPlaying = false;
	int audioLoopEnd = 0;
	float audioVolume = 1.0f;
	bool instantStop = false;
	OwnedArray<WVoice> voices;
	int sampleRate = 44100;
	bool mouseDragToVolume = false;
	int mouseDragToVolumeMouseType = kMouse_RightClick;
	float mouseDragToVolumeMin = 0.0f;
	float mouseDragToVolumeMax = 1.0f;
	int measures = 0; // Default (global) value //
	int &globalMeasures;
	int &BPM;
	int &samplerate;
	bool &isStereo;
	bool markToRemoveFromQueue = false;
	//
	AudioSampleBuffer audio;
	ScopedPointer<AudioSampleBuffer> recordBuffer;
	String soundFilename;
	bool reloadAudio = false;
	bool playOnLoad = false;
	bool stopLooping = false;
	//
	int recordingMouseType = kMouse_RightClick;
	bool isRecording = false;
	int recordingType = kRecordingType_None;
	int pingPongRecording = 0;
	String recordingSource;
	Colour recordingColour;
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WPR44ButtonObject : public WPR44Object
{
public:
	WPR44ButtonObject() : WPR44Object() { };
	//
	int action = kAction_None;
	int midiValues[3] = { 1, 1, 0 };
	String targetName;
	int clickDecay = 140; // ms //
	Colour clickColour = Colours::red.withAlpha(0.22f);
	int fadeRate = 10; // ms //
	bool isSynced = true;
	float initialFadeState = 0.0f;
};