#include "Instrument.h"


/*
 * quote from https://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm
 * "Every object in C++ has access to its own address through an important
 * pointer called this pointer. The this pointer is an implicit parameter
 * to all member functions. Therefore, inside a member function,
 * this may be used to refer to the invoking object."
 *
 * ------ HANDS-ON TIPS ------
 * • Locate the this pointer in the Instrument.cpp file
 * • Remove the this pointer, what do expect to happen?
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
