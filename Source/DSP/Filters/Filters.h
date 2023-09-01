#pragma once
#include <JuceHeader.h>

class Filters
{
public:
    
    struct Parameters
    {
        float highpassFreq = 20.0f;
        float highpassResonance = 0.0f;
        float lowpassFreq  = 20000.0f;
        float lowpassResonance = 0.0f;
    };
    
    Filters();
    ~Filters();
    
    /** Prepare filters */
    void prepare (juce::dsp::ProcessSpec& inSpec);
    
    /** Process methods for filters */
    void processHighPass (juce::AudioBuffer<float>& buffer);
    void processLowPass (juce::AudioBuffer<float>& buffer);
    
    /** Update filters parameters */
    void updateFilters (Filters::Parameters newParameters);
    
private:
    
    juce::dsp::LadderFilter<float> highpassFilter;
    juce::dsp::LadderFilter<float> lowpassFilter;
    
    Filters::Parameters filtersParameters;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Filters)
};
