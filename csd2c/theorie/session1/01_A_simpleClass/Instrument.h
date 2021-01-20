#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

/*
 * Inside a class declaration, you can use the acces specifiers 'public',
 * 'protected' and 'private' to set the acces restriction of class members.
 * - public, is accesible from anywhere outside the class
 * - private, cannot be accesed or viewed from outside the class. Only the class
 * itself (and friends) can acces private members
 * - protected, same as private, but can also be accessed in derived classes
 *
 * The default is 'private'. So in order to allow the use of a method from
 * outside, you have to use the keyword public, as below.
 */

//class declaration
class Instrument {
public:
//__ member functions a.k.a. methods __
  void makeSound();

//__ member variables a.k.a. fields __
  std::string sound;
};
//NOTE: always use a semicolon at end of class declaration



#endif
