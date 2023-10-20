//
//  WaveformComponent.cpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>

class LayoutComponent : public juce::Component
{
        
public:
    LayoutComponent()
    {
        
    }
    
    void paint (juce::Graphics& g)
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
        g.setColour (juce::Colours::white);
        g.setFont (35.0f);
        g.drawFittedText ("Working!", getLocalBounds(), juce::Justification::centred, 1);
    }
    
    // void resized () override {}
};
