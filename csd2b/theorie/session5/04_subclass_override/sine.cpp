#include <iostream>
#include "sine.h"



Sine::Sine ()
{
  std::cout << "Sine - constructor Sine(double freq)\n";
}

Sine::~Sine()
{
  std::cout << "Sine - destructor\n";
}

void Sine::calc()
{
  std::cout << "Sine - calc\n";
}
