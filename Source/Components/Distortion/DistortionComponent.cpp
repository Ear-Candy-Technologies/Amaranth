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
    
    juce::Rectangle<int> title { 0, 0, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Distortion", title, juce::Justification::centred, 1);
}

void DistortionComponent::resized() {}
