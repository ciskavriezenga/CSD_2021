#include "StringInstrument.h"

/*
 * The ability to reuse code by deriving a class from a base class is called
 * class inheritance. This is part of object-oriented programming.
 * A derived class inherits methods and fields of its base class.
 * The base class, also called parent- or super class, contains members that
 * can be used in derived classes, also called sub- or child class.
 *
 * Which base class members are accesible to the derived class depend on the
 * acces specifiers ('public', 'private', 'protected') in the base class.
 * - public, is accesible from anywhere outside the class
 * - private, cannot be accesed or viewed from outside the class. Only the class
 * itself (and friends) can acces private members
 * - protected, same as private, but can also be accessed from derived classes
 *
 *
 * This example contains two classes:
 * - Instrument
 * - StringInstrument
 *
 * Instrument is the base class.
 * StringInstrument is the derived class.
 *
 * 'A string instrument is a instrument'
 * The relationship between Instrument and StringInstrument can be described
 * as a 'is a' relationship. For such a relationship inheritance is useful.
 *
 *
 * ------ HANDS-ON TIPS ------
 * • add protected method to the derived class. Try to use this method inside
 * the derived class. Can you use this method inside the main function?
 *
 * • change the protected method created above to a private method.
 * Can you still use this method inside the derived class?
 *
 * • add another derived class, e.g. WoodwindInstrument
 * ---------------------------

int main() {

  StringInstrument myStringInstrument("pling");

  std::cout << std::endl;
  myStringInstrument.makeSound();

  //exit the programm -> deconstructor Instrument objects will be called
  return 0;
}
