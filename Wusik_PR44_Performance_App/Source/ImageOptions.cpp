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

#include "PluginProcessor.h"
#include "PluginEditor.h"

//[/Headers]

#include "ImageOptions.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

//[/MiscUserDefs]

//==============================================================================
ImageOptions::ImageOptions ()
{
    //[Constructor_pre] You can add your own custom stuff here..

	getLookAndFeel().setDefaultSansSerifTypefaceName("Verdana");

    //[/Constructor_pre]

    label3.reset (new Label ("new label",
                             TRANS("Back Colour")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (27, 121, 93, 24);

    textButton_BackColour.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_BackColour.get());
    textButton_BackColour->setButtonText (String());
    textButton_BackColour->addListener (this);
    textButton_BackColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_BackColour->setBounds (134, 122, 72, 24);

    label7.reset (new Label ("new label",
                             TRANS("Screen")));
    addAndMakeVisible (label7.get());
    label7->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label7->setBounds (38, 598, 93, 24);

    objectType.reset (new Label ("new label",
                                 TRANS("Type: Image/Label")));
    addAndMakeVisible (objectType.get());
    objectType->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    objectType->setJustificationType (Justification::centred);
    objectType->setEditable (false, false, false);
    objectType->setColour (TextEditor::textColourId, Colours::black);
    objectType->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    objectType->setBounds (16, 78, 288, 24);

    textButton_Image.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_Image.get());
    textButton_Image->setTooltip (TRANS("Background Image (can be transparent)"));
    textButton_Image->setButtonText (TRANS("Image"));
    textButton_Image->addListener (this);
    textButton_Image->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Image->setBounds (134, 163, 72, 24);

    textButton_Duplicate.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Duplicate.get());
    textButton_Duplicate->setButtonText (TRANS("Duplicate"));
    textButton_Duplicate->addListener (this);
    textButton_Duplicate->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Duplicate->setBounds (63, 24, 88, 24);

    textButton_Delete.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_Delete.get());
    textButton_Delete->setButtonText (TRANS("Delete"));
    textButton_Delete->addListener (this);
    textButton_Delete->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Delete->setBounds (176, 24, 88, 24);

    comboBox_Screen.reset (new ComboBox ("new combo box"));
    addAndMakeVisible (comboBox_Screen.get());
    comboBox_Screen->setTooltip (TRANS("Which screen this object should show on"));
    comboBox_Screen->setEditableText (false);
    comboBox_Screen->setJustificationType (Justification::centredLeft);
    comboBox_Screen->setTextWhenNothingSelected (String());
    comboBox_Screen->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox_Screen->addItem (TRANS("A"), 1);
    comboBox_Screen->addItem (TRANS("B"), 2);
    comboBox_Screen->addItem (TRANS("C"), 3);
    comboBox_Screen->addItem (TRANS("D"), 4);
    comboBox_Screen->addListener (this);

    comboBox_Screen->setBounds (145, 598, 90, 28);

    label10.reset (new Label ("new label",
                              TRANS("Image")));
    addAndMakeVisible (label10.get());
    label10->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label10->setBounds (27, 163, 93, 24);

    textButton_ImageScale.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_ImageScale.get());
    textButton_ImageScale->setButtonText (String());
    textButton_ImageScale->addListener (this);
    textButton_ImageScale->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImageScale->setBounds (134, 204, 72, 24);

    label11.reset (new Label ("new label",
                              TRANS("Scale")));
    addAndMakeVisible (label11.get());
    label11->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label11->setBounds (27, 204, 93, 24);

    toggleButton_ImageStretch.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_ImageStretch.get());
    toggleButton_ImageStretch->setButtonText (TRANS("Stretch"));
    toggleButton_ImageStretch->addListener (this);

    toggleButton_ImageStretch->setBounds (221, 164, 81, 24);

    toggleButton_ImageToBack.reset (new ToggleButton ("Internal Clock"));
    addAndMakeVisible (toggleButton_ImageToBack.get());
    toggleButton_ImageToBack->setTooltip (TRANS("Keep image in the most background position, relative to the other objects (but still on top of the main background)."));
    toggleButton_ImageToBack->setButtonText (TRANS("To Back"));
    toggleButton_ImageToBack->addListener (this);

    toggleButton_ImageToBack->setBounds (221, 197, 81, 24);

    textButton_Shadow.reset (new TextButton ("button Back Colour"));
    addAndMakeVisible (textButton_Shadow.get());
    textButton_Shadow->setButtonText (TRANS("Shadow"));
    textButton_Shadow->addListener (this);
    textButton_Shadow->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_Shadow->setBounds (224, 122, 64, 24);

    label12.reset (new Label ("new label",
                              TRANS("Round/Square")));
    addAndMakeVisible (label12.get());
    label12->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label12->setBounds (27, 282, 101, 25);

    textButton_RoundSquare.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_RoundSquare.get());
    textButton_RoundSquare->setTooltip (TRANS("0.0 is square and 1.0 is complete round corners."));
    textButton_RoundSquare->setButtonText (String());
    textButton_RoundSquare->addListener (this);
    textButton_RoundSquare->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_RoundSquare->setBounds (134, 284, 72, 24);

    label2.reset (new Label ("new label",
                             TRANS("Transparency")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (27, 242, 101, 25);

    textButton_ImageAlpha.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_ImageAlpha.get());
    textButton_ImageAlpha->setTooltip (TRANS("0.0 is square and 1.0 is complete round corners."));
    textButton_ImageAlpha->setButtonText (String());
    textButton_ImageAlpha->addListener (this);
    textButton_ImageAlpha->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_ImageAlpha->setBounds (134, 244, 72, 24);

    toggleButton_ImageCut.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_ImageCut.get());
    toggleButton_ImageCut->setTooltip (TRANS("Cut the image according to the background rectangle."));
    toggleButton_ImageCut->setButtonText (TRANS("Cut"));
    toggleButton_ImageCut->addListener (this);

    toggleButton_ImageCut->setBounds (221, 230, 72, 24);

    textButton_Name.reset (new TextButton ("Name"));
    addAndMakeVisible (textButton_Name.get());
    textButton_Name->setButtonText (String());
    textButton_Name->addListener (this);
    textButton_Name->setColour (TextButton::buttonColourId, Colour (0xff0e2781));

    textButton_Name->setBounds (35, 371, 272, 32);

    label5.reset (new Label ("new label",
                             TRANS("Font Size")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label5->setBounds (38, 547, 93, 24);

    label6.reset (new Label ("new label",
                             TRANS("Font Colour")));
    addAndMakeVisible (label6.get());
    label6->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label6->setBounds (38, 505, 93, 24);

    textButton_FontColour.reset (new TextButton ("button Font Colour"));
    addAndMakeVisible (textButton_FontColour.get());
    textButton_FontColour->setButtonText (String());
    textButton_FontColour->addListener (this);
    textButton_FontColour->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_FontColour->setBounds (145, 506, 72, 24);

    label8.reset (new Label ("new label",
                             TRANS("Position\n"
                             "Horizontal")));
    addAndMakeVisible (label8.get());
    label8->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label8->setBounds (38, 423, 101, 25);

    textButton_HorizontalPos.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_HorizontalPos.get());
    textButton_HorizontalPos->setButtonText (String());
    textButton_HorizontalPos->addListener (this);
    textButton_HorizontalPos->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_HorizontalPos->setBounds (145, 423, 72, 24);

    label9.reset (new Label ("new label",
                             TRANS("Vertical")));
    addAndMakeVisible (label9.get());
    label9->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label9->setBounds (38, 462, 101, 25);

    textButton_VerticalPos.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_VerticalPos.get());
    textButton_VerticalPos->setButtonText (String());
    textButton_VerticalPos->addListener (this);
    textButton_VerticalPos->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_VerticalPos->setBounds (145, 464, 72, 24);

    textButton_FontSize.reset (new TextButton ("button Border Colour"));
    addAndMakeVisible (textButton_FontSize.get());
    textButton_FontSize->setTooltip (TRANS("0.0 is square and 1.0 is complete round corners."));
    textButton_FontSize->setButtonText (String());
    textButton_FontSize->addListener (this);
    textButton_FontSize->setColour (TextButton::buttonColourId, Colour (0xff001da8));

    textButton_FontSize->setBounds (145, 547, 72, 24);

    label4.reset (new Label ("new label",
                             TRANS("Label Text")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (132, 342, 82, 25);

    toggleButton_ShowName.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton_ShowName.get());
    toggleButton_ShowName->setTooltip (TRANS("Show the button name"));
    toggleButton_ShowName->setButtonText (TRANS("Show"));
    toggleButton_ShowName->addListener (this);

    toggleButton_ShowName->setBounds (235, 416, 72, 24);

    textEditor_Multi.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor_Multi.get());
    textEditor_Multi->setMultiLine (true);
    textEditor_Multi->setReturnKeyStartsNewLine (true);
    textEditor_Multi->setReadOnly (false);
    textEditor_Multi->setScrollbarsShown (true);
    textEditor_Multi->setCaretVisible (true);
    textEditor_Multi->setPopupMenuEnabled (true);
    textEditor_Multi->setColour (TextEditor::backgroundColourId, Colour (0xff15232a));
    textEditor_Multi->setColour (CaretComponent::caretColourId, Colour (0xffffb2b2));
    textEditor_Multi->setText (TRANS("Disabled"));

    textEditor_Multi->setBounds (16, 715, 300, 293);

    label13.reset (new Label ("new label",
                              TRANS("Multi Line Text")));
    addAndMakeVisible (label13.get());
    label13->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label13->setBounds (128, 677, 101, 25);


    //[UserPreSize]

	textEditor_Multi->addListener(this);

    //[/UserPreSize]

    setSize (360, 1024);


    //[Constructor] You can add your own custom stuff here..



    //[/Constructor]
}

ImageOptions::~ImageOptions()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label3 = nullptr;
    textButton_BackColour = nullptr;
    label7 = nullptr;
    objectType = nullptr;
    textButton_Image = nullptr;
    textButton_Duplicate = nullptr;
    textButton_Delete = nullptr;
    comboBox_Screen = nullptr;
    label10 = nullptr;
    textButton_ImageScale = nullptr;
    label11 = nullptr;
    toggleButton_ImageStretch = nullptr;
    toggleButton_ImageToBack = nullptr;
    textButton_Shadow = nullptr;
    label12 = nullptr;
    textButton_RoundSquare = nullptr;
    label2 = nullptr;
    textButton_ImageAlpha = nullptr;
    toggleButton_ImageCut = nullptr;
    textButton_Name = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    textButton_FontColour = nullptr;
    label8 = nullptr;
    textButton_HorizontalPos = nullptr;
    label9 = nullptr;
    textButton_VerticalPos = nullptr;
    textButton_FontSize = nullptr;
    label4 = nullptr;
    toggleButton_ShowName = nullptr;
    textEditor_Multi = nullptr;
    label13 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ImageOptions::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = 24, y = 8, width = 272, height = 56;
        Colour fillColour = Colour (0x3000001c);
        //[UserPaintCustomArguments] Customize the painting arguments here..

    		//if (processor->selectedObject->type == WPR44Object::kType_Button) fillColour = Colours::transparentBlack;

        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 19, y = 331, width = 309, height = 253;
        Colour fillColour = Colour (0x2a11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 25, y = 656, width = 278, height = 8;
        Colour fillColour = Colour (0xff11126f);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ImageOptions::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ImageOptions::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton_BackColour.get())
    {
        //[UserButtonCode_textButton_BackColour] -- add your button handler code here..

		browseColour(&processor->selectedObject->backgroundColour, textButton_BackColour.get());

        //[/UserButtonCode_textButton_BackColour]
    }
    else if (buttonThatWasClicked == textButton_Image.get())
    {
        //[UserButtonCode_textButton_Image] -- add your button handler code here..

		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Background].isNotEmpty())
		{
			processor->selectedObject->imagesFilename[WPR44Object::kImage_Background] = String();
			processor->selectedObject->images[WPR44Object::kImage_Background] = nullptr;
			processor->loadImages();
			textButton_Image->setButtonText("Image");
			processor->imageWindow->repaint();
			processor->mainWindow->repaint();
		}
		else
		{
			FileChooser loadFile("Load Background Image", processor->lastBackImagePath, String("*"));
			if (loadFile.browseForFileToOpen())
			{
				processor->lastBackImagePath = loadFile.getResult().getParentDirectory();
				processor->userSettings->setValue("Image Path", processor->lastBackImagePath.getFullPathName());
				textButton_Image->setButtonText("(*)Image");
				processor->selectedObject->imagesFilename[WPR44Object::kImage_Background] = loadFile.getResult().getFullPathName();
				processor->loadImages();
				processor->mainWindow->repaint();
			}
		}

        //[/UserButtonCode_textButton_Image]
    }
    else if (buttonThatWasClicked == textButton_Duplicate.get())
    {
        //[UserButtonCode_textButton_Duplicate] -- add your button handler code here..

		processor->duplicateObject(processor->selectedObject);

        //[/UserButtonCode_textButton_Duplicate]
    }
    else if (buttonThatWasClicked == textButton_Delete.get())
    {
        //[UserButtonCode_textButton_Delete] -- add your button handler code here..

		if (ConfirmBox("Delete Object", "Are you sure?"))
		{
			processor->imageWindow->setVisible(false);
			EditCompo* edCompo = (EditCompo*)processor->mainWindow->getContentComponent();
			//
			ARRAY_Iterator(edCompo->dasButtons)
			{
				if (edCompo->dasButtons[index]->leObject == processor->selectedObject)
				{
					removeChildComponent(edCompo->dasButtons[index]);
					edCompo->dasButtons[index]->removeListener(edCompo);
					edCompo->dasButtons.remove(index);
					break;
				}
			}
			//
			processor->deleteSelectedObject = true;
			processor->mainWindow->repaint();
			return;
		}

        //[/UserButtonCode_textButton_Delete]
    }
    else if (buttonThatWasClicked == textButton_ImageScale.get())
    {
        //[UserButtonCode_textButton_ImageScale] -- add your button handler code here..

		String theValue;
		AskValue("Image Scale", "(1.0 is the default size)", String(processor->selectedObject->imageScale), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->selectedObject->imageScale = theValue.getFloatValue();
			textButton_ImageScale->setButtonText(String(processor->selectedObject->imageScale, 2));
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_ImageScale]
    }
    else if (buttonThatWasClicked == toggleButton_ImageStretch.get())
    {
        //[UserButtonCode_toggleButton_ImageStretch] -- add your button handler code here..

		processor->selectedObject->imageStretch = toggleButton_ImageStretch->getToggleState();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ImageStretch]
    }
    else if (buttonThatWasClicked == toggleButton_ImageToBack.get())
    {
        //[UserButtonCode_toggleButton_ImageToBack] -- add your button handler code here..

		processor->selectedObject->toBack = toggleButton_ImageToBack->getToggleState();
		//
		processor->mainWindow->getContentComponent()->removeAllChildren();
		((EditCompo*)processor->mainWindow->getContentComponent())->dasButtons.clear();
		((EditCompo*)processor->mainWindow->getContentComponent())->createButtons();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ImageToBack]
    }
    else if (buttonThatWasClicked == textButton_Shadow.get())
    {
        //[UserButtonCode_textButton_Shadow] -- add your button handler code here..

		StringArray enabledS = { "No", "Yes" };
		AlertWindow w("Shadow Effect", "", AlertWindow::NoIcon);
		w.addComboBox("Enabled", enabledS, "Enabled");
		w.addTextEditor("Colour", processor->selectedObject->shadowSettings.colour.toString(), "Shadow Colour");
		w.addTextEditor("Offset", processor->selectedObject->shadowSettings.offset.toString(), "X,Y offset");
		w.addTextEditor("Radius", String(processor->selectedObject->shadowSettings.radius), "Radius of the effect");
		w.addButton("OK", 1, KeyPress(KeyPress::returnKey, 0, 0));
		w.addButton("Cancel", 0, KeyPress(KeyPress::escapeKey, 0, 0));
		w.setAlwaysOnTop(true);
		//
		if (processor->selectedObject->shadowEffectOn) w.getComboBoxComponent("Enabled")->setSelectedId(2, NotificationType::dontSendNotification);
		else w.getComboBoxComponent("Enabled")->setSelectedId(1, NotificationType::dontSendNotification);
		//
		if (w.runModalLoop() != 0)
		{
			processor->selectedObject->shadowSettings.colour = Colour::fromString(w.getTextEditorContents("Colour"));
			processor->selectedObject->shadowSettings.radius = w.getTextEditorContents("Radius").getIntValue();
			processor->selectedObject->shadowSettings.offset.x = w.getTextEditorContents("Offset").upToFirstOccurrenceOf(",", false, false).getIntValue();
			processor->selectedObject->shadowSettings.offset.y = w.getTextEditorContents("Offset").fromFirstOccurrenceOf(",", false, false).getIntValue();
			//
			if (w.getComboBoxComponent("Enabled")->getSelectedId() == 1) processor->selectedObject->shadowEffectOn = false;
			else processor->selectedObject->shadowEffectOn = true;
			//
			processor->selectedObject->shadowEffect.setShadowProperties(processor->selectedObject->shadowSettings);
			//
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_Shadow]
    }
    else if (buttonThatWasClicked == textButton_RoundSquare.get())
    {
        //[UserButtonCode_textButton_RoundSquare] -- add your button handler code here..

		String theValue;
		AskValue("Rounded Corners", "(0.0 is fully square and around 50.0 is fully round)", String(processor->selectedObject->roundCorners, 2), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->selectedObject->roundCorners = theValue.getFloatValue();
			textButton_RoundSquare->setButtonText(String(processor->selectedObject->roundCorners, 2));
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_RoundSquare]
    }
    else if (buttonThatWasClicked == textButton_ImageAlpha.get())
    {
        //[UserButtonCode_textButton_ImageAlpha] -- add your button handler code here..

		String theValue;
		AskValue("Background Transparency", "", String(processor->selectedObject->backgroundTransparency, 2), "(0.0f is none (fully opaque) and 1.0 is fully transparent)", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->selectedObject->backgroundTransparency = theValue.getFloatValue();
			if (processor->selectedObject->backgroundTransparency == 0.0f) textButton_ImageAlpha->setButtonText("Off"); else textButton_ImageAlpha->setButtonText(String(processor->selectedObject->backgroundTransparency, 2));
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_ImageAlpha]
    }
    else if (buttonThatWasClicked == toggleButton_ImageCut.get())
    {
        //[UserButtonCode_toggleButton_ImageCut] -- add your button handler code here..

		processor->selectedObject->cutImageUsingBackground = toggleButton_ImageCut->getToggleState();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ImageCut]
    }
    else if (buttonThatWasClicked == textButton_Name.get())
    {
        //[UserButtonCode_textButton_Name] -- add your button handler code here..

		String theValue;
		AskValue("Label Text", "(Add {NL} for new lines)", processor->selectedObject->name, "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->selectedObject->name = theValue;
			if (processor->selectedObject->name.isEmpty()) textButton_Name->setButtonText("(empty)"); else textButton_Name->setButtonText(processor->selectedObject->name);
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_Name]
    }
    else if (buttonThatWasClicked == textButton_FontColour.get())
    {
        //[UserButtonCode_textButton_FontColour] -- add your button handler code here..

		browseColour(&processor->selectedObject->fontColour, textButton_FontColour.get());

        //[/UserButtonCode_textButton_FontColour]
    }
    else if (buttonThatWasClicked == textButton_HorizontalPos.get())
    {
        //[UserButtonCode_textButton_HorizontalPos] -- add your button handler code here..

		String defaultValue = String(processor->selectedObject->namePosition[0]);
		if (processor->selectedObject->namePosition[0] == -1) defaultValue = "Center";
		String theValue;
		AskValue("Horizontal Position in Pixels", "(use Center for auto center)", defaultValue, "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			if (theValue.compareIgnoreCase("center") == 0)
			{
				processor->selectedObject->namePosition[0] = -1;
				processor->selectedObject->namePosition[1] = -1;
			}
			else
			{
				processor->selectedObject->namePosition[0] = theValue.getIntValue();
				if (processor->selectedObject->namePosition[1] == -1) processor->selectedObject->namePosition[1] = 0;
			}
			//
			processor->mainWindow->repaint();
			updateValuesFromProcessor();
		}

        //[/UserButtonCode_textButton_HorizontalPos]
    }
    else if (buttonThatWasClicked == textButton_VerticalPos.get())
    {
        //[UserButtonCode_textButton_VerticalPos] -- add your button handler code here..

		String defaultValue = String(processor->selectedObject->namePosition[1]);
		if (processor->selectedObject->namePosition[1] == -1) defaultValue = "Center";
		String theValue;
		AskValue("Vertical Position in Pixels", "(use Center for auto center)", defaultValue, "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			if (theValue.compareIgnoreCase("center") == 0)
			{
				processor->selectedObject->namePosition[0] = -1;
				processor->selectedObject->namePosition[1] = -1;
			}
			else
			{
				processor->selectedObject->namePosition[1] = theValue.getIntValue();
				if (processor->selectedObject->namePosition[0] == -1) processor->selectedObject->namePosition[0] = 0;
			}
			//
			processor->mainWindow->repaint();
			updateValuesFromProcessor();
		}

        //[/UserButtonCode_textButton_VerticalPos]
    }
    else if (buttonThatWasClicked == textButton_FontSize.get())
    {
        //[UserButtonCode_textButton_FontSize] -- add your button handler code here..

		String theValue;
		AskValue("Font Heigth", "", String(processor->selectedObject->fontSize, 2), "", "Ok", "Cancel", theValue);
		if (theValue.isNotEmpty())
		{
			processor->selectedObject->fontSize = theValue.getFloatValue();
			textButton_FontSize->setButtonText(String(processor->selectedObject->fontSize, 2));
			processor->mainWindow->repaint();
		}

        //[/UserButtonCode_textButton_FontSize]
    }
    else if (buttonThatWasClicked == toggleButton_ShowName.get())
    {
        //[UserButtonCode_toggleButton_ShowName] -- add your button handler code here..

		processor->selectedObject->showName = toggleButton_ShowName->getToggleState();
		processor->mainWindow->repaint();

        //[/UserButtonCode_toggleButton_ShowName]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ImageOptions::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]

	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;

    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox_Screen.get())
    {
        //[UserComboBoxCode_comboBox_Screen] -- add your combo box handling code here..

		processor->selectedObject->screen = comboBox_Screen->getSelectedId() - 1;
		((EditCompo*)processor->mainWindow->getContentComponent())->updateObjects();
		processor->mainWindow->repaint();

        //[/UserComboBoxCode_comboBox_Screen]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...


void ImageOptionsWindow::closeButtonPressed()
{
	static WusikPr44AudioProcessor* _processor = (WusikPr44AudioProcessor*)processor;
	//
	setVisible(false);
	_processor->selectedObject = nullptr;
	if (tooltipWindow->isVisible()) tooltipWindow->closeButtonPressed();
	_processor->imageWindow->setVisible(false);
}

void ImageOptions::textEditorTextChanged(TextEditor& txtEditor)
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	processor->selectedObject->multiLine = textEditor_Multi->getText();
	processor->mainWindow->repaint();
}

void ImageOptions::updateValuesFromProcessor()
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (processor->selectedObject != nullptr)
	{
		textButton_BackColour->setColour(TextButton::buttonColourId, processor->selectedObject->backgroundColour);
		comboBox_Screen->setSelectedItemIndex(processor->selectedObject->screen);
		toggleButton_ImageStretch->setToggleState(processor->selectedObject->imageStretch, NotificationType::dontSendNotification);
		if (processor->selectedObject->backgroundTransparency == 0.0f) textButton_ImageAlpha->setButtonText("Off"); else textButton_ImageAlpha->setButtonText(String(processor->selectedObject->backgroundTransparency, 2));
		textButton_RoundSquare->setButtonText(String(processor->selectedObject->roundCorners, 2));
		toggleButton_ImageCut->setToggleState(processor->selectedObject->cutImageUsingBackground, NotificationType::dontSendNotification);
		textButton_FontColour->setColour(TextButton::buttonColourId, processor->selectedObject->fontColour);
		textButton_FontSize->setButtonText(String(processor->selectedObject->fontSize, 2));
		toggleButton_ShowName->setToggleState(processor->selectedObject->showName, NotificationType::dontSendNotification);
		textEditor_Multi->setText(processor->selectedObject->multiLine, false);
		//
		if (processor->selectedObject->imagesFilename[WPR44Object::kImage_Background].isEmpty()) textButton_Image->setButtonText("Image"); else textButton_Image->setButtonText("(*)Image");
		if (processor->selectedObject->name.isEmpty()) textButton_Name->setButtonText("(empty)"); else textButton_Name->setButtonText(processor->selectedObject->name);
		//
		if (processor->selectedObject->namePosition[0] == -1) textButton_HorizontalPos->setButtonText("Center"); else textButton_HorizontalPos->setButtonText(String(processor->selectedObject->namePosition[0]));
		if (processor->selectedObject->namePosition[1] == -1) textButton_VerticalPos->setButtonText("Center"); else textButton_VerticalPos->setButtonText(String(processor->selectedObject->namePosition[1]));
		//
		textButton_ImageScale->setButtonText(String(processor->selectedObject->imageScale, 2));
		toggleButton_ImageToBack->setToggleState(processor->selectedObject->toBack, NotificationType::dontSendNotification);
		//
		repaint();
	}
}

bool ImageOptionsWindow::keyPressed(const KeyPress &key)
{
	if (key.getKeyCode() == KeyPress::F4Key && key.getModifiers().isAltDown())
	{
		((WusikPr44AudioProcessor*)processor)->imageWindow->closeButtonPressed();
		if (tooltipWindow->isVisible()) tooltipWindow->closeButtonPressed();
		return true;
	}
	else if (((WusikPr44AudioProcessor*)processor)->keyPressHandle(key)) return true;
	//
	return false;
}


void ImageOptions::changeListenerCallback(ChangeBroadcaster* source)
{
	static WusikPr44AudioProcessor* processor = (WusikPr44AudioProcessor*)parent;
	//
	if (auto* cs = dynamic_cast<ColourSelector*> (source))
	{
		if (edColour != nullptr)
		{
			*edColour = cs->getCurrentColour();
			processor->mainWindow->repaint();
			edButton->setColour(TextButton::buttonColourId, *edColour);
			repaint();
		}
	}
}

void ImageOptionsWindow::timerCallback()
{
	static WusikPr44AudioProcessor* _processor = (WusikPr44AudioProcessor*)processor;
	//
	stopTimer();
	//
	bool foundOneOver = false;
	if (tooltipWindow == nullptr) tooltipWindow = new WToolTipWindow(_processor, this, false);
	//
	Component* const* childrensData;
	int arraySize = 0;
	//
	childrensData = options->getChildren().getRawDataPointer();
	arraySize = options->getChildren().size();
	//
	for (int index = 0; index < arraySize; index++)
	{
		if (childrensData[index]->isMouseOver())
		{
			//WMessageBox("Is Mouse Over!", childrensData[index]->getName());
			//
			foundOneOver = true;
			//
			if (tooltipWindow->componentOver == childrensData[index])
			{
				if ((Time::getApproximateMillisecondCounter() - tooltipWindow->componentOverTime) > 1000)
				{
					String toolTip = _processor->getToolTipFor(*childrensData[index]);
					if (toolTip.isNotEmpty())
					{
						tooltipWindow->textEditor->setText(toolTip, false);
						tooltipWindow->setVisible(true);
						tooltipWindow->repaint();
					}
				}
			}
			else
			{
				tooltipWindow->setVisible(false);
				tooltipWindow->componentOver = childrensData[index];
				tooltipWindow->componentOverTime = Time::getApproximateMillisecondCounter();
			}
			//
			break;
		}
	}
	//
	if (!foundOneOver)
	{
		tooltipWindow->componentOver = nullptr;
		tooltipWindow->setVisible(false);
	}
	//
	startTimer(100);
}

ImageOptionsWindow::ImageOptionsWindow(void* _processor) : processor(_processor), DocumentWindow("Object Options", Colours::darkslategrey, DocumentWindow::closeButton)
{
	setUsingNativeTitleBar(true);
	//
	setBounds(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getWidth() - 380,
		(Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) + 40,
		332, (Desktop::getInstance().getDisplays().getMainDisplay().totalArea.getHeight() / 2) - 80);
	//
	Viewport* viewPort = new Viewport("Options");
	viewPort->setBounds(0, 0, getWidth(), getHeight());
	viewPort->setScrollBarsShown(true, false);
	options = new ImageOptions;
	options->parent = processor;
	options->updateValuesFromProcessor();
	viewPort->setViewedComponent(options, true);
	setContentOwned(viewPort, false);
	//
	tooltipWindow = new WToolTipWindow(processor, this, false);
	//
	setVisible(true);
	setAlwaysOnTop(true);
	startTimer(100);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ImageOptions" componentName=""
                 parentClasses="public Component, public ChangeListener, TextEditor::Listener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="360"
                 initialHeight="1024">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="24 8 272 56" fill="solid: 3000001c" hasStroke="0"/>
    <RECT pos="19 331 309 253" fill="solid: 2a11126f" hasStroke="0"/>
    <RECT pos="25 656 278 8" fill="solid: ff11126f" hasStroke="0"/>
  </BACKGROUND>
  <LABEL name="new label" id="e7f02b1a8c98769d" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="27 121 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Back Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="7c47ebb2dddbb2d4" memberName="textButton_BackColour"
              virtualName="" explicitFocusOrder="0" pos="134 122 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="8217d615b5215d2b" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="38 598 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Screen" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="505de9703595e854" memberName="objectType"
         virtualName="" explicitFocusOrder="0" pos="16 78 288 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Type: Image/Label" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="1" italic="0" justification="36"
         typefaceStyle="Bold"/>
  <TEXTBUTTON name="button Back Colour" id="600b32191c9cdb9f" memberName="textButton_Image"
              virtualName="" explicitFocusOrder="0" pos="134 163 72 24" tooltip="Background Image (can be transparent)"
              bgColOff="ff001da8" buttonText="Image" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="button Border Colour" id="c90921e9976578e3" memberName="textButton_Duplicate"
              virtualName="" explicitFocusOrder="0" pos="63 24 88 24" bgColOff="ff001da8"
              buttonText="Duplicate" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Border Colour" id="bf4fc7211130fa4" memberName="textButton_Delete"
              virtualName="" explicitFocusOrder="0" pos="176 24 88 24" bgColOff="ff001da8"
              buttonText="Delete" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="c3cba96534f107c7" memberName="comboBox_Screen"
            virtualName="" explicitFocusOrder="0" pos="145 598 90 28" tooltip="Which screen this object should show on"
            editable="0" layout="33" items="A&#10;B&#10;C&#10;D" textWhenNonSelected=""
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="9c5d69e7f53cd37c" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="27 163 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Image" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Back Colour" id="ce293861d75d497a" memberName="textButton_ImageScale"
              virtualName="" explicitFocusOrder="0" pos="134 204 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="d85b9fc523346f2f" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="27 204 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Scale" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TOGGLEBUTTON name="Internal Clock" id="2acb8ef5b183ed05" memberName="toggleButton_ImageStretch"
                virtualName="" explicitFocusOrder="0" pos="221 164 81 24" buttonText="Stretch"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Internal Clock" id="a520775541a4cadb" memberName="toggleButton_ImageToBack"
                virtualName="" explicitFocusOrder="0" pos="221 197 81 24" tooltip="Keep image in the most background position, relative to the other objects (but still on top of the main background)."
                buttonText="To Back" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TEXTBUTTON name="button Back Colour" id="daa505427685a403" memberName="textButton_Shadow"
              virtualName="" explicitFocusOrder="0" pos="224 122 64 24" bgColOff="ff001da8"
              buttonText="Shadow" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="8e61c9a175745604" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="27 282 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Round/Square" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="6244c1509b2e63d7" memberName="textButton_RoundSquare"
              virtualName="" explicitFocusOrder="0" pos="134 284 72 24" tooltip="0.0 is square and 1.0 is complete round corners."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="33517a34a1c3a9e" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="27 242 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Transparency" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="9a7e6b456c1a5353" memberName="textButton_ImageAlpha"
              virtualName="" explicitFocusOrder="0" pos="134 244 72 24" tooltip="0.0 is square and 1.0 is complete round corners."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TOGGLEBUTTON name="new toggle button" id="80f944eea26078ce" memberName="toggleButton_ImageCut"
                virtualName="" explicitFocusOrder="0" pos="221 230 72 24" tooltip="Cut the image according to the background rectangle."
                buttonText="Cut" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TEXTBUTTON name="Name" id="353a336e476e6b" memberName="textButton_Name"
              virtualName="" explicitFocusOrder="0" pos="35 371 272 32" bgColOff="ff0e2781"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="2737572746ba2135" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="38 547 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Font Size" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fdfb5910eec3f6cc" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="38 505 93 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Font Colour" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Font Colour" id="b1e0c26c645f5e99" memberName="textButton_FontColour"
              virtualName="" explicitFocusOrder="0" pos="145 506 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="6513102db0e70d89" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="38 423 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Position&#10;Horizontal" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="3f244b5549098510" memberName="textButton_HorizontalPos"
              virtualName="" explicitFocusOrder="0" pos="145 423 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="78474f6603bdf315" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="38 462 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Vertical" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="button Border Colour" id="edb138f6131500ed" memberName="textButton_VerticalPos"
              virtualName="" explicitFocusOrder="0" pos="145 464 72 24" bgColOff="ff001da8"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="button Border Colour" id="724a3cd288ca46fc" memberName="textButton_FontSize"
              virtualName="" explicitFocusOrder="0" pos="145 547 72 24" tooltip="0.0 is square and 1.0 is complete round corners."
              bgColOff="ff001da8" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="9f5e140e0abd4bbd" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="132 342 82 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Label Text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15.0"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="db713733f64bd797" memberName="toggleButton_ShowName"
                virtualName="" explicitFocusOrder="0" pos="235 416 72 24" tooltip="Show the button name"
                buttonText="Show" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="0"/>
  <TEXTEDITOR name="new text editor" id="6d4fed4af1ca3796" memberName="textEditor_Multi"
              virtualName="" explicitFocusOrder="0" pos="16 715 300 293" bkgcol="ff15232a"
              caretcol="ffffb2b2" initialText="Disabled" multiline="1" retKeyStartsLine="1"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <LABEL name="new label" id="f003de4f17b67e2b" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="128 677 101 25" edTextCol="ff000000"
         edBkgCol="0" labelText="Multi Line Text" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

