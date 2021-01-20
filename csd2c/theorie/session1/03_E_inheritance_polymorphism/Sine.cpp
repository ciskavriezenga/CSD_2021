#include "Sine.h"

Sine::Sine(float freq) : Signal(freq) {}

void Sine::process(float* const* const outputs, size_t channelCount, size_t frameCount, int sampleRate) {
  for (int frame = 0; frame < frameCount; ++frame)
  {
    // Generate the new output sample
    auto sample = sin(phase);

    // Increase the phase for next round
    phase += freq / sampleRate * twoPi;
    if (phase >= twoPi)
      phase -= twoPi;

    // Iterate over the channels
    for (auto channel = 0; channel < channelCount; ++channel) {
      outputs[channel][frame] = sample * 0.4;
    }
  }
}
