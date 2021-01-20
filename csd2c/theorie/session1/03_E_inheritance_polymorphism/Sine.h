#include "Signal.h"

class Sine : public Signal {
public:
  Sine(float freq = 0);
  void process(float* const* const outputs, size_t channelCount, size_t frameCount, int sampleRate);
};
