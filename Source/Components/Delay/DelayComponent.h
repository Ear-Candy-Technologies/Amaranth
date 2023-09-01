/*
  ==============================================================================

    DelayComponent.h
    Created: 29 Aug 2023 7:36:10pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class DelayComponent : public juce::Component
{
public:
    
    DelayComponent (AmaranthAudioProcessor&);
    ~DelayComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
                        juce::Label& label, juce::String inLabel);

private:
    
    AmaranthAudioProcessor& processor;
    
    juce::Slider timeSlider;
    juce::Slider feedbackSlider;
    juce::Slider mixSlider;
    
    juce::Label timeLabel;
    juce::Label feedbackLabel;
    juce::Label mixLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> timeAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayComponent)
};
