#include "PluginProcessor.h"
#include "PluginEditor.h"

StereoReverbAudioProcessorEditor::StereoReverbAudioProcessorEditor (StereoReverbAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), audioProcessor (p), valueTreeState(vts)
{
    setSize (400, 220);

    // Room Size Slider
    roomSizeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    roomSizeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 20);
    roomSizeSlider.setRange(0.0f, 1.0f, 0.01f);
    roomSizeSlider.setSkewFactorFromMidPoint(0.5f);
    roomSizeSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkslategrey);
    roomSizeSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::deepskyblue);
    addAndMakeVisible(roomSizeSlider);

    roomSizeLabel.setText("Room Size", juce::dontSendNotification);
    roomSizeLabel.setJustificationType(juce::Justification::centred);
    roomSizeLabel.attachToComponent(&roomSizeSlider, false);
    addAndMakeVisible(roomSizeLabel);

    roomSizeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        valueTreeState, "roomSize", roomSizeSlider);

    // Decay Time Slider
    decayTimeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    decayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 70, 20);
    decayTimeSlider.setRange(0.1f, 10.0f, 0.01f);
    decayTimeSlider.setSkewFactorFromMidPoint(1.0f);
    decayTimeSlider.setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colours::darkslategrey);
    decayTimeSlider.setColour(juce::Slider::rotarySliderFillColourId, juce::Colours::orange);
    addAndMakeVisible(decayTimeSlider);

    decayTimeLabel.setText("Decay Time (s)", juce::dontSendNotification);
    decayTimeLabel.setJustificationType(juce::Justification::centred);
    decayTimeLabel.attachToComponent(&decayTimeSlider, false);
    addAndMakeVisible(decayTimeLabel);

    decayTimeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        valueTreeState, "decayTime", decayTimeSlider);
}

StereoReverbAudioProcessorEditor::~StereoReverbAudioProcessorEditor()
{
}

void StereoReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (juce::Colour(0xff22232b));

    g.setColour (juce::Colours::white);
    g.setFont (24.0f);
    g.drawFittedText ("Stereo Reverb", getLocalBounds().removeFromTop(40), juce::Justification::centred, 1);

    g.setColour(juce::Colours::grey);
    g.drawRoundedRectangle(30, 60, getWidth() - 60, getHeight() - 90, 16.0f, 2.0f);
}

void StereoReverbAudioProcessorEditor::resized()
{
    auto area = getLocalBounds().reduced(40, 20);
    auto sliderArea = area.removeFromBottom(120);

    roomSizeSlider.setBounds(sliderArea.removeFromLeft(sliderArea.getWidth()/2).reduced(20, 10));
    decayTimeSlider.setBounds(sliderArea.reduced(20, 10));
}
```

```cmake
#