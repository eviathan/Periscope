//
//  Channel.h
//  Periscope
//
//  Created by Brian Williams on 20/10/2023.
//

#ifndef Channel_h
#define Channel_h
#include "../Enums/AppStateType.h"

struct Channel {
    bool isEnabled;
    bool isMonitored;
    juce::Array<float>* buffer = new juce::Array<float>();
    juce::Colour colour;
    
    Channel(bool isEnabled, bool isMonitored, juce::Colour colour) :
        isEnabled(isEnabled),
        isMonitored(isMonitored),
        colour(colour) { }
};

#endif /* Channel_h */

