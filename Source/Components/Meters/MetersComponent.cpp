#include "MetersComponent.h"

MetersComponent::MetersComponent (AmaranthAudioProcessor& p) : processor (p)
{
    addAndMakeVisible (levelMeterL);
    levelMeterL.setValueFunction ({ [&] { return processor.levelMeterAnalyzer.getRMSValue(0); }});
     
    addAndMakeVisible (levelMeterR);
    levelMeterR.setValueFunction ({ [&] { return processor.levelMeterAnalyzer.getRMSValue(1); }});
}

MetersComponent::~MetersComponent() {}

void MetersComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (20.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 0, 0, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Meters", title, juce::Justification::centred, 1);
}

void MetersComponent::resized()
{
    levelMeterL.setBoundsRelative (0.5f - 0.3f, 0.15f, 0.3f, 0.8f);
    levelMeterR.setBoundsRelative (0.5f, 0.15f, 0.3f, 0.8f);
}
