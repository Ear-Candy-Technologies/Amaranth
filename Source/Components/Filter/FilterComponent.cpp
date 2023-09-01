#include "FilterComponent.h"

FilterComponent::FilterComponent (AmaranthAudioProcessor& p) : processor (p)
{
    prepareSlider (highpassSlider, ID::FILTER_HIGHPASS, highpassAttach, highpassLabel, "HPF");
    prepareSlider (lowpassSlider,  ID::FILTER_LOWPASS,  lowpassAttach,  lowpassLabel,  "LPF");
}

FilterComponent::~FilterComponent() {}

void FilterComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (18.0f);
    g.setColour      (juce::Colours::black);
    
    g.setFont      (18.0f);
    g.addTransform (juce::AffineTransform::rotation (-juce::MathConstants<float>::halfPi, getWidth() * 0.5f, getHeight() * 0.5f));
    g.drawText     ("Filter", 5, - getWidth()/2 + 20, getWidth(), getHeight(), juce::Justification::centred);
}

void FilterComponent::resized()
{
    highpassSlider.setBoundsRelative (0.2f, 0.275f, 0.225f, 0.6f);
    lowpassSlider.setBoundsRelative  (0.6f, 0.275f, 0.225f, 0.6f);
}

void FilterComponent::prepareSlider (juce::Slider& slider, juce::String sliderID,
                                   std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
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
