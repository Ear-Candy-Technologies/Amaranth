#include "MasterComponent.h"

MasterComponent::MasterComponent (AmaranthAudioProcessor& p) : processor (p)
{
    masterSlider.setSliderStyle  (juce::Slider::SliderStyle::LinearBar);
    masterSlider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible            (masterSlider);
    
    masterAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, ID::MASTER, masterSlider);
}

MasterComponent::~MasterComponent() {}

void MasterComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
}

void MasterComponent::resized()
{
    masterSlider.setBoundsRelative (0.025f, 0.15f, 0.925f, 0.7f);
}
