#pragma once
#include <JuceHeader.h>

class AmaranthSound : public juce::SynthesiserSound
{
public:
    
    AmaranthSound();
    ~AmaranthSound() override;
    
    bool appliesToNote ([[maybe_unused]] int midiNoteNumber) override;
    
    bool appliesToChannel ([[maybe_unused]] int midiChannel) override;
    
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthSound)
    
};
