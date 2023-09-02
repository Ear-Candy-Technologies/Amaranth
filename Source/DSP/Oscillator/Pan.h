/*
  ==============================================================================

    Pan.h
    Created: 31 Aug 2023 5:18:04pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Pan
{
public:
    
    Pan() {}
    ~Pan() {}
    
    void process (juce::AudioBuffer<float>& inBuffer, float inPan)
    {
        for (int channel = 0; channel < inBuffer.getNumChannels(); channel++)
        {
            for (int i = 0; i < inBuffer.getNumSamples(); i++)
            {
                float sample = inBuffer.getSample (channel, i);
                
                if (channel == 0)
                {
                    sample *= sqrtf(((PI/2.0f)-inPan)*(2.0f/PI)*cosf(inPan));
                    inBuffer.setSample (channel, i, sample);
                }
                else
                {
                    sample *= sqrtf(inPan * (2.0f/PI) * sinf(inPan));
                    inBuffer.setSample (channel, i, sample);
                }
            }
        }
    }
    
private:
    
    float PI = juce::MathConstants<float>::pi;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pan)

};
