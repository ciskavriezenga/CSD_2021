#include "Instrument.h"

//initialize static field 'numInstruments'
int Instrument::numInstruments = 0;

Instrument::Instrument() {
  numInstruments++;
}

void Instrument::makeSound() {
  std::cout << "A sound is produced: \"";
  std::cout << sound << "\"" << std::endl;
}
