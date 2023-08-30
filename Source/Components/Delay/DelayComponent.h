/*
  ==============================================================================

    DelayComponent.h
    Created: 29 Aug 2023 7:36:10pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class DelayComponent : public juce::Component
{
public:
    
    DelayComponent();
    ~DelayComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayComponent)
};
