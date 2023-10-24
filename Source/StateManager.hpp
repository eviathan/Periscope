//
//  StateManager.hpp
//  Periscope
//
//  Created by Brian Williams on 20/10/2023.
//

#ifndef StateManager_hpp
#define StateManager_hpp

#include <stdio.h>
#include <JuceHeader.h>
#include "Models/AppState.h"
#include "Enums/AppStateType.h"

using StateChangedDelegate = std::function<void(const int value)>;

class StateManager
{
public:
    StateManager();
    
    std::unique_ptr<AppState> state;
    
    void changeState(int value);
    void registerChangedStateDelegate(const StateChangedDelegate& delegate);
    
    int getBufferSizeForState(AppStateType state) const;
    
    std::string getAppStateLabel();
    
private:
    std::vector<StateChangedDelegate> stateChangedDelegates;
    
    // NOTE: This is temporary we want to calculate this based on zoom
    // and/ or other settings at the moment its 1 bar of 4/4 at 120bpm for testing
    static constexpr int samplesPerBarAt120BPM = 2 * 44100; // 88,200 samples
};

#endif /* StateManager_hpp */
