#pragma once

#include <JuceHeader.h>
#include "Header/HeaderComponent.h"
#include "Master/MasterComponent.h"
#include "Oscillator/OscillatorComponent.h"
#include "Filter/FilterComponent.h"
#include "ADSR/ADSRComponent.h"
#include "Delay/DelayComponent.h"
#include "Distortion/DistortionComponent.h"
#include "Reverb/ReverbComponent.h"
#include "Meters/MetersComponent.h"
#include "Keyboard/KeyboardComponent.h"

#include "../Helpers/Sizes.h"
#include "../PluginProcessor.h"

#include "../LookAndFeel/FilmStripKnob.h"

class MainComponent : public juce::Component
{
public:
    
    MainComponent (AmaranthAudioProcessor&);
    ~MainComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    AmaranthAudioProcessor& processor;
    
    HeaderComponent headerComponent { processor };
    MasterComponent masterComponent { processor };
    
    OscillatorComponent oscillator_1 { processor, ID::Oscillator::One };
    OscillatorComponent oscillator_2 { processor, ID::Oscillator::Two };
    FilterComponent filterComponent { processor };
    ADSRComponent envelopeComponent { processor };
    
    DistortionComponent distortionComponent  { processor };
    ReverbComponent reverbComponent          { processor };
    DelayComponent delayComponent            { processor };
    
    MetersComponent metersComponent     { processor };
    KeyboardComponent keyboardComponent { processor.keyboardState };
    
    const juce::Image knobImage = juce::ImageFileFormat::loadFrom (BinaryData::Clean_Small_BW_Knob_png, BinaryData::Clean_Small_BW_Knob_pngSize);
    FilmStripKnob filmStripKnob { knobImage };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
