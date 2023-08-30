#pragma once
#include <JuceHeader.h>

#include "../../Parameters/Parameters.h"
#include "../Oscillator.h"

class AmaranthVoice : public juce::SynthesiserVoice
{
public:
    
    AmaranthVoice();
    ~AmaranthVoice() override;
    
    bool canPlaySound (juce::SynthesiserSound *) override;
    
    void startNote (int midiNoteNumber, float velocity, juce::SynthesiserSound *sound, int currentPitchWheelPosition) override;
    
    void stopNote (float velocity, bool allowTailOff) override;
    
    void controllerMoved (int controllerNumber, int newControllerValue) override;
    
    void pitchWheelMoved (int newPitchWheelValue) override;
    
    void prepare (double inSampleRate, int inSamplesPerBlock, int inNumChannels);
    
    void updateParameters (juce::AudioProcessorValueTreeState& apvt);
    
    void renderNextBlock (juce::AudioBuffer<float> &outputBuffer, int startSample, int numSamples) override;
    
private:

    Oscillator osc;

    juce::AudioBuffer<float> synthBuffer;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthVoice)
};
