#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_


#pragma once


class Oscillator {
//access specifier
public:
  Oscillator();
  ~Oscillator();
  void tick();
  virtual void calc();


};

#endif
