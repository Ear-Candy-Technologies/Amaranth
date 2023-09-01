#include "OscillatorComponent.h"

OscillatorComponent::OscillatorComponent (AmaranthAudioProcessor& p, ID::Oscillator inNumOSC) : processor(p), currentOscillator (inNumOSC)
{
    prepareSlider (gainSlider,   getOscillatorID (ID::OscillatorSection::Gain),  gainAttach, gainLabel, "Gain");
    prepareSlider (panSlider,    getOscillatorID (ID::OscillatorSection::Pan),    panAttach, panLabel, "Pan");
    prepareSlider (detuneSlider, getOscillatorID (ID::OscillatorSection::Detune), detuneAttach, detuneLabel, "Detune");
    prepareSlider (widthSlider,  getOscillatorID (ID::OscillatorSection::Width),  widthAttach, widthLabel, "Width");
}

OscillatorComponent::~OscillatorComponent() {}

void OscillatorComponent::paint (juce::Graphics& g)
{
    g.fillAll              (juce::Colours::darkviolet.contrasting());
    g.drawRoundedRectangle (5, 5, getWidth() - 10, getHeight() - 10, 10, 1);
    
    g.setFont      (18.0f);
    g.addTransform (juce::AffineTransform::rotation (-juce::MathConstants<float>::halfPi, getWidth() * 0.5f, getHeight() * 0.5f));
    g.drawText     ("Oscillator", 5, - getWidth()/2 + 20, getWidth(), getHeight(), juce::Justification::centred);
}

void OscillatorComponent::resized()
{
    gainSlider.setBoundsRelative   (0.075f,  0.275f, 0.225f, 0.6f);
    panSlider.setBoundsRelative    (0.3f,    0.275f, 0.225f, 0.6f);
    detuneSlider.setBoundsRelative (0.54f,  0.275f, 0.225f, 0.6f);
    widthSlider.setBoundsRelative  (0.775f,  0.275f, 0.225f, 0.6f);
}

void OscillatorComponent::prepareSlider (juce::Slider& slider, juce::String sliderID, std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>& attach,
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
        }
    }
    
    return finalID;
}
