#include <iostream>

/*
 * NOTE
 * This example uses functionality from c++11
 * To compile this file without the use of a make file, run:
 * g++ -std=c++11  oscillator_extended.cpp -o osc
 *
 * other options:
 * c++11 / c++14 / c++17
 */

//access specifier: public, protected, private
// public: vanuit buitenaf te gebruiken
// protected, private: door het object zelf te gebruiken


static int oscCount = 0;

class Oscillator {
//access specifier
public:
  Oscillator();
  Oscillator(float freq);
  ~Oscillator();
  void setFreq(float freq);
  float getFreq();
  // TODO add setter, getter and field for amplitude
//access specifier
protected:
  float freq;
};

// constructor delegation
Oscillator::Oscillator () : Oscillator(220)
{}

// initialiser list
Oscillator::Oscillator(float freq) : freq(freq) {
  std::cout << "Oscillator - constructor Oscillator(float freq)\n";
  oscCount++;
}


Oscillator::~Oscillator()
{
  std::cout << "Oscillator - destructor\n";
  oscCount--;
}

void Oscillator::setFreq(float freq)
{
  if(freq > 0 && freq < 22050) {
    // this pointer, freq of class Oscillator
    this->freq = freq;
  } else {
    std::cout << "Incorrect frequency, please pass values between (0,22050)\n";
  }

}

float Oscillator::getFreq()
{
  return freq;
}

int main ()
{
  std::cout << "oscCount: " << oscCount << "\n";
  {
    Oscillator osc1;
    std::cout << "oscCount: " << oscCount << "\n";
  }
  std::cout << "oscCount: " << oscCount << "\n";
  Oscillator osc2;
  std::cout << "oscCount: " << oscCount << "\n";

  return 0;
}
