#pragma once
#include <JuceHeader.h>

#include "../../Parameters/Parameters.h"
#include "../Oscillator/Oscillator.h"
#include "../Filters/Filters.h"


class AmaranthVoice : public juce::SynthesiserVoice
{
public:
    
    AmaranthVoice (juce::AudioProcessorValueTreeState&);
    ~AmaranthVoice() override;
    
    bool canPlaySound (juce::SynthesiserSound*) override;
    
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    void updateOscillators (float currentFrequency);
    
    void stopNote (float velocity, bool allowTailOff) override;
    
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    void prepare (juce::dsp::ProcessSpec&);
    
    void updateParameters();
    
    void renderNextBlock (juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    
    void sumOscillators();
    
private:
    
    juce::AudioProcessorValueTreeState& apvts;

    Oscillator oscOne { apvts, ID::Oscillator::One };
    Oscillator oscTwo { apvts, ID::Oscillator::Two };

    juce::AudioBuffer<float> synthBuffer;
    
    juce::AudioBuffer<float> oscOneBuffer;
    juce::AudioBuffer<float> oscTwoBuffer;
    
    Filters filters;
    Filters::Parameters filterParameters;
    
    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthVoice)
};
