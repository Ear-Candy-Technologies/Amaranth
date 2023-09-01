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
        Phase  = 4
    };

    /** Osc One  */
    static const juce::String OSC_ONE_GAIN    = "OscOneGain";
    static const juce::String OSC_ONE_PAN     = "OscOnePan";
    static const juce::String OSC_ONE_DETUNE  = "OscOneDetune";
    static const juce::String OSC_ONE_WIDTH   = "OscOneWidth";
    static const juce::String OSC_ONE_PHASE   = "OscOnePhase";

    static const juce::StringArray OSC_ONE { OSC_ONE_GAIN, OSC_ONE_PAN, OSC_ONE_DETUNE, OSC_ONE_WIDTH, OSC_ONE_PHASE };

    /** Osc Two */
    static const juce::String OSC_TWO_GAIN    = "OscTwoGain";
    static const juce::String OSC_TWO_PAN     = "OscTwoPan";
    static const juce::String OSC_TWO_DETUNE  = "OscTwoDetune";
    static const juce::String OSC_TWO_WIDTH   = "OscTwoWidth";
    static const juce::String OSC_TWO_PHASE   = "OscTwoPhase";

    static const juce::StringArray OSC_TWO { OSC_TWO_GAIN, OSC_TWO_PAN, OSC_TWO_DETUNE, OSC_TWO_WIDTH, OSC_TWO_PHASE };

    /** ADSR */
    static const juce::String ATTACK  = "Attack";
    static const juce::String DECAY   = "Decay";
    static const juce::String SUSTAIN = "Sustain";
    static const juce::String RELEASE = "Release";

    /** Ranges */
    static const juce::NormalisableRange<float> gainRange   (-60.0f,  12.0f,  1.0f, 1.0f); // Gain (dB)
    static const juce::NormalisableRange<float> panRange    (0.0f,    juce::MathConstants<float>::halfPi, 0.01f, 1.0f); // Pan
    static const juce::NormalisableRange<float> detuneRange (0.0f,    1.0f,   0.01f, 1.0f); // Detune
    static const juce::NormalisableRange<float> widthRange  (0.0f,    1.0f,   0.01f, 1.0f); // Width
    static const juce::NormalisableRange<float> phaseRange  (-180.0f, 180.0f, 1.0f,  1.0f); // Phase
    static const juce::NormalisableRange<float> adsrRange   (0.0f,    1.0f,   0.01f, 1.0f); // ADSR

    /** Default value */
    static constexpr float gainDefault   { 0.0f };
    static constexpr float panDefault    { juce::MathConstants<float>::halfPi/2.0f };
    static constexpr float detuneDefault { 0.5f };
    static constexpr float widthDefault  { 0.0f };
    static constexpr float phaseDefault  { 0.0f };
    static constexpr float adsrDefault   { 0.5f };
}

/** Parameters user can move */
juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
