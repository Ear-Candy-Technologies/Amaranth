/*
  ==============================================================================

    SynthVoice.h
    Created: 20 Jun 2022 10:14:54pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    
    SynthSound();
    
    ~SynthSound() override;
    
    bool appliesToNote ([[maybe_unused]] int midiNoteNumber) override;
    
    bool appliesToChannel ([[maybe_unused]] int midiChannel) override;
    
private:
    
    
};
