#include "PolyphonicInstrument.h"

/*
 * TODO - add information
 *
 * ------ HANDS-ON TIPS ------
 * TODO - add HANDS-ON TIPS
 * ---------------------------
 */

int main() {
  Instrument myInstrument;
  myInstrument.setNote(72);
  myInstrument.play();

  PolyphonicInstrument myPolyInstrument;
  myPolyInstrument.setNote(67);
  myPolyInstrument.play();

  std::cout << "\nEnding program\n";
  //exit the programm
  return 0;
}
