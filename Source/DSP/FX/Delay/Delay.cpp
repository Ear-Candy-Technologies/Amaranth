#include "Delay.h"

Delay::Delay() {}

Delay::~Delay() {}

void Delay::setSampleRate (float inSampleRate)
{
    mSampleRate = inSampleRate;
}

void Delay::updateParameter (float inTime, float inFeedback, float inDryWet)
{
    time     = inTime;
    feedback = inFeedback;
    drywet   = inDryWet;
}

void Delay::process (juce::AudioBuffer<float>& buffer)
{
    const float wet            = drywet;
    const float dry            = 1.0f - wet;
    const float feedbackMapped = juce::jmap (feedback, 0.0f, 1.0f, 0.0f, 0.95f);
    
    for (int channel = 0; channel < buffer.getNumChannels(); channel++)
    {
        for (int i = 0; i < buffer.getNumSamples(); i++)
        {
            // For modulated parameters it is better to use smoothness at sample level.
            // For other knob values it can be smoothed at block level
            
            // Delay starts here...
            const float sample = buffer.getSample (channel, i);
            
            // Parameter Smoothing
            mTimeSmoothed[channel] = mTimeSmoothed[channel] - 0.002f * (mTimeSmoothed[channel] - time);
            
            float delayTimeInSamples  = mTimeSmoothed[channel] * mSampleRate;
            const float delayedSample = getInterpolatedSample (channel, delayTimeInSamples);
            
            mBuffer[mDelayIndex[channel]]     = sample + (mFeedbackSample[channel] * feedbackMapped);
            mFeedbackSample[channel] = delayedSample;
            
            // Write again to the buffer and the to the DAW
            float outSample = (sample * dry) + (delayedSample * wet);
            
            buffer.setSample (channel, i, outSample);
            
            mDelayIndex[channel] += 1;
            
            if (mDelayIndex[channel] >= maxBufferSize)
                mDelayIndex[channel] -= maxBufferSize;
        }
    }
}

float Delay::getInterpolatedSample (int channel, float inDelayTimeInSamples)
{
    float readPosition = (float) mDelayIndex[channel] - inDelayTimeInSamples;
    
    if (readPosition < 0.0f)
        readPosition += maxBufferSize;
    
    int index_y0 = (int)readPosition - 1;
    if (index_y0 <= 0)
        index_y0 += maxBufferSize;
    
    int index_y1 = (int)readPosition;
    if (index_y1 > maxBufferSize)
        index_y1 -= maxBufferSize;
    
    const float sample_y0 = mBuffer[index_y0];
    const float sample_y1 = mBuffer[index_y1];
    const float timeDiff  = readPosition - (int)readPosition;
    
    float outSample = getLinearInterpolation (sample_y0, sample_y1, timeDiff);
    
    return outSample;
}
