//
//  TabButtonComponent.h
//  Periscope
//
//  Created by Brian Williams on 22/10/2023.
//

#ifndef TabButtonComponent_h
#define TabButtonComponent_h

class TabButtonComponent : public juce::ShapeButton
{
public:
    TabButtonComponent(Channel* chan) :
        ShapeButton("TabButton", juce::Colours::pink, juce::Colours::pink, juce::Colours::pink)
    {
        channel = chan;
        onClick =  [this] { onClickedTab(); };
    }

    void paintButton(juce::Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override
    {
        if(channel->isEnabled)
        {
            drawEnabled(g, getOpacity(shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown));
        }
        else
        {
            drawDisabled(g);
        }
    }

private:
    Channel* channel;
    
    void onClickedTab()
    {
        channel->isEnabled = !channel->isEnabled;
    }
    
    void drawEnabled(juce::Graphics& g, float opacity)
    {
        g.setColour (channel->colour.withSaturation(channel->colour.getSaturation() * opacity));
        drawRoundedBottomRightRect(g, false);

        g.setColour (juce::Colours::white);
        g.setFont (25.0f);
//        g.drawFittedText("-9.21", getLocalBounds(), juce::Justification::right, 1);
        g.drawText("-9.22", getWidth() - 136, 0, 66, 44, juce::Justification::right);
        
        g.setFont (14.0f);
        g.drawText("db", getWidth() - 80, 4, 44, 44, juce::Justification::centred);
        //g.drawFittedText("dB", getLocalBounds(), juce::Justification::right, 1);
    }
    
    void drawDisabled(juce::Graphics& g)
    {
        g.setColour (juce::Colour::fromRGB(35, 35, 35));
        drawRoundedBottomRightRect(g, true);
        
        g.setColour (juce::Colour::fromRGBA(255, 255,255, 80));
        g.setFont (21.0f);
        g.drawText("OFF", getWidth() - 100, -16, 44, 80, juce::Justification::centred);
//        g.drawFittedText ("OFF", getLocalBounds(), juce::Justification::right, 1);
    }
    
    void drawRoundedBottomRightRect(juce::Graphics& g, bool withStroke)
    {
        float radius = 16.0f;
        juce::Path path;
        juce::Rectangle<float> rect = getLocalBounds().toFloat();
        
        path.startNewSubPath(rect.getX(), rect.getY());
        path.lineTo(rect.getRight(), rect.getY());
        path.lineTo(rect.getRight(), rect.getBottom() - radius);
        
        // Corrected control point for the curve
        float controlX = rect.getRight();
        float controlY = rect.getBottom() - (radius * (sqrt(2)/2));

        path.quadraticTo(controlX, controlY, rect.getRight() - radius, rect.getBottom());
        path.lineTo(rect.getX(), rect.getBottom());
        
//        path.quadraticTo(rect.getRight(), rect.getBottom(), rect.getRight() - radius, rect.getBottom());
//        path.lineTo(rect.getX(), rect.getBottom());
        
        path.closeSubPath();
        g.fillPath(path);
        
        if(withStroke)
        {
            g.setColour(juce::Colour::fromRGBA(0, 0, 0, 80));
            float lineWidth = 3.0f;
            g.strokePath(path, juce::PathStrokeType(lineWidth));
        }
    }
    
    float getOpacity(bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
    {
        if(shouldDrawButtonAsHighlighted)
        {
            if(shouldDrawButtonAsDown)
            {
                return 0.0f;
            }
            else
            {
                return 0.8f;
            }
        }
        else
        {
            return 1.0f;
        }
    }
};

#endif /* TabButtonComponent_h */
