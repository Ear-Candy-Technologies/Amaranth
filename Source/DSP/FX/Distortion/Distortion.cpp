/*
  ==============================================================================

    Distortion.cpp
    Created: 1 Sep 2023 3:17:40pm
    Author:  Fernando Garcia

  ==============================================================================
*/

#include "Distortion.h"
Distortion::Distortion() {}
Distortion::~Distortion() {}

void Distortion::setDrive (float inDrive) {drive = inDrive;}
void Distortion::setMix (float inMix) {mix = inMix;}
void Distortion::setDistortionIndex (int inDistortionIndex) {distortionIndex = inDistortionIndex;}

float Distortion::softClipping (float inSample)
{
    float gainSample = drive * inSample;
    return (gainSample) - ( powf(gainSample, 3.0f) / 3.0f) ;
}

float Distortion::hardClipping (float inSample)
{
    float threshold = 0.55f;
    float gainSample = drive * inSample;
    
    if (gainSample > threshold)
    {
        return threshold;
    }
    
    if (gainSample < -threshold)
    {
        return -threshold;
    }
    
    return gainSample;
}

float Distortion::bitCrusher(float inSample)
{
    int BitDepth = 4;
    int max = (int)powf(2, BitDepth) - 1;
    double bitCrushSample = round((inSample + 1.0) * max) / max - 1.0f;
    return (float)bitCrushSample;
}

void Distortion::processDryWet (juce::AudioBuffer<float>& inDryBuffer,
                                juce::AudioBuffer<float>& inWetBuffer)
{
    for (int channel = 0; channel < inDryBuffer.getNumChannels(); ++channel)
    {
        for (int i = 0; i < inDryBuffer.getNumSamples(); i++)
        {
            float wet = inWetBuffer.getSample (channel, i);
            float dry = inDryBuffer.getSample (channel, i);
            float out = dry * (1.0f - mix) + (mix * wet);
            
            inWetBuffer.setSample (channel, i, out);
        }
    }
}

void Distortion::process (juce::AudioBuffer<float> &buffer)
{
    dryBuffer.makeCopyOf (buffer);
    for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < buffer.getNumSamples();  i++)
        {
            auto sample = buffer.getSample (channel, i);
            float processedSample;
            
            switch (distortionIndex)
            {
                case 0:
                    processedSample = softClipping (sample);
                    break;
                
                case 1:
                    processedSample = hardClipping (sample);
                    break;
                    
                case 2:
                    processedSample = bitCrusher (sample);
                    break;
                    
                default:
                    processedSample = sample;
                    break;
            }
            
            buffer.setSample (channel, i, processedSample);
        }
    }
    processDryWet(dryBuffer, buffer);
}
