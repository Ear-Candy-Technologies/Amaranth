/*
  ==============================================================================

    MetersComponent.h
    Created: 29 Aug 2023 7:42:45pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "LevelMeter.h"
#include "../../PluginProcessor.h"

class MetersComponent : public juce::Component, public juce::Timer
{
public:
    
    MetersComponent (AmaranthAudioProcessor&);
    ~MetersComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override;

private:
    
    AmaranthAudioProcessor& processor;
    
    LevelMeter levelMeterL;
    LevelMeter levelMeterR;
    
    juce::AudioVisualiserComponent audioVisualiserComponent { 2 };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MetersComponent)
};
