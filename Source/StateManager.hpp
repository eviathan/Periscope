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

class StateManager
{
public:
    StateManager();
    
    std::unique_ptr<AppState> state;
    
    void changeState(int value);
    std::string getAppStateLabel();
};

#endif /* StateManager_hpp */
