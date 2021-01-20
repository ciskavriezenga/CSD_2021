#include "Square.h"
#include <cmath>

Square::Square(float freq) : Signal(freq) {}

void Square::process( float* const* const outputBuffer,
                      std::size_t numChannels,
                      std::size_t numFrames,
                      int sampleRate) {
  //NOTE -very dirty square generation! Additive sin() should be used instead
  double tempSample;

  for(int i = 0; i < numFrames; i++) {
    //calculate sample
    tempSample = sin(phase);
    if(tempSample >= 0) {
      outputBuffer[1][i] = 0.5;
    } else {
      outputBuffer[1][i] = -0.5;
    }

    phase += (freq / sampleRate) * twoPi ;
    if(phase > twoPi) {
      phase -= twoPi;
    }
  }
}
