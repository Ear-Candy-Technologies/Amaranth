/*
  ==============================================================================

    MasterComponent.h
    Created: 1 Sep 2023 12:00:39am
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class MasterComponent  : public juce::Component
{
public:
    
    MasterComponent (AmaranthAudioProcessor&);
    ~MasterComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    AmaranthAudioProcessor& processor;
    
    juce::Slider masterSlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> masterAttach;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MasterComponent)
};
