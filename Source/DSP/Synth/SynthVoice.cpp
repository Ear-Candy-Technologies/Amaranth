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

void SynthVoice::startNote ([[maybe_unused]] int midiNoteNumber,
                            [[maybe_unused]] float velocity,
                            [[maybe_unused]] juce::SynthesiserSound *sound,
                            [[maybe_unused]] int currentPitchWheelPosition)
{
    
}

void SynthVoice::stopNote ([[maybe_unused]] float velocity,
                           [[maybe_unused]] bool allowTailOff)
{
    
}

void SynthVoice::controllerMoved ([[maybe_unused]] int controllerNumber, [[maybe_unused]] int newControllerValue) {}

void SynthVoice::pitchWheelMoved ([[maybe_unused]] int newPitchWheelValue) {}

void SynthVoice::prepare ([[maybe_unused]]  double inSampleRate,
                          [[maybe_unused]]  int inSamplesPerBlock,
                          [[maybe_unused]]  int inNumChannels)
{
    
}

void SynthVoice::updateParameters([[maybe_unused]] juce::AudioProcessorValueTreeState& apvt)
{
    
}

void SynthVoice::renderNextBlock ([[maybe_unused]] juce::AudioBuffer<float>& outputBuffer,
                                  [[maybe_unused]] int startSample,
                                  [[maybe_unused]] int numSamples)
{
    
}
