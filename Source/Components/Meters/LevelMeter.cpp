#include <JuceHeader.h>
#include "LevelMeter.h"

LevelMeter::LevelMeter (std::function<float()>&& valueFunction, juce::Image grillImage) : valueSupplier (std::move(valueFunction))
{
    startTimerHz (24);
    
    grill = grillImage;
}

LevelMeter::LevelMeter (std::function<float()>&& valueFunction) : valueSupplier (std::move(valueFunction))
{
    startTimerHz (24);
}

LevelMeter::~LevelMeter()
{
    stopTimer();
}

void LevelMeter::paint (juce::Graphics& g)
{
    if (valueSupplier != nullptr)
    {
        const auto level = valueSupplier();
        auto bounds      = getLocalBounds().toFloat().reduced (1.0f);
            
        g.setColour (juce::Colours::black);
        g.fillRect  (bounds);
        
        if (level > -60.0f)
        {
            g.setGradientFill (gradient);
            const auto scaledY = juce::jmap (level, -60.0f, 6.0f, 0.0f, static_cast<float> (getHeight()));
            g.fillRect (bounds.removeFromBottom(scaledY));
        }
    }
}

void LevelMeter::paintOverChildren (juce::Graphics& g)
{
    if (grill.isValid())
        g.drawImage (grill, getLocalBounds().toFloat());
}

void LevelMeter::resized()
{
    const auto bounds = getLocalBounds().toFloat();
    gradient = juce::ColourGradient { juce::Colours::green, bounds.getBottomLeft(), juce::Colours::red, bounds.getTopLeft(), false };
    gradient.addColour (0.5, juce::Colours::yellow);
}

void LevelMeter::timerCallback()
{
    repaint();
}

void LevelMeter::setValueFunction (std::function<float()>&& valueFunction)
{
    valueSupplier = valueFunction;
}
