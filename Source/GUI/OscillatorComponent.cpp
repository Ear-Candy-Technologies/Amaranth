/*
  ==============================================================================

    OscillatorComponent.cpp
    Created: 15 Jul 2022 12:18:34pm
    Author:  Rodolfo Ortiz

  ==============================================================================
*/

#include "OscillatorComponent.h"

OscillatorComponent::OscillatorComponent (AmaranthAudioProcessor& p) : processor(p)
{
    gainSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 50, 30);
    addAndMakeVisible (gainSlider);
    
    gainAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, GAIN_OSC_ID, gainSlider);
}

OscillatorComponent::~OscillatorComponent()
{
    
}

void OscillatorComponent::paint (juce::Graphics& g)
{
    
}

void OscillatorComponent::resized()
{
    gainSlider.setBoundsRelative (0.0f, 0.0f, 0.5f, 0.5f);
}
