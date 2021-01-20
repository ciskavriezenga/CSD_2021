#include "Instrument.h"

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
