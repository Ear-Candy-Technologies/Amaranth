/*
  ==============================================================================

    KeyboardComponent.h
    Created: 28 Aug 2023 4:40:14pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class OscillatorComponent : public juce::Component
{
public:
    
    OscillatorComponent (AmaranthAudioProcessor&);
    ~OscillatorComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    AmaranthAudioProcessor& processor;
    
    juce::Slider gainSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};
