#include "Instrument.h"

Instrument::Instrument(std::string name) {
 std::cout << "______ Instrument - ";
 std::cout << "inside constructor Instrument()\n";
 this->name = name;
}

Instrument::~Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside destructor\n";
}

std::string Instrument::getName() {
  return name;
}

void Instrument::makeSound() {
  std::cout << "______ Instrument - ";
  std::cout << "inside makeSound method.";
}
