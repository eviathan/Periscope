//
//  SingleWaveformComponent.h
//  Periscope
//
//  Created by Brian Williams on 24/10/2023.
//

#ifndef SingleWaveformComponent_h
#define SingleWaveformComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

class SingleWaveformComponent : public juce::Component,
                                public juce::Timer
{
        
public:
    StateManager* stateManager;
    
    SingleWaveformComponent(StateManager* sManager)
    {
        stateManager = sManager;
        grid = new GridComponent(stateManager);
        
        startTimerHz(60);
        setBufferedToImage(true);
        
//        addAndMakeVisible(grid);
    }
    
    ~SingleWaveformComponent()
    {
        stopTimer();
    }
    
    void paint(juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::black);  // Fill the background

        for (int i = 0; i < stateManager->state->channelCount; ++i)
        {
            const auto& channel = stateManager->state->channels[i];
            if (channel.isEnabled && channel.isMonitored)
            {
                drawWaveform(g, channel.buffer, channel.colour);
            }
        }
    }
    
//    void paint (juce::Graphics& g) override
//    {
//        g.fillAll (juce::Colours::black);
//        g.setColour (juce::Colours::white);
//
//        g.setFont (35.0f);
//        g.drawFittedText ("Single", getLocalBounds(), juce::Justification::centred, 1);
//    }
    
    void resized () override
    {
        grid->setBounds(0, 0, getWidth(), getHeight());
    }
    
private:
    GridComponent* grid;
    const float LINE_THICKNESS = 2.0f;
   
    // NOTE: Good for OSCILLOSCOPE
//    void drawWaveform(juce::Graphics& g, float* buffer, juce::Colour colour)
//    {
//        const int w = getWidth();
//        const int h = getHeight();
//        const int bufferLength = stateManager->state->bufferSize;
//
//        g.setColour(colour);
//
//        for (int i = 1; i < w && i < bufferLength; ++i)
//        {
//            float sample1 = buffer[i - 1];
//            float sample2 = buffer[i];
//
//            g.drawLine(i - 1,
//                       h * (1.0f - (sample1 * 0.5f + 0.5f)),
//                       i,
//                       h * (1.0f - (sample2 * 0.5f + 0.5f)),
//                       LINE_THICKNESS);
//        }
//    }
    void drawWaveform(juce::Graphics& g, float* buffer, juce::Colour colour)
    {
        const int w = getWidth();
        const int h = getHeight();
        const int bufferLength = stateManager->state->bufferSize;

        juce::Path waveformPath;

        // Starting at the first point
        float firstSample = buffer[0];
        waveformPath.startNewSubPath(0, h * (1.0f - (firstSample * 0.5f + 0.5f)));

        // Trace the upper edge of the waveform
        for (int i = 1; i < w && i < bufferLength; ++i)
        {
            float sample = buffer[i];
            waveformPath.lineTo(i, h * (1.0f - (sample * 0.5f + 0.5f)));
        }

        // Now trace the bottom edge to close the path
        for (int i = juce::jmin(w, bufferLength) - 1; i >= 0; --i)
        {
            float sample = buffer[i];
            waveformPath.lineTo(i, h - (h * (1.0f - (sample * 0.5f + 0.5f))));
        }

        waveformPath.closeSubPath();

        // Fill the waveform with a color that's 70% opaque
        g.setColour(colour.withAlpha(0.7f));
        g.fillPath(waveformPath);

        // Draw the waveform outline with a thickness of 2 pixels
        g.setColour(colour);
        g.strokePath(waveformPath, juce::PathStrokeType(2.0f));
    }

    void timerCallback() override
    {
        repaint();  // Redraw the component
    }
};


#endif /* SingleWaveformComponent_h */
