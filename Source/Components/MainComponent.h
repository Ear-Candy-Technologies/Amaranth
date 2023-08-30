#pragma once

#include <JuceHeader.h>
#include "Header/HeaderComponent.h"
#include "Oscillator/OscillatorComponent.h"
#include "Filter/FilterComponent.h"
#include "Envelope/EnvelopeComponent.h"
#include "Delay/DelayComponent.h"
#include "Distortion/DistortionComponent.h"
#include "Reverb/ReverbComponent.h"
#include "Meters/MetersComponent.h"
#include "Keyboard/KeyboardComponent.h"

#include "../Helpers/Sizes.h"
#include "../PluginProcessor.h"

class MainComponent : public juce::Component
{
public:
    
    MainComponent (AmaranthAudioProcessor&);
    ~MainComponent() override;
    
    void paint (juce::Graphics&) override;
    void resized() override;
    
private:
    
    AmaranthAudioProcessor& processor;
    
    HeaderComponent headerComponent     { processor };
    
    OscillatorComponent oscillator_1    { processor };
    OscillatorComponent oscillator_2    { processor };
    FilterComponent filterComponent;
    EnvelopeComponent envelopeComponent;
    
    DistortionComponent distortionComponent;
    ReverbComponent reverbComponent;
    DelayComponent delayComponent;
    
    MetersComponent metersComponent;
    KeyboardComponent keyboardComponent { processor.keyboardState };
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
