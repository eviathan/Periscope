//
//  FooterComponent.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef FooterComponent_h
#define FooterComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "ChannelTabComponent.h"

class FooterComponent : public juce::Component
{
        
public:
    FooterComponent(StateManager& stateManager) :
        stateManager(stateManager)
    {
        channelTabs = new ChannelTabComponent(stateManager);
        
        addAndMakeVisible(channelTabs);
    }
    
    void resized () override
    {
        channelTabs->setBounds(0, 0, getWidth(), CHANNEL_TABS_HEIGHT);
    }

private:
    StateManager& stateManager;
    const int CHANNEL_TABS_HEIGHT = 44;
    const int SCROLL_BAR_HEIGHT = 22;
    
    ChannelTabComponent* channelTabs;
};


#endif /* FooterComponent_h */
