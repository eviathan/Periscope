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
    AppStateType::Phase,
    AppStateType::Spectral
};

StateManager::StateManager() :
    state(std::make_unique<AppState>())
{
    int initialBufferSize = getBufferSizeForState(state->stateType);

    for (int i = 0; i < state->channelCount; ++i)
    {
        Channel& channel = state->channels[i];

        // Allocate and initialize new buffer
        channel.buffer = new float[initialBufferSize];
        std::fill_n(channel.buffer, initialBufferSize, 0.0f);
    }

    state->bufferSize = initialBufferSize;
}

void StateManager::changeState(int value)
{
    int newState = static_cast<int>(state->stateType) + value;
    size_t length = sizeof(allStates) / sizeof(allStates[0]);

    if (newState < 0)
    {
        newState += length;
    }

    newState %= length;
    state->stateType = static_cast<AppStateType>(newState);
    
    for (const auto& delegate : stateChangedDelegates)
    {
        delegate(newState);
    }
    
    // Update the buffer size and reallocate memory for each channel
    uint64_t newBufferSize = getBufferSizeForState(state->stateType);
    for (int i = 0; i < state->channelCount; ++i) {
        state->channels[i].allocateBuffer(newBufferSize);
    }
}

void StateManager::registerChangedStateDelegate(const StateChangedDelegate& delegate)
{
    stateChangedDelegates.push_back(delegate);
}


std::string StateManager::getAppStateLabel()
{
    switch (state->stateType)
    {
        case AppStateType::Single:
            return "SINGLE";
        case AppStateType::Layer:
            return "LAYER";
        case AppStateType::Stack:
            return "STACK";
        case AppStateType::Sum:
            return "SUM";
        case AppStateType::Spectrum:
            return "SPECTRUM";
        case AppStateType::Oscilloscope:
            return "SCOPE";
        case AppStateType::Phase:
            return "PHASE";
        case AppStateType::Spectral:
            return "SPECTRAL";
        default:
            return "N/A";
    }
}


int StateManager::getBufferSizeForState(AppStateType state) const
{
    switch (state) {
            case Single:
            case Sum:
            case Layer:
            case Stack:
            case Spectral:  // Set the spectral to be the same value as the waveform views
                return samplesPerBarAt120BPM;
            case Spectrum:
                return 4096;
            case Oscilloscope:
                return 441;  // e.g., 10ms at 44.1kHz
            case Phase:
                return 1024;
            default:
                return 1024;  // Default buffer size (can adjust as needed)
        }
}
