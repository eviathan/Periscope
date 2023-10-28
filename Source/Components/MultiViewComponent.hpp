//
//  MultiViewComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "../StateManager.hpp"

#include "SingleWaveformComponent.h"
#include "SumWaveformComponent.h"
#include "LayerWaveformComponent.h"
#include "StackWaveformComponent.h"
#include "SpectrumComponent.h"
#include "OscilloscopeComponent.h"
#include "PhaseScopeComponent.h"
#include "SpectralComponent.h"

class MultiViewComponent : public juce::Component
{
        
public:
    MultiViewComponent(StateManager& sManager) :
        stateManager(sManager)
    {
        stateManager.registerChangedStateDelegate([this](const int value) {
            this->switchToComponent(value);
        });
        
        singleWaveform = new SingleWaveformComponent(stateManager);
        sumWaveformComponent = new SumWaveformComponent(stateManager);
        layerWaveformComponent = new LayerWaveformComponent(stateManager);
        stackWaveformComponent = new StackWaveformComponent(stateManager);
        spectrumComponent = new SpectrumComponent(stateManager);
        oscilloscopeComponent = new OscilloscopeComponent(stateManager);
        phaseScopeComponent = new PhaseScopeComponent(stateManager);
        spectralComponent = new SpectralComponent(stateManager);
        
        components.add(singleWaveform);
        components.add(sumWaveformComponent);
        components.add(layerWaveformComponent);
        components.add(stackWaveformComponent);
        components.add(spectrumComponent);
        components.add(oscilloscopeComponent);
        components.add(phaseScopeComponent);
        components.add(spectralComponent);

        for (auto* component : components)
        {
            addAndMakeVisible(component);
            component->setVisible(false);
        }
        
        if (components.size() > 0)
            components[0]->setVisible(true);
    }
    
    void paint (juce::Graphics& g) override
    {
        g.fillAll(juce::Colours::white);
    }
    
    void switchToComponent(int index)
    {
        if (index >= 0 && index < components.size())
        {
            for (int i = 0; i < components.size(); ++i)
                components[i]->setVisible(i == index);
        }
    }
    
    void resized() override
    {
        auto localBounds = getLocalBounds();
        
        for (auto* component : components)
        {
            component->setBounds(0, 0, localBounds.getWidth(), localBounds.getHeight() - BOTTOM_BORDER_WIDTH);
        }
            
    }
    
private:
    StateManager& stateManager;
    
    const float BOTTOM_BORDER_WIDTH = 2.0f;
    juce::OwnedArray<juce::Component> components;
    
    SingleWaveformComponent* singleWaveform;
    SumWaveformComponent* sumWaveformComponent;
    LayerWaveformComponent* layerWaveformComponent;
    StackWaveformComponent* stackWaveformComponent;
    SpectrumComponent* spectrumComponent;
    OscilloscopeComponent* oscilloscopeComponent;
    PhaseScopeComponent* phaseScopeComponent;
    SpectralComponent* spectralComponent;
};
