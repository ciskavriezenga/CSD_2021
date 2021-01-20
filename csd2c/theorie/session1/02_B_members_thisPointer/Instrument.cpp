#include "Instrument.h"

Instrument::Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside constructor Instrument()\n";
}

Instrument::Instrument(std::string sound) {
  std::cout << "______ Instrument - ";
  std::cout << "inside constructor Instrument(std::string sound)\n";
  /*
   * the sound parameter has the same name as the Instrument object sound field
   * to refer to the Instrument object sound field we have to use
   * the this pointer: this->sound
   */
  this->sound = sound;
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

void Instrument::setSound(std::string sound) {
  //check if string is not empty
  if(sound.size() > 0) {
    /*
     * the sound parameter has the same name as the Instrument object sound field
     * to refer to the Instrument object sound field we have to use
     * the this pointer: this->sound
     */
    this->sound = sound;
  }
}

std::string Instrument::getSound() {
  return sound;
}
