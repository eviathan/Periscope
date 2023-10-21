////
////  WaveformComponent.cpp
////  Periscope - All
////
////  Created by Brian Williams on 20/10/2023.
////
//
//#include "WaveformComponent.hpp"
//#include <JuceHeader.h>
//
//class MainComponent : public juce::OpenGLAppComponent
//{
//        
//public:
//    MainComponent()
//    {
//        setSize (800, 600);
//        startTimer(30);  // This will refresh the component every 30ms, adjust as needed
//    }
//
//    ~MainComponent() override
//    {
//        shutdownOpenGL();
//    }
//
//    void initialise() override
//    {
//        // Initialize OpenGL resources here
//    }
//
//    void shutdown() override
//    {
//        // Cleanup OpenGL resources
//    }
//
//    void render() override
//    {
//        juce::OpenGLHelpers::clear(juce::Colours::black);
//
//        // TODO: Add OpenGL drawing code for bezier curves and points
//    }
//
//    void mouseDown(const juce::MouseEvent& e) override
//    {
//        // Handle mouse down event
//    }
//
//    void mouseDrag(const juce::MouseEvent& e) override
//    {
//        // Handle mouse drag event
//    }
//
//    void timerCallback() override
//    {
//        repaint();
//    }
//
//private:
//    // Your data members, e.g., std::vector for points, controlPoints, etc.
//
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
//};
