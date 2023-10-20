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
    juce::Array<Channel> channels; // NOTE: We are getting this working monophonically for now but
};
#endif /* AppState_h */
