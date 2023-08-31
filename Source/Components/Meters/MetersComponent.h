/*
  ==============================================================================

    MetersComponent.h
    Created: 29 Aug 2023 7:42:45pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class MetersComponent  : public juce::Component
{
public:
    
    MetersComponent();
    ~MetersComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MetersComponent)
};
