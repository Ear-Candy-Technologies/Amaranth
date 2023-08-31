#include "HeaderComponent.h"

HeaderComponent::HeaderComponent (AmaranthAudioProcessor& p) : processor(p)
{
    
}

HeaderComponent::~HeaderComponent() {}

void HeaderComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Header", getLocalBounds(), juce::Justification::centred, 1);
}

void HeaderComponent::resized() {}
