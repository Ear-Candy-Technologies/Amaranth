#include "Filters.h"

Filters::Filters() {}

Filters::~Filters() {}

void Filters::prepare (juce::dsp::ProcessSpec& inSpec)
{
    // Prepare highPass filter
    highpassFilter.prepare (inSpec);
    highpassFilter.setCutoffFrequencyHz (filtersParameters.highpassFreq);
    highpassFilter.setResonance (filtersParameters.highpassResonance);
    
    // Prepare lowPass filter
    lowpassFilter.prepare (inSpec);
    lowpassFilter.setCutoffFrequencyHz (filtersParameters.lowpassFreq);
    lowpassFilter.setResonance (filtersParameters.lowpassResonance);
}

void Filters::processHighPass (juce::AudioBuffer<float>& buffer)
{
    auto audioBlock = juce::dsp::AudioBlock<float> (buffer);
    auto context = juce::dsp::ProcessContextReplacing<float> (audioBlock);
    highpassFilter.process (context);
}

void Filters::processLowPass (juce::AudioBuffer<float>& buffer)
{
    auto audioBlock = juce::dsp::AudioBlock<float> (buffer);
    auto context = juce::dsp::ProcessContextReplacing<float> (audioBlock);
    lowpassFilter.process (context);
}

void Filters::updateFilters (Filters::Parameters newParameters)
{
    // Update highPass filter
    highpassFilter.setCutoffFrequencyHz (newParameters.highpassFreq);
    highpassFilter.setResonance(newParameters.highpassResonance);
    
    // Update lowPass filter
    lowpassFilter.setCutoffFrequencyHz (newParameters.highpassFreq);
    lowpassFilter.setResonance(newParameters.highpassResonance);
}
