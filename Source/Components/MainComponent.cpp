#include "MainComponent.h"

MainComponent::MainComponent (AmaranthAudioProcessor& p) : processor(p)
{
    addAndMakeVisible (headerComponent);
    
    addAndMakeVisible (oscillator_1);
    addAndMakeVisible (oscillator_2);
    addAndMakeVisible (filterComponent);
    addAndMakeVisible (envelopeComponent);
    
    addAndMakeVisible (distortionComponent);
    addAndMakeVisible (reverbComponent);
    addAndMakeVisible (delayComponent);
    
    addAndMakeVisible (metersComponent);
    addAndMakeVisible (keyboardComponent);
    
    setLookAndFeel (&filmStripKnob);
}

MainComponent::~MainComponent()
{
    setLookAndFeel (nullptr);
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll        (juce::Colours::darkviolet);
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::white);
    g.drawFittedText ("Amaranth", getLocalBounds(), juce::Justification::centred, 1);
}

void MainComponent::resized()
{
    headerComponent.setBoundsRelative   (Sizes::headerBounds);
    
    oscillator_1.setBoundsRelative      (Sizes::oscOnebounds);
    oscillator_2.setBoundsRelative      (Sizes::oscTwobounds);
    filterComponent.setBoundsRelative   (Sizes::filterBounds);
    envelopeComponent.setBoundsRelative (Sizes::envelopeBounds);
    
    distortionComponent.setBoundsRelative (Sizes::distortionBounds);
    reverbComponent.setBoundsRelative     (Sizes::reverbBounds);
    delayComponent.setBoundsRelative      (Sizes::delayBounds);
    
    metersComponent.setBoundsRelative   (Sizes::metersBounds);
    keyboardComponent.setBoundsRelative (Sizes::keyboardBounds);
}
