/*
  ==============================================================================

    ReverbComponent.h
    Created: 29 Aug 2023 7:36:31pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "../../PluginProcessor.h"

//==============================================================================
/*
*/
class ReverbComponent  : public juce::Component
{
public:
    ReverbComponent(AmaranthAudioProcessor&);
    ~ReverbComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void addSlider();

private:
    AmaranthAudioProcessor& processor;
    
    juce::Slider roomSizeSlider;
    juce::Slider dampingSlider;
    juce::Slider mixSlider;
    juce::Slider widthSlider;
    juce::Slider feedbackSlider;
    
    juce::Label roomSizeLabel;
    juce::Label dampingLabel;
    juce::Label mixLabel;
    juce::Label widthLabel;
    juce::Label feedbackLabel;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dampingAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> widthAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttach;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ReverbComponent)
};
