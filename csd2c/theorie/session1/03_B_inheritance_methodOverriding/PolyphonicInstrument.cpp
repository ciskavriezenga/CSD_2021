#include "PolyphonicInstrument.h"

PolyphonicInstrument::PolyphonicInstrument() {
  std::cout << "______ PolyphonicInstrument - ";
  std::cout << "inside constructor PolyphonicInstrument()\n";
}

PolyphonicInstrument::~PolyphonicInstrument() {
  std::cout << "______ PolyphonicInstrument - ";
  std::cout << "inside destructor\n";
}

void PolyphonicInstrument::play() {
  //play a major chord.
  int note = getNote();
  std::cout << "playing notes " << note << ", " << note + 4 <<
               " and " << note + 7 << std:: endl;
}
