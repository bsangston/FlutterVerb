/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.0.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUIComponents.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUIComponents::GUIComponents ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (mixSlider = new Slider ("Mix"));
    mixSlider->setTooltip (TRANS("Controls the percetange of wet and dry mix"));
    mixSlider->setRange (0, 100, 0.1);
    mixSlider->setSliderStyle (Slider::LinearVertical);
    mixSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    mixSlider->addListener (this);

    addAndMakeVisible (predelaySlider = new Slider ("Predelay"));
    predelaySlider->setTooltip (TRANS("Controls the amount of delay before the reverb"));
    predelaySlider->setRange (0, 500, 0.1);
    predelaySlider->setSliderStyle (Slider::LinearVertical);
    predelaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    predelaySlider->addListener (this);

    addAndMakeVisible (decaySlider = new Slider ("Decay"));
    decaySlider->setTooltip (TRANS("Controls the decay time of the reverb (in sec)"));
    decaySlider->setRange (0.1, 100, 0.1);
    decaySlider->setSliderStyle (Slider::LinearVertical);
    decaySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider->addListener (this);

    addAndMakeVisible (highcutSlider = new Slider ("High Cut"));
    highcutSlider->setTooltip (TRANS("Controls the cutoff frequency of a lowpass filter processing the reverb output"));
    highcutSlider->setRange (100, 20000, 1);
    highcutSlider->setSliderStyle (Slider::LinearVertical);
    highcutSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    highcutSlider->addListener (this);

    addAndMakeVisible (densitySlider = new Slider ("Density"));
    densitySlider->setTooltip (TRANS("Controls the echo density"));
    densitySlider->setRange (0, 100, 0.1);
    densitySlider->setSliderStyle (Slider::LinearVertical);
    densitySlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    densitySlider->addListener (this);

    addAndMakeVisible (diffusionSlider = new Slider ("Diffusion"));
    diffusionSlider->setTooltip (TRANS("Controls the amount of diffusion"));
    diffusionSlider->setRange (0, 100, 0.1);
    diffusionSlider->setSliderStyle (Slider::LinearVertical);
    diffusionSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    diffusionSlider->addListener (this);

    addAndMakeVisible (modRateSlider = new Slider ("Mod Rate"));
    modRateSlider->setTooltip (TRANS("Controls the rate of the late reverb modulation"));
    modRateSlider->setRange (0.05, 5, 0.01);
    modRateSlider->setSliderStyle (Slider::LinearVertical);
    modRateSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modRateSlider->addListener (this);

    addAndMakeVisible (modDepthSlider = new Slider ("Mod Depth"));
    modDepthSlider->setTooltip (TRANS("Controls the depth of the late reverb modulation"));
    modDepthSlider->setRange (0, 1, 0.1);
    modDepthSlider->setSliderStyle (Slider::LinearVertical);
    modDepthSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modDepthSlider->addListener (this);

    addAndMakeVisible (mixLabel = new Label ("Mix",
                                             TRANS("Mix")));
    mixLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    mixLabel->setJustificationType (Justification::centred);
    mixLabel->setEditable (false, false, false);
    mixLabel->setColour (TextEditor::textColourId, Colours::black);
    mixLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (predelayLabel = new Label ("Predelay",
                                                  TRANS("Predelay")));
    predelayLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    predelayLabel->setJustificationType (Justification::centred);
    predelayLabel->setEditable (false, false, false);
    predelayLabel->setColour (TextEditor::textColourId, Colours::black);
    predelayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (decayLabel = new Label ("Decay",
                                               TRANS("Decay")));
    decayLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    decayLabel->setJustificationType (Justification::centred);
    decayLabel->setEditable (false, false, false);
    decayLabel->setColour (TextEditor::textColourId, Colours::black);
    decayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (highcutLabel = new Label ("HighCut",
                                                 TRANS("High Cut")));
    highcutLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    highcutLabel->setJustificationType (Justification::centred);
    highcutLabel->setEditable (false, false, false);
    highcutLabel->setColour (TextEditor::textColourId, Colours::black);
    highcutLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (densityLabel = new Label ("Density",
                                                 TRANS("Density")));
    densityLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    densityLabel->setJustificationType (Justification::centred);
    densityLabel->setEditable (false, false, false);
    densityLabel->setColour (TextEditor::textColourId, Colours::black);
    densityLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (diffusionLabel = new Label ("Diffusion",
                                                   TRANS("Diffusion")));
    diffusionLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    diffusionLabel->setJustificationType (Justification::centred);
    diffusionLabel->setEditable (false, false, false);
    diffusionLabel->setColour (TextEditor::textColourId, Colours::black);
    diffusionLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modRateLabel = new Label ("ModRate",
                                                 TRANS("Mod Rate")));
    modRateLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    modRateLabel->setJustificationType (Justification::centred);
    modRateLabel->setEditable (false, false, false);
    modRateLabel->setColour (TextEditor::textColourId, Colours::black);
    modRateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepthLabel = new Label ("ModDepth",
                                                  TRANS("Mod Depth")));
    modDepthLabel->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    modDepthLabel->setJustificationType (Justification::centred);
    modDepthLabel->setEditable (false, false, false);
    modDepthLabel->setColour (TextEditor::textColourId, Colours::black);
    modDepthLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (title = new Label ("title",
                                          TRANS("FlutterVerb")));
    title->setFont (Font ("Avenir", 29.70f, Font::bold));
    title->setJustificationType (Justification::centred);
    title->setEditable (false, false, false);
    title->setColour (TextEditor::textColourId, Colours::black);
    title->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (855, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GUIComponents::~GUIComponents()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mixSlider = nullptr;
    predelaySlider = nullptr;
    decaySlider = nullptr;
    highcutSlider = nullptr;
    densitySlider = nullptr;
    diffusionSlider = nullptr;
    modRateSlider = nullptr;
    modDepthSlider = nullptr;
    mixLabel = nullptr;
    predelayLabel = nullptr;
    decayLabel = nullptr;
    highcutLabel = nullptr;
    densityLabel = nullptr;
    diffusionLabel = nullptr;
    modRateLabel = nullptr;
    modDepthLabel = nullptr;
    title = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUIComponents::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff0b0b0d));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUIComponents::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mixSlider->setBounds (24, 88, 80, 288);
    predelaySlider->setBounds (128, 88, 80, 288);
    decaySlider->setBounds (232, 88, 80, 288);
    highcutSlider->setBounds (336, 88, 80, 288);
    densitySlider->setBounds (440, 88, 80, 288);
    diffusionSlider->setBounds (544, 88, 80, 288);
    modRateSlider->setBounds (648, 88, 80, 288);
    modDepthSlider->setBounds (752, 88, 80, 288);
    mixLabel->setBounds (35, 56, 56, 24);
    predelayLabel->setBounds (118, 56, 102, 24);
    decayLabel->setBounds (220, 56, 102, 24);
    highcutLabel->setBounds (325, 56, 102, 24);
    densityLabel->setBounds (430, 56, 102, 24);
    diffusionLabel->setBounds (534, 56, 102, 24);
    modRateLabel->setBounds (638, 56, 102, 24);
    modDepthLabel->setBounds (742, 56, 102, 24);
    title->setBounds (320, 16, 224, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUIComponents::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == mixSlider)
    {
        //[UserSliderCode_mixSlider] -- add your slider handling code here..
        //[/UserSliderCode_mixSlider]
    }
    else if (sliderThatWasMoved == predelaySlider)
    {
        //[UserSliderCode_predelaySlider] -- add your slider handling code here..
        //[/UserSliderCode_predelaySlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == highcutSlider)
    {
        //[UserSliderCode_highcutSlider] -- add your slider handling code here..
        //[/UserSliderCode_highcutSlider]
    }
    else if (sliderThatWasMoved == densitySlider)
    {
        //[UserSliderCode_densitySlider] -- add your slider handling code here..
        //[/UserSliderCode_densitySlider]
    }
    else if (sliderThatWasMoved == diffusionSlider)
    {
        //[UserSliderCode_diffusionSlider] -- add your slider handling code here..
        //[/UserSliderCode_diffusionSlider]
    }
    else if (sliderThatWasMoved == modRateSlider)
    {
        //[UserSliderCode_modRateSlider] -- add your slider handling code here..
        //[/UserSliderCode_modRateSlider]
    }
    else if (sliderThatWasMoved == modDepthSlider)
    {
        //[UserSliderCode_modDepthSlider] -- add your slider handling code here..
        //[/UserSliderCode_modDepthSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUIComponents" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="855" initialHeight="400">
  <BACKGROUND backgroundColour="ff0b0b0d"/>
  <SLIDER name="Mix" id="54a342b3cb88deef" memberName="mixSlider" virtualName=""
          explicitFocusOrder="0" pos="24 88 80 288" tooltip="Controls the percetange of wet and dry mix"
          min="0" max="100" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Predelay" id="7e74169b8b6d942d" memberName="predelaySlider"
          virtualName="" explicitFocusOrder="0" pos="128 88 80 288" tooltip="Controls the amount of delay before the reverb"
          min="0" max="500" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Decay" id="47fdf5d47e8493d3" memberName="decaySlider" virtualName=""
          explicitFocusOrder="0" pos="232 88 80 288" tooltip="Controls the decay time of the reverb (in sec)"
          min="0.10000000000000000555" max="100" int="0.10000000000000000555"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="High Cut" id="3a3958c3158b09b1" memberName="highcutSlider"
          virtualName="" explicitFocusOrder="0" pos="336 88 80 288" tooltip="Controls the cutoff frequency of a lowpass filter processing the reverb output"
          min="100" max="20000" int="1" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Density" id="b6e825285ea00423" memberName="densitySlider"
          virtualName="" explicitFocusOrder="0" pos="440 88 80 288" tooltip="Controls the echo density"
          min="0" max="100" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Diffusion" id="30476bf6dc0934fe" memberName="diffusionSlider"
          virtualName="" explicitFocusOrder="0" pos="544 88 80 288" tooltip="Controls the amount of diffusion"
          min="0" max="100" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Mod Rate" id="2b42f37382ad8e05" memberName="modRateSlider"
          virtualName="" explicitFocusOrder="0" pos="648 88 80 288" tooltip="Controls the rate of the late reverb modulation"
          min="0.050000000000000002776" max="5" int="0.010000000000000000208"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Mod Depth" id="24c8e1a408fb23c" memberName="modDepthSlider"
          virtualName="" explicitFocusOrder="0" pos="752 88 80 288" tooltip="Controls the depth of the late reverb modulation"
          min="0" max="1" int="0.10000000000000000555" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <LABEL name="Mix" id="4d4c133601671458" memberName="mixLabel" virtualName=""
         explicitFocusOrder="0" pos="35 56 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="Predelay" id="5a0ee36fc9a56774" memberName="predelayLabel"
         virtualName="" explicitFocusOrder="0" pos="118 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Predelay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="Decay" id="469452b6476668c4" memberName="decayLabel" virtualName=""
         explicitFocusOrder="0" pos="220 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="HighCut" id="2858629b3880b835" memberName="highcutLabel"
         virtualName="" explicitFocusOrder="0" pos="325 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="High Cut" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="Density" id="91a5a731c4d063f9" memberName="densityLabel"
         virtualName="" explicitFocusOrder="0" pos="430 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Density" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="Diffusion" id="a8a8c24f1568174" memberName="diffusionLabel"
         virtualName="" explicitFocusOrder="0" pos="534 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Diffusion" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="ModRate" id="e277c52c1e5fbb2b" memberName="modRateLabel"
         virtualName="" explicitFocusOrder="0" pos="638 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="ModDepth" id="6a28b99f049116ce" memberName="modDepthLabel"
         virtualName="" explicitFocusOrder="0" pos="742 56 102 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="title" id="e6185ab1d35ec305" memberName="title" virtualName=""
         explicitFocusOrder="0" pos="320 16 224 24" edTextCol="ff000000"
         edBkgCol="0" labelText="FlutterVerb" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Avenir"
         fontsize="29.699999999999999289" kerning="0" bold="1" italic="0"
         justification="36" typefaceStyle="Bold"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
