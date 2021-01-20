#include "Signal.h"


//member initialisation -> freq(freq)
Signal::Signal(float freq) : freq(freq) {
  phase = 0;
}

Signal::~Signal(){}

void Signal::setFreq(float freq) {
  this->freq = freq;
}

float Signal::getFreq() {
  return freq;
}
