#pragma once
#include <JuceHeader.h>
#include "Pan.h"
#include "../../Parameters/Parameters.h"

class Oscillator : public juce::dsp::Oscillator<float>
{
public:

    Oscillator (juce::AudioProcessorValueTreeState& apvts);
    ~Oscillator();
    
    struct Parameters
    {
        float gain = 0.0f;
        float freq = 100.0f;
        float pan  = juce::MathConstants<float>::halfPi;
        
        juce::ADSR::Parameters adsr;
        
        std::function<NumericType(NumericType)> function;
    };
    
    /** Prepare osc (call in prepareToPlay) */
    void prepareOscillator (juce::dsp::ProcessSpec inSpec);
    
    /** Update osc parameters with APVT */
    void updateParameters();
    
    /** Process samples with osc */
    void processOscillator (juce::dsp::ProcessContextReplacing<float> inContext, juce::AudioBuffer<float>& synthBuffer);
    
    /** Set osc function (call in prepareToPlay or when user change wave) */
    void setFunction (const std::function<NumericType(NumericType)>& inFunction);
    void setFreq     (float inFreq);
    void setGain     (float inGain);
    void setPan      (float inPan);
    void setADSR     (float inAttack, float inDecay, float inSustain, float inRelease);

    void startNote();
    void stopNote();

    /** Check if ADSR is active */
    bool getIsActive() { return adsr.isActive(); }

private:

    /** Main JUCE Oscillator */
    juce::dsp::Oscillator<float> osc { [](float x) { return std::sin(x); }};

    juce::dsp::Gain<float> gain;
    Pan pan;
    juce::ADSR adsr;
    
    /** Parameters */
    Parameters parameters;
    juce::AudioProcessorValueTreeState& apvts;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};
