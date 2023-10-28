//
//  StackWaveformComponent.h
//  Periscope
//
//  Created by Brian Williams on 24/10/2023.
//

#ifndef StackWaveformComponent_h
#define StackWaveformComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

class StackWaveformComponent : public juce::Component
{
        
public:
    StackWaveformComponent(StateManager& sManager) :
        stateManager(sManager)
    {
        grid = new GridComponent(stateManager);
        
//        addAndMakeVisible(grid);
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colours::black);
        g.setColour (juce::Colours::white);

        g.setFont (35.0f);
        g.drawFittedText ("Stack", getLocalBounds(), juce::Justification::centred, 1);
    }
    
    void resized () override
    {
        grid->setBounds(0, 0, getWidth(), getHeight());
    }
    
private:
    StateManager& stateManager;
    GridComponent* grid;
};

#endif /* StackWaveformComponent_h */
