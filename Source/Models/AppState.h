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
    juce::Array<Channel> channels;
    
    float zoomLevel = 1.0f;
    bool quantized = false;
};
#endif /* AppState_h */
