#pragma once

#include <JuceHeader.h>

#include "./Helpers/ParamsHelper.h"
#include "./DSP/Synth/SynthSound.h"
#include "./DSP/Synth/SynthVoice.h"

class AmaranthAudioProcessor  : public juce::AudioProcessor
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
    
    // Prepare Synth
    void prepareSynth();
    
    // Audio Parameters APVTS
    juce::AudioProcessorValueTreeState apvt;
    juce::AudioProcessorValueTreeState::ParameterLayout createAPVT();

private:
    
    // Global synth class
    juce::Synthesiser synth;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmaranthAudioProcessor)
};
