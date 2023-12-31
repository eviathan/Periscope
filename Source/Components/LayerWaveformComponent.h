//
//  LayerWaveformComponent.h
//  Periscope
//
//  Created by Brian Williams on 24/10/2023.
//

#ifndef LayerWaveformComponent_h
#define LayerWaveformComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

class LayerWaveformComponent : public juce::Component
{
        
public:
    LayerWaveformComponent(StateManager& sManager) :
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
        g.drawFittedText ("Layer", getLocalBounds(), juce::Justification::centred, 1);
    }
    
    void resized () override
    {
        grid->setBounds(0, 0, getWidth(), getHeight());
    }
    
private:
    StateManager& stateManager;
    GridComponent* grid;
};

#endif /* LayerWaveformComponent_h */
