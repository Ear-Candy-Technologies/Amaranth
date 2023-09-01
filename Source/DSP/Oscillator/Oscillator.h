#pragma once
#include <JuceHeader.h>
#include "Pan.h"
#include "../../Parameters/Parameters.h"

/*class Oscillator : public juce::dsp::Oscillator<float>
{
public:

    Oscillator (juce::AudioProcessorValueTreeState& apvts, ID::Oscillator);
    ~Oscillator();
    
    struct Parameters
    {
        float gain = 0.0f;
        float freq = 100.0f;
        float pan  = juce::MathConstants<float>::halfPi;
        
        juce::ADSR::Parameters adsr;
        
        std::function<NumericType(NumericType)> function;
    };
    
    void prepareOscillator (juce::dsp::ProcessSpec inSpec, const std::function<NumericType(NumericType)> inFunction);
    
    void updateParameters();
    
    void processOscillator (juce::dsp::ProcessContextReplacing<float>& inContext, juce::AudioBuffer<float>& synthBuffer);
    void processOscillator (juce::dsp::ProcessContextReplacing<float>& inContext);
    
    void setFunction (const std::function<NumericType(NumericType)>& inFunction);
    void setFreq     (float inFreq);
    void setGain     (float inGain);
    void setPan      (float inPan);

private:
    
    ID::Oscillator oscillatorID;
    juce::StringArray ids;

    juce::dsp::Gain<float> gain;
    Pan pan;
    
    Parameters parameters;
    juce::AudioProcessorValueTreeState& apvts;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator)
};*/

class Oscillator
{
public:
    
    Oscillator (juce::AudioProcessorValueTreeState& apvts, ID::Oscillator);
    ~Oscillator();
    
    struct Parameters
    {
        float gain = 0.0f;
        float freq = 100.0f;
        float pan  = juce::MathConstants<float>::halfPi;
        
        juce::ADSR::Parameters adsr;
        
        std::function<float(float)> function;
    };
    
    /** Prepare osc (call in prepareToPlay) */
    void prepare (juce::dsp::ProcessSpec inSpec, const std::function<float(float)> inFunction);
    
    /** Update osc parameters with APVT */
    void updateParameters();
    
    /** Process samples with osc */
    void process (juce::AudioBuffer<float>& buffer);
    
    /** Set osc function (call in prepareToPlay or when user change wave) */
    void setFunction (const std::function<float(float)>& inFunction);
    void setFreq     (float inFreq);
    void setGain     (float inGain);
    void setPan      (float inPan);
    
private:
    
    ID::Oscillator oscillatorID;
    juce::StringArray ids;

    juce::dsp::Oscillator<float> osc;
    
    juce::dsp::Gain<float> gain;
    Pan pan;
    
    /** Parameters */
    Parameters parameters;
    juce::AudioProcessorValueTreeState& apvts;
    
    float samplerate { 0.0f };
    float fase[2]    { 0.0f };
};
