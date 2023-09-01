#include "Oscillator.h"

Oscillator::Oscillator (juce::AudioProcessorValueTreeState& inApvts, ID::Oscillator inOscillatorID) : oscillatorID (inOscillatorID), apvts (inApvts)
{
    switch (oscillatorID)
    {
        case ID::Oscillator::One:
            ids = ID::OSC_ONE;
            break;
            
        case ID::Oscillator::Two:
            ids = ID::OSC_TWO;
            break;
    };
}

Oscillator::~Oscillator() {}

void Oscillator::prepare (juce::dsp::ProcessSpec inSpec,  const std::function<float(float)> inFunction)
{
    setFunction (inFunction);
    
    osc.prepare  (inSpec);
    gain.prepare (inSpec);
}

void Oscillator::updateParameters()
{
    setGain  (*apvts.getRawParameterValue(ids[ID::OscillatorSection::Gain]));
    setPan   (*apvts.getRawParameterValue(ids[ID::OscillatorSection::Pan]));
    setWidth (*apvts.getRawParameterValue(ids[ID::OscillatorSection::Width]));
}

void Oscillator::process (juce::AudioBuffer<float>& buffer)
{
    juce::dsp::AudioBlock<float> audioBlock { buffer };
    juce::dsp::ProcessContextReplacing<float> context (audioBlock);
    
    osc.process         (context);
    gain.process        (context);
    pan.process         (buffer, parameters.pan);
    stereoWidth.process (buffer, parameters.width);
}

void Oscillator::setFunction (const std::function<float(float)>& inFunction)
{
    parameters.function = inFunction;
    osc.initialise (parameters.function);
}

void Oscillator::setFreq (float inFreq)
{
    parameters.freq = inFreq;
    
    float detune = 0.0f;
    
    switch (oscillatorID)
    {
        case ID::Oscillator::One:
            detune = (1 - detuneRelations[0]) * *apvts.getRawParameterValue(ids[ID::OscillatorSection::Detune]);
            break;
            
        case ID::Oscillator::Two:
            detune = (1 - detuneRelations[1]) * *apvts.getRawParameterValue(ids[ID::OscillatorSection::Detune]);
            break;
    };
    
    detune *= parameters.freq;
    parameters.freq += detune;
    
    osc.setFrequency (parameters.freq);
}

void Oscillator::setGain (float inGain)
{
    parameters.gain = inGain;
    gain.setGainDecibels (parameters.gain);
}

void Oscillator::setPan (float inPan)
{
    parameters.pan = inPan;
}

void Oscillator::setWidth (float inWidth)
{
    parameters.width = inWidth;
}
