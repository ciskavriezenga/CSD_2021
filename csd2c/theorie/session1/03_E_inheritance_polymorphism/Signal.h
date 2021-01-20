#ifndef H_SIGNAL
#define H_SIGNAL

#include <iostream>
#include <cmath>

class Signal {
public:
  //use default value for freq parameter
  Signal(float freq = 0);
  virtual ~Signal();

  virtual void process(float* const* const outputs, size_t channelCount, size_t frameCount, int sampleRate) = 0;

  void setFreq(float freq);
  float getFreq();

protected:
  //constexpr:  towPi should always stay the same -> constant expression
  //            a constant expression declares that it is possible to evaluate
  //            the value of the function or variable at compile time
  //static:     there is only one copy of the static member, even though
  //             multiple objects are created.
  static constexpr double  twoPi = 2 * M_PI;
  float freq;
  double phase;
};

#endif
