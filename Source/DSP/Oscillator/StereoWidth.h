/*
  ==============================================================================

    StereoWidth.h
    Created: 31 Aug 2023 9:03:52pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once

class StereoWidth
{
public:
    
    StereoWidth() {}
    ~StereoWidth() {}
    
    void process (juce::AudioBuffer<float>& inBuffer, float inWidth)
    {
        mWidthSmoothed = mWidthSmoothed - 0.002f * (mWidthSmoothed - inWidth);
        
        float mMidGain   = 1.0f;
        float mSidesGain = mWidthSmoothed;
        
        for (int sample = 0; sample < inBuffer.getNumSamples(); sample++)
        {
            auto midSignal   = inBuffer.getSample (0, sample) + inBuffer.getSample (1, sample) * mMidGain   / sqrt (2.0f);
            auto sidesSignal = inBuffer.getSample (0, sample) - inBuffer.getSample (1, sample) * mSidesGain / sqrt (2.0f);
            
            inBuffer.setSample (0, sample, midSignal + sidesSignal);
            inBuffer.setSample (1, sample, midSignal - sidesSignal);
        }
    }
    
private:
    
    float mWidthSmoothed { 0.0f };
    
};
