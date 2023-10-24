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
    StateManager* stateManager;
    
    StackWaveformComponent(StateManager* sManager)
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

#endif /* StackWaveformComponent_h */
