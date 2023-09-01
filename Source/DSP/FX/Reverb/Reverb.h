/*
  ==============================================================================

    Reverb.h
    Created: 31 Aug 2023 7:20:52pm
    Author:  Fernando Garcia

  ==============================================================================
*/

#include <JuceHeader.h>
#pragma once

class Reverb
{
public:
    
    Reverb();
    ~Reverb();
    
    void setReverbParamters (float roomSize   = 0.5f,
                             float damping    = 0.5f,
                             float mix        = 0.33f,
                             float width      = 1.0f,
                             float freezeMode = 0.0f);

    void prepare (juce::dsp::ProcessSpec spec);

    void process (juce::AudioBuffer<float>& buffer);

private:
    
    juce::dsp::Reverb reverb;
    
    juce::dsp::Reverb::Parameters reverbParameters;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Reverb)
};
