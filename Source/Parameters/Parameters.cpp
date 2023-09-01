#include "Parameters.h"

juce::AudioProcessorValueTreeState::ParameterLayout createParameters()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
    
    static const float PI = juce::MathConstants<float>::pi;
        
    /** Osc One */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_GAIN,   1), ID::OSC_ONE_GAIN,   ID::gainRange,   ID::gainDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_PAN,    1), ID::OSC_ONE_PAN,    ID::panRange,    PI / 4.0f));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_DETUNE, 1), ID::OSC_ONE_DETUNE, ID::detuneRange, ID::detuneDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_ONE_WIDTH,  1), ID::OSC_ONE_WIDTH,  ID::widthRange,  ID::widthDefault));
    
    /** Osc Two */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_GAIN,   1), ID::OSC_TWO_GAIN,   ID::gainRange,   ID::gainDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_PAN,    1), ID::OSC_TWO_PAN,    ID::panRange,    PI / 4.0f));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_DETUNE, 1), ID::OSC_TWO_DETUNE, ID::detuneRange, ID::detuneDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::OSC_TWO_WIDTH,  1), ID::OSC_TWO_WIDTH,  ID::widthRange,  ID::widthDefault));
    
    /** ADSR */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::ATTACK,    1),  ID::ATTACK,   ID::adsrRange, ID::adsrDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::DECAY, 1),      ID::DECAY,    ID::adsrRange, ID::adsrDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::SUSTAIN,  1),   ID::SUSTAIN,  ID::adsrRange, ID::adsrDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::RELEASE,  1),   ID::RELEASE,  ID::adsrRange, ID::adsrDefault));
    
    /** FX */
    /** Reverb */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_RB_ROOM_SIZE,   1), ID::FX_RB_ROOM_SIZE,   ID::fxRbRoomSizeRange,   ID::fxRbRoomSizeDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_RB_DAMPING,   1), ID::FX_RB_DAMPING,   ID::fxRbDampingRange,   ID::fxRbDampingDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_RB_MIX,   1), ID::FX_RB_MIX,   ID::fxRbMixRange,   ID::fxRbMixDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_RB_WIDTH,   1), ID::FX_RB_WIDTH,   ID::fxRbWidthRange,   ID::fxRbWidthDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_RB_FEEDBACK,   1), ID::FX_RB_FEEDBACK,   ID::fxRbFeedbackRange,   ID::fxRbFeedbackDefault));
    
    /** Delay */
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_DEL_MIX, 1),      ID::FX_DEL_MIX,     ID::fxdelMixRange,   ID::fxRbMixDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_DEL_TIME, 1),     ID::FX_DEL_TIME,    ID::fxDelTimeRange,   ID::fxDelTimeDefault));
    params.add (std::make_unique<juce::AudioParameterFloat> (juce::ParameterID (ID::FX_DEL_FEEDBACK, 1), ID::FX_DEL_FEEDBACK, ID::fxDelFeedbackRange,   ID::fxDelFeedbackDefault));
    
    return params;
}


