#include "Sine.h"

Sine::Sine(float freq) : Signal(freq) {}

void Sine::process(float* output, int frameCount, int sampleRate) {
  for (int frame = 0; frame < frameCount; ++frame)
  {
    // Generate the new output sample
    auto sample = sin(phase);

    // Increase the phase for next round
    phase += freq / sampleRate * 2 * M_PI;
    if (phase >= 2 * M_PI)
      phase -= 2 * M_PI;

    output[frame] = sample;
  }
}
