#include "HeaderComponent.h"

HeaderComponent::HeaderComponent (AmaranthAudioProcessor& p) : processor(p) {}

HeaderComponent::~HeaderComponent() {}

void HeaderComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Amaranth", getLocalBounds().reduced (20, 0), juce::Justification::left, 1);
    
    g.setFont (12.0f);
    juce::Rectangle<int> version { -10, (int) (getHeight() * 0.73f) , getWidth(), (int) (getHeight() * 0.1f) };
    g.drawText ("Version: " + (juce::String) JucePlugin_VersionString, version, juce::Justification::right);
    
}

void HeaderComponent::resized() {}
