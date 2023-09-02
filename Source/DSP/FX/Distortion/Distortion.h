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
    
    void setInput (float inInput);
    void setDrive (float inDrive);
    void setTone  (float inTone);
    
    void setDistortionIndex (int inDistortionIndex);
    
    float softClipping (float inSample);
    float hardClipping (float inSample);
    float bitCrusher   (float inSample);
    
    void process (juce::AudioBuffer<float>& buffer);

private:
    int distortionIndex { 0 };
    float input { 1.0f };
    float drive { 1.0f };
    float tone  { 0.5f };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Distortion)
};
