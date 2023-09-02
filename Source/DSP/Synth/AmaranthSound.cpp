#include "AmaranthSound.h"

AmaranthSound::AmaranthSound() {}
AmaranthSound::~AmaranthSound() {}

bool AmaranthSound::appliesToNote ([[maybe_unused]] int midiNoteNumber)
{
    return true;
}

bool AmaranthSound::appliesToChannel ([[maybe_unused]] int midiChannel)
{
    return true;
}
