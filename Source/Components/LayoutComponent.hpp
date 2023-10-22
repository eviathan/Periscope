//
//  WaveformComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "HeaderComponent.hpp"
#include "MultiViewComponent.hpp"
#include "../StateManager.hpp"

class LayoutComponent : public juce::Component
{
        
public:
    LayoutComponent(StateManager* stateManager)
    {
        header = new HeaderComponent(stateManager);
        body = new MultiViewComponent(stateManager);
        
        addAndMakeVisible(header);
        addAndMakeVisible(body);
        
//        setSize (1280, 720);
    }
    
//    void paint (juce::Graphics& g) override
//    {
//        // (Our component is opaque, so we must completely fill the background with a solid colour)
//        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//    
//        g.setColour (juce::Colours::white);
//        g.setFont (35.0f);
//        g.drawFittedText ("Working!", getLocalBounds(), juce::Justification::centred, 1);
//    }
    
    void resized () override
    {
        header->setBounds(0, 0, getWidth(), headerHeight);
        body->setBounds(0, headerHeight, getWidth(), getHeight() - headerHeight);
    }
    
private:
    const int headerHeight = 117;
    HeaderComponent* header;
    MultiViewComponent* body;
};
