#include "Sine.h"
/*
 * quote from http://www.cplusplus.com/doc/tutorial/polymorphism/
 * "Abstract classes are classes that can only be used as base classes, and thus
 * are allowed to have virtual member functions without definition (known as
 * pure virtual functions)."
 *
 * A class method can be a pure virtual function, which is a virtual function
 * with no definition. They start with the 'virtual' keyword and ends with '= 0'.
 *
 * TODO - add (bit more) explenation + HANDSON TIPS
 */

#define sampleRate 44100

int main() {
  int frameCount = 256;
  //create an outputBuffer
  float* outputBuffer = new float[frameCount];
  //create a Signal object
  Sine mySine(220);

  //let's call mySine process method 10 times
  for(int i = 0; i < 10; i++) {
    mySine.process(outputBuffer, frameCount, sampleRate);
    //print out values in outputBuffer
    for(int i = 0; i < frameCount; i++) {
      std::cout << ", " << outputBuffer[i];
    }
    std::cout << std::endl;
  }

  //delete output array
  delete [] outputBuffer;
  return 0;
}
