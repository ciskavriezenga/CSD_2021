#include <iostream>
#include "oscillator.h"



// constructor delegation
Oscillator::Oscillator () : Oscillator(220)
{}

// initialiser list
Oscillator::Oscillator(float freq) : freq(freq) {
  std::cout << "Oscillator - constructor Oscillator(float freq)\n";
}


Oscillator::~Oscillator()
{
  std::cout << "Oscillator - destructor\n";
}

void Oscillator::setFreq(float freq)
{
  if(freq > 0 && freq < 22050) {
    // this pointer, freq of class Oscillator
    this->freq = freq;
  } else {
    std::cout << "Incorrect frequency, please pass values between (0,22050)\n";
  }

}

float Oscillator::getFreq()
{
  return freq;
}

