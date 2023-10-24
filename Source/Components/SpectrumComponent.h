//
//  SpectrumComponent.h
//  Periscope
//
//  Created by Brian Williams on 24/10/2023.
//

#ifndef SpectrumComponent_h
#define SpectrumComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

class SpectrumComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    SpectrumComponent(StateManager* sManager)
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

#endif /* SpectrumComponent_h */