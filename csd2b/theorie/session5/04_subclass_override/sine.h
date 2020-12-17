#ifndef _Sine_H_
#define _Sine_H_
#include "oscillator.h"
#define SAMPLERATE 44100

#pragma once


class Sine : public Oscillator {
//access specifier
public:
  Sine();
  ~Sine();
  // override base class method
  void calc();

};

#endif
