#ifndef _OSCILLATOR_H_
#define _OSCILLATOR_H_

#pragma once

/*
 * NOTE
 * This example uses functionality from c++11
 * To compile this file without the use of a make file, run:
 * g++ -std=c++11  oscillator_extended.cpp -o osc
 *
 * other options:
 * c++11 / c++14 / c++17
 */


//access specifier: public, protected, private
// public: vanuit buitenaf te gebruiken
// protected, private: door het object zelf te gebruiken

class Oscillator {
//access specifier
public:
  Oscillator();
  Oscillator(float freq);
  ~Oscillator();
  void setFreq(float freq);
  float getFreq();
  // TODO add setter, getter and field for amplitude
//access specifier
protected:
  float freq;
};

#endif

