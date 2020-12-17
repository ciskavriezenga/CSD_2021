#include <iostream>
#include "oscillator.h"




Oscillator::Oscillator ()
{
  std::cout << "Oscillator - constructor Oscillator(double freq)\n";
}



Oscillator::~Oscillator()
{
  std::cout << "Oscillator - destructor\n";
}



void Oscillator::tick()
{
  std::cout << "Oscillator - tick\n";
  calc();
}

void Oscillator::calc()
{
  std::cout << "Oscillator - calc\n";
}
