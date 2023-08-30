#include "FilterComponent.h"

FilterComponent::FilterComponent()
{
    
}

FilterComponent::~FilterComponent() {}

void FilterComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Filter", getLocalBounds(), juce::Justification::centred, 1);
}

void FilterComponent::resized() {}
