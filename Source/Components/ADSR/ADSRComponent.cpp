#include "ADSRComponent.h"

ADSRComponent::ADSRComponent (AmaranthAudioProcessor& p) : processor (p)
{
    prepareSlider (attackSlider,  ID::ATTACK,  attackAttach, attackLabel, "Attack");
    prepareSlider (decaySlider,   ID::DECAY,   decayAttach, decayLabel, "Decay");
    prepareSlider (sustainSlider, ID::SUSTAIN, sustainAttach, sustainLabel, "Sustain");
    prepareSlider (releaseSlider, ID::RELEASE, releaseAttach, releaseLabel, "Release");
}

ADSRComponent::~ADSRComponent() {}

void ADSRComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont        (18.0f);
    g.setColour      (juce::Colours::black);
    
    g.setFont      (18.0f);
    g.addTransform (juce::AffineTransform::rotation (-juce::MathConstants<float>::halfPi, getWidth() * 0.5f, getHeight() * 0.5f));
    g.drawText     ("ADSR", 5, - getWidth()/2 + 20, getWidth(), getHeight(), juce::Justification::centred);
}

void ADSRComponent::resized()
{
    attackSlider.setBoundsRelative   (0.075f,  0.275f, 0.225f, 0.6f);
    decaySlider.setBoundsRelative    (0.3f,    0.275f, 0.225f, 0.6f);
    sustainSlider.setBoundsRelative  (0.54f,  0.275f, 0.225f, 0.6f);
    releaseSlider.setBoundsRelative  (0.775f,  0.275f, 0.225f, 0.6f);
}

void ADSRComponent::prepareSlider (juce::Slider& slider, juce::String sliderID,
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
