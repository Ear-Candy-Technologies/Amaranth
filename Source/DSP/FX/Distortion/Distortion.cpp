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

void Distortion::setInput (float inInput) {input = inInput;}
void Distortion::setDrive (float inDrive) {drive = inDrive;}
void Distortion::setTone  (float inTone)  {tone = inTone;}
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
    float bitCrushSample = round((inSample + 1.0) * max) / max - 1.0;
    return bitCrushSample;
}
