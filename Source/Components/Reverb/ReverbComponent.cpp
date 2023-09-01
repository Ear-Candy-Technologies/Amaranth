#include "ReverbComponent.h"

void ReverbComponent::addSlider()
{
    addAndMakeVisible (roomSizeLabel);
    // sliders
    roomSizeAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(processor.apvts, ID::FX_RB_ROOM_SIZE, roomSizeSlider);
    roomSizeSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    roomSizeSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    //roomSizeSlider.setLookAndFeel(&lookAndFeel);
    addAndMakeVisible(roomSizeSlider);
}

ReverbComponent::ReverbComponent(AmaranthAudioProcessor& p): processor(p)
{
    addSlider();
}

ReverbComponent::~ReverbComponent()
{
    roomSizeSlider.setLookAndFeel (nullptr);
}

void ReverbComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (20.0f);
    g.setColour      (juce::Colours::black);
    g.drawFittedText ("Reverb", getLocalBounds(), juce::Justification::centred, 1);
}

void ReverbComponent::resized()
{
    float bigDiameter = 0.475f;
    roomSizeSlider.setBoundsRelative(0.50f - bigDiameter   /2, 0.3f - bigDiameter   /2, bigDiameter,   bigDiameter);
}
