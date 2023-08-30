/*
  ==============================================================================

    Sizes.h
    Created: 29 Aug 2023 7:47:55pm
    Author:  Jesús Valdez

  ==============================================================================
*/

#pragma once

namespace Sizes
{
    static constexpr int MAIN_WIDTH  = 1100;
    static constexpr int MAIN_HEIGHT = 600;

    static const juce::Rectangle<float> headerBounds    { 0.0f, 0.0f, 1.0f, 0.1f };

    static const juce::Rectangle<float> oscOnebounds    { 0.0f, 0.1f, 0.5f, 0.2f };
    static const juce::Rectangle<float> oscTwobounds    { 0.0f, 0.3f, 0.5f, 0.2f };
    static const juce::Rectangle<float> filterBounds    { 0.0f, 0.5f, 0.5f, 0.2f };
    static const juce::Rectangle<float> envelopeBounds  { 0.0f, 0.7f, 0.5f, 0.2f };

    static const juce::Rectangle<float> distortionBounds    { 0.5f, 0.1f, 0.1f, 0.8f };
    static const juce::Rectangle<float> reverbBounds        { 0.6f, 0.1f, 0.1f, 0.8f };
    static const juce::Rectangle<float> delayBounds         { 0.7f, 0.1f, 0.1f, 0.8f };

    static const juce::Rectangle<float> metersBounds    { 0.8f, 0.1f, 0.2f, 0.8f };
    static const juce::Rectangle<float> keyboardBounds  { 0.0f, 0.9f, 1.0f, 0.1f };

}
