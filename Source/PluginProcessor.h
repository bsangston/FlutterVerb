/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "UParam.h"
#include "BiQuad.h"
#include "PoleZero.h"
#include "DelayA.h"
#include "Mu45FilterCalc.h"


//==============================================================================
/**
*/
class FlutterVerbAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    FlutterVerbAudioProcessor();
    ~FlutterVerbAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;
    
    int getNumParameters() override;
    float getParameter(int index) override;
    void setParameter(int index, float newValue) override;
    float getParameterDefaultValue(int index) override;
    
    const String getParameterName(int index) override;
    
    const String getParameterText(int index) override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    //Enumerated type to store user parameters
    enum Parameters {
        mixParam = 0,
        predelayParam,
        decayParam,
        highcutParam,
        densityParam,
        diffusionParam,
        modRateParam,
        modDepthParam,
        totalNumParams
    };
    
    //User parameter values
    float uParamMix;
    float uParamPredelay;
    float uParamDecay;
    float uParamHighCut;
    float uParamDensity;
    float uParamDiffusion;
    float uParamModRate;
    float uParamModDepth;

    UParam getUserParams();
    UParam usrParams[totalNumParams];
    
    

private:
    //==============================================================================
    
    //Default values for all user parameters
    const float defaultMix = 100;
    const float defaultPredelay = 0;
    const float defaultDecay = 3;
    const float defaultHighCut = 8000;
    const float defaultDensity = 75;
    const float defaultDiffusion = 50;
    const float defaultModRate = 0;
    const float defaultModDepth = 0.5;
    
    //Parameter Names
    const String mixName = "Mix";
    const String predelayName = "Predelay";
    const String decayName = "Decay";
    const String highcutName = "High Cut";
    const String densityName = "Density";
    const String diffusionName = "Diffusion";
    const String modRateName = "Mod Rate";
    const String modDepthName = "Mod Depth";
    
    
    //Algorithm params
    float fs;
    float dryGain, wetGain;
    std::vector<float> fbGains;
    float predelay;
    float highcut;
    float density, diffusion;
    float modRate, modDepth;
    
    stk::BiQuad lowpassL, lowpassR;
    stk::DelayA allpass1L, allpass1R;
    stk::DelayA allpass2L, allpass2R;
    stk::DelayA allpass3L, allpass3R;
    stk::DelayA fbcf1L, fbcf1R;
    stk::DelayA fbcf2L, fbcf2R;
    stk::DelayA fbcf3L, fbcf3R;
    stk::DelayA fbcf4L, fbcf4R;
    
    std::vector<stk::BiQuad> lowpass;
    std::vector<stk::PoleZero> allpass1, allpass2, allpass3;
    std::vector<std::vector<stk::PoleZero>> allpassFilterBank;
    
    std::vector<stk::DelayA> delay1, delay2, delay3, fbcf1, fbcf2, fbcf3, fbcf4;
    std::vector<std::vector<stk::DelayA>> delayNetwork;
    
    //Max/min values
    float maxPredelay = 500; //ms
    float minDecay = 0.1, maxDecay = 100; //ms
    float maxHighCut = 20000, minHighCut = 100;
    float maxModRate = 5; //hz
   
    void calcGains();
    void setupAllPass();
    void calcAllPass();
    void calcLowPass();
    void calcFilterCoeffs();
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FlutterVerbAudioProcessor)
};
