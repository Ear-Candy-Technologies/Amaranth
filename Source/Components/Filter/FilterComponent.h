/*
  ==============================================================================

    FilterComponent.h
    Created: 29 Aug 2023 7:30:03pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class FilterComponent : public juce::Component
{
public:
    
    FilterComponent (AmaranthAudioProcessor&);
    ~FilterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void prepareSlider (juce::Slider& slider, juce::String sliderID,
                        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
                        juce::Label& label, juce::String labelText);

private:
    
    AmaranthAudioProcessor& processor;
    
    juce::Slider highpassSlider;
    juce::Slider lowpassSlider;
    juce::Slider highpassResonanceSlider;
    juce::Slider lowpassResonanceSlider;
    
    juce::Label highpassLabel;
    juce::Label lowpassLabel;
    juce::Label highpassResonanceLabel;
    juce::Label lowpassResonanceLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> highpassAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowpassAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> highpassResonanceAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowpassResonanceAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
