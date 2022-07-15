/*
  ==============================================================================

    SynthVoice.cpp
    Created: 20 Jun 2022 10:14:54pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#include "SynthVoice.h"

SynthVoice::SynthVoice() {}

SynthVoice::~SynthVoice() {}

bool SynthVoice::canPlaySound (juce::SynthesiserSound* sound)
{
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;
}

void SynthVoice::startNote (int midiNoteNumber,
                            [[maybe_unused]] float velocity,
                            [[maybe_unused]] juce::SynthesiserSound *sound,
                            [[maybe_unused]] int currentPitchWheelPosition)
{
    auto frequency = static_cast<float>(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    osc.setOscFreq (frequency);
    osc.startNote();
}

void SynthVoice::stopNote ([[maybe_unused]] float velocity, bool allowTailOff)
{
    osc.stopNote();
    
    if(!allowTailOff || !osc.getIsActive())
        clearCurrentNote();
}

void SynthVoice::controllerMoved ([[maybe_unused]] int controllerNumber, [[maybe_unused]] int newControllerValue) {}

void SynthVoice::pitchWheelMoved ([[maybe_unused]] int newPitchWheelValue) {}

void SynthVoice::prepare (double inSampleRate, int inSamplesPerBlock, int inNumChannels)
{
    juce::dsp::ProcessSpec spec;
    spec.sampleRate = inSampleRate;
    spec.numChannels = static_cast<juce::uint32> (inNumChannels);
    spec.maximumBlockSize = static_cast<juce::uint32> (inSamplesPerBlock);
    
    osc.setOscFunction ( [](float x) { return std::sinf(x); } );
    osc.prepareOsc (spec);
}

void SynthVoice::updateParameters([[maybe_unused]] juce::AudioProcessorValueTreeState& apvt)
{
    auto oscGain = apvt.getRawParameterValue(GAIN_OSC_ID)->load();
    osc.updateParameters(oscGain, 0.8f, 0.8f, 1.0f, 1.5f);
}

void SynthVoice::renderNextBlock (juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    if(!isVoiceActive())
        return;
    
    synthBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    synthBuffer.clear();
    
    juce::dsp::AudioBlock<float> audioBlock { synthBuffer };
    juce::dsp::ProcessContextReplacing<float> context (audioBlock);
    
    osc.processOsc (context, synthBuffer);
    
    for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
    {
        outputBuffer.addFrom(channel, startSample, synthBuffer, channel, 0, numSamples);
        
        if(!osc.getIsActive())
            clearCurrentNote();
    }
}
