#include "HeaderComponent.h"

HeaderComponent::HeaderComponent (AmaranthAudioProcessor& p) : processor(p)
{
    
}

HeaderComponent::~HeaderComponent() {}

void HeaderComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::black);

    g.setFont        (25.0f);
    g.setColour      (juce::Colours::white);
    g.drawFittedText ("Header", getLocalBounds(), juce::Justification::centred, 1);
}

void HeaderComponent::resized() {}
