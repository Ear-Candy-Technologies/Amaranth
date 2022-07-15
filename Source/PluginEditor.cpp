
#include "PluginProcessor.h"
#include "PluginEditor.h"

AmaranthAudioProcessorEditor::AmaranthAudioProcessorEditor (AmaranthAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible (mainComponent);
    
    setSize (1100, 750);
}

AmaranthAudioProcessorEditor::~AmaranthAudioProcessorEditor() {}

void AmaranthAudioProcessorEditor::paint (juce::Graphics& g)
{

}

void AmaranthAudioProcessorEditor::resized()
{
    mainComponent.setBounds (getLocalBounds());
}
