//
//  GridComponent.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef GridComponent_h
#define GridComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"


// TODO:
// 1. We need to create the background grid view
// 6. We need to sort out the zooming control below the footer

class GridComponent : public juce::Component
{
        
public:
    StateManager* stateManager;
    
    GridComponent(StateManager* sManager)
    {
        stateManager = sManager;
    }
    
    void paint (juce::Graphics& g)
    {
        g.fillAll(juce::Colour::fromRGB(25, 27, 28));
        
        int numberOfDivisions = 4; // TODO: Calculate this from the stateManagers quantization and beats or zoom level
        int width = getWidth();
        int height = getHeight();

        g.setColour(juce::Colour::fromRGBA(118, 118, 118, 33));

        for (int i = 0; i < numberOfDivisions; ++i)
        {
            int xPosition = round((width / static_cast<float>(numberOfDivisions)) * i);
            g.drawRect(xPosition, 0, 2, height);
        }
        
        g.setColour (juce::Colours::white);
        
        float borderWidth = 2.0f;
        juce::Rectangle<float> bottomBorder(0, getHeight() - borderWidth, getWidth(), borderWidth);
        g.fillRect(bottomBorder);
    }
    
    // void resized () override {}
private:
    int numberOfDivisions;
    
    void drawGridLine(int index)
    {
        
    }
};


#endif /* GridComponent_h */
