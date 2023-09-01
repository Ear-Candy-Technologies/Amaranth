#pragma once
#include <JuceHeader.h>
#include "Pan.h"
#include "StereoWidth.h"
#include "../../Parameters/Parameters.h"

class Oscillator
{
public:
    
    Oscillator (juce::AudioProcessorValueTreeState& apvts, ID::Oscillator);
    ~Oscillator();
    
    struct Parameters
    {
        float gain  = 0.0f;
        float freq  = 100.0f;
        float pan   = juce::MathConstants<float>::halfPi;
        float width = 0.0f;
        
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
    void setWidth    (float inWidth);
    
private:
    
    ID::Oscillator oscillatorID;
    juce::StringArray ids;

    juce::dsp::Oscillator<float> osc;
    
    juce::dsp::Gain<float> gain;
    Pan pan;
    StereoWidth stereoWidth;
    
    /** Parameters */
    Parameters parameters;
    juce::AudioProcessorValueTreeState& apvts;
    
    float detuneRelations[6] = {
        1.0f,
        1.01991221f,
        0.98047643f,
        0.93711560f,
        0.88997686f,
        1.06216538f
    };
};
