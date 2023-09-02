/*
  ==============================================================================

    Parameters.h
    Created: 29 Aug 2023 6:38:30pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

/** Parameters names */
namespace ID
{
    enum Oscillator
    {
        One = 0,
        Two = 1
    };

    enum OscillatorSection
    {
        Gain   = 0,
        Pan    = 1,
        Detune = 2,
        Width  = 3,
    };

    /** Osc One  */
    static const juce::String OSC_ONE_GAIN    = "OscOneGain";
    static const juce::String OSC_ONE_PAN     = "OscOnePan";
    static const juce::String OSC_ONE_DETUNE  = "OscOneDetune";
    static const juce::String OSC_ONE_WIDTH   = "OscOneWidth";

    static const juce::StringArray OSC_ONE { OSC_ONE_GAIN, OSC_ONE_PAN, OSC_ONE_DETUNE, OSC_ONE_WIDTH };

    /** Osc Two */
    static const juce::String OSC_TWO_GAIN    = "OscTwoGain";
    static const juce::String OSC_TWO_PAN     = "OscTwoPan";
    static const juce::String OSC_TWO_DETUNE  = "OscTwoDetune";
    static const juce::String OSC_TWO_WIDTH   = "OscTwoWidth";

    static const juce::StringArray OSC_TWO { OSC_TWO_GAIN, OSC_TWO_PAN, OSC_TWO_DETUNE, OSC_TWO_WIDTH };

    /** ADSR */
    static const juce::String ATTACK  = "Attack";
    static const juce::String DECAY   = "Decay";
    static const juce::String SUSTAIN = "Sustain";
    static const juce::String RELEASE = "Release";

    /** Ranges */
    static const float PI = juce::MathConstants<float>::pi;
    static const juce::NormalisableRange<float> gainRange   (-60.0f,  12.0f,   1.0f, 1.0f); // Gain (dB)
    static const juce::NormalisableRange<float> panRange    (0.0f,    PI/2.0f, 0.01f, 1.0f); // Pan
    static const juce::NormalisableRange<float> detuneRange (0.0f,    1.0f,    0.01f, 1.0f); // Detune
    static const juce::NormalisableRange<float> widthRange  (0.0f,    1.0f,    0.01f, 1.0f); // Width
    static const juce::NormalisableRange<float> adsrRange   (0.0f,    1.0f,    0.01f, 1.0f); // ADSR

    /** Default value */
    static constexpr float gainDefault   { 0.0f };
    static constexpr float detuneDefault { 0.5f };
    static constexpr float widthDefault  { 0.0f };

    static constexpr float phaseDefault  { 0.0f };

    /** Filters */
    static const juce::String FILTER_HIGHPASS = "Highpass";
    static const juce::String FILTER_LOWPASS  = "Lowpass";
    static const juce::String FILTER_HIGHPASS_RES  = "HighpassResonance";
    static const juce::String FILTER_LOWPASS_RES   = "LowpassResonance";
    
    static const juce::NormalisableRange<float> highpassFilterRange (20.0f, 20000.0f,  0.01f, 0.3f);
    static const juce::NormalisableRange<float> lowpassFilterRange  (20.0f, 20000.0f,  0.01f, 0.3f);
    static const juce::NormalisableRange<float> highpassResonanceRange (0.0f, 1.0f, 0.01f, 1.0f);
    static const juce::NormalisableRange<float> lowpassResonanceRange  (0.0f, 1.0f, 0.01f, 1.0f);
    
    static constexpr float highpassFilterDefault { 20.0f };
    static constexpr float lowpassFilterDefault  { 20000.0f };
    static constexpr float highpassResonanceDefault { 0.0f };
    static constexpr float lowpassResonanceDefault  { 0.0f };

    /** FX */
    /** Distortion */
    static const juce::String FX_DST_DRIVE   = "DSTDrive";
    static const juce::String FX_DST_MIX     = "DSTMix";
    static const juce::String FX_DST_TYPE    = "DSTType";
    
    static const juce::NormalisableRange<float> fxDstDriveRange (0.0f,  2.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxDstMixRange   (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxDstTypeRange  (-1.0f,  2.0f,  1.0f, 1.0f);

    static constexpr float fxDstDriveDefault { 1.0f };
    static constexpr float fxDstMixDefault   { 0.0f };
    static constexpr float fxDstTypeDefault  { -1.0f };
    
    /** Reverb */
    static const juce::String FX_RB_ROOM_SIZE    = "RoomSize";
    static const juce::String FX_RB_DAMPING      = "Damping";
    static const juce::String FX_RB_MIX          = "Mix";
    static const juce::String FX_RB_WIDTH        = "Width";
    static const juce::String FX_RB_FEEDBACK     = "Feedback";

    static const juce::NormalisableRange<float> fxRbRoomSizeRange (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxRbDampingRange  (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxRbMixRange      (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxRbWidthRange    (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxRbFeedbackRange (0.0f,  1.0f,  0.01f, 1.0f);

    static constexpr float fxRbRoomSizeDefault { 0.5f };
    static constexpr float fxRbDampingDefault  { 0.5f };
    static constexpr float fxRbMixDefault      { 0.33f };
    static constexpr float fxRbWidthDefault    { 0.45f };
    static constexpr float fxRbFeedbackDefault { 0.0f };

    /** Delay */
    static const juce::String FX_DEL_TIME     = "Time";
    static const juce::String FX_DEL_FEEDBACK = "DelFeedback";
    static const juce::String FX_DEL_MIX      = "DelMix";

    static const juce::NormalisableRange<float> fxDelTimeRange      (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxDelFeedbackRange  (0.0f,  1.0f,  0.01f, 1.0f);
    static const juce::NormalisableRange<float> fxdelMixRange       (0.0f,  1.0f,  0.01f, 1.0f);

    static constexpr float fxDelTimeDefault      { 0.5f };
    static constexpr float fxDelFeedbackDefault  { 0.5f };
    static constexpr float fxDelMixDefault       { 0.33f };

    /** Master */
    static const juce::String MASTER = "Master";
    static const juce::NormalisableRange<float> masterRange (-60.0f,  12.0f,   1.0f, 1.0f); // Gain (dB)
    static constexpr float masterDefault { -12.0f };

    static constexpr float adsrDefault   { 0.5f };
}

/** Parameters user can move */
juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
