/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
#pragma once
#include "PluginProcessor.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
class leButton : public Button, public Timer
{
public:
	leButton(WusikPr44AudioProcessor* _processor);
	~leButton();
	//
	void resized() override;
	void clicked() override { repaint(); }
	using Button::clicked;
	void paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
	void mouseDown(const MouseEvent& e) override;
	void mouseUp(const MouseEvent& e) override;
	void mouseDrag(const MouseEvent& e) override;
	void timerCallback() override;
	//
	int getSnapToGrid(int value)
	{
		if (snapToGrid[0]) return int(float(int(float(value) / gridSize[0])) * gridSize[0]); else return value;
	}
	//
	bool wasOpenMenu = false;
	int prevPosition[2] = { 0, 0 };
	bool mouseMoved = false;
	bool *snapToGrid = nullptr;
	float *gridSize = nullptr;
	WusikPr44AudioProcessor* processor;
	WPR44Object* leObject = nullptr;
	ComponentBoundsConstrainer resizeConstrainer;
	ScopedPointer<ResizableCornerComponent> resizeCorner;
	Colour clickColour = Colours::transparentBlack;
	ScopedPointer<Image> imageTemp;
	ScopedPointer<Image> imageTemp2;
	ScopedPointer<Graphics> render;
	bool redoButton = false;
	int animationWidth = 0;
	uint32 selectedTime = 0;
	ScopedPointer<TextEditor> MultiLineText;
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
class WZoomCompo : public Component, public Timer
{
public:
	WZoomCompo(leButton* _originalButton) : originalButton(_originalButton)
	{
		setInterceptsMouseClicks(false, false);
		setBounds(originalButton->getBounds());
		startTimer(20);
	};
	//
	void paint(Graphics& g) override
	{
		g.setColour(originalButton->leObject->zoomColour.withAlpha(alphaZoom));
		g.fillRoundedRectangle(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2), originalButton->leObject->roundCorners);
	};
	//
	void timerCallback() override
	{
		stopTimer();
		//
		if (originalButton->leObject->zoomType == WPR44Object::kZoom_Fast)
		{
			alphaZoom -= 0.1f;
			setBounds(getBounds().expanded(8));
		}
		else if (originalButton->leObject->zoomType == WPR44Object::kZoom_Slow)
		{
			alphaZoom -= 0.012f;
			setBounds(getBounds().expanded(1));
		}
		else
		{
			alphaZoom -= 0.044f;
			setBounds(getBounds().expanded(6));
		}
		//
		//
		if (alphaZoom < 0.0f) return;
		repaint();
		startTimer(20);
	};
	//
	leButton* originalButton;
	float alphaZoom = 1.0f;
};