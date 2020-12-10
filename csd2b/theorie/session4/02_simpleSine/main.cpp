#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include <limits>
/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */



int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();
  std::cout << "\n" << std::numeric_limits<float>::min() << "\n";
  std::cout << "\n" << std::numeric_limits<float>::max() << "\n";
  float phase = 8200;
  float amplitude = 0.5;
  float frequency = 880;
  float delta = frequency / samplerate;
  //assign a function to the JackModule::onProces
  jack.onProcess = [samplerate, &phase, delta, amplitude, frequency](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {


    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = amplitude * sin(phase * M_PI * 2.0f );
      phase += delta;//frequency / samplerate;
      if(((double)frequency / (double)samplerate) > (double)std::numeric_limits<float>::max()) {
        std::cout << "WRAPPED " << phase << "\n";
      }
      if(phase > 1.0) phase -= 1.0;
    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' ENTER when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
      case 'p':
        std::cout << "frequency: " << frequency << "\n";
        std::cout << "samplerate: " << samplerate << "\n";
        std::cout << "amplitude: " << amplitude << "\n";
        std::cout << "phase: " << phase << "\n";
        std::cout << "delta: " << delta << "\n";
        break;
    }
  }

  //end the program
  return 0;
} // main()
