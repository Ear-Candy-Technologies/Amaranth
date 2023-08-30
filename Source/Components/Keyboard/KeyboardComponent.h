/*
  ==============================================================================

    KeyboardComponent.h
    Created: 28 Aug 2023 4:40:14pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "../../PluginProcessor.h"
 
class KeyboardComponent : public juce::Component, public juce::Timer
{
public:
    
    KeyboardComponent (juce::MidiKeyboardState&);
    ~KeyboardComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override;
    
private:
    
    juce::MidiKeyboardState& keyboardState;
    juce::MidiKeyboardComponent keyboardComponent { keyboardState, juce::MidiKeyboardComponent::horizontalKeyboard };

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (KeyboardComponent)
};
