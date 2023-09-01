/*
  ==============================================================================

    EnvelopeComponent.h
    Created: 29 Aug 2023 7:29:54pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class ADSRComponent : public juce::Component
{
public:
    
    ADSRComponent (AmaranthAudioProcessor&);
    ~ADSRComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void prepareSlider (juce::Slider& slider, juce::String sliderID,
                        std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach);


private:
    
    AmaranthAudioProcessor& processor;

    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> decayAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sustainAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
