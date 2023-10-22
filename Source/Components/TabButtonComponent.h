//
//  TabButtonComponent.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef TabButtonComponent_h
#define TabButtonComponent_h

class TabButtonComponent : public juce::Component
{
public:
    TabButtonComponent(Channel* chan)
    {
        channel = chan;
    }

    void paint (juce::Graphics& g) override
    {
        if(channel->isEnabled)
        {
            drawEnabled(g);
        }
        else
        {
            drawDisabled(g);
        }
    }

private:
    Channel* channel;
    
    void drawEnabled(juce::Graphics& g)
    {
//        g.fillAll (channel->colour); // NOTE THIS NEEDS TO BE UNSET BECAUSE WE NEED TO DRAW THESE WITH A BORDER RADIUS
        g.setColour (channel->colour);
        drawRoundedBottomRightRect(g);

        g.setColour (juce::Colours::white);
        g.setFont (25.0f);
        g.drawFittedText ("-9.21!", getLocalBounds(), juce::Justification::right, 1);
    }
    
    void drawDisabled(juce::Graphics& g)
    {
        g.fillAll (juce::Colour::fromRGB(35, 35, 35));
        g.setColour (juce::Colour::fromRGBA(255, 255,255, 255));

        g.setFont (21.0f);
        g.drawFittedText ("OFF", getLocalBounds(), juce::Justification::right, 1);
    }
    
    void drawRoundedBottomRightRect(juce::Graphics& g)
    {
        float radius = 16.0f;
        juce::Path path;
        juce::Rectangle<float> rect = getLocalBounds().toFloat();
        
        path.startNewSubPath(rect.getX(), rect.getY());
        path.lineTo(rect.getRight(), rect.getY());
        path.lineTo(rect.getRight(), rect.getBottom() - radius);
        path.quadraticTo(rect.getRight(), rect.getBottom(), rect.getRight() - radius, rect.getBottom());
        path.lineTo(rect.getX(), rect.getBottom());
        path.closeSubPath();

        g.fillPath(path);
    }

};

#endif /* TabButtonComponent_h */
