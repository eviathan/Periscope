//
//  ChannelTabComponent.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef ChannelTabComponent_h
#define ChannelTabComponent_h

#include "../Utilities/ColourUtility.h"
#include "../StateManager.hpp"
#include "TabButtonComponent.h"

class ChannelTabComponent : public juce::Component
{
    
public:
    StateManager* stateManager;
    
    ChannelTabComponent(StateManager* sManager)
    {
        stateManager = sManager;
        setupTabs();
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll (juce::Colour::fromRGB(35, 35, 35));
    }

    void resized () override
    {
        for (int i = 0; i < stateManager->state->channelCount; ++i)
        {
            int itemWidth = (getWidth() / stateManager->state->channelCount) * (i + 1);
            items[i]->setBounds(0, 0, itemWidth, getHeight());
            items[i]->toBack();
        }
    }

private:
    TabButtonComponent* items[8];

    void setupTabs()
    {
        for (int i = 0; i < stateManager->state->channelCount; ++i)
        {
            bool isLast = stateManager->state->channelCount == i + 1;
            items[i] = new TabButtonComponent(&stateManager->state->channels[i], i, isLast);
            addAndMakeVisible(items[i]);
        }
    }
};

#endif /* ChannelTabComponent_h */
