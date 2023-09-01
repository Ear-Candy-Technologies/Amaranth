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
    osc.setFreq (frequency);
    osc.startNote();
}

void AmaranthVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
    osc.stopNote();
    
    if (!allowTailOff || !osc.getIsActive())
        clearCurrentNote();
}

void AmaranthVoice::controllerMoved (int /*controllerNumber*/, int /*newControllerValue*/) {}

void AmaranthVoice::pitchWheelMoved (int /*newPitchWheelValue*/) {}

void AmaranthVoice::prepare (juce::dsp::ProcessSpec& spec)
{    
    osc.prepareOscillator (spec);
}

void AmaranthVoice::updateParameters()
{
    osc.updateParameters();
}

void AmaranthVoice::renderNextBlock (juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
    if (!isVoiceActive())
        return;
    
    synthBuffer.setSize (outputBuffer.getNumChannels(), numSamples, false, false, true);
    synthBuffer.clear();
    
    juce::dsp::AudioBlock<float> audioBlock { synthBuffer };
    juce::dsp::ProcessContextReplacing<float> context (audioBlock);
    
    osc.processOscillator (context, synthBuffer);
    
    for (int channel = 0; channel < outputBuffer.getNumChannels(); channel++)
    {
        outputBuffer.addFrom (channel, startSample, synthBuffer, channel, 0, numSamples);
        
        if (!osc.getIsActive())
            clearCurrentNote();
    }
}
