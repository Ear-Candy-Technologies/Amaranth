/*
  ==============================================================================

    SynthVoice.h
    Created: 20 Jun 2022 10:14:54pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../Helpers/ParamsHelper.h"
#include "../Oscillator.h"


class SynthVoice : public juce::SynthesiserVoice
{
    public:
        
        SynthVoice();
        
        ~SynthVoice() override;
        
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
    
};
