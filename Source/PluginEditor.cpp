#include "PluginProcessor.h"
#include "PluginEditor.h"

AmaranthAudioProcessorEditor::AmaranthAudioProcessorEditor (AmaranthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize (600, 400);
}

AmaranthAudioProcessorEditor::~AmaranthAudioProcessorEditor() {}

void AmaranthAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(191, 41, 239));

    g.setFont(25.0f);
    g.setColour (juce::Colours::white);
    g.drawFittedText ("Amaranth", getLocalBounds(), juce::Justification::centred, 1);
}

void AmaranthAudioProcessorEditor::resized() {}
