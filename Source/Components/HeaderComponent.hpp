//
//  HeaderComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "BinaryData.h"
#include "MultiStateSelectorComponent.h"

class HeaderComponent : public juce::Component
{
        
public:
    HeaderComponent(StateManager* sManager)
    {
        auto svgData = BinaryData::Logo_svg;

        juce::String svgString = juce::CharPointer_UTF8(svgData);
        std::unique_ptr<juce::XmlElement> svgElement = juce::XmlDocument::parse(svgString);

        if (svgElement != nullptr)
        {
            svgDrawable = juce::Drawable::createFromSVG(*svgElement);

            if (svgDrawable)
            {
                svgDrawable->setBounds(0, 0, 100, 100);
                juce::AffineTransform transform = juce::AffineTransform::translation(40, 15);
                svgDrawable->setTransform(transform);
            }
        }
        
        appStateSelector = new MultiStateSelectorComponent(sManager);
        auto appStateSelectorWidth = 175;
        auto appStateSelectorHeight = 50;
        
        appStateSelector->setBounds(950, 38, appStateSelectorWidth, appStateSelectorHeight);
        addAndMakeVisible(appStateSelector);
    }
    
    void paint (juce::Graphics& g)
    {
        g.fillAll (juce::Colours::black);
        g.setColour (juce::Colours::white);
        
        float borderWidth = 2.0f;
        juce::Rectangle<float> bottomBorder(0, getHeight() - borderWidth, getWidth(), borderWidth);
        g.fillRect(bottomBorder);
        
        if (svgDrawable != nullptr)
           svgDrawable->draw(g, 1.0f);
    }
    
private:
    std::unique_ptr<juce::Drawable> svgDrawable;
    MultiStateSelectorComponent* appStateSelector;
};
