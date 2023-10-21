/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PeriscopeAudioProcessorEditor::PeriscopeAudioProcessorEditor (PeriscopeAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    layout = new LayoutComponent(p.stateManager);
    addAndMakeVisible(layout);
        
    setSize (1200, 700);
}

PeriscopeAudioProcessorEditor::~PeriscopeAudioProcessorEditor()
{
}

//==============================================================================
void PeriscopeAudioProcessorEditor::paint (juce::Graphics& g)
{
//    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
//    g.setColour (juce::Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Wazzooo!", getLocalBounds(), juce::Justification::centred, 1);
}

void PeriscopeAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    layout->setBounds(0, 0, getWidth(), getHeight());
}
