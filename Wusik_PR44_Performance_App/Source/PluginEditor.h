/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
// ------------------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Intro Menu.h"
#include "EditCompo.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
class JUCE_API WPR44LookAndFeel : public LookAndFeel_V4
{
	Font getTextButtonFont(TextButton&, int buttonHeight) override { return Font("Verdana", "Normal", 32.0f); };

	void drawCornerResizer(Graphics& g, int w, int h, bool isMouseOver, bool isMouseDragging) override
	{
		if (!isMouseDragging)
		{
			auto lineThickness = jmin(w, h) * 0.075f;

			for (float i = 0.0f; i < 1.0f; i += 0.3f)
			{
				g.setColour(Colours::black);

				g.drawLine(w * i,
					h + 1.0f,
					w + 1.0f,
					h * i,
					lineThickness);

				if (isMouseOver) g.setColour(Colours::red); else g.setColour(Colours::darkgrey);

				g.drawLine(w * i + lineThickness,
					h + 1.0f,
					w + 1.0f,
					h * i + lineThickness,
					lineThickness);
			}
		}
	}

};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WusikPr44AudioProcessorEditor  : public AudioProcessorEditor, public Button::Listener, public Timer
{
public:
    WusikPr44AudioProcessorEditor (WusikPr44AudioProcessor&);
    ~WusikPr44AudioProcessorEditor();
	//
	void timerCallback() override
	{
		stopTimer();
		//
		if (!processor.connectedToDevice && processor.connectDevice == 1 && 
			processor.connectDeviceTime > 0 && Time::getMillisecondCounter() > processor.connectDeviceTime)
		{
			processor.connectDeviceTime = 0;
			processor.connectDevice = 0;
			processor.initErrorMessage = "Retrying Connection...";
			repaint();
		}
		//
		if (processor.connectedToDevice)
		{
			if (processor.switchInterfaces)
			{
				processor.switchInterfaces = false;
				if (processor.optionsWindow != nullptr) processor.optionsWindow->closeButtonPressed();
				if (processor.objectOptionsWindow != nullptr) processor.objectOptionsWindow->closeButtonPressed();
				if (processor.mainWindow != nullptr) processor.mainWindow->closeButtonPressed();
				if (processor.imageWindow != nullptr) processor.imageWindow->closeButtonPressed();
				//
				processor.isEditing = !processor.isEditing;
				if (processor.isEditing) buttonClicked(introMenu->gettextButtonEdit()); else buttonClicked(nullptr);
			}
		}
		//
		startTimer(242);
	};
	//
	void createInterface();
	void buttonClicked(Button* buttonThatWasClicked) override;
    void paint (Graphics&) override;
	void mouseUp(const MouseEvent& e) override;
	//
private:
	WPR44LookAndFeel wsLookAndFeel;
	IntroMenu* introMenu;
    WusikPr44AudioProcessor& processor;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WusikPr44AudioProcessorEditor)
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class MainWindow : public DocumentWindow, public Timer
{
public:
	MainWindow(bool _edit, WusikPr44AudioProcessor& _processor, String name) : 
		processor(_processor), isEditing(_edit), DocumentWindow("Wusik PR44", Colours::black, _processor.fullscreenMode ? 0 : DocumentWindow::allButtons, true)
	{
		setUsingNativeTitleBar(true);
		//
		if (processor.fullscreenMode) setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea);
		else
		{
			if (processor.lastMainWindowSize.getWidth() > 0)setBounds(processor.lastMainWindowSize);
			else setBounds(200, 200, Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() / 2, Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2);
		}
		//
		EditCompo* editCompo = new EditCompo();
		setContentOwned(editCompo, false);
		editCompo->setBounds(getBounds());
		editCompo->parent = &processor;
		editCompo->createButtons();
		editCompo->updateObjects();
		//
		setVisible(true);
		toFront(true);
		startTimer(100);
		//
		processor.changeScreenMode();
	}
	//
	void closeButtonPressed() override 
	{
		if (isEditing)
		{
			if (processor.optionsWindow != nullptr) processor.optionsWindow->setVisible(false);
			if (processor.objectOptionsWindow != nullptr) processor.objectOptionsWindow->setVisible(false);
			if (processor.imageWindow != nullptr) processor.imageWindow->setVisible(false);
		}
		//
		processor.sequencerClock.stop();
		if (processor.mainWindow != nullptr)
		{
			if (!processor.fullscreenMode) processor.lastMainWindowSize = getBounds();
			((EditCompo*)processor.mainWindow->getContentComponent())->dasButtons.clear();
			processor.mainWindow->setVisible(false);
		}
		processor.stopAllSounds = true;
	}
	void timerCallback() override
	{
		stopTimer();
		//
		if (processor.fullscreenMode)
		{
			if (!bringScreenBack && getBounds().getX() != 0 || getBounds().getY() != 0) setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea);
		}
		//
		if (processor.loadingAudiosPosition != -1)
		{
			((EditCompo*)getContentComponent())->repaint();
		}
		//
		bool foundOne = true;
		while (foundOne)
		{
			foundOne = false;
			EditCompo* edCompo = (EditCompo*)getContentComponent();
			//
			ARRAY_Iterator(edCompo->zoomCompos)
			{
				if (edCompo->zoomCompos[index]->alphaZoom <= 0.0f)
				{
					foundOne = true;
					edCompo->zoomCompos.remove(index);
					break;
				}
			}
		}
		//
		startTimer(242);
	};
	//
	bool isEditing = false;
	bool bringScreenBack = false;
	bool hasConnected = false;
	WusikPr44AudioProcessor& processor;
	//
private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
};