#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  std::string getName();
  virtual void makeSound();

//a base class protected member will be accessible for a derived class
protected:
  Instrument(std::string name);
  //destructor
  /*
   * when a class contains a virtual method -> use virtual destructor,
   * to make sure that when deleting an object with pointer to base class
   * the child's constructor gets called as well!
   */
  virtual ~Instrument();

private:
  std::string name;
};




#endif
