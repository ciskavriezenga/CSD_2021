#include "StringInstrument.h"

StringInstrument::StringInstrument(std::string aSound) : Instrument(aSound, "a string") {
  std::cout << "______ StringInstrument - ";
  std::cout << "inside constructor StringInstrument(std::string aSound)\n";
}
