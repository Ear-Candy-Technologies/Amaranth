#include "OscillatorComponent.h"

OscillatorComponent::OscillatorComponent (AmaranthAudioProcessor& p, ID::Oscillator inNumOSC) : processor(p), currentOscillator (inNumOSC)
{
    prepareSlider (gainSlider,   getOscillatorID (ID::OscillatorSection::Gain),  gainAttach);
    prepareSlider (panSlider,    getOscillatorID (ID::OscillatorSection::Pan),    panAttach);
    prepareSlider (detuneSlider, getOscillatorID (ID::OscillatorSection::Detune), detuneAttach);
    prepareSlider (widthSlider,  getOscillatorID (ID::OscillatorSection::Width),  widthAttach);
    prepareSlider (phaseSlider,  getOscillatorID (ID::OscillatorSection::Phase),  phaseAttach);
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
    gainSlider.setBoundsRelative   (0.0f, 0.0f, 0.2f, 1.0f);
    panSlider.setBoundsRelative    (0.2f, 0.0f, 0.2f, 1.0f);
    detuneSlider.setBoundsRelative (0.4f, 0.0f, 0.2f, 1.0f);
    widthSlider.setBoundsRelative  (0.6f, 0.0f, 0.2f, 1.0f);
    phaseSlider.setBoundsRelative  (0.8f, 0.0f, 0.2f, 1.0f);
}

void OscillatorComponent::prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach)
{
    slider.setSliderStyle  (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    slider.setTextBoxStyle (juce::Slider::TextEntryBoxPosition::NoTextBox, false, 0, 0);
    addAndMakeVisible      (slider);
    
    attach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment> (processor.apvts, sliderID, slider);
}

juce::String OscillatorComponent::getOscillatorID (ID::OscillatorSection oscillatorSection)
{
    juce::String finalID;
    
    if (currentOscillator == ID::Oscillator::One)
    {
        switch (oscillatorSection)
        {
            case ID::OscillatorSection::Gain:
                finalID = ID::OSC_ONE_GAIN;
                break;
                
            case ID::OscillatorSection::Pan:
                finalID = ID::OSC_ONE_PAN;
                break;
                
            case ID::OscillatorSection::Detune:
                finalID = ID::OSC_ONE_DETUNE;
                break;
                
            case ID::OscillatorSection::Width:
                finalID = ID::OSC_ONE_WIDTH;
                break;
                
            case ID::OscillatorSection::Phase:
                finalID = ID::OSC_ONE_PHASE;
                break;
        }
    }
    
    else
    {
        switch (oscillatorSection)
        {
            case ID::OscillatorSection::Gain:
                finalID = ID::OSC_TWO_GAIN;
                break;
                
            case ID::OscillatorSection::Pan:
                finalID = ID::OSC_TWO_PAN;
                break;
                
            case ID::OscillatorSection::Detune:
                finalID = ID::OSC_TWO_DETUNE;
                break;
                
            case ID::OscillatorSection::Width:
                finalID = ID::OSC_TWO_WIDTH;
                break;
                
            case ID::OscillatorSection::Phase:
                finalID = ID::OSC_TWO_PHASE;
                break;
        }
    }
    
    return finalID;
}
