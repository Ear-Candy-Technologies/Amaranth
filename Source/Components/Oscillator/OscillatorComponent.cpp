#include "OscillatorComponent.h"

OscillatorComponent::OscillatorComponent (AmaranthAudioProcessor& p) : processor(p)
{
    gainSlider.setSliderStyle  (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 50, 30);
    addAndMakeVisible          (gainSlider);
    
    gainAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, ID::OSC_ONE_GAIN, gainSlider);
}

OscillatorComponent::~OscillatorComponent() {}

void OscillatorComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (25.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Oscillator", getLocalBounds(), juce::Justification::centred, 1);
}

void OscillatorComponent::resized()
{
    //gainSlider.setBoundsRelative (0.0f, 0.075f, 0.5f, 0.8f);
}
