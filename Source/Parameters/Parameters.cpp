#include "Parameters.h"

juce::AudioProcessorValueTreeState::ParameterLayout createParameters()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
        
    /** Osc One */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_GAIN,   1), ID::OSC_ONE_GAIN,   ID::gainRange,   ID::gainDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_PAN,    1), ID::OSC_ONE_PAN,    ID::panRange,    ID::panDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_DETUNE, 1), ID::OSC_ONE_DETUNE, ID::detuneRange, ID::detuneDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_WIDTH,  1), ID::OSC_ONE_WIDTH,  ID::widthRange,  ID::widthDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_PHASE,  1), ID::OSC_ONE_PHASE,  ID::phaseRange,  ID::phaseDefault));
    
    /** Osc Two */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_GAIN,   1), ID::OSC_TWO_GAIN,   ID::gainRange,   ID::gainDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_PAN,    1), ID::OSC_TWO_PAN,    ID::panRange,    ID::panDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_DETUNE, 1), ID::OSC_TWO_DETUNE, ID::detuneRange, ID::detuneDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_WIDTH,  1), ID::OSC_TWO_WIDTH,  ID::widthRange,  ID::widthDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_PHASE,  1), ID::OSC_TWO_PHASE,  ID::phaseRange,  ID::phaseDefault));
    
    /** ADSR */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::ATTACK,    1),  ID::ATTACK,   ID::adsrRange, ID::adsrDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::DECAY, 1),      ID::DECAY,    ID::adsrRange, ID::adsrDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::SUSTAIN,  1),   ID::SUSTAIN,  ID::adsrRange, ID::adsrDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::RELEASE,  1),   ID::RELEASE,  ID::adsrRange, ID::adsrDefault));
    
    return params;
}
