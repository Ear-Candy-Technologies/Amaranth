/*
  ==============================================================================

    Distortion.h
    Created: 1 Sep 2023 3:17:40pm
    Author:  Fernando Garcia

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include <cmath>

class Distortion
{
public:
    Distortion();
    ~Distortion();
    
    void setDrive (float inDrive);
    void setMix (float inMix);
    
    void setDistortionIndex (int inDistortionIndex);
    
    float softClipping (float inSample);
    float hardClipping (float inSample);
    float bitCrusher   (float inSample);
    
    void process (juce::AudioBuffer<float>& buffer);

private:
    void processDryWet (juce::AudioBuffer<float>& inDryBuffer,
                        juce::AudioBuffer<float>& inWetBuffer);
    juce::AudioBuffer<float> dryBuffer;
    
    int distortionIndex { 0 };
    float drive { 1.0f };
    float mix { 1.0f };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Distortion)
};
