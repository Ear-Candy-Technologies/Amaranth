/*
  ==============================================================================

    LevelMeterAnalyzer.h
    Created: 1 Sep 2023 12:49:48pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once

class LevelMeterAnalyzer
{
public:
    
    LevelMeterAnalyzer() {}
    ~LevelMeterAnalyzer() {}
    
    void prepare (int inNumSamples, double inSampleRate,  int numChannels, float inInitialLevel, float inTargetValue)
    {
        numSamples = inNumSamples;
        
        for (int channel = 0; channel < numChannels; channel++)
        {
            rmsLevel[channel].reset                    (inSampleRate, inInitialLevel);
            rmsLevel[channel].setCurrentAndTargetValue (inTargetValue);
        }
    }
    
    void process (juce::AudioBuffer<float>& buffer)
    {
        for (int channel = 0; channel < buffer.getNumChannels(); channel++)
        {
            const auto value = juce::Decibels::gainToDecibels (buffer.getRMSLevel (channel,  0, buffer.getNumSamples()));
            
            rmsLevel[channel].skip (numSamples);
            
            if (value < rmsLevel[channel].getCurrentValue())
                rmsLevel[channel].setTargetValue (value);
            else
                rmsLevel[channel].setCurrentAndTargetValue (value);
        }
    }
    
    float getRMSValue (int channel)
    {
        jassert (channel == 0 || channel == 1);
        return rmsLevel[channel].getCurrentValue();
    }
    
private:
    
    int numSamples;
    
    juce::LinearSmoothedValue<float> rmsLevel[2];
};
