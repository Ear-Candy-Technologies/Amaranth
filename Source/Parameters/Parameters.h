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
    static const juce::NormalisableRange<float> gainRange   (-60.f, 12.f, 0.1f, 1.f); // Gain (dB)
    static const juce::NormalisableRange<float> panRange    (-60.f, 12.f, 0.1f, 1.f); // Pan
    static const juce::NormalisableRange<float> detuneRange (-60.f, 12.f, 0.1f, 1.f); // Detune
    static const juce::NormalisableRange<float> widthRange  (-60.f, 12.f, 0.1f, 1.f); // Width
    static const juce::NormalisableRange<float> phaseRange  (-60.f, 12.f, 0.1f, 1.f); // Phase

    static constexpr float gainDefault   { 0.0f };
    static constexpr float panDefault    { 0.0f };
    static constexpr float detuneDefault { 0.0f };
    static constexpr float widthDefault  { 0.0f };
    static constexpr float phaseDefault  { 0.0f };
}

/** Parameters user can move */
juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
