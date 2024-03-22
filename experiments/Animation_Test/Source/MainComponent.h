#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
  This component lives inside our window, and this is where you should put all your controls and content.
*/
class MainComponent  : public juce::AnimatedAppComponent
{
public:
  //==============================================================================
  MainComponent();
  ~MainComponent() override;

  //==============================================================================
  void update() override;

  //==============================================================================
  void paint (juce::Graphics& g) override;
  void resized() override;

private:
  //==============================================================================
  // Your private member variables go here...

  static constexpr  int    m_frames_per_second = 60;
  static constexpr  float  m_time_interval_s   = 1.0f / m_frames_per_second;
  static constexpr  float  m_two_pi            = 6.2832f;
  static constexpr  float  m_frequency_hz      = 0.5f;
  static constexpr  int    m_ellipseRadius     = 30;
  static constexpr  int    m_rotationRadius    = 150;
                    float  m_xCoord;
                    float  m_yCoord;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
