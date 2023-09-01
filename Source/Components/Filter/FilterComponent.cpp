#include "FilterComponent.h"

FilterComponent::FilterComponent()
{
    
}

FilterComponent::~FilterComponent() {}

void FilterComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (18.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 13, 13, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Filter", title, juce::Justification::left, 1);
}

void FilterComponent::resized() {}
