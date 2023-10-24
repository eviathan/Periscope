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
    StateManager* stateManager;
    
    LayerWaveformComponent(StateManager* sManager)
    {
        stateManager = sManager;
        grid = new GridComponent(stateManager);
        
        addAndMakeVisible(grid);
    }
    
    void resized () override
    {
        grid->setBounds(0, 0, getWidth(), getHeight());
    }
    
private:
    GridComponent* grid;
};

#endif /* LayerWaveformComponent_h */
