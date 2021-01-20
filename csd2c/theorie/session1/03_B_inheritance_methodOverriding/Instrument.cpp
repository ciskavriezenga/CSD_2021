#include "Instrument.h"

Instrument::Instrument() {
 std::cout << "______ Instrument - ";
 std::cout << "inside constructor Instrument()\n";
 noteMin = 48;
 noteMax = 72;
 note = noteMin;
}

Instrument::~Instrument() {
  std::cout << "______ Instrument - ";
  std::cout << "inside destructor\n";
}

void Instrument::play() {
    std::cout << "playing note " << note << std::endl;
}

void Instrument::setNote(int note) {
  //if note is outside allowed range -> return
  if(note < noteMin || note > noteMax) {
    std::cout << "______ Instrument - setNote(int note) " <<
                  "received un incorrect value\n" <<
                  "Only use values from " << noteMin <<
                  " to " << noteMax << std::endl;
    return;
  }
  this->note = note;
}

int Instrument::getNote() {
  return note;
}
