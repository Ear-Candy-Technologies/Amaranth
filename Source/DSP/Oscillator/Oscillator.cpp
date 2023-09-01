#include "Oscillator.h"

Oscillator::Oscillator (juce::AudioProcessorValueTreeState& inApvts) : apvts (inApvts) {}

Oscillator::~Oscillator() {}

void Oscillator::prepareOscillator (juce::dsp::ProcessSpec inSpec)
{
    setFunction ( [](float x) { return std::sinf(x);} );
    
    prepare            (inSpec);
    gain.prepare       (inSpec);
    adsr.setSampleRate (inSpec.sampleRate);
}

void Oscillator::updateParameters()
{
    setGain (*apvts.getRawParameterValue(ID::OSC_ONE_GAIN));
    setPan  (*apvts.getRawParameterValue(ID::OSC_ONE_PAN));
    setADSR (*apvts.getRawParameterValue(ID::ATTACK),
             *apvts.getRawParameterValue(ID::DECAY),
             *apvts.getRawParameterValue(ID::SUSTAIN),
             *apvts.getRawParameterValue(ID::RELEASE));
}

void Oscillator::processOscillator (juce::dsp::ProcessContextReplacing<float> inContext, juce::AudioBuffer<float>& synthBuffer)
{
    process      (inContext);
    gain.process (inContext);
    pan.process  (synthBuffer, parameters.pan);
    
    adsr.applyEnvelopeToBuffer (synthBuffer, 0, synthBuffer.getNumSamples());
}

void Oscillator::setFunction (const std::function<NumericType(NumericType)>& inFunction)
{
    parameters.function = inFunction;
    initialise (inFunction);
}

void Oscillator::setFreq (float inFreq)
{
    parameters.freq = inFreq;
    setFrequency (parameters.freq);
}

void Oscillator::setGain (float inGain)
{
    parameters.gain = inGain;
    gain.setGainDecibels (parameters.gain);
}

void Oscillator::setPan (float inPan)
{
    parameters.pan = inPan;
}

void Oscillator::setADSR (float inAttack, float inDecay, float inSustain, float inRelease)
{
    parameters.adsr.attack  = inAttack;
    parameters.adsr.decay   = inDecay;
    parameters.adsr.sustain = inSustain;
    parameters.adsr.release = inRelease;
    adsr.setParameters (parameters.adsr);
}

void Oscillator::startNote()
{
    adsr.noteOn();
}

void Oscillator::stopNote()
{
    adsr.noteOff();
}
