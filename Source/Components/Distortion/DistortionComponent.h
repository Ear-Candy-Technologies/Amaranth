/*
  ==============================================================================

    DistortionComponent.h
    Created: 29 Aug 2023 7:36:23pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class DistortionComponent : public juce::Component
{
public:
    
    DistortionComponent (AmaranthAudioProcessor&);
    ~DistortionComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
                        juce::Label& label, juce::String inLabel);

private:
    
    AmaranthAudioProcessor& processor;
    
    juce::Slider typeSlider;
    juce::Slider driveSlider;
    juce::Slider mixSlider;
    
    juce::Label typeLabel;
    juce::Label driveLabel;
    juce::Label mixLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> typeAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionComponent)
};
