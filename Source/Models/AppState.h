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
    AppStateType AppState;
    
    int bufferSize = 512;
    float windowSize;
    juce::Array<Channel> channels;
    
    float zoomLevel;
    bool quantized;
};
#endif /* AppState_h */
