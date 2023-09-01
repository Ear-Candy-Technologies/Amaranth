#include "AmaranthVoice.h"

AmaranthVoice::AmaranthVoice (juce::AudioProcessorValueTreeState& inAPVTS) : apvts (inAPVTS) {}

AmaranthVoice::~AmaranthVoice() {}

bool AmaranthVoice::canPlaySound (juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void AmaranthVoice::startNote (int midiNoteNumber, float /*velocity*/, juce::SynthesiserSound* /*sound*/, int /*currentPitchWheelPosition*/)
{
    auto frequency = static_cast<float>(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    updateOscillators (frequency);
    adsr.noteOn();
}

void AmaranthVoice::updateOscillators (float currentFrequency)
{
    oscOne.setFreq (currentFrequency);
    oscTwo.setFreq (currentFrequency);
}

void AmaranthVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
    adsr.noteOff();
    
    if (!allowTailOff || !adsr.isActive())
        clearCurrentNote();
}

void AmaranthVoice::controllerMoved (int /*controllerNumber*/, int /*newControllerValue*/) {}

void AmaranthVoice::pitchWheelMoved (int /*newPitchWheelValue*/) {}

void AmaranthVoice::prepare (juce::dsp::ProcessSpec& spec)
{
    adsr.setSampleRate (spec.sampleRate);
    
    juce::ADSR::Parameters adsrParams;
    adsrParams.attack  = 0.0f;
    adsrParams.decay   = 0.0f;
    adsrParams.sustain = 1.0f;
    adsrParams.release = 1.0f;
    adsr.setParameters (adsrParams);
    
    oscOne.prepare (spec, [](float x) { return std::sinf (2.0f * juce::MathConstants<float>::pi * x); });
    oscTwo.prepare (spec, [](float x) { return x <= 0.5f ? 1.0f : -1.0f; });
}

void AmaranthVoice::updateParameters()
{
    oscOne.updateParameters();
    oscTwo.updateParameters();
}

void AmaranthVoice::renderNextBlock (juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    if (!isVoiceActive())
        return;
    
    synthBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    synthBuffer.clear();
    
    oscOneBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    oscOneBuffer.clear();
    
    oscTwoBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    oscTwoBuffer.clear();
    
    oscOne.process (oscOneBuffer);
    oscTwo.process (oscTwoBuffer);
    
    sumOscillators();
    
    adsr.applyEnvelopeToBuffer (synthBuffer, 0, synthBuffer.getNumSamples());
    
    for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
    {
        outputBuffer.addFrom (channel, startSample, synthBuffer, channel, 0, numSamples);
        
        if (!adsr.isActive())
            clearCurrentNote();
    }
}

void AmaranthVoice::sumOscillators()
{
    for (int channel = 0; channel < oscOneBuffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < oscOneBuffer.getNumSamples(); i++)
        {
            float one = oscOneBuffer.getSample (channel, i);
            float two = oscTwoBuffer.getSample (channel, i);
            
            float outSample = one + two;
            
            synthBuffer.setSample (channel, i, outSample);
        }
    }
}
