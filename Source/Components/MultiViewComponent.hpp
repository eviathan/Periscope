//
//  MultiViewComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "GridComponent.h"

// TODO:
// 1. We need to create the background grid view
// 2. We need to create a footer component for this tab buttons
// 3. We need to create the tab button components
// 4. We need to create the Wave Form views and pass the state to the waveform view
// 5. We need to create the ms and sample HUD
// 6. We need to sort out the zooming control below the footer


class MultiViewComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    MultiViewComponent(StateManager* sManager)
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
