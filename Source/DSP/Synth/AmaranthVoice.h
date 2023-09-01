#pragma once
#include <JuceHeader.h>

#include "../../Parameters/Parameters.h"
#include "../Oscillator/Oscillator.h"

class AmaranthVoice : public juce::SynthesiserVoice
{
public:
    
    AmaranthVoice (juce::AudioProcessorValueTreeState&);
    ~AmaranthVoice() override;
    
    bool canPlaySound (juce::SynthesiserSound *) override;
    
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    
    void stopNote (float velocity, bool allowTailOff) override;
    
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    void prepare (juce::dsp::ProcessSpec&);
    
    void updateParameters();
    
    void renderNextBlock (juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    
private:
    
    juce::AudioProcessorValueTreeState& apvts;

    Oscillator osc { apvts };

    juce::AudioBuffer<float> synthBuffer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthVoice)
};
