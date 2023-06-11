/*
	Created by Guilherme (William) Kalfelz @ Wusik.com (c) 2020
*/
//
#include "LeButton.h"
#include "EditCompo.h"
#include "PixelBlenders.h"
//
// ------------------------------------------------------------------------------------------------------------------------------------
leButton::leButton(WusikPr44AudioProcessor* _processor) : processor(_processor), Button("")
{
	if (processor->isEditing)
	{
		resizeConstrainer.setSizeLimits(50, 50, 5000, 5000);
		resizeCorner = new ResizableCornerComponent(this, &resizeConstrainer);
		addAndMakeVisible(resizeCorner);
	}
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
leButton::~leButton() 
{ 
	if (processor->isEditing)
	{
		if (leObject != nullptr) leObject->position = getBounds();
	}
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
void leButton::resized()
{
	if (processor->isEditing)
	{
		if (gridSize != nullptr)
		{
			resizeConstrainer.setSizeLimits(gridSize[0], gridSize[0], 9999, 9999);
			setBounds(getBounds().getX(), getBounds().getY(), getSnapToGrid(getWidth()), getSnapToGrid(getHeight()));
		}
		//
		resizeCorner->setBounds(getWidth() - 42 - 28, getHeight() - 42 - 28, 42, 42);
		resizeCorner->setAlpha(0.22f);
		redoButton = true;
		//
		if (leObject != nullptr && processor->selectedObject != leObject) processor->selectObject(leObject);
		//
		if (MultiLineText != nullptr) MultiLineText->setBounds(60, 60, getWidth() - 120, getHeight() - 120);
	}
};
//
// ------------------------------------------------------------------------------------------------------------------------------------
void leButton::timerCallback()
{
	stopTimer();
	//
	if (processor->isEditing && leObject->justSelected)
	{
		if (selectedTime > 0 && (Time::getApproximateMillisecondCounter() - selectedTime) > 1000)
		{
			selectedTime = 0;
			leObject->justSelected = false;
			repaint();
		}
		//
		startTimer(20);
	}
	//
	if (leObject->type == WPR44Object::kType_Button)
	{
		WPR44ButtonObject* buttonObject = (WPR44ButtonObject*)leObject;
		if (buttonObject->action != WPR44Object::kAction_MultiStarter)
		{
			clickColour = Colours::transparentBlack;
			repaint();
		}
	}
	//
	if (leObject != nullptr)
	{
		if (leObject->type == WPR44Object::kType_Sound && leObject->animationColour.getFloatAlpha() > 0.0f)
		{
			WPR44SoundObject* soundObject = (WPR44SoundObject*)leObject;
			//
			if (!soundObject->isPlaying)
			{
				if (animationWidth != 0)
				{
					animationWidth = 0;
					repaint();
				}
			}
			else
			{
				if (soundObject->voices.getLast()->audioPosition != -1 && soundObject->audio.getNumSamples() > 0)
				{
					int xPos = 0;
					//
					if (soundObject->animationType == WPR44Object::kAnimation_Beat && processor->sequencerClock.totalSamplesPerBeat > 0)
					{
						int xPos2 = int(float(soundObject->voices.getLast()->audioPosition) / float(processor->sequencerClock.totalSamplesPerBeat));
						xPos = (float(getWidth() - (28 * 2)) / float((soundObject->audio.getNumSamples() / processor->sequencerClock.totalSamplesPerBeat) - 1)) * float(xPos2);
					}
					else if (soundObject->animationType == WPR44Object::kAnimation_Measure && processor->sequencerClock.totalSamplesPerBeat > 0)
					{
						int xPos2 = int(float(soundObject->voices.getLast()->audioPosition) / float((processor->sequencerClock.totalSamplesPerBeat * 4)));
						xPos = (float(getWidth() - (28 * 2)) / float((soundObject->audio.getNumSamples() / (processor->sequencerClock.totalSamplesPerBeat * 4)) - 1)) * float(xPos2);
					}
					else
					{
						if (soundObject->measures == 0) xPos = (float(getWidth() - (28 * 2)) / float(processor->sequencerClock.totalSamplesForAllMeasures)) * float(soundObject->voices.getLast()->audioPosition);
							else xPos = (float(getWidth() - (28 * 2)) / float(soundObject->measures * 4 * processor->sequencerClock.totalSamplesPerBeat)) * float(soundObject->voices.getLast()->audioPosition);
					}
					//
					if (xPos != animationWidth)
					{
						animationWidth = jmax(0, xPos);
						repaint();
					}
				}
			}
			//
			startTimer(20);
		}
	}
}
// ------------------------------------------------------------------------------------------------------------------------------------
void leButton::mouseDown(const MouseEvent& e)
{
	mouseMoved = false;
	//
	if (leObject != nullptr && leObject->animationColour.getFloatAlpha() > 0.0f) startTimer(20);
	//
	if (processor->isEditing && !e.mods.isMiddleButtonDown())
	{
		prevPosition[0] = getBounds().getX();
		prevPosition[1] = getBounds().getY();
		wasOpenMenu = false;
	}
	else
	{
		processor->objectTriggered(leObject);
	}
	//
	repaint();
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void leButton::mouseUp(const MouseEvent& e)
{
	if (processor->isEditing && !e.mods.isMiddleButtonDown())
	{
		if (!mouseMoved)
		{
			if (e.mods.isRightButtonDown()) wasOpenMenu = true;
			Button::mouseDown(e);
			Button::mouseUp(e);
		}
	}
	else
	{
		if (leObject->type == WPR44Object::kType_Sound)
		{
			WPR44SoundObject* soundObject = (WPR44SoundObject*)leObject;
			//
			if (soundObject->mouseDragToVolume && !mouseMoved)
			{
				processor->objectTriggered(leObject);
			}
		}
	}
	//
	if (leObject->zoomType != WPR44Object::kZoom_Off && leObject->zoomColour.getAlpha() > 0.0f
		&& leObject->type != WPR44Object::kType_Image)
	{
		((EditCompo*)processor->mainWindow->getContentComponent())->zoomCompos.add(new WZoomCompo(this));
		processor->mainWindow->getContentComponent()->addAndMakeVisible(((EditCompo*)processor->mainWindow->getContentComponent())->zoomCompos.getLast());
		((EditCompo*)processor->mainWindow->getContentComponent())->zoomCompos.getLast()->toFront(false);
		toFront(true);
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void leButton::mouseDrag(const MouseEvent& e)
{
	if (processor->isEditing)
	{
		if (mouseMoved || fabs(e.getDistanceFromDragStartX()) >= gridSize[0] || fabs(e.getDistanceFromDragStartY()) >= gridSize[0])
		{
			mouseMoved = true;
			//
			setBounds(getSnapToGrid(prevPosition[0] + e.getDistanceFromDragStartX()),
				getSnapToGrid(prevPosition[1] + e.getDistanceFromDragStartY()),
				getWidth(), getHeight());
		}
	}
	else
	{
		//
	}
}
//
// ------------------------------------------------------------------------------------------------------------------------------------
void leButton::paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
	if (leObject != nullptr)
	{
		if (leObject->type == WPR44Object::kType_Image && MultiLineText == nullptr && leObject->multiLine.isNotEmpty() && leObject->multiLine.compareIgnoreCase("disabled") != 0)
		{
			MultiLineText = new TextEditor("Multi");
			MultiLineText->setMultiLine(true);
			MultiLineText->setReturnKeyStartsNewLine(true);
			MultiLineText->setReadOnly(true);
			MultiLineText->setScrollbarsShown(true);
			MultiLineText->setCaretVisible(false);
			MultiLineText->setPopupMenuEnabled(true);
			MultiLineText->setColour(TextEditor::outlineColourId, Colours::transparentBlack);
			MultiLineText->setColour(TextEditor::shadowColourId, Colours::transparentBlack);
			MultiLineText->setColour(TextEditor::ColourIds::backgroundColourId, Colours::transparentBlack);
			MultiLineText->setColour(TextEditor::ColourIds::textColourId, leObject->fontColour);
			MultiLineText->setMultiLine(true);
			MultiLineText->setInterceptsMouseClicks(!processor->isEditing, !processor->isEditing);
			MultiLineText->applyFontToAllText(processor->globalFont.withHeight(leObject->fontSize));
			MultiLineText->setText(leObject->multiLine, false);
			MultiLineText->setBounds(60, 60, getWidth() - 120, getHeight() - 120);
			addAndMakeVisible(MultiLineText);
		}
		if (leObject->type == WPR44Object::kType_Image && MultiLineText != nullptr && (leObject->multiLine.isEmpty() || leObject->multiLine.compareIgnoreCase("disabled") == 0))
		{
			MultiLineText = nullptr;
		}
		//
		if (processor->isEditing && MultiLineText != nullptr)
		{
			MultiLineText->applyFontToAllText(processor->globalFont.withHeight(leObject->fontSize));
			MultiLineText->setText(leObject->multiLine, false);
		}
		//
		#define WDRAWRECT(aa, bb, cc, dd) if (leObject->fill) graphicsContext->fillRoundedRectangle(aa, bb, cc, dd, leObject->roundCorners); else graphicsContext->drawRoundedRectangle(aa, bb, cc, dd, leObject->roundCorners, leObject->thickness)
		//
		Graphics* graphicsContext = &g;
		//
		if (leObject->shadowEffectOn || leObject->cutImageUsingBackground)
		{
			if (imageTemp == nullptr || redoButton)
			{
				imageTemp = new Image(Image::ARGB, getWidth(), getHeight(), true);
				render = new Graphics(*imageTemp);
				leObject->shadowEffect.setShadowProperties(leObject->shadowSettings);
				redoButton = false;
				//
				if (leObject->cutImageUsingBackground) imageTemp2 = new Image(Image::ARGB, getWidth(), getHeight(), true);
			}
			//
			graphicsContext = render;
			imageTemp->clear(Rectangle<int>(0, 0, getWidth(), getHeight()));
			if (leObject->cutImageUsingBackground)
			{
				if (imageTemp2 == nullptr) imageTemp2 = new Image(Image::ARGB, getWidth(), getHeight(), true);
				imageTemp2->clear(Rectangle<int>(0, 0, getWidth(), getHeight()));
			}
		}
		//
		if (leObject->type != WPR44Object::kType_Image && !leObject->borderToFront)
		{
			graphicsContext->setColour(leObject->borderColour);
			graphicsContext->drawRoundedRectangle(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2), leObject->roundCorners, leObject->borderWidth);
		}
		//
		#define WDRAWIMAGE(imageEnum) if (leObject->imageStretch) graphicsContext->drawImage(*leObject->images[WPR44Object::imageEnum],\
				22, 22, getWidth() - 44,\
				getHeight() - 44, 0, 0, leObject->images[WPR44Object::imageEnum]->getWidth(),\
				leObject->images[WPR44Object::imageEnum]->getHeight());\
				else if (leObject->imageScale != 1.0f)\
				graphicsContext->drawImage(*leObject->images[WPR44Object::imageEnum], 22, 22,\
				int(leObject->imageScale * float(leObject->images[WPR44Object::imageEnum]->getWidth())) - 44,\
				int(leObject->imageScale * float(leObject->images[WPR44Object::imageEnum]->getHeight())) - 44, 0, 0,\
				leObject->images[WPR44Object::imageEnum]->getWidth(), leObject->images[WPR44Object::imageEnum]->getHeight());\
				else graphicsContext->drawImage(*leObject->images[WPR44Object::imageEnum], 22, 22,\
				getWidth() - 44,\
				getHeight() - 44, 0, 0,\
				getWidth(), getHeight());
		//
		if (leObject->images[WPR44Object::kImage_Background] != nullptr)
		{
			graphicsContext->setColour(Colours::black);
			graphicsContext->setOpacity(1.0f - leObject->backgroundTransparency);
			WDRAWIMAGE(kImage_Background);
			graphicsContext->setOpacity(1.0f);
		}
		else
		{
			graphicsContext->setColour(leObject->backgroundColour);
			WDRAWRECT(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2));
		}
		//
		if (leObject->type == WPR44Object::kType_Sound)
		{
			if (((WPR44SoundObject*)leObject)->isPlaying)
			{
				if (leObject->images[WPR44Object::kImage_Playing] != nullptr)
				{
					graphicsContext->setColour(Colours::black);
					WDRAWIMAGE(kImage_Playing);
				}
				else if (!leObject->coloursToFont)
				{
					graphicsContext->setColour(((WPR44SoundObject*)leObject)->playingColour);
					WDRAWRECT(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2));
				}
			}
			if ((((WPR44SoundObject*)leObject)->isQueuedToPlay || ((WPR44SoundObject*)leObject)->isQueuedToPlayMulti))
			{
				if (leObject->images[WPR44Object::kImage_Queued] != nullptr)
				{
					graphicsContext->setColour(Colours::black);
					WDRAWIMAGE(kImage_Queued);
				}
				else if (!leObject->coloursToFont)
				{
					graphicsContext->setColour(((WPR44SoundObject*)leObject)->queuedColour);
					WDRAWRECT(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2));
				}
			}
			if (((WPR44SoundObject*)leObject)->isQueuedToStop)
			{
				if (leObject->images[WPR44Object::kImage_Stop] != nullptr)
				{
					graphicsContext->setColour(Colours::black);
					WDRAWIMAGE(kImage_Stop);
				}
				else if (!leObject->coloursToFont)
				{
					graphicsContext->setColour(((WPR44SoundObject*)leObject)->stopColour);
					WDRAWRECT(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2));
				}
			}
			if (((WPR44SoundObject*)leObject)->isRecording && leObject->images[WPR44Object::kImage_Recording] != nullptr)
			{
				graphicsContext->setColour(Colours::black);
				WDRAWIMAGE(kImage_Recording);
			}
		}
		//
		if (clickColour.getFloatAlpha() > 0.0f && leObject->images[WPR44Object::kImage_Click] != nullptr)
		{
			graphicsContext->setColour(Colours::black);
			WDRAWIMAGE(kImage_Click);
		}
		else
		{
			graphicsContext->setColour(clickColour);
			WDRAWRECT(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2));
		}
		//
		if (leObject->type != WPR44Object::kType_Image && leObject->borderToFront)
		{
			graphicsContext->setColour(leObject->borderColour);
			graphicsContext->drawRoundedRectangle(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2), leObject->roundCorners, leObject->borderWidth);
		}
		//
		if (leObject->animationColour.getFloatAlpha() > 0.0f)
		{
			graphicsContext->setColour(leObject->animationColour);
			graphicsContext->fillRect(28, 28, animationWidth, getHeight() - (28 * 2));
		}
		//
		if (processor->isEditing && leObject->justSelected)
		{
			graphicsContext->setColour(Colours::red.withAlpha(0.28f));
			WDRAWRECT(16, 16, getWidth() - 32, getHeight() - 32);
			//
			if (selectedTime == 0)
			{
				int xS = Time::getApproximateMillisecondCounter();
				selectedTime = xS;
				startTimer(20);
			}
		}
		//
		if (leObject->showName && leObject->name.isNotEmpty())
		{
			graphicsContext->setColour(leObject->fontColour);
			graphicsContext->setFont(processor->globalFont.withHeight(leObject->fontSize));
			//
			if (leObject->type != WPR44Object::kType_Image && leObject->coloursToFont)
			{
				if (((WPR44SoundObject*)leObject)->isQueuedToStop) graphicsContext->setColour(((WPR44SoundObject*)leObject)->stopColour);
				else if (((WPR44SoundObject*)leObject)->isPlaying) graphicsContext->setColour(((WPR44SoundObject*)leObject)->playingColour);
				else if (((WPR44SoundObject*)leObject)->isQueuedToPlay) graphicsContext->setColour(((WPR44SoundObject*)leObject)->queuedColour);
			}
			//
			if (leObject->namePosition[0] == -1) graphicsContext->drawFittedText(leObject->name.replace("{NL}", "\n"), 2, 2, getWidth() - 4, getHeight() - 4, Justification::centred, 1);
			else graphicsContext->drawFittedText(leObject->name.replace("{NL}", "\n"), leObject->namePosition[0], leObject->namePosition[1], getWidth() * 2, getHeight() * 2, Justification::topLeft, 1);
		}
		//
		if (leObject->shadowEffectOn || leObject->cutImageUsingBackground)
		{
			if (leObject->cutImageUsingBackground)
			{
				Graphics rr(*imageTemp2);
				rr.setColour(Colours::white);
				rr.fillRoundedRectangle(28, 28, getWidth() - (28 * 2), getHeight() - (28 * 2), leObject->roundCorners);
				//
				Blend<DstInPixelBlender>(*imageTemp, *imageTemp2);
				if (!leObject->shadowEffectOn) g.drawImageAt(*imageTemp, 0, 0);
			}
			//
			if (leObject->shadowEffectOn)
			{
				leObject->shadowEffect.applyEffect(*imageTemp, g, 1.0f, 1.0f);
				g.drawImageAt(*imageTemp, 0, 0);
			}
		}
	}
	else // ------------- No Object ------------- //
	{
		g.fillAll(Colours::white);
		g.setColour(Colours::blue);
		g.fillRect(4, 4, getWidth() - 8, getHeight() - 8);
		g.fillAll(Colours::red.withAlpha(0.18f));
	}
}