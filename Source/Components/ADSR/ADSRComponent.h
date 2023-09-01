/*
  ==============================================================================

    EnvelopeComponent.h
    Created: 29 Aug 2023 7:29:54pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class ADSRComponent : public juce::Component
{
public:
    
    ADSRComponent();
    ~ADSRComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
