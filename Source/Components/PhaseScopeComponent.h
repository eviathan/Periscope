//
//  PhaseScopeComponent.h
//  Periscope
//
//  Created by Brian Williams on 24/10/2023.
//

#ifndef PhaseScopeComponent_h
#define PhaseScopeComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

class PhaseScopeComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    PhaseScopeComponent(StateManager* sManager)
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

#endif /* PhaseScopeComponent_h */
