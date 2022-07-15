/*
  ==============================================================================

    MainComponent.cpp
    Created: 15 Jul 2022 11:54:57am
    Author:  Rodolfo Ortiz

  ==============================================================================
*/

#include "MainComponent.h"

MainComponent::MainComponent(AmaranthAudioProcessor& p) : processor(p)
{
    addAndMakeVisible (oscillator_1);
}

MainComponent::~MainComponent()
{
    
}

void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colours::dimgrey);

    g.setFont (25.0f);
    g.setColour (juce::Colours::white);
    g.drawFittedText ("Amaranth", getLocalBounds(), juce::Justification::centred, 1);
}

void MainComponent::resized()
{
    oscillator_1.setBoundsRelative (0.0f, 0.0f, 0.2f, 0.3f);
}
