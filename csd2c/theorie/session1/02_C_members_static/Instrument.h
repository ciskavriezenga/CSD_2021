#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

//class declaration
class Instrument {
public:
  //constructor
  Instrument();

  void makeSound();
  std::string sound;
  //declare static field 'numInstruments'
  static int numInstruments;
};
//NOTE: always use a semicolon at end of class declaration



#endif
