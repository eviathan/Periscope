//
//  Channel.h
//  Periscope
//
//  Created by Brian Williams on 20/10/2023.
//

#ifndef Channel_h
#define Channel_h
#include <array>
#include "../Enums/AppStateType.h"

struct Channel {
    bool isEnabled;
    bool isMonitored;
    float* buffer = nullptr;  // raw pointer to a dynamically allocated array
    juce::Colour colour;
    
    Channel(bool isEnabled, bool isMonitored, juce::Colour colour) :
        isEnabled(isEnabled),
        isMonitored(isMonitored),
        colour(colour) { }
    
    ~Channel() {
        delete[] buffer;
    }
    
    void allocateBuffer(size_t size) {
        delete[] buffer; // deallocate previous memory
        buffer = new float[size];
    }
};

#endif /* Channel_h */

