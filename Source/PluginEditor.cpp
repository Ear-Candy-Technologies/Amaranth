
#include "PluginProcessor.h"
#include "PluginEditor.h"

AmaranthAudioProcessorEditor::AmaranthAudioProcessorEditor (AmaranthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible (mainComponent);
    
    setSize (600, 400);
}

AmaranthAudioProcessorEditor::~AmaranthAudioProcessorEditor() {}

void AmaranthAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void AmaranthAudioProcessorEditor::resized()
{
    mainComponent.setBounds (getLocalBounds());
}
