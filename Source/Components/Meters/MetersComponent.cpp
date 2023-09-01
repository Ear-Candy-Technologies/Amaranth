#include "MetersComponent.h"

MetersComponent::MetersComponent()
{
    
}

MetersComponent::~MetersComponent() {}

void MetersComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 0, 0, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Meters", title, juce::Justification::centred, 1);
}

void MetersComponent::resized() {}
