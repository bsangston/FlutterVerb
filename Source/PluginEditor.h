/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class FlutterVerbAudioProcessorEditor  : public AudioProcessorEditor,
                                         public SliderListener, //Inherits sliderlistener
                                         public Timer //Inherits timer
{
public:
    FlutterVerbAudioProcessorEditor (FlutterVerbAudioProcessor&);
    ~FlutterVerbAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider*) override;
    void timerCallback() override;
    
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FlutterVerbAudioProcessor& processor;
    
    Slider mixSlider;
    Slider predelaySlider;
    Slider decaySlider;
    Slider highcutSlider;
    Slider densitySlider;
    Slider diffusionSlider;
    Slider modRateSlider;
    Slider modDepthSlider;
    
    Label mixLabel;
    Label predelayLabel;
    Label decayLabel;
    Label highcutLabel;
    Label densityLabel;
    Label diffusionLabel;
    Label modRateLabel;
    Label modDepthLabel;
    
    Label title;

    
    FlutterVerbAudioProcessor& getProcessor() const {
        return static_cast<FlutterVerbAudioProcessor&> (processor);
    }
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlutterVerbAudioProcessorEditor)
};
