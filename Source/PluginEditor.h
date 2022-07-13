#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"

// Include any class inside namespace
namespace Amaranth
{
    
}

class AmaranthAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    
    AmaranthAudioProcessorEditor (AmaranthAudioProcessor&);
    ~AmaranthAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:

    AmaranthAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthAudioProcessorEditor)
};
