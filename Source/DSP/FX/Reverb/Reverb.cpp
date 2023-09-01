/*
  ==============================================================================

    Reverb.cpp
    Created: 31 Aug 2023 7:20:52pm
    Author:  Fernando Garcia

  ==============================================================================
*/

#include "Reverb.h"

Reverb::Reverb() {}
Reverb::~Reverb() {}

void Reverb::setReverbParamters(float roomSize, float damping, float wetLevel, float dryLevel, float width, float freezeMode)
{
    reverbParameters.roomSize = roomSize;
    reverbParameters.damping = damping;
    reverbParameters.wetLevel = wetLevel;
    reverbParameters.dryLevel = dryLevel;
    reverbParameters.width = width;
    reverbParameters.freezeMode = freezeMode;
}

void Reverb::prepare(juce::dsp::ProcessSpec spec)
{
    reverb.reset();
    reverb.prepare(spec);
    setReverbParamters();
}


void Reverb::process(juce::AudioBuffer<float>& buffer)
{
    reverb.setParameters (reverbParameters);
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    reverb.process (context);
}
