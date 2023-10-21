//
//  MultiViewComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "../StateManager.hpp"


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
    }
    
    void paint (juce::Graphics& g)
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
        g.setColour (juce::Colours::white);
        g.setFont (35.0f);
        g.drawFittedText ("Working!", getLocalBounds(), juce::Justification::centred, 1);
    }
    
    // void resized () override {}
};
