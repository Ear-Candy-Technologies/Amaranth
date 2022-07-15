/*
  ==============================================================================

    MainComponent.h
    Created: 15 Jul 2022 11:54:57am
    Author:  Rodolfo Ortiz

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class MainComponent : public juce::Component
{
public:
    MainComponent();
    ~MainComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
