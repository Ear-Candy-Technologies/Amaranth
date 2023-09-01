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
    
    juce::Slider inputSlider;
    juce::Slider driveSlider;
    juce::Slider toneSlider;
    
    juce::Label inputLabel;
    juce::Label driveLabel;
    juce::Label toneLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inputAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> toneAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionComponent)
};
