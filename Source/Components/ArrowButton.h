//
//  ArrowButton.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef ArrowButton_h
#define ArrowButton_h

#include <JuceHeader.h>
#include "../Enums/Direction.h"

class ArrowButton : public juce::ShapeButton
{
public:
    //==============================================================================
    ArrowButton(juce::String name, Direction direction, juce::Colour normalColour, juce::Colour overColour, juce::Colour downColour) :
        ShapeButton(name, normalColour, overColour, downColour),
        direction(direction),
        normalColour(normalColour),
        overColour(overColour),
        downColour(downColour)
    { }
    
    void paintButton(juce::Graphics& g, bool isMouseOverButton, bool isButtonDown) override
    {        
        juce::Colour baseColour;
        if (isButtonDown)
        {
            baseColour = downColour;
        }
        else if (isMouseOverButton)
        {
            baseColour = overColour;
        }
        else
        {
            baseColour = normalColour;
        }
        g.setColour(baseColour);
        
        juce::Path arrowPath;
        if (direction == Direction::Left)
        {
            arrowPath.addTriangle(20, 14, 0, 25, 20, 36);
        }
        else if (direction == Direction::Right)
        {
            arrowPath.addTriangle(6, 14, 26, 25, 6, 36);
        }

        g.fillPath(arrowPath);
    }    
    
private:
    Direction direction;
    juce::Colour normalColour;
    juce::Colour overColour;
    juce::Colour downColour;
};


#endif /* ArrowButton_h */
