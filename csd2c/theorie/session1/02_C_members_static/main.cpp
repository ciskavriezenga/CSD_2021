#include <iostream>
#include "Instrument.h"

/*
 * This example contains a simple class with a static public field.
 *
 * ------ HANDS-ON TIPS ------
 * • change the static field numInstruments in a normal field, what result do
 * you expect?
 * ---------------------------
 */

int main() {
  //create the first Instrument object
  Instrument instrument1;

  std::cout <<  "\n\nWe created an instrument, " <<
                instrument1.numInstruments << " instrument exists.\n\n";

  //create a few more instruments
  Instrument instrument2;
  Instrument instrument3;
  Instrument instrument4;

  //note that we can use instrument1 to display numInstruments
  std::cout <<  "We created a few more instruments, " <<
                instrument1.numInstruments << " instruments exist.\n\n";

  //exit the programm
  return 0;
}
