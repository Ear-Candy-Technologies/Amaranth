#include "ADSRComponent.h"

ADSRComponent::ADSRComponent (AmaranthAudioProcessor& p) : processor (p)
{
    prepareSlider (attackSlider,  ID::ATTACK,  attackAttach);
    prepareSlider (decaySlider,   ID::DECAY,   decayAttach);
    prepareSlider (sustainSlider, ID::SUSTAIN, sustainAttach);
    prepareSlider (releaseSlider, ID::RELEASE, releaseAttach);
}

ADSRComponent::~ADSRComponent() {}

void ADSRComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (18.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 13, 13, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("ADSR", title, juce::Justification::left, 1);
}

void ADSRComponent::resized()
{
    attackSlider.setBoundsRelative   (0.0f,  0.0f, 0.25f, 1.0f);
    decaySlider.setBoundsRelative    (0.25f, 0.0f, 0.25f, 1.0f);
    sustainSlider.setBoundsRelative  (0.5f,  0.0f, 0.25f, 1.0f);
    releaseSlider.setBoundsRelative  (0.75f, 0.0f, 0.25f, 1.0f);
}

void ADSRComponent::prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach)
{
    slider.setSliderStyle  (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible      (slider);
    
    attach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, sliderID, slider);
}
