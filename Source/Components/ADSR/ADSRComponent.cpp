#include "ADSRComponent.h"

ADSRComponent::ADSRComponent()
{
    
}

ADSRComponent::~ADSRComponent() {}

void ADSRComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (18.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 13, 13, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Envelope", title, juce::Justification::left, 1);
}

void ADSRComponent::resized() {}
