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
        
        // Prepare osc (call in prepareToPlay)
        void prepareOsc (juce::dsp::ProcessSpec inSpec);
        
        // Set osc function (call in prepareToPlay or when user change wave)
        void setOscFunction (const std::function<NumericType(NumericType)>& inFunction);
        
        // Set osc freq in Hz
        void setOscFreq (float inFreq);
    
        // ADSR noteOn()
        void startNote();
        
        // ADSR noteOff()
        void stopNote();
    
        // Check if ADSR is active
        bool getIsActive() { return adsr.isActive(); }
        
        // Update osc parameters with APVT
        void updateParameters (float inGain, float inAttack, float inDecay, float inSustain, float inRelease);
        
        // Process samples with osc
        void processOsc (juce::dsp::ProcessContextReplacing<float> inContext, juce::AudioBuffer<float>& synthBuffer);
    
    private:
    
        // Main JUCE Oscillator
        juce::dsp::Oscillator<float> osc { [](float x) { return std::sin(x); }};
    
        // Osc gain
        juce::dsp::Gain<float> gain;
    
        // Osc ADSR
        juce::ADSR adsr;
        juce::ADSR::Parameters adsrParams;
    
};
