/*
  ==============================================================================

    OscillatorComponent.h
    Created: 15 Jul 2022 12:18:34pm
    Author:  Rodolfo Ortiz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../PluginProcessor.h"

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
