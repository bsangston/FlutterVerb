/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
FlutterVerbAudioProcessorEditor::FlutterVerbAudioProcessorEditor (FlutterVerbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p),

    mixSlider("mix"),
    predelaySlider("predelay"),
    decaySlider("decay"),
    highcutSlider("high cut"),
    densitySlider("density"),
    diffusionSlider("diffusion"),
    modRateSlider("mod rate"),
    modDepthSlider("mod depth"),

    mixLabel("Mix","Mix"),
    predelayLabel("Predelay","Predelay"),
    decayLabel("Decay","Decay"),
    highcutLabel("High Cut","High Cut"),
    densityLabel("Density","Density"),
    diffusionLabel("Diffusion","Diffusion"),
    modRateLabel("Mod Rate","Mod Rate"),
    modDepthLabel("Mod Depth","Mod Depth"),

    title("Title", "FlutterVerb")

{
   
    addAndMakeVisible (mixSlider);
    mixSlider.setTooltip (TRANS("Controls the percetange of wet and dry mix"));
    mixSlider.setRange (0, 100, 0.1);
    mixSlider.setSliderStyle (Slider::LinearVertical);
    mixSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    mixSlider.addListener (this);
    
    addAndMakeVisible (predelaySlider);
    predelaySlider.setTooltip (TRANS("Controls the amount of delay before the reverb"));
    predelaySlider.setRange (0, 500, 0.1);
    predelaySlider.setSliderStyle (Slider::LinearVertical);
    predelaySlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    predelaySlider.addListener (this);
    
    addAndMakeVisible (decaySlider);
    decaySlider.setTooltip (TRANS("Controls the decay time of the reverb (in sec)"));
    decaySlider.setRange (0.1, 100, 0.1);
    decaySlider.setSliderStyle (Slider::LinearVertical);
    decaySlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    decaySlider.addListener (this);
    
    addAndMakeVisible (highcutSlider);
    highcutSlider.setTooltip (TRANS("Controls the cutoff frequency of a lowpass filter processing the reverb output"));
    highcutSlider.setRange (100, 20000, 0.1);
    highcutSlider.setSliderStyle (Slider::LinearVertical);
    highcutSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    highcutSlider.addListener (this);
    
    addAndMakeVisible (densitySlider);
    densitySlider.setTooltip (TRANS("Controls the echo density"));
    densitySlider.setRange (0, 100, 0.1);
    densitySlider.setSliderStyle (Slider::LinearVertical);
    densitySlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    densitySlider.addListener (this);
    
    addAndMakeVisible (diffusionSlider);
    diffusionSlider.setTooltip (TRANS("Controls the amount of diffusion"));
    diffusionSlider.setRange (0, 100, 0.1);
    diffusionSlider.setSliderStyle (Slider::LinearVertical);
    diffusionSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    diffusionSlider.addListener (this);
    
    addAndMakeVisible (modRateSlider);
    modRateSlider.setTooltip (TRANS("Controls the rate of the late reverb modulation"));
    modRateSlider.setRange (0.05, 5, 0.01);
    modRateSlider.setSliderStyle (Slider::LinearVertical);
    modRateSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modRateSlider.addListener (this);
    
    addAndMakeVisible (modDepthSlider);
    modDepthSlider.setTooltip (TRANS("Controls the depth of the late reverb modulation"));
    modDepthSlider.setRange (0, 1, 0.1);
    modDepthSlider.setSliderStyle (Slider::LinearVertical);
    modDepthSlider.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modDepthSlider.addListener (this);
    
    addAndMakeVisible (mixLabel);
    mixLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    mixLabel.setJustificationType (Justification::centred);
    mixLabel.setEditable (false, false, false);
    mixLabel.setColour (TextEditor::textColourId, Colours::black);
    mixLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (predelayLabel);
    predelayLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    predelayLabel.setJustificationType (Justification::centred);
    predelayLabel.setEditable (false, false, false);
    predelayLabel.setColour (TextEditor::textColourId, Colours::black);
    predelayLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (decayLabel);
    decayLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    decayLabel.setJustificationType (Justification::centred);
    decayLabel.setEditable (false, false, false);
    decayLabel.setColour (TextEditor::textColourId, Colours::black);
    decayLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (highcutLabel);
    highcutLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    highcutLabel.setJustificationType (Justification::centred);
    highcutLabel.setEditable (false, false, false);
    highcutLabel.setColour (TextEditor::textColourId, Colours::black);
    highcutLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (densityLabel);
    densityLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    densityLabel.setJustificationType (Justification::centred);
    densityLabel.setEditable (false, false, false);
    densityLabel.setColour (TextEditor::textColourId, Colours::black);
    densityLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (diffusionLabel);
    diffusionLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    diffusionLabel.setJustificationType (Justification::centred);
    diffusionLabel.setEditable (false, false, false);
    diffusionLabel.setColour (TextEditor::textColourId, Colours::black);
    diffusionLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (modRateLabel);
    modRateLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    modRateLabel.setJustificationType (Justification::centred);
    modRateLabel.setEditable (false, false, false);
    modRateLabel.setColour (TextEditor::textColourId, Colours::black);
    modRateLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (modDepthLabel);
    modDepthLabel.setFont (Font ("Avenir", 15.00f, Font::plain).withTypefaceStyle ("Regular"));
    modDepthLabel.setJustificationType (Justification::centred);
    modDepthLabel.setEditable (false, false, false);
    modDepthLabel.setColour (TextEditor::textColourId, Colours::black);
    modDepthLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    addAndMakeVisible (title);
    title.setFont (Font ("Avenir", 29.70f, Font::bold));
    title.setJustificationType (Justification::centred);
    title.setEditable (false, false, false);
    title.setColour (TextEditor::textColourId, Colours::black);
    modDepthLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    setSize (855, 400);

    //Start timer
    startTimer(50); //timerCallback() called every 50msec
}

FlutterVerbAudioProcessorEditor::~FlutterVerbAudioProcessorEditor()
{

}

//==============================================================================
void FlutterVerbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.setColour (Colour (0xff0b0b0d));
//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.fillAll (Colour (0xff0b0b0d));
    g.setFont (15.0f);
}

void FlutterVerbAudioProcessorEditor::resized()
{
    //Set position and size of the slider objects
    mixSlider.setBounds (24, 88, 80, 288);
    predelaySlider.setBounds (128, 88, 80, 288);
    decaySlider.setBounds (232, 88, 80, 288);
    highcutSlider.setBounds (336, 88, 80, 288);
    densitySlider.setBounds (440, 88, 80, 288);
    diffusionSlider.setBounds (544, 88, 80, 288);
    modRateSlider.setBounds (648, 88, 80, 288);
    modDepthSlider.setBounds (752, 88, 80, 288);
    mixLabel.setBounds (35, 56, 56, 24);
    predelayLabel.setBounds (118, 56, 102, 24);
    decayLabel.setBounds (220, 56, 102, 24);
    highcutLabel.setBounds (325, 56, 102, 24);
    densityLabel.setBounds (430, 56, 102, 24);
    diffusionLabel.setBounds (534, 56, 102, 24);
    modRateLabel.setBounds (638, 56, 102, 24);
    modDepthLabel.setBounds (742, 56, 102, 24);
    title.setBounds (320, 16, 224, 24);
}


// Implement the listener callback function
// This is the Slider::Listener callback, when the user drags a slider.
void FlutterVerbAudioProcessorEditor::sliderValueChanged (Slider* slider)
{
    float vstVal;
    
    // It's vital to use setParameterNotifyingHost to change any parameters that are automatable
    // by the host, rather than just modifying them directly, otherwise the host won't know
    // that they've changed.
    // first set the usrParam from the slider, and get the vst normalized version of the uParam:
    
    if (slider == &mixSlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::mixParam].setWithUparam(mixSlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::mixParam, vstVal);
        
    }
    
    else if (slider == &predelaySlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::predelayParam].setWithUparam(predelaySlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::predelayParam, vstVal);
        
    }
    
    else if (slider == &decaySlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::decayParam].setWithUparam(decaySlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::decayParam, vstVal);
        
    }
    
    else if (slider == &highcutSlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::highcutParam].setWithUparam(highcutSlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::highcutParam, vstVal);
        
    }
    
    else if (slider == &densitySlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::densityParam].setWithUparam(densitySlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::densityParam, vstVal);
    }
    
    else if (slider == &diffusionSlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::diffusionParam].setWithUparam(diffusionSlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::diffusionParam, vstVal);
    }
    
    else if (slider == &modRateSlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::modRateParam].setWithUparam(modRateSlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::modRateParam, vstVal);
    }
    
    else if (slider == &modDepthSlider)
    {
        vstVal = getProcessor().usrParams[FlutterVerbAudioProcessor::modDepthParam].setWithUparam(modDepthSlider.getValue());
        getProcessor().setParameterNotifyingHost (FlutterVerbAudioProcessor::modDepthParam, vstVal);
    }
    
}



// Set the timer callback to update the UI
// This timer periodically checks whether any of the filter's parameters have changed...
void FlutterVerbAudioProcessorEditor::timerCallback()
{
    // get a pointer to our Processor object
    FlutterVerbAudioProcessor& ourProcessor = getProcessor();
    
    // these get will update the sliders in the UI
    mixSlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::mixParam].getUparamVal(), dontSendNotification);
    predelaySlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::predelayParam].getUparamVal(), dontSendNotification);
    decaySlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::decayParam].getUparamVal(), dontSendNotification);
    highcutSlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::highcutParam].getUparamVal(), dontSendNotification);
    densitySlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::densityParam].getUparamVal(), dontSendNotification);
    diffusionSlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::diffusionParam].getUparamVal(), dontSendNotification);
    modRateSlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::modRateParam].getUparamVal(), dontSendNotification);
    modDepthSlider.setValue(ourProcessor.usrParams[FlutterVerbAudioProcessor::modDepthParam].getUparamVal(), dontSendNotification);
    
    
}
