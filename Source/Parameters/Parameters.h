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

    /** Osc Two */
    static const juce::String OSC_TWO_GAIN    = "OscTwoGain";
    static const juce::String OSC_TWO_PAN     = "OscTwoPan";
    static const juce::String OSC_TWO_DETUNE  = "OscTwoDetune";
    static const juce::String OSC_TWO_WIDTH   = "OscTwoWidth";
    static const juce::String OSC_TWO_PHASE   = "OscTwoPhase";

    /** Ranges */
    static const juce::NormalisableRange<float> gainRange   (-60.0f,  12.0f,  1.0f, 1.0f); // Gain (dB)
    static const juce::NormalisableRange<float> panRange    (-100.0f, 100.0f, 1.0f, 1.0f); // Pan
    static const juce::NormalisableRange<float> detuneRange (-60.0f,  12.0f,  1.0f, 1.0f); // Detune
    static const juce::NormalisableRange<float> widthRange  (-100.0f, 100.0f, 1.0f, 1.0f); // Width
    static const juce::NormalisableRange<float> phaseRange  (-180.0f, 180.0f, 1.0f, 1.0f); // Phase

    /** Default value */
    static constexpr float gainDefault   { 0.0f };
    static constexpr float panDefault    { 0.0f };
    static constexpr float detuneDefault { 0.0f };
    static constexpr float widthDefault  { 0.0f };
    static constexpr float phaseDefault  { 0.0f };
}

/** Parameters user can move */
juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
