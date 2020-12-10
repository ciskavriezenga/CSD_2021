#define _USE_MATH_DEFINES
#include "sine.h"
#include <math.h>

Sine::Sine(float frequency, double samplerate) : frequency(frequency),
  samplerate(samplerate), amplitude(1.0), sample(0), phase(0)
{
  std::cout << "Sine - constructor\n";
}



Sine::~Sine() {
  std::cout << "Sine - destructor\n";
}


float Sine::getSample() {
  return sample;
}

void Sine::tick() {
  // NOTE - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / samplerate;
  sample = sin(M_PI * 2 * phase);
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Sine::getFrequency()
{
  return frequency;
}
