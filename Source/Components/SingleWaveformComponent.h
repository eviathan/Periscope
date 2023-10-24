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

class SingleWaveformComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    SingleWaveformComponent(StateManager* sManager)
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


#endif /* SingleWaveformComponent_h */
