//
//  AppState.h
//  Periscope
//
//  Created by Brian Williams on 20/10/2023.
//

#ifndef AppState_h
#define AppState_h

#include "../Enums/AppStateType.h"
#include "Channel.h"

struct AppState {
    AppStateType stateType = AppStateType::Single;
    
    int bufferSize = 512;
    float windowSize = 100.0f;
    float zoomLevel = 1.0f;
    bool quantized = false;
    
     Channel channels[8] = {
         Channel(true, true, juce::Colour(178, 76, 79)),
         Channel(false, false, juce::Colour(187, 128, 33)),
         Channel(false, false, juce::Colour(210, 197, 6)),
         Channel(false, false, juce::Colour(149, 231, 115)),
         Channel(true, true, juce::Colour(115, 213, 167)),
         Channel(true, true, juce::Colour(69, 156, 178)),
         Channel(false, false, juce::Colour(98, 69, 178)),
         Channel(false, false, juce::Colour(178, 69, 172))
    };
    int channelCount = sizeof(channels) / sizeof(channels[0]);
};
#endif /* AppState_h */
