/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "Structure.h"
#include "Options.h"
#include "ObjectOptions.h"
#include "ImageOptions.h"
//
#define WDEMONSTRATION_VERSION 0
#define WVERSION "1.0.2"
//
#if WDEMONSTRATION_VERSION
	#define WCHEKCDEMOMESSAGE WMessageBox("Not available in the demonstration version.", "Sorry, but this feature is only available in the full version."); return
#else
	#define WCHEKCDEMOMESSAGE
#endif
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WToolTipWindow : public DocumentWindow
{
public:
	WToolTipWindow(void* _processor, DocumentWindow* _parentWindow, bool isTop) : parentWindow(_parentWindow), processor(_processor), DocumentWindow("Tool Tip", Colours::darkslategrey.withAlpha(0.12f), 0)
	{
		setUsingNativeTitleBar(true);
		//
		if (isTop)
		{
			setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() - 380 - 360, 40,
				332, (Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) - 80);
		}
		else
		{
			setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() - 380 - 360,
				(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) + 40,
				332, (Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) - 80);
		}
		//
		textEditor = new TextEditor("Tool Tips");
		setContentOwned(textEditor, false);
		textEditor->setMultiLine(true);
		textEditor->setReturnKeyStartsNewLine(false);
		textEditor->setReadOnly(true);
		textEditor->setScrollbarsShown(true);
		textEditor->setCaretVisible(false);
		textEditor->setPopupMenuEnabled(false);
		textEditor->setText(String());
		textEditor->setColour(TextEditor::ColourIds::backgroundColourId, Colours::black.withAlpha(0.62f));
		textEditor->setColour(TextEditor::ColourIds::outlineColourId, Colours::transparentBlack);
		textEditor->setBounds(40, 40, getWidth() - 80, getHeight() - 80);
		textEditor->setFont(Font("Verdana", "Normal", 22.0f));
		//
		setVisible(false);
		setAlwaysOnTop(true);
	}
	//
	void closeButtonPressed() override
	{
		setVisible(false);
		parentWindow->closeButtonPressed();
	}
	//
	bool keyPressed(const KeyPress &key) override
	{
		return parentWindow->keyPressed(key);
	}
	//
	DocumentWindow* parentWindow;
	Component* componentOver = nullptr;
	uint32 componentOverTime = 0;
	void* processor;
	TextEditor* textEditor;
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WPR44ImagesDatabase
{
public:
	String filename;
	Image image;
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WusikPr44AudioProcessor  : public AudioProcessor
{
public:
    WusikPr44AudioProcessor();
    ~WusikPr44AudioProcessor();
	//
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
	void releaseResources() override { };
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;
    AudioProcessorEditor* createEditor() override;
	bool hasEditor() const override { return true; };
	const String getName() const override { return JucePlugin_Name; };
	bool acceptsMidi() const override { return true; };
	bool producesMidi() const override { return true; };
	bool isMidiEffect() const override { return false; };
	double getTailLengthSeconds() const override { return 0.0; };
	int getNumPrograms() override { return 1; };
	int getCurrentProgram() override { return 0; };
	void setCurrentProgram(int index) override { };
	const String getProgramName(int index) override { return "Wusik PR44"; };
	void changeProgramName(int index, const String& newName) override { };
    void getStateInformation (MemoryBlock& destData) override;
	void getMainSettings(MemoryOutputStream& dataStream, bool isTemplate);
	void putMainSettings(MemoryInputStream& dataStream, bool isTemplate);
	void getObjectSettings(MemoryOutputStream& dataStream, WPR44Object* theObject, bool isTemplate);
	void putObjectSettings(MemoryInputStream& dataStream, WPR44Object* theObject, bool isTemplate);
    void setStateInformation (const void* data, int sizeInBytes) override;
	void loadBackgroundImage();
	void loadAudios();
	void loadImages();
	void loadData();
	void checkButtonActions(bool checkSynced);
	void selectObject(WPR44Object* object);
	void duplicateObject(WPR44Object* object, int posX = -1, int posY = -1);
	void changeScreenMode();
	bool keyPressHandle(const KeyPress &key);
	void objectTriggered(WPR44Object* object);
	void objectStopGroup(String groupName, WPR44Object* ignoreThis);
	String loadAudioDialog(WPR44SoundObject* soundObject);
	//
	String getObjectType(WPR44Object* object)
	{
		if (object->type == WPR44Object::kType_Button) return "Button";
		else if (object->type == WPR44Object::kType_Sound) return "Sound";
		else if (object->type == WPR44Object::kType_Image) return "Image";
		//
		else "Error";
	}
	//
	String getToolTipFor(Component& c)
	{
		if (Process::isForegroundProcess()
			&& !ModifierKeys::currentModifiers.isAnyMouseButtonDown())
		{
			if (auto* ttc = dynamic_cast<TooltipClient*> (&c))
				if (!c.isCurrentlyBlockedByAnotherModalComponent())
					return ttc->getTooltip();
		}

		return {};
	}
	//
	String readGlobalSettings(String key, String defaultVal)
	{
		String sKey("HKEY_CURRENT_USER\\Software\\Wusik\\Wusik PR44\\" + key);
		if (WindowsRegistry::keyExists(sKey) &&
			WindowsRegistry::getValue("HKEY_CURRENT_USER\\Software\\Wusik\\Wusik PR44\\" + key).isNotEmpty())
		{
			return WindowsRegistry::getValue("HKEY_CURRENT_USER\\Software\\Wusik\\Wusik PR44\\" + key);
		}
		//
		return defaultVal;
	}
	void saveGlobalSettings(String key, String value)
	{
		WindowsRegistry::setValue("HKEY_CURRENT_USER\\Software\\Wusik\\Wusik PR44\\" + key, value);
	}
	void deleteGlobalSettings(String key)
	{
		saveGlobalSettings(key, "");
		if (WindowsRegistry::keyExists("HKEY_CURRENT_USER\\Software\\Wusik\\Wusik PR44\\" + key)) WindowsRegistry::deleteKey("HKEY_CURRENT_USER\\Software\\Wusik\\Wusik PR44\\" + key);
	}
	void stopSounds(WPR44SoundObject* _objectSound)
	{
		_objectSound->isPlaying = false;
		_objectSound->stopLooping = true;
		//
		int theRateMS = useThisFadeRate;
		if (theRateMS == -1) theRateMS = 10;
		//
		_objectSound->envelopeTarget = 0.0f;
		_objectSound->envelopeRate = 1.0f / ((float(lastSampleRate) / 1000.0f) * float(theRateMS));
	}
	void stopLoopingSounds()
	{
		ARRAY__Iterator(leObjects, obj)
		{
			if (leObjects[obj]->type == WPR44Object::kType_Sound)
			{
				stopSounds((WPR44SoundObject*)leObjects[obj]);
			}
		}
	}
	//
	File checkFileSampleRate(const File file, const double dOutSampleRate)
	{
		AudioFormatReader* reader = audioFormatManager.createReaderFor(file);
		//
		if (reader) 
		{
			if (reader->lengthInSamples > 0) 
			{
				if (reader->sampleRate != dOutSampleRate) 
				{
					//find the out file number of samples
					juce::int64 iSamples = ceil(dOutSampleRate * reader->lengthInSamples / reader->sampleRate);
					//
					AudioSampleBuffer tempBuffer(reader->numChannels, iSamples);
					AudioSampleBuffer readBuffer(reader->numChannels, reader->lengthInSamples);
					//
					//read the samples from file
					reader->read(&readBuffer, 0, readBuffer.getNumSamples(), 0, true, true);
					//
					LagrangeInterpolator interpolator;
					int iResult = 0;
					for (int i = 0; i < reader->numChannels; i++) {
						iResult = interpolator.process(reader->sampleRate / dOutSampleRate,
							readBuffer.getReadPointer(i),
							tempBuffer.getWritePointer(i),
							tempBuffer.getNumSamples());
					}
					//
					File sTempFile = File::createTempFile(String("temp_") + file.getFileNameWithoutExtension() + String(".wav"));
					AudioFormat* audioFormat = audioFormatManager.findFormatForFileExtension(sTempFile.getFileExtension());
					juce::AudioFormatWriter* pTempWriter = audioFormat->createWriterFor(sTempFile.createOutputStream(),
						dOutSampleRate,
						reader->numChannels,
						reader->bitsPerSample ? reader->bitsPerSample : 24,
						reader->metadataValues,
						audioFormat->getQualityOptions().size() - 1);
					auto res = pTempWriter->writeFromAudioSampleBuffer(tempBuffer, 0, tempBuffer.getNumSamples());
					pTempWriter->flush();
					delete pTempWriter;
					//
					jassert(res);
					delete reader;
					return sTempFile;
				}
			}
			else
			{
				delete reader;
				AlertWindow::showMessageBox(AlertWindow::WarningIcon, "No Audio", "There is not enough audio for playing.");
			}
		}
		else
		{
			AlertWindow::showMessageBox(AlertWindow::WarningIcon, "Corrupt file Audio", "The audio file loaded is corrupted.");
		}
		//
		return file;
	}
	//
	AudioFormatManager audioFormatManager;
	ScopedPointer<PropertiesFile::Options> userSettingsOptions;
	ScopedPointer<PropertiesFile> userSettings;
	ScopedPointer<DocumentWindow> mainWindow;
	ScopedPointer<OptionsWindow> optionsWindow;
	ScopedPointer<ObjectOptionsWindow> objectOptionsWindow;
	ScopedPointer<ImageOptionsWindow> imageWindow;
	OwnedArray<WPR44Object> leObjects;
	Rectangle<int> lastMainWindowSize;
	WPR44Object* selectedObject = nullptr;
	String initErrorMessage;
	int loadingAudiosPosition = -1;
	float gridSize = 50.0f;
	bool snapToGrid = true;
	bool showGrid = true;
	Colour gridColour;
	Colour backColour;
	Colour beatFlashColour;
	Colour beatFlashFirstBeatColour;
	Colour beatFlashFirstMeasureColour;
	float backImageScale = 1.0f;
	float backTransparency = 0.0f;
	File backImage;
	File lastBackImagePath;
	File lastLoadedAudioPath;
	File lastLoadedImage;
	Image backgroundImage;
	bool backgroundImageStretch;
	String globalFontName;
	Font globalFont;
	int showingScreen = 0;
	int prevShowingScreen = -1;
	int numberOfMeasures = 4;
	bool internalClock = true;
	int internalBPM = 120;
	Colour laskBackColour = Colours::white;
	Colour lastBorderColour = Colours::grey;
	Colour lastPlayingColour = Colours::red.withAlpha(0.52f);
	Colour lastBeatColour = Colours::red;
	Colour lastFontColour = Colours::white;
	bool learnMIDI = false;
	int learnMIDICC = -1;
	int learnMIDIKey = -1;
	KeyPress lastKeyPressed;
	int newObjectCounter = 1;
	bool autoPlayAudioOnLoad = true;
	bool isEditing = false;
	int lastSampleRate = 44100;
	int lastBPM = 120;
	bool stopAllSounds = false;
	Array<WPR44SoundObject*> queueSndPlaybacks;
	OwnedArray<WPR44ImagesDatabase> imagesDatabase;
	bool deleteSelectedObject = false;
	bool autoStartClock = false;
	int beatFlashDecayMS = 40;
	bool deleteAllObjects = false;
	int useThisFadeRate = -1; // uses default //
	WPR44Clock sequencerClock;
	bool isStereo = true;
	bool flashBeat = false;
	int flashTime = 0;
	int flashTimeCounter = 0;
	bool switchInterfaces = false;
	bool disableF5SwitchKey = false;
	String selectedTemplate;
	String dataPath;
	bool dataLoaded = false;
	Array<WPR44ButtonObject*> buttonActions;
	float initialMasterEnvelopeState = 1.0f;
	float masterEnvelopeOutput = 1.0f;
	float masterEnvelopeRate = 0.0f;
	bool stopAllOnEnvelopeDown = false;
	bool selectingMultipleObjectsToPlay = false;
	float masterVolume = 0.92f;
	bool masterVolumeAutoLower = true;
	bool fullscreenMode = true;
	bool connectedToDevice = false;
	int connectDevice = 0;
	uint32_t connectDeviceTime = 0;
	MidiBuffer midiOutFromActionButtons;
	MidiBuffer midiOutFromActionButtonsNoteOff[2];
	//
#if WDEMONSTRATION_VERSION
	bool confirmedDemonstration = false;
#else
	bool confirmedDemonstration = true;
#endif
	//
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WusikPr44AudioProcessor)
};