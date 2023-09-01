#include "DelayComponent.h"

DelayComponent::DelayComponent()
{
    
}

DelayComponent::~DelayComponent() {}

void DelayComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (20.0f);
    g.setColour      (juce::Colours::black);

    juce::Rectangle<int> title { 0, 0, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Delay", title, juce::Justification::centred, 1);
}

void DelayComponent::resized() {}
