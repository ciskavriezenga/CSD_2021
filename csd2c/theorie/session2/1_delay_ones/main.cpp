#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */
// 10 seconds if samplerate = 44100
#define DELAY_SIZE 441000


#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);

  float delayBuffer[DELAY_SIZE];
  int writeHead = 0;
  int readHead = 0;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&delayBuffer, &writeHead, &readHead](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // write audio input to delay buffer, until buffer is full
      if(writeHead < DELAY_SIZE) {
        delayBuffer[writeHead] = inBuf[i];
        writeHead++;
        outBuf[i] = 0;
      } // if delay buffer is full, play from delay buffer until end
      else if (readHead < DELAY_SIZE){
        outBuf[i] = delayBuffer[readHead];
        readHead++;
      } // if delay buffer is played --> audio output 0
      else {
        outBuf[i] = 0;
      }
    }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }

  //end the program
  return 0;
} // main()
