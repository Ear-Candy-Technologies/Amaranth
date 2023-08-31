#include "PluginEditor.h"

AmaranthAudioProcessorEditor::AmaranthAudioProcessorEditor (AmaranthAudioProcessor& p) : AudioProcessorEditor (&p), audioProcessor (p)
{
    addAndMakeVisible (mainComponent);
    
    if (auto* constrainer = getConstrainer())
    {
        constrainer->setFixedAspectRatio ((double) (Sizes::MAIN_WIDTH / (double) (Sizes::MAIN_HEIGHT)));
        constrainer->setSizeLimits       ((int) (Sizes::MAIN_WIDTH * 0.8f), (int) (Sizes::MAIN_HEIGHT * 0.8f), Sizes::MAIN_WIDTH * 2, Sizes::MAIN_HEIGHT * 2);
    }
    
    setResizable (true, true);
    setSize      (Sizes::MAIN_WIDTH, Sizes::MAIN_HEIGHT);
}

AmaranthAudioProcessorEditor::~AmaranthAudioProcessorEditor() {}

void AmaranthAudioProcessorEditor::paint (juce::Graphics& ) {}

void AmaranthAudioProcessorEditor::resized()
{
    const auto scaleFactor = float (getWidth()) / Sizes::MAIN_WIDTH;
    mainComponent.setTransform (juce::AffineTransform::scale(scaleFactor));
    mainComponent.setBounds    (0, 0, Sizes::MAIN_WIDTH, Sizes::MAIN_HEIGHT);
}
