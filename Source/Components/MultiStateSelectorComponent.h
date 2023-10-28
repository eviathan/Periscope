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
    MultiStateSelectorComponent(StateManager& stateManager) :
        stateManager(stateManager)
    {
        auto normalColour = juce::Colours::white;
        auto overColour = juce::Colours::grey;
        auto downColour = juce::Colours::darkgrey;
        
        leftButton = new ArrowButton("leftArrow", Direction::Left, normalColour, overColour, downColour);
        leftButton->onClick = [this] { onLeftClick(); };
        
        juce::Font labelFont("Futura", 37.0f, juce::Font::plain);
        labelFont.setTypefaceStyle("Bold");
        
        label = new juce::Label("stateSelectorLabel", stateManager.getAppStateLabel());
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
        leftButton->setBounds(0, 0, BUTTON_WIDTH, getHeight());
        label->setBounds(BUTTON_WIDTH, 0, getWidth() - (BUTTON_WIDTH * 2), getHeight());
        rightButton->setBounds(getWidth() - BUTTON_WIDTH, 0, BUTTON_WIDTH, getHeight());
    }
    
private:
    StateManager& stateManager;
    const int BUTTON_WIDTH = 26;
    
    ArrowButton* leftButton;
    juce::Label* label;
    ArrowButton* rightButton;
    
    void onLeftClick()
    {
        stateManager.changeState(-1);
        std::string labelText = stateManager.getAppStateLabel();
        label->setText(labelText, juce::NotificationType::dontSendNotification);
    }
    
    void onRightClick()
    {
        stateManager.changeState(1);
        std::string labelText = stateManager.getAppStateLabel();
        label->setText(labelText, juce::NotificationType::dontSendNotification);
    }
};

#endif /* MultiStateSelectorComponent_h */
