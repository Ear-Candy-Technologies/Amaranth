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
    
    OscillatorComponent (AmaranthAudioProcessor&, ID::Oscillator);
    ~OscillatorComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
    juce::String getOscillatorID (ID::OscillatorSection oscillatorSection);
    
    void prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach);
    
private:
    
    AmaranthAudioProcessor& processor;
    
    ID::Oscillator currentOscillator;
    
    juce::Slider gainSlider;
    juce::Slider panSlider;
    juce::Slider detuneSlider;
    juce::Slider widthSlider;
    juce::Slider phaseSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> panAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> detuneAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> widthAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> phaseAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};
