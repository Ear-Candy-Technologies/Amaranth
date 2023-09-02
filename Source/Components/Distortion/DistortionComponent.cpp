#include "DistortionComponent.h"

DistortionComponent::DistortionComponent (AmaranthAudioProcessor& p) : processor (p)
{
    prepareSlider (typeSlider,  ID::FX_DST_TYPE,   typeAttach, typeLabel, "Type");
    prepareSlider (driveSlider,  ID::FX_DST_DRIVE,  driveAttach, driveLabel, "Drive");
    prepareSlider (mixSlider,   ID::FX_DST_MIX,    mixAttach,  mixLabel,  "Mix");
}

DistortionComponent::~DistortionComponent() {}

void DistortionComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (20.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 0, 0, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Distortion", title, juce::Justification::centred, 1);
}

void DistortionComponent::resized()
{
    typeSlider.setBoundsRelative (0.0f, 0.22f, 1.0f, 0.15f);
    driveSlider.setBoundsRelative (0.0f, 0.47f, 1.0f, 0.15f);
    mixSlider.setBoundsRelative  (0.0f, 0.72f,  1.0f, 0.15f);
}

void DistortionComponent::prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
                                         juce::Label& label, juce::String labelText)
{
    slider.setSliderStyle  (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible      (slider);
    
    label.setJustificationType  (juce::Justification::centred);
    label.setText               (labelText, juce::dontSendNotification);
    label.attachToComponent     (&slider, false);
    label.setColour             (juce::Label::ColourIds::textColourId, juce::Colours::black);
    addAndMakeVisible           (label);
    
    attach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, sliderID, slider);
}
