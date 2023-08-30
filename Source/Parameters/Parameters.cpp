#include "Parameters.h"

juce::AudioProcessorValueTreeState::ParameterLayout createParameters()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
    
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::GAIN_OSC_ID, 1), ID::GAIN_OSC_NAME, 0.0f, 1.0f, 0.5f));
    
    return params;
}
