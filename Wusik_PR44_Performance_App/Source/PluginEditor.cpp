/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
#include "PluginProcessor.h"
#include "PluginEditor.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
WusikPr44AudioProcessorEditor::WusikPr44AudioProcessorEditor (WusikPr44AudioProcessor& p) : AudioProcessorEditor (&p), processor (p)
{
    setSize (640, 420);
	//
	#if WDEMONSTRATION_VERSION
		processor.confirmedDemonstration = false;
	#endif
	//
	if (processor.initErrorMessage.isEmpty())
	{
		#if WDEMONSTRATION_VERSION
			processor.initErrorMessage = "Wusik PR44 V" + String(WVERSION) + " Demonstration Version.\nThe only limitation is that it doesn't save preset/project-data.\n\nClick To Continue...\n\nwww.Wusik.com (c) 2021";
			setSize(780, 420);
		#else
			processor.initErrorMessage = "Connecting...";
		#endif
	}
	//
	startTimer(242);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessorEditor::createInterface()
{
	setLookAndFeel(&wsLookAndFeel);
	wsLookAndFeel.setDefaultSansSerifTypefaceName("Verdana");
	//
	introMenu = new IntroMenu;
	introMenu->gettextButtonLaunch()->addListener(this);
	introMenu->gettextButtonEdit()->addListener(this);
	addAndMakeVisible(introMenu);
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
WusikPr44AudioProcessorEditor::~WusikPr44AudioProcessorEditor()
{
	if (processor.mainWindow != nullptr) processor.mainWindow->closeButtonPressed();
	setLookAndFeel(nullptr);
	deleteAllChildren();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessorEditor::paint (Graphics& g)
{
	if (processor.initErrorMessage.isNotEmpty())
	{
		g.fillAll(Colours::black.withAlpha(0.88f));
		g.setColour(Colours::orangered);
		g.setFont(28.0f);
		//
		g.drawFittedText(processor.initErrorMessage, getLocalBounds(), Justification::centred, 1);
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessorEditor::mouseUp(const MouseEvent& e)
{
#if WDEMONSTRATION_VERSION
	if (!processor.confirmedDemonstration && processor.dataPath.isNotEmpty())
	{
		processor.initErrorMessage = String();
		processor.confirmedDemonstration = true;
		setSize(640, 420);
		createInterface();
		return;
	}
#endif
	//
	if (processor.initErrorMessage.isNotEmpty())
	{
		FileChooser findDataFolder("Wusik PR44 Data Folder", File(), String("*"));
		if (findDataFolder.browseForDirectory())
		{
			processor.dataPath = File::addTrailingSeparator(findDataFolder.getResult().getFullPathName());
			//
			if (processor.dataPath.isNotEmpty() && File(processor.dataPath).exists() && File(processor.dataPath + "Projects Exported").exists())
			{
				processor.saveGlobalSettings("Data Path", processor.dataPath);
				processor.loadData();
				createInterface();
				processor.initErrorMessage = String();
			}
			else
			{
				processor.dataPath = String();
				processor.initErrorMessage = "This is not a valid data folder or files are missing. Try again.";
			}
		}
		//
		repaint();
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void WusikPr44AudioProcessorEditor::buttonClicked(Button* buttonThatWasClicked)
{
	if (buttonThatWasClicked != introMenu->gettextButtonEdit())
	{
		if (processor.leObjects.size() == 0)
		{
			WMessageBox("Empty Project", "The project is empty. Please, edit it first to add objects...");
			return;
		}
		//
		ARRAY_Iterator(processor.leObjects)
		{
			if (processor.leObjects[index]->type == WPR44Object::kType_Sound)
			{
				if (((WPR44SoundObject*)processor.leObjects[index])->audio.getNumSamples() == 0)
				{
					WMessageBox("Missing Audio", "The following sound object is missing the audio: " + processor.leObjects[index]->name);
				}
			}
			else if (processor.leObjects[index]->type == WPR44Object::kType_Button)
			{
				if (((WPR44ButtonObject*)processor.leObjects[index])->action == WPR44Object::kAction_None)
				{
					WMessageBox("Missing Action", "The following button object is missing the action: " + processor.leObjects[index]->name);
				}
			}
		}
	}
	//
	processor.isEditing = buttonThatWasClicked == introMenu->gettextButtonEdit();
	processor.stopAllSounds = true;
	processor.selectedObject = nullptr;
	processor.mainWindow.reset(new MainWindow(buttonThatWasClicked == introMenu->gettextButtonEdit(), processor, "Wusik PS44"));
	processor.mainWindow->toFront(true);
	if (buttonThatWasClicked == introMenu->gettextButtonEdit()) processor.optionsWindow = new OptionsWindow(&processor);
	processor.changeScreenMode();
}