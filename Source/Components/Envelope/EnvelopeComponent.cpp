#include "EnvelopeComponent.h"

EnvelopeComponent::EnvelopeComponent()
{
    
}

EnvelopeComponent::~EnvelopeComponent() {}

void EnvelopeComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Envelope", getLocalBounds(), juce::Justification::centred, 1);
}

void EnvelopeComponent::resized() {}
