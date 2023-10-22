////
////  ChannelTabItemComponent.h
////  Periscope
////
////  Created by Brian Williams on 22/10/2023.
////
//
//#ifndef ChannelTabItemComponent_h
//#define ChannelTabItemComponent_h
//
//class ChannelTabItemComponent : public juce::Component
//{
//        
//public:
//    ChannelTabItemComponent(Channel* chan)
//    {
//        channel = chan;
//    }
//
//    void paint (juce::Graphics& g) override
//    {
//        g.fillAll (channel->colour); // NOTE THIS NEEDS TO BE UNSET BECAUSE WE NEED TO DRAW THESE WITH A BORDER RADIUS
//        g.setColour (juce::Colours::white);
//
//        g.setFont (25.0f);
//        g.drawFittedText ("-9.21!", getLocalBounds(), juce::Justification::centred, 1);
//    }
//
////    void resized () override
////    {
////    }
////
//private:
//    Channel* channel;
//};
//
//#endif /* ChannelTabItemComponent_h */
//&
