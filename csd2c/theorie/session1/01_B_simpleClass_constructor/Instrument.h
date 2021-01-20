#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  //default constructor (different from the implicit default constructor)
  Instrument();
  //it is possible to overload the constructor to allow setting aSound string
  Instrument(std::string aSound);

  void makeSound();
  //setter and getter function
  void setSound(std::string aSound);
  std::string getSound();

private:
  std::string sound;
};




#endif
