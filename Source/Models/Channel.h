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
#include "../Utilities/CircularBuffer.h"

struct Channel {
    bool isEnabled;
    bool isMonitored;
    float* buffer = nullptr;  // raw pointer to a dynamically allocated array
    juce::Colour colour;
    
    CircularBuffer<float>* circularBuffer;
    
    Channel(bool isEnabled, bool isMonitored, juce::Colour colour) :
        isEnabled(isEnabled),
        isMonitored(isMonitored),
        colour(colour) { }
    
    ~Channel()
    {
        delete[] buffer;
        delete circularBuffer;
    }
    
    void allocateBuffer(int size)
    {
        delete[] buffer; // deallocate previous memory
        delete circularBuffer;
        
        buffer = new float[size];
        circularBuffer = new CircularBuffer<float>(size);
    }
};

#endif /* Channel_h */

