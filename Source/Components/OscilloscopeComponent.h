//
//  OscilloscopeComponent.h
//  Periscope
//
//  Created by Brian Williams on 24/10/2023.
//

#ifndef OscilloscopeComponent_h
#define OscilloscopeComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

class OscilloscopeComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    OscilloscopeComponent(StateManager* sManager)
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

#endif /* OscilloscopeComponent_h */
