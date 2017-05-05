/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

#define JucePlugin_Name "FlutterVerb"

const float delayTimes[] = {1051, 337, 113, 4799, 4999, 5399, 5801};

//==============================================================================
FlutterVerbAudioProcessor::FlutterVerbAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    
    usrParams[mixParam].setMinMax(0, 100);
    usrParams[mixParam].setWithUparam(defaultMix);
    
    usrParams[predelayParam].setMinMax(0, maxPredelay);
    usrParams[predelayParam].setWithUparam(defaultPredelay);
    
    usrParams[decayParam].setMinMax(0, maxDecay);
    usrParams[decayParam].setWithUparam(defaultDecay);
    
    usrParams[highcutParam].setMinMax(minHighCut, maxHighCut);
    usrParams[highcutParam].setWithUparam(defaultHighCut);
    
    usrParams[densityParam].setMinMax(0, 100);
    usrParams[densityParam].setWithUparam(defaultDensity);
    
    usrParams[diffusionParam].setMinMax(0, 100);
    usrParams[diffusionParam].setWithUparam(defaultDiffusion);
    
    usrParams[modRateParam].setMinMax(0, maxModRate);
    usrParams[modRateParam].setWithUparam(defaultModRate);
    
    usrParams[modDepthParam].setMinMax(0, 1);
    usrParams[modDepthParam].setWithUparam(defaultModDepth);
    
    lowpass.push_back(lowpassL);
    lowpass.push_back(lowpassR);
    
    delay1.push_back(allpass1L);
    delay1.push_back(allpass1R);
    
    delay2.push_back(allpass2L);
    delay2.push_back(allpass2R);
    
    delay3.push_back(allpass3L);
    delay3.push_back(allpass3R);
    
    fbcf1.push_back(fbcf1L);
    fbcf1.push_back(fbcf1R);
    
    fbcf2.push_back(fbcf2L);
    fbcf2.push_back(fbcf2R);
    
    fbcf3.push_back(fbcf3L);
    fbcf3.push_back(fbcf3R);
    
    fbcf4.push_back(fbcf4L);
    fbcf4.push_back(fbcf4R);

    fbGains.push_back(0.7f);
    fbGains.push_back(0.7f);
    fbGains.push_back(0.7f);
    fbGains.push_back(0.742f);
    fbGains.push_back(0.733f);
    fbGains.push_back(0.715f);
    fbGains.push_back(0.697f);
    
    delayNetwork.push_back(delay1);
    delayNetwork.push_back(delay2);
    delayNetwork.push_back(delay3);
    delayNetwork.push_back(fbcf1);
    delayNetwork.push_back(fbcf2);
    delayNetwork.push_back(fbcf3);
    delayNetwork.push_back(fbcf4);

}

FlutterVerbAudioProcessor::~FlutterVerbAudioProcessor()
{
}

//==============================================================================
const String FlutterVerbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}


int FlutterVerbAudioProcessor::getNumParameters() {
    return totalNumParams;
}

float FlutterVerbAudioProcessor::getParameter(int index) {
    
   return usrParams[index].getVstVal();
    
}

void FlutterVerbAudioProcessor::setParameter(int index, float newValue) {
    
    usrParams[index].setWithVstVal(newValue);
    
    switch(index) {
        case mixParam:
            calcGains();
            break;
        case predelayParam:
            calcAllPass();
            break;
        case decayParam:
            calcAllPass();
            break;
        case highcutParam:
            calcLowPass();
            break;
        case densityParam:
            calcAllPass();
            break;
        case diffusionParam:
            calcAllPass();
            break;
        case modRateParam:
            break;
        case modDepthParam:
            break;
        default:
            break;
    }
    
}

void FlutterVerbAudioProcessor::calcGains() {
    wetGain = 0.01 * usrParams[mixParam].getUparamVal();
    dryGain = 1 - wetGain;
}

void FlutterVerbAudioProcessor::calcAllPass() {

    
    for (int i = 0; i < delayNetwork.size(); ++i) {
        
        fbGains[i] = pow(10, (-3 * delayTimes[i])/(usrParams[decayParam].getUparamVal() * fs));
        
        for (int j = 0; j < delayNetwork[i].size(); ++j) {
            delayNetwork[i][j].setDelay(delayTimes[i]);
        }
    }
    
}

void FlutterVerbAudioProcessor::calcLowPass() {

    float Q = 0.7071;
    float coeffs[5];
    float fc = usrParams[highcutParam].getUparamVal();
   
    Mu45FilterCalc::calcCoeffsLPF(coeffs, fc, Q, fs);
    
    for (int i = 0; i < lowpass.size(); ++i) {
        lowpass[i].setCoefficients(coeffs[0], coeffs[1], coeffs[2], coeffs[3], coeffs[4]);
    }
    
}

void FlutterVerbAudioProcessor::calcFilterCoeffs() {
    calcAllPass();
    calcLowPass();
}



float FlutterVerbAudioProcessor::getParameterDefaultValue(int index) {
    switch (index)
    {
        case mixParam:
            return defaultMix;
        case predelayParam:
            return defaultPredelay;
        case decayParam:
            return defaultDecay;
        case highcutParam:
            return defaultHighCut;
        case densityParam:
            return defaultDensity;
        case diffusionParam:
            return defaultDiffusion;
        case modRateParam:
            return defaultModRate;
        case modDepthParam:
            return defaultModDepth;
            
        default: return 0.0f;
    }
    
}

const String FlutterVerbAudioProcessor::getParameterName(int index) {
    switch (index)
    {
        case mixParam:         return mixName;
        case predelayParam:    return predelayName;
        case decayParam:       return decayName;
        case highcutParam:     return highcutName;
        case densityParam:     return densityName;
        case diffusionParam:   return diffusionName;
        case modRateParam:     return modRateName;
        case modDepthParam:    return modDepthName;
            
        default:               return String::empty;
    }
    
    
}

const String FlutterVerbAudioProcessor::getParameterText (int index)
{
    return String( usrParams[index].getUparamVal() );
}


bool FlutterVerbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool FlutterVerbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double FlutterVerbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int FlutterVerbAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int FlutterVerbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void FlutterVerbAudioProcessor::setCurrentProgram (int index)
{
}

const String FlutterVerbAudioProcessor::getProgramName (int index)
{
    return {};
}

void FlutterVerbAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void FlutterVerbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    fs = sampleRate;
    
    //calc all algorithm params
    calcGains();
    calcFilterCoeffs();
    
}

void FlutterVerbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool FlutterVerbAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void FlutterVerbAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    const int numSamples = buffer.getNumSamples();
    
    
    //Local variables
    float wetSignal, d1, d2, d3, d4, s1, s2, OutA, OutB, OutC, OutD;
    
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        float* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
        
        for (int i = 0; i < numSamples; ++i) {
            
            d1 = channelData[i] + delay1[channel].nextOut()*fbGains[0];
            d2 = delay2[channel].nextOut()*fbGains[1];
            d3 = delay3[channel].nextOut()*fbGains[2];
            
            wetSignal = 0.33f*(delay3[channel].tick(delay2[channel].tick(delay1[channel].tick(channelData[i]))));
            
            d1 = wetSignal + fbcf1[channel].nextOut()*fbGains[3];
            d2 = wetSignal + fbcf2[channel].nextOut()*fbGains[4];
            d3 = wetSignal + fbcf3[channel].nextOut()*fbGains[5];
            d4 = wetSignal + fbcf4[channel].nextOut()*fbGains[6];
            
            d1 = fbcf1[channel].tick(d1);
            d2 = fbcf2[channel].tick(d2);
            d3 = fbcf3[channel].tick(d3);
            d4 = fbcf4[channel].tick(d4);
            
            wetSignal = (d1 + d2 + d3 + d4) * 0.25f;
            
            channelData[i] = lowpass[channel].tick(channelData[i]*dryGain + wetGain*wetSignal);
           
            
        }
        
        
    }
    
    
}

//==============================================================================
bool FlutterVerbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* FlutterVerbAudioProcessor::createEditor()
{
    return new FlutterVerbAudioProcessorEditor (*this);
}

//==============================================================================
void FlutterVerbAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void FlutterVerbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new FlutterVerbAudioProcessor();
}
