#include "MetersComponent.h"

MetersComponent::MetersComponent (AmaranthAudioProcessor& p) : processor (p)
{
    addAndMakeVisible (audioVisualiserComponent);
    
    addAndMakeVisible (levelMeterL);
    levelMeterL.setValueFunction ({ [&] { return processor.levelMeterAnalyzer.getRMSValue(0); }});
     
    addAndMakeVisible (levelMeterR);
    levelMeterR.setValueFunction ({ [&] { return processor.levelMeterAnalyzer.getRMSValue(1); }});
    
    audioVisualiserComponent.setBufferSize (256);
    audioVisualiserComponent.setColours    (juce::Colours::darkviolet.contrasting(), juce::Colours::black);
    startTimerHz (60);
}

MetersComponent::~MetersComponent()
{
    stopTimer();
}

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
    audioVisualiserComponent.setBoundsRelative (0.05f, 0.125f, 0.89f, 0.2f);
    levelMeterL.setBoundsRelative (0.5f - 0.3f, 0.325f, 0.3f, 0.65f);
    levelMeterR.setBoundsRelative (0.5f, 0.325f, 0.3f, 0.65f);
}

void MetersComponent::timerCallback()
{
    audioVisualiserComponent.pushBuffer (processor.helperBuffer);
}
