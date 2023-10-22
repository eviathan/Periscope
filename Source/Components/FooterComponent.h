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

class FooterComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    FooterComponent(StateManager* sManager)
    {
        stateManager = sManager;
    }
    
    void paint (juce::Graphics& g) override
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

        g.setColour (juce::Colours::white);
        g.setFont (35.0f);
        g.drawFittedText ("Working!", getLocalBounds(), juce::Justification::centred, 1);
    }
    
//    void resized () override
//    {
//    }
//
private:
};


#endif /* FooterComponent_h */
