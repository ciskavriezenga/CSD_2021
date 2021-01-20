#include "Instrument.h"

/*
 * This example contains a simple class.
 * The class declaration is based inside a header file: Instrument.h
 * The class implementation is based inside a cpp file: Instrument.cpp
 *
 * ------ HANDS-ON TIPS ------
 * • Add another class member function, also called a method.
 *
 * • Add another class member variable, also called a field
 * ---------------------------
 */

int main() {
  //create an Instrument object
  Instrument myInstrument;

  //set the sound field
  myInstrument.sound = "Ding";

  //call the makeSound method 'make a sound into the console'
  myInstrument.makeSound();

  //exit the programm
  return 0;
}
