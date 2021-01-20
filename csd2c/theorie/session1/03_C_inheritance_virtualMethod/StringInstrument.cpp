#include "StringInstrument.h"

StringInstrument::StringInstrument(std::string name) : Instrument(name) {
  std::cout << "______ StringInstrument - ";
  std::cout << "inside constructor StringInstrument(std::string name)\n";
}

void StringInstrument::makeSound() {
  std::cout << "On a string instrument, known by the name \"" << getName();
  std::cout << "\" a sound is played: pling" << std::endl;
}
