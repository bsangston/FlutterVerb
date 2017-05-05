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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GUIComponents  : public Component,
                       public SliderListener
{
public:
    //==============================================================================
    GUIComponents ();
    ~GUIComponents();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> mixSlider;
    ScopedPointer<Slider> predelaySlider;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Slider> highcutSlider;
    ScopedPointer<Slider> densitySlider;
    ScopedPointer<Slider> diffusionSlider;
    ScopedPointer<Slider> modRateSlider;
    ScopedPointer<Slider> modDepthSlider;
    ScopedPointer<Label> mixLabel;
    ScopedPointer<Label> predelayLabel;
    ScopedPointer<Label> decayLabel;
    ScopedPointer<Label> highcutLabel;
    ScopedPointer<Label> densityLabel;
    ScopedPointer<Label> diffusionLabel;
    ScopedPointer<Label> modRateLabel;
    ScopedPointer<Label> modDepthLabel;
    ScopedPointer<Label> title;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GUIComponents)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
