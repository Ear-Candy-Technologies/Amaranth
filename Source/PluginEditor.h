#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "GUI/MainComponent.h"

class AmaranthAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    
    AmaranthAudioProcessorEditor (AmaranthAudioProcessor&);
    ~AmaranthAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    AmaranthAudioProcessor& audioProcessor;
    
    MainComponent mainComponent { audioProcessor };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthAudioProcessorEditor)
};
