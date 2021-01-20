#include "Instrument.h"

/*
 * This example contains a class with a defined deconstructor.
 *
 * Constructors and destructors are special function members of a class.
 * A constructor is called when an object is created.
 * A destructor is called when an object is destoryed.
 *
 * If a class definition does not contain a deconstructor definition, an implicit
 * deconstructor is used by default.
 *
 * ------ HANDS-ON TIPS ------
 * • Look at the text printed to the console, when is the destructor called?
 * ---------------------------
 */

int main() {
  //create an Instrument object
  Instrument myInstrument;

  //create another Instrument object, using the other constructor
  Instrument secondInstrument("Dong");

  //set the sound field by the use of setter
  myInstrument.setSound("Ding");
  //call the makeSound method 'make a sound into the console'
  myInstrument.makeSound();

  //secondInstrument.aSound is set in the constructor
  //therefor secontInstrument.makeSound will print 'Dong'
  secondInstrument.makeSound();

  //exit the programm -> deconstructor Instrument objects will be called
  return 0;
}
