/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
PeriscopeAudioProcessor::PeriscopeAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    stateManager = new StateManager();
}

PeriscopeAudioProcessor::~PeriscopeAudioProcessor()
{
}

//==============================================================================
const juce::String PeriscopeAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PeriscopeAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool PeriscopeAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool PeriscopeAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double PeriscopeAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int PeriscopeAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int PeriscopeAudioProcessor::getCurrentProgram()
{
    return 0;
}

void PeriscopeAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String PeriscopeAudioProcessor::getProgramName (int index)
{
    return {};
}

void PeriscopeAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void PeriscopeAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void PeriscopeAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool PeriscopeAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void PeriscopeAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    const int numSamples = buffer.getNumSamples();
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        // Ensure the channel is enabled and monitored
        if (stateManager->state->channels[channel].isEnabled &&
            stateManager->state->channels[channel].isMonitored)
        {
            const float* channelData = buffer.getReadPointer(channel);

            // Copying the data to your channel buffer
            std::copy(channelData, channelData + numSamples, stateManager->state->channels[channel].buffer);
        }
    }
    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, numSamples);

    
    fillBuffers(buffer);
}

//==============================================================================
bool PeriscopeAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* PeriscopeAudioProcessor::createEditor()
{
    return new PeriscopeAudioProcessorEditor (*this);
}

//==============================================================================
void PeriscopeAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void PeriscopeAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PeriscopeAudioProcessor();
}

//==============================================================================

void PeriscopeAudioProcessor::fillBuffers(juce::AudioBuffer<float>& buffer)
{
    
}
