#include "Instrument.h"

Instrument::Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside constructor Instrument()\n";
}

Instrument::Instrument(std::string aSound) {
  std::cout << "______ Instrument - ";
  std::cout << "inside constructor Instrument(std::string aSound)\n";
  sound = aSound;
}

//the deconstructor will be called when object is destroyed
//can be used to free up memory that was used to create the object
//or e.g. close an output file
Instrument::~Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside destructor\n";
}

void Instrument::makeSound() {
  std::cout << "A sound is produced: \"";
  std::cout << sound << "\"" << std::endl;
}

void Instrument::setSound(std::string aSound) {
  //check if string is not empty
  if(aSound.size() > 0) {
    sound = aSound;
  }
}

std::string Instrument::getSound() {
  return sound;
}
