//
//  MultiStateSelectorComponent.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef MultiStateSelectorComponent_h
#define MultiStateSelectorComponent_h

#include <JuceHeader.h>
#include "../StateManager.hpp"
#include "ArrowButton.h"
#include "../Enums/Direction.h"


class MultiStateSelectorComponent : public juce::Component
{
       
public:
   StateManager* stateManager;
   
    MultiStateSelectorComponent(StateManager* sManager)
    {
        stateManager = sManager;
        
        auto normalColour = juce::Colours::white;
        auto overColour = juce::Colours::grey;
        auto downColour = juce::Colours::darkgrey;
        
        leftButton = new ArrowButton("leftArrow", Direction::Left, normalColour, overColour, downColour);
        leftButton->onClick = [this] { onLeftClick(); };
        
        juce::Font labelFont("Futura", 37.0f, juce::Font::plain);
        labelFont.setTypefaceStyle("Bold");
        
        label = new juce::Label("stateSelectorLabel", "SINGLE");
        label->setColour(juce::Label::textColourId, juce::Colours::white);
        label->setFont(labelFont);
        label->setJustificationType(juce::Justification::centred);
        
        rightButton = new ArrowButton("rightArrow", Direction::Right, normalColour, overColour, downColour);
        rightButton->onClick = [this] { onRightClick(); };
        
        addAndMakeVisible(leftButton);
        addAndMakeVisible(rightButton);
        addAndMakeVisible(label);
    }
   
    void resized () override
    {
        leftButton->setBounds(0, 0, 26, getHeight());
        label->setBounds(26, 0, 148, getHeight());
        rightButton->setBounds(getWidth() - 26, 0, 26, getHeight());
    }
    
private:
    ArrowButton* leftButton;
    juce::Label* label;
    ArrowButton* rightButton;
    
    void onLeftClick()
    {
        
    }
    
    void onRightClick()
    {
        
    }
};

#endif /* MultiStateSelectorComponent_h */
