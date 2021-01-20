#include "Instrument.h"

/*
 * Inside a class declaration, you can use the access specifiers 'public',
 * 'protected' and 'private' to set the acces restriction of class members.
 * - public, is accesible from anywhere outside the class
 * - private, cannot be accesed or viewed from outside the class. Only the class
 * itself (and friends) can acces private members
 * - protected, same as private, but can also be accessed from derived classes
 *
 *
 * ------ HANDS-ON TIPS ------
 * • Why would you want to add a public method to a class to set / get a
 * private field?
 *
 * • Add a class that inheriteds from Instrument. Try to access the protected
 * and private fields fromout this derived class.
 *
 * • Try accessing the field 'sound' directly inside the main function:
 * myInstrument.sound;
 * And before running make, what do you expect to happen?
 *
 * • Move the field 'sound' below the 'public' acces specifier. Can you acces
 * it directly from the main?
 * ---------------------------
 */


int main() {
  //create an Instrument object
  Instrument myInstrument;

  //line below would not work, because sound is a private field
  //myInstrument.sound = "Ding";

  //set the sound field by the use of setter
  myInstrument.setSound("Ding");
  //print the content of the sound field to console, by the use of getter
  std::cout << "myInstrument.sound contains: \"";
  std::cout << myInstrument.getSound() << "\"" << std::endl;

  //call the makeSound method 'make a sound into the console'
  myInstrument.makeSound();

  //exit the programm
  return 0;
}
