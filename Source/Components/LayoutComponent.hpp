//
//  WaveformComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "HeaderComponent.hpp"
#include "MultiViewComponent.hpp"
#include "FooterComponent.h"
#include "../StateManager.hpp"

class LayoutComponent : public juce::Component
{
public:
    LayoutComponent(StateManager& stateManager)
    {
        header = new HeaderComponent(stateManager);
        body = new MultiViewComponent(stateManager);
        footer = new FooterComponent(stateManager);
        
        addAndMakeVisible(header);
        addAndMakeVisible(body);
        addAndMakeVisible(footer);
    }
    
    void resized () override
    {
        header->setBounds(0, 0, getWidth(), HEADER_HEIGHT);
        body->setBounds(0, HEADER_HEIGHT, getWidth(), getHeight() - HEADER_HEIGHT - FOOTER_HEIGHT);
        footer->setBounds(0, getHeight() - FOOTER_HEIGHT, getWidth(), FOOTER_HEIGHT);
    }
    
private:
    const int HEADER_HEIGHT = 117;
    const int FOOTER_HEIGHT = 66;
    
    HeaderComponent* header;
    MultiViewComponent* body;
    FooterComponent* footer;
};
