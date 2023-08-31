/*
  ==============================================================================

    DistortionComponent.h
    Created: 29 Aug 2023 7:36:23pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class DistortionComponent : public juce::Component
{
public:
    
    DistortionComponent();
    ~DistortionComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionComponent)
};
