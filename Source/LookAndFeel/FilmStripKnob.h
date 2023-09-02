/*
  ==============================================================================

    FilmStripKnob.h
    Created: 31 Aug 2023 10:23:17pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once

class FilmStripKnob : public juce::LookAndFeel_V4
{
public:
    
    FilmStripKnob (juce::Image inImage = {})
    {
        knobImage = inImage;
    }
    
    ~FilmStripKnob() override {}
    
private:
    
    juce::Image knobImage;
    
    void drawRotarySlider (juce::Graphics& g,
                           int x, int y,
                           int width, int height,
                           float sliderPosProportional,
                           float /*rotaryStartAngle*/,
                           float /*rotaryEndAngle*/,
                           juce::Slider& /*slider*/) override
    {
        const int numFrames  = knobImage.getHeight() / knobImage.getWidth();
        const int frameIndex = (int) std::ceil(sliderPosProportional * (numFrames - 1));
        const float radius   = fmin (width * 0.5f, height * 0.5f);
        const float centreX  = x + width * 0.5f;
        const float centreY  = y + height * 0.5f;
        const float rx       = centreX - radius;
        const float ry       = centreY - radius;
        
        g.drawImage (knobImage,
                     (int) rx,
                     (int) ry,
                     (int) (2 * radius),
                     (int) (2 * radius),
                     0,
                     frameIndex * knobImage.getWidth(),
                     knobImage.getWidth(),
                     knobImage.getWidth());
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilmStripKnob)
};
