#pragma once

#include <JuceHeader.h>

#include "Parameters/Parameters.h"
#include "Helpers/Globals.h"

#include "DSP/Synth/AmaranthSound.h"
#include "DSP/Synth/AmaranthVoice.h"

#include "DSP/FX/Reverb/Reverb.h"
#include "DSP/FX/Delay/Delay.h"

class AmaranthAudioProcessor : public juce::AudioProcessor
{
public:
    
    AmaranthAudioProcessor();
    ~AmaranthAudioProcessor() override;
    
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif
    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;
    const juce::String getName() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    void prepareSynth();
    void updateParameters();
    
    /** Audio Parameters */
    juce::AudioProcessorValueTreeState apvts;
    
    /** Keyboard state */
    juce::MidiKeyboardState keyboardState;

private:
    
    juce::Synthesiser synth;
    
    // FX stage
    Reverb reverb;
    Delay delay;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthAudioProcessor)
};
