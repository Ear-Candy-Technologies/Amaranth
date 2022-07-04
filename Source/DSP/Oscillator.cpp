/*
  ==============================================================================

    Oscillator.cpp
    Created: 3 Jul 2022 1:55:42am
    Author:  Jesús Valdez

  ==============================================================================
*/

#include "Oscillator.h"

Oscillator::Oscillator() {}

Oscillator::~Oscillator() {}

void Oscillator::prepareOsc (juce::dsp::ProcessSpec inSpec)
{
    prepare (inSpec);
    
    gain.prepare (inSpec);
    
    adsr.setSampleRate (inSpec.sampleRate);
    adsrParams.attack = 0.8f;
    adsrParams.decay = 0.8f;
    adsrParams.sustain = 1.0f;
    adsrParams.release = 1.5f;
    adsr.setParameters (adsrParams);
}

void Oscillator::setOscFunction (const std::function<NumericType(NumericType)>& inFunction)
{
    initialise (inFunction);
}

void Oscillator::setOscFreq (float inFreq)
{
    setFrequency (inFreq);
}

void Oscillator::startNote()
{
    adsr.noteOn();
}

void Oscillator::stopNote()
{
    adsr.noteOff();
}

void Oscillator::updateParameters (float inGain, float inAttack, float inDecay, float inSustain, float inRelease)
{
    gain.setGainLinear(inGain);
    
    adsrParams.attack = inAttack;
    adsrParams.decay = inDecay;
    adsrParams.sustain = inSustain;
    adsrParams.release = inRelease;
    adsr.setParameters (adsrParams);
}

void Oscillator::processOsc (juce::dsp::ProcessContextReplacing<float> inContext, juce::AudioBuffer<float>& synthBuffer)
{
    process (inContext);
    gain.process (inContext);
    
    adsr.applyEnvelopeToBuffer (synthBuffer, 0, synthBuffer.getNumSamples());
}
