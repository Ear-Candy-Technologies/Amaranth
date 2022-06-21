#include "PluginProcessor.h"
#include "PluginEditor.h"

namespace Amaranth
{
    #include "./DSP/Synth/SynthSound.cpp"
    #include "./DSP/Synth/SynthVoice.cpp"
}

AmaranthAudioProcessor::AmaranthAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvt(*this, nullptr, Amaranth::PARAMETERS, createAPVT())
#endif
{
    prepareSynth();
}

AmaranthAudioProcessor::~AmaranthAudioProcessor() {}

void AmaranthAudioProcessor::prepareSynth()
{
    synth.addSound(new Amaranth::SynthSound());
    
    for (auto i = 0; i < 5; i++)
        synth.addVoice (new Amaranth::SynthVoice());
}

juce::AudioProcessorValueTreeState::ParameterLayout AmaranthAudioProcessor::createAPVT()
{
    juce::AudioProcessorValueTreeState::ParameterLayout params;
    
    
    
    return params;
}

const juce::String AmaranthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AmaranthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AmaranthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool AmaranthAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double AmaranthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AmaranthAudioProcessor::getNumPrograms()
{
    return 1;
}

int AmaranthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AmaranthAudioProcessor::setCurrentProgram ([[maybe_unused]] int index) {}

const juce::String AmaranthAudioProcessor::getProgramName ([[maybe_unused]] int index)
{
    return {};
}

void AmaranthAudioProcessor::changeProgramName ([[maybe_unused]] int index, [[maybe_unused]] const juce::String& newName) {}

void AmaranthAudioProcessor::prepareToPlay (double sampleRate, [[maybe_unused]] int samplesPerBlock)
{
    synth.setCurrentPlaybackSampleRate(sampleRate);
    
    for(int i = 0; i < synth.getNumVoices(); i++)
    {
        if(auto voice = dynamic_cast<Amaranth::SynthVoice*>(synth.getVoice(i)))
            voice->prepare(sampleRate, samplesPerBlock, getTotalNumInputChannels());
    }
}

void AmaranthAudioProcessor::releaseResources() {}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AmaranthAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif
    return true;
  #endif
}
#endif

void AmaranthAudioProcessor::processBlock ([[maybe_unused]] juce::AudioBuffer<float>& buffer, [[maybe_unused]] juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    // Update parameters
    for(int i = 0; i < synth.getNumVoices(); i++)
    {
        if(auto voice = dynamic_cast<Amaranth::SynthVoice*>(synth.getVoice(i)))
            voice->updateParameters(apvt);
    }
    
    // Synth DSP
    synth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

bool AmaranthAudioProcessor::hasEditor() const
{
    return true;
}

juce::AudioProcessorEditor* AmaranthAudioProcessor::createEditor()
{
    return new AmaranthAudioProcessorEditor (*this);
}

void AmaranthAudioProcessor::getStateInformation ([[maybe_unused]] juce::MemoryBlock& destData) {}

void AmaranthAudioProcessor::setStateInformation ([[maybe_unused]] const void* data, [[maybe_unused]] int sizeInBytes) {}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AmaranthAudioProcessor();
}
