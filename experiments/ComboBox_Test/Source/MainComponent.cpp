#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
  addAndMakeVisible (textLabel);
  textLabel.setFont (textFont);

  addAndMakeVisible (styleMenu);
  styleMenu.addItem ("Plain",  1);
  styleMenu.addItem ("Bold",   2);
  styleMenu.addItem ("Italic", 3);
  styleMenu.onChange = [this](void){ styleMenuChanged(); };
  styleMenu.setSelectedId (1);

  setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
  // (Our component is opaque, so we must completely fill the background with a solid colour)
  g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

  g.setFont (juce::Font (16.0f));
  g.setColour (juce::Colours::white);
  g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
  // This is called when the MainComponent is resized.
  // If you add any child components, this is where you should
  // update their positions.

  textLabel  .setBounds (10, 10, getWidth() - 20, 40);
  styleMenu  .setBounds (10, 40, getWidth() - 20, 40);
  // coloursMenu.setBounds (10, 70, getWidth() - 20, 20);
}

void MainComponent::styleMenuChanged(void)
{
  switch (styleMenu.getSelectedId())
  {
    case 1: textFont.setStyleFlags (juce::Font::plain);  break;
    case 2: textFont.setStyleFlags (juce::Font::bold);   break;
    case 3: textFont.setStyleFlags (juce::Font::italic); break;
    default: break;
  }

  textLabel.setFont (textFont);
}