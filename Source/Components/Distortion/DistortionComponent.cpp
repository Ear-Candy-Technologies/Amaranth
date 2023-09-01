#include "DistortionComponent.h"

DistortionComponent::DistortionComponent (AmaranthAudioProcessor& p) : processor (p)
{
    prepareSlider (inputSlider,  ID::FX_DEL_TIME,        inputAttach, inputLabel, "Input");
    prepareSlider (driveSlider,  ID::FX_DEL_FEEDBACK,    driveAttach, driveLabel, "Drive");
    prepareSlider (toneSlider,   ID::FX_DEL_MIX,         toneAttach,  toneLabel,  "Tone");
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
    inputSlider.setBoundsRelative (0.0f, 0.22f, 1.0f, 0.15f);
    driveSlider.setBoundsRelative (0.0f, 0.47f, 1.0f, 0.15f);
    toneSlider.setBoundsRelative  (0.0f, 0.72f,  1.0f, 0.15f);
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
    
    //attach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, sliderID, slider);
}
