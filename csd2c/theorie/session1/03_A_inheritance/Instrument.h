#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  void makeSound();

  //getters and setters
  void setSound(std::string sound);
  std::string getSound();
  void setPlayablePart(std::string playablePart);
  std::string getPlayablePart();

//a base class protected member will be accessible for a derived class
protected:
  Instrument();
  /*
   * inside a function declaration you can set a default argument
   * when the constructor below is called, with only the first string,
   * playablePart is set to "an unknown part"
   */
  Instrument(std::string sound, std::string playablePart = "an unknown part");
  //destructor
  ~Instrument();

private:
  std::string sound;
  std::string playablePart;
};




#endif
