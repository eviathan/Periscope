//
//  HeaderComponent.hpp
//  Periscope - All
//
//  Created by Brian Williams on 20/10/2023.
//

#include <JuceHeader.h>
#include "BinaryData.h"

class HeaderComponent : public juce::Component
{
        
public:
    HeaderComponent()
    {
        auto svgData = BinaryData::Logo_svg;

        juce::String svgString = juce::CharPointer_UTF8(svgData);
        std::unique_ptr<juce::XmlElement> svgElement = juce::XmlDocument::parse(svgString);

        if (svgElement != nullptr)
        {
            svgDrawable = std::move(juce::Drawable::createFromSVG(*svgElement));

            if (svgDrawable)
            {
                // Set the SVG drawable's bounds, scale it, position it, etc.
                svgDrawable->setBounds(0, 0, 100, 100); // Position and size it as you want
                juce::AffineTransform transform = juce::AffineTransform::translation(40, 15);
                svgDrawable->setTransform(transform);
            }
        }
    }
    
    void paint (juce::Graphics& g)
    {
        // (Our component is opaque, so we must completely fill the background with a solid colour)
        g.fillAll (juce::Colours::black);
    
        g.setColour (juce::Colours::white);
//        g.setFont (35.0f);
//        g.drawFittedText ("Header!", getLocalBounds(), juce::Justification::centred, 1);
        
//        g.setColour(juce::Colours::red);

        // Draw the bottom border
        float borderWidth = 2.0f;  // Set the desired border width
        juce::Rectangle<float> bottomBorder(0, getHeight() - borderWidth, getWidth(), borderWidth);
        g.fillRect(bottomBorder);
        
        if (svgDrawable != nullptr)
           svgDrawable->draw(g, 1.0f);  // The second argument is the opacity
    }
    
    // void resized () override {}
    
private:
    std::unique_ptr<juce::Drawable> svgDrawable;
};
