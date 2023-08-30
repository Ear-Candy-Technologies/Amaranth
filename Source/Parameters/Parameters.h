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
    static const juce::String GAIN_OSC_ID   = "GainOsc";
    static const juce::String GAIN_OSC_NAME = "Gain Osc";
}

/** Parameters user can move */
juce::AudioProcessorValueTreeState::ParameterLayout createParameters();
