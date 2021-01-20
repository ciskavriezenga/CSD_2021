#include "Signal.h"

class Sine : public Signal {
public:
  Sine(float freq = 0);
  void process(float* output, int frameCount, int sampleRate);
};
