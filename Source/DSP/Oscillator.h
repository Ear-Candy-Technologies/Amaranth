/*
  ==============================================================================

    Oscillator.h
    Created: 3 Jul 2022 1:55:42am
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class Oscillator : public juce::dsp::Oscillator<float>
{
    public:
    
        Oscillator();
        
        ~Oscillator();
        
        void prepareOsc (juce::dsp::ProcessSpec inSpec);
        
        void setOscFunction (const std::function<NumericType(NumericType)>& inFunction);
        
        void setOscFreq (float inFreq);
    
        void startNote();
    
        void stopNote();
    
        bool getIsActive() { return adsr.isActive(); }
    
        void updateParameters (float inGain);
        
        void processOsc (juce::dsp::ProcessContextReplacing<float> inContext, juce::AudioBuffer<float>& synthBuffer);
    
    private:
    
        juce::dsp::Oscillator<float> osc { [](float x) { return std::sin(x); }};
        juce::dsp::Gain<float> gain;
        juce::ADSR adsr;
        juce::ADSR::Parameters adsrParams;
    
};
