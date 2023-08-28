#pragma once

#include <JuceHeader.h>
#include "Components/OscillatorComponent.h"
#include "Components/KeyboardComponent.h"

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
    
    KeyboardComponent keyboardComponent { processor.keyboardState };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
