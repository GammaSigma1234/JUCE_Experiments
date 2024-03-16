#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent(void)
{
  // addAndMakeVisible(childComponent); // (GS) children components, if any, must be added this way. This particular example has no children.

  // Make sure you set the size of the component after you add any child components.
  setSize(800, 600);

  // setFramesPerSecond(m_frames_per_second); // This sets the frequency of the update calls.
  setSynchroniseToVBlank(true); // (GS) used to reduce the run-time stuttering of the animation. Replaces the previous instruction.
}

MainComponent::~MainComponent(void)
{;}

//==============================================================================
void MainComponent::update(void)
{
  // This function is called at the frequency specified by the `setFramesPerSecond()` call
  // in the constructor. You can use it to update counters, animate values, etc.
  const float x_centering = (float)getWidth()  / 2.0f;
  const float y_centering = (float)getHeight() / 2.0f;
  const float currentTime = getFrameCounter() * m_time_interval_s;
  m_xCoord  = x_centering + (float)m_radius * std::sin((float) currentTime * m_two_pi * m_frequency_hz);
  m_yCoord  = y_centering + (float)m_radius * std::cos((float) currentTime * m_two_pi * m_frequency_hz);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
  // Our component is opaque, so we must completely fill the background with a solid colour
  g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  // You can add your drawing code here!
  g.setColour(getLookAndFeel().findColour(juce::Slider::thumbColourId));
  juce::Point<float> p(m_xCoord, m_yCoord);

  g.fillEllipse(p.x, p.y, 30.0f, 30.0f);
}

void MainComponent::resized()
{
  // This is called when the MainContentComponent is resized.
  // If you add any child components, this is where you should update their positions.
}
