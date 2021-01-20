#include "Signal.h"

class Square : public Signal {
public:
  Square(float freq = 0);

  void process( float* const* const outputBuffer,
                std::size_t numChannels,
                std::size_t numFrames,
                int sampleRate);
};
