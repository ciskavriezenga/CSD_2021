#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  Instrument();
  Instrument(std::string aSound);
  //destructor
  ~Instrument();

  void makeSound();
  //setter and getter function
  void setSound(std::string aSound);
  std::string getSound();

private:
  std::string sound;
};




#endif
