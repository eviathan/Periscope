//
//  ColourUtility.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef ColourUtility_h
#define ColourUtility_h

#include <JuceHeader.h>

extern const juce::Colour COLOURS[];
extern const int NUMBER_OF_COLOURS;

juce::Colour getColourForChannel(int channel);

#endif /* ColourUtility_h */
