#include "ReverbComponent.h"

ReverbComponent::ReverbComponent(AmaranthAudioProcessor& p): processor(p)
{
    prepareSlider (roomSizeSlider,  ID::FX_RB_ROOM_SIZE, roomSizeAttach,    roomSizeLabel,  "Room");
    prepareSlider (dampingSlider,   ID::FX_RB_DAMPING,   dampingAttach,     dampingLabel,   "Damping");
    prepareSlider (mixSlider,       ID::FX_RB_MIX,       mixAttach,         mixLabel,       "Mix");
    prepareSlider (widthSlider,     ID::FX_RB_WIDTH,     widthAttach,       widthLabel,     "Width");
    prepareSlider (feedbackSlider,  ID::FX_RB_FEEDBACK,  feedbackAttach,    feedbackLabel,  "Feedback");
}

ReverbComponent::~ReverbComponent()
{
    roomSizeSlider.setLookAndFeel (nullptr);
}

void ReverbComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
}

void ReverbComponent::resized()
{
    roomSizeSlider.setBoundsRelative    (0.0f, 0.06f, 1.0f, 0.125f);
    dampingSlider.setBoundsRelative     (0.0f, 0.25f, 1.0f, 0.125f);
    mixSlider.setBoundsRelative         (0.0f, 0.45f, 1.0f, 0.125f);
    widthSlider.setBoundsRelative       (0.0f, 0.65f, 1.0f, 0.125f);
    feedbackSlider.setBoundsRelative    (0.0f, 0.85f, 1.0f, 0.125f);
}

void ReverbComponent::prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
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
