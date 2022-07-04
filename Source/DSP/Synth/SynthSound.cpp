/*
  ==============================================================================

    SynthVoice.cpp
    Created: 20 Jun 2022 10:14:54pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#include "SynthSound.h"

SynthSound::SynthSound() {}

SynthSound::~SynthSound() {}

bool SynthSound::appliesToNote ([[maybe_unused]] int midiNoteNumber)
{
    return true;
}

bool SynthSound::appliesToChannel ([[maybe_unused]] int midiChannel)
{
    return true;
}
