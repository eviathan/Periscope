//
//  StateManager.cpp
//  Periscope
//
//  Created by Brian Williams on 20/10/2023.
//

#include "StateManager.hpp"

constexpr AppStateType allStates[] =
{
    AppStateType::Single,
    AppStateType::Sum,
    AppStateType::Layer,
    AppStateType::Stack,
    AppStateType::Spectrum,
    AppStateType::Oscilloscope,
    AppStateType::Phase
};

StateManager::StateManager() :
    state(std::make_unique<AppState>()) { }

void StateManager::changeState(int value)
{
    int newState = static_cast<int>(state->stateType) + value;
    size_t length = sizeof(allStates) / sizeof(allStates[0]);

    if (newState < 0) {
        newState += length;  // Adjust it before taking modulus
    }

    newState %= length;
    state->stateType = static_cast<AppStateType>(newState);
}


std::string StateManager::getAppStateLabel()
{
    switch (state->stateType) {
        case AppStateType::Single:
            return "Single";
        case AppStateType::Layer:
            return "Layer";
        case AppStateType::Stack:
            return "Stack";
        case AppStateType::Sum:
            return "Sum";
        case AppStateType::Spectrum:
            return "Spectre";
        case AppStateType::Oscilloscope:
            return "Scope";
        case AppStateType::Phase:
            return "Phase";
        default:
            return "N/A";
    }
}
