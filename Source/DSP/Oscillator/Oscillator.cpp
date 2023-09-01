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
    //setFunction ( [](float x) { return x * 2.0f - 1.0f; });
    
    osc.prepare  (inSpec);
    gain.prepare (inSpec);
}

void Oscillator::updateParameters()
{
    setGain (*apvts.getRawParameterValue(ids[ID::OscillatorSection::Gain]));
    setPan  (*apvts.getRawParameterValue(ids[ID::OscillatorSection::Pan]));
}

/*void Oscillator::processOscillator (juce::dsp::ProcessContextReplacing<float>& inContext, juce::AudioBuffer<float>& synthBuffer)
{
    process      (inContext);
    gain.process (inContext);
    pan.process  (synthBuffer, parameters.pan);
}*/

void Oscillator::process (juce::AudioBuffer<float>& buffer)
{
    /*for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < buffer.getNumSamples(); i++)
        {
            float sample    = buffer.getSample (channel, i);
            float funcValue = parameters.function (sample);
            float outSample = 0.0f;
            
            // Updating x
            fase[channel] += parameters.freq * (1.0f / samplerate);
            
            // Moving x
            if (fase[channel] >= 1.0f)
                fase[channel] = 0.0f;
            
            // Sum values
            outSample = sample + funcValue;
            
            buffer.setSample (channel, i, outSample);
        }
    }*/
    
    /*for (auto channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < buffer.getNumSamples(); i++)
        {
            auto sample    = buffer.getSample (channel, i);
            auto outSample = osc.processSample (sample);
            buffer.setSample (channel, i, outSample);
        }
    }*/
    
    juce::dsp::AudioBlock<float> audioBlock { buffer };
    juce::dsp::ProcessContextReplacing<float> context (audioBlock);
    
    osc.process  (context);
    gain.process (context);
    pan.process  (buffer, parameters.pan);
}

void Oscillator::setFunction (const std::function<float(float)>& inFunction)
{
    parameters.function = inFunction;
    osc.initialise (parameters.function);
}

void Oscillator::setFreq (float inFreq)
{
    parameters.freq = inFreq;
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

/*float synth_OSC::funcValue (int inTypeWave)
{
    float funcValue = 0.0f;
    
    switch(inTypeWave)
    {
        case 0:
            funcValue = sin(2.0f * pi * fase);
            break;
        case 1:
            funcValue = (2.0f / pi) * asin(sin(2.0f * pi * fase));
            break;
        case 2:
            if (fase <= 0.5f)
                funcValue = 1.0f;
            else
                funcValue = -1.0f;
    }
    
    return funcValue;
}*/
