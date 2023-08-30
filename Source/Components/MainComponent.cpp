#include "MainComponent.h"

MainComponent::MainComponent(AmaranthAudioProcessor& p) : processor(p)
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
}

MainComponent::~MainComponent() {}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll        (juce::Colours::darkviolet);
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::white);
    g.drawFittedText ("Amaranth", getLocalBounds(), juce::Justification::centred, 1);
}

void MainComponent::resized()
{
    headerComponent.setBoundsRelative   (0.0f, 0.0f, 1.0f, 0.1f);
    
    oscillator_1.setBoundsRelative      (0.0f, 0.1f, 0.5f, 0.2f);
    oscillator_2.setBoundsRelative      (0.0f, 0.3f, 0.5f, 0.2f);
    filterComponent.setBoundsRelative   (0.0f, 0.5f, 0.5f, 0.2f);
    envelopeComponent.setBoundsRelative (0.0f, 0.7f, 0.5f, 0.2f);
    
    distortionComponent.setBoundsRelative (0.5f, 0.1f, 0.1f, 0.8f);
    reverbComponent.setBoundsRelative     (0.6f, 0.1f, 0.1f, 0.8f);
    delayComponent.setBoundsRelative      (0.7f, 0.1f, 0.1f, 0.8f);
    
    metersComponent.setBoundsRelative   (0.8f, 0.1f, 0.2f, 0.8f);
    keyboardComponent.setBoundsRelative (0.0f, 0.9f, 1.0f, 0.1f);
}
