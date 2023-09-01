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
    
    g.setFont        (20.0f);
    g.setColour      (juce::Colours::black);
    
    juce::Rectangle<int> title { 0, 0, getWidth(), (int) (getHeight() * 0.1f) };
    g.drawFittedText ("Reverb", title, juce::Justification::centred, 1);
}

void ReverbComponent::resized()
{
    roomSizeSlider.setBoundsRelative    (0.0f, 0.15f, 1.0f, 0.15f);
    //dampingSlider.setBoundsRelative     (0.0f, 0.36f, 1.0f, 0.15f);
    widthSlider.setBoundsRelative       (0.0f, 0.36f, 1.0f, 0.15f);
    feedbackSlider.setBoundsRelative    (0.0f, 0.58f, 1.0f, 0.15f);
    mixSlider.setBoundsRelative         (0.0f, 0.8f, 1.0f, 0.15f);
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
