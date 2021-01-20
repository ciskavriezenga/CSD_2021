#include <iostream>
#include <cmath>

class Signal {
public:
  //use default value for freq parameter
  Signal(float freq = 0);
  virtual ~Signal();

  // a pure virtual function
  virtual void process(float* output, int frameCount, int sampleRate) = 0;

  void setFreq(float freq);
  float getFreq();

protected:
  float freq;
  double phase;
};
