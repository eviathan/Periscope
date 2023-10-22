//
//  ColourUtility.cpp
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#include <stdio.h>
#include "ColourUtility.h"

const juce::Colour COLOURS[] = {
    juce::Colour(178, 76, 79),
    juce::Colour(187, 128, 33),
    juce::Colour(210, 197, 6),
    juce::Colour(149, 231, 115),
    juce::Colour(115, 213, 167),
    juce::Colour(69, 156, 178),
    juce::Colour(98, 69, 178),
    juce::Colour(178, 69, 172)
};

const int NUMBER_OF_COLOURS = sizeof(COLOURS) / sizeof(COLOURS[0]);

juce::Colour getColourForChannel(int channel)
{
    if(channel < 0 || channel >= NUMBER_OF_COLOURS)
        return juce::Colours::pink;
        
    return COLOURS[channel];
}
