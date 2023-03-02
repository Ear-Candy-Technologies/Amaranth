#pragma once

#include <JuceHeader.h>
#include "OscillatorComponent.h"
#include "../PluginProcessor.h"

class MainComponent : public juce::Component
{
public:
    
    MainComponent (AmaranthAudioProcessor&);
    
    ~MainComponent() override;
    
    void paint (juce::Graphics&) override;
    
    void resized() override;
    
private:
    
    AmaranthAudioProcessor& processor;
    
    OscillatorComponent oscillator_1 { processor };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
