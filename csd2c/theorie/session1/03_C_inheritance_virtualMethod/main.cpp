#include "StringInstrument.h"


/*
 * NOTE: Checkout out example 04_dynamic/01_simplePointer first
 * TODO - add explenation + HANDSON TIPS
 */
int main() {
  //create a StringInstrument object and pass a name as parameter.
  StringInstrument myStringInstrument("My Precious");

  std::cout << std::endl;
  myStringInstrument.makeSound();

  // create Instrument pointer to the StringIntstrument object
  Instrument *instrument = (Instrument*) &myStringInstrument;
  // call the makeSound method --> because this is a virtual method, the method
  // of the subclass will be called. 
  instrument->makeSound();
  //exit the programm -> deconstructor Instrument objects will be called
  return 0;
}
