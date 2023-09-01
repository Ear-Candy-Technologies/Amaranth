/*
  ==============================================================================

    Meter.h
    Created: 1 Sep 2023 12:38:19pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class LevelMeter : public juce::Component, juce::Timer
{
public:
    
    LevelMeter (std::function<float()>&& valueFunction, juce::Image grillImage);
    
    LevelMeter (std::function<float()>&& valueFunction = {});
    
    ~LevelMeter() override;

    void paint             (juce::Graphics&) override;
    void paintOverChildren (juce::Graphics&) override;
    
    void resized() override;
    void timerCallback() override;
    
    void setValueFunction (std::function<float()>&& valueFunction);
    
    float getRMSValue (int channel);

private:
    
    std::function<float()> valueSupplier;
    
    juce::ColourGradient gradient;
    
    juce::Image grill;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LevelMeter)
};
