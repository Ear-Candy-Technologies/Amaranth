#pragma once

#include <JuceHeader.h>
#include "../../PluginProcessor.h"

class HeaderComponent : public juce::Component
{
public:
    
    HeaderComponent (AmaranthAudioProcessor&);
    ~HeaderComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    AmaranthAudioProcessor& processor;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
