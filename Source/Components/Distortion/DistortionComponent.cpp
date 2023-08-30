#include "DistortionComponent.h"

DistortionComponent::DistortionComponent()
{
    
}

DistortionComponent::~DistortionComponent() {}

void DistortionComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (20.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Distortion", getLocalBounds(), juce::Justification::centred, 1);
}

void DistortionComponent::resized() {}
