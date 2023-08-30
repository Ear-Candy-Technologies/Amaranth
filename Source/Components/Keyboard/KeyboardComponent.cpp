#include "KeyboardComponent.h"

KeyboardComponent::KeyboardComponent (juce::MidiKeyboardState& keyState) : keyboardState(keyState)
{
    keyboardComponent.setMidiChannel (1);
    addAndMakeVisible (keyboardComponent);
    
    startTimer (400);
}

KeyboardComponent::~KeyboardComponent() {}

void KeyboardComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::red);
}

void KeyboardComponent::resized()
{
    keyboardComponent.setBoundsRelative (0.0f, 0.0f, 1.0f, 1.0f);
}

void KeyboardComponent::timerCallback()
{
    keyboardComponent.grabKeyboardFocus();
    stopTimer();
}
