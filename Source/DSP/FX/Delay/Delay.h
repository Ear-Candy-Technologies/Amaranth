/*
 ==============================================================================
 
 Delay.h
 Created: 2 Jan 2021 10:25:55pm
 Author:  Flavio Everardo
 
 ==============================================================================
 */

#pragma once
#include <JuceHeader.h>

const int maxBufferSize = 192000; // Fix this. Move it to another place and check other numbers

class Delay
{
public:
    Delay();
    ~Delay();
    
    void setSampleRate (float inSampleRate);
    
    void reset();
    
    void updateParameter (float inTime, float inFeedback, float inDryWet);
    
    void process (juce::AudioBuffer<float>& buffer);
    
    float getLinearInterpolation (float v0, float v1, float t)
    {
        return (1 - t) * v0 + t * v1;
    }
    
private:
    
    float time;
    float feedback;
    float drywet;
    
    /**  internal function */
    float getInterpolatedSample (int channel, float inDelayTimeInSamples);
    
    float mSampleRate              { -1 };
    float mBuffer[maxBufferSize] = { 0.0f };
    float mFeedbackSample[2]       { 0 };
    float mTimeSmoothed[2]         { 0 };
    
    int mDelayIndex[2] { 0 };
};
