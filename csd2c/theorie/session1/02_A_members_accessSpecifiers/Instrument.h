#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>
/*
* The default acces specifiers is 'private'.
* So in order to allow the use of a method from outside,
* you have to use the keyword public.
*
*
* The class Instrument contains:
* - public methods, e.g. setSound, a method with through which we can set
* the private field sound. 'setSound' is part of the Instrument class and it
* can therefor acces the private field 'sound'.
*
* - protected member, 'material'. This field can be accessed by the class
* itself (and friends) and derived classes.
*
* - private member, 'sound', This field cannot be accesed or viewed from
* outside the class. Only the class itself (and friends) can acces it.
*/

//class declaration
class Instrument {
public:
  void makeSound();
  //setter and getter function - sound field
  void setSound(std::string aSound);
  std::string getSound();

protected:
  std::string material;
private:
  std::string sound;
};




#endif
