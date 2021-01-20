#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  Instrument();
  Instrument(std::string sound);
  //destructor
  ~Instrument();

  void makeSound();
  //setter and getter function - sound field
  void setSound(std::string sound);
  std::string getSound();

private:
  std::string sound;
};




#endif
