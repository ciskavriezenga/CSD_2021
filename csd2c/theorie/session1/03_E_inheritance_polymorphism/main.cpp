#include <bear/Audio/File.hpp>
#include <bear/Audio/Output.hpp>
#include "Sine.h"
#include "Square.h"
/*
 * NOTE: example is not finished yet, but working.
 * TODO - add explenation + HANDSON TIPS
 */

using namespace bear;
using namespace unit;

int main() {
  //create a Signal object
  Sine mySine(220);

  //create a Square object
  Square mySquare(220);

  /*
   * Because Sine and Square are both derived classes of Signal, we can
   * assign objects of both types to a Signal pointer.
   */
  //create a Signal pointer and assign to address of mySine
  Signal* mySignal = &mySine;

  //retrieve bear default audio output object
  auto& output = audio::Output::getDefaultOutput();

  //create onOutput function using labmda function (see \05_cpp11And14\01_lambdaFunction)
  output.onOutput = [&](auto outputs, size_t channelCount, size_t frameCount)
  {
    const unit::hertz<float> sampleRate = output.getSampleRate();

    /*
     * through the mySignal pointer we can call the process method of the object
     * that mySignal points to. This could be mySine.process or mySquare.process,
     * both different type of objects -> POLYMORPHISM!!
     */
    mySignal->process(outputs, channelCount, frameCount, sampleRate.value);
  };

  std::cout <<  "\n\n*********************************\n" <<
                "Starting an audio signal.\n" <<
                "You can select the type of signal, " <<
                "enter 1 or 2 below on the commandline:\n" <<
                "1 -> sinewave\n" <<
                "2 -> squarewave\n";
  output.start();

  bool running = true;
  while (running)
  {
      switch (std::cin.get())
      {
          case 'q': running = false; break;
          case '1':
            mySignal = &mySine;
            break;
          case '2':
            mySignal = &mySquare;
            break;
      }
  }

  // Stop the output stream
  output.stop();

  return 0;
}
