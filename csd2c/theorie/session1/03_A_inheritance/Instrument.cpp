#include "Instrument.h"

Instrument::Instrument() {
 std::cout << "______ Instrument - ";
 std::cout << "inside constructor Instrument()\n";
}

Instrument::Instrument(std::string sound, std::string playablePart) {
 std::cout << "______ Instrument - ";
 std::cout << "inside constructor Instrument(std::string sound, std::string playablePart)\n";
 this->sound = sound;
 this->playablePart = playablePart;
}

Instrument::~Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside destructor\n";
}

void Instrument::makeSound() {
  std::cout << "On \"" << playablePart << "\" ";
  std::cout << "a sound is produced: \"";
  std::cout << sound << "\"" << std::endl;
}

void Instrument::setSound(std::string sound) {
  //check if string is not empty
  if(sound.size() > 0) {
    this->sound = sound;
  }
}

void Instrument::setPlayablePart(std::string playablePart) {
  //check if string is not empty
  if(playablePart.size() > 0) {
    this->playablePart = playablePart;
  }

}

std::string Instrument::getPlayablePart() {
  return playablePart;
}

std::string Instrument::getSound() {
  return sound;
}
