#include <iostream>
#include <thread>
#include "jack_module.h"
#include "writeToFile.h"
#include "math.h"
#include <limits>
#include <sstream>

#define BUFFER_SIZE 50
#define PLAY_AUDIO 0

// NOTE: source function to_string_with_precision:
// https://stackoverflow.com/questions/16605967/
//   set-precision-of-stdto-string-when-converting-floating-point-values
template <typename T>
std::string to_string_with_precision(const T a_value, const int n = 6)
{
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}


int main(int argc,char **argv)
{
  /*
  Starting with phase 0 --> no problem occure. We create a correct waveform.
  Starting at phase 8200 --> something 'strange' happens ;)
  Question: What is going wrong?
  */
  float phase = 0; // TODO: also try: 8200 as starting point
  float frequency = 882; // in 50 sample we are at phase 0 again
  float samplerate = 44100;
  const float minF = std::numeric_limits<float>::min();
  const float maxF = std::numeric_limits<float>::max();
  std::cout << "\nFloat range: [" << minF << ", " << maxF << "]\n";

  // write 1 period of the waveform to a file and a buffer
  WriteToFile fileWriter_output("data/data_output_sin.csv", true);
  WriteToFile fileWriter_input("data/data_input_sin.csv", true);
  WriteToFile fileWriter_phase("data/data_phase_delta.csv", true);

  // NOTE: M_PI value is of type double and are accurate within the precision
  // of the double type.
  std::cout.precision(40);
  std::cout << "M_PI value from the math lib: " << M_PI << "\n";
  std::cout << "M_PI value as float: " << float(M_PI) << "\n";



#if 0
  float buffer[BUFFER_SIZE];
  float prev_sin_input = 0;
  float prev_phase = 0;
  for(int i = 0; i < BUFFER_SIZE; i++) {
    //float sample = sin(phase * M_PI * 2.0f );
    float sin_input = (phase * M_PI * 2.0);
    float sample = sin(sin_input);

    fileWriter_output.write(std::to_string(sample) + "\n");
    fileWriter_input.write(std::to_string(sin_input) + "\n");
    phase += frequency / samplerate;
    if(i > 0) std::cout << phase - prev_phase << "\n";
    if(i > 0) fileWriter_phase.write(to_string_with_precision(phase - prev_phase) + "\n");
    // if(i > 0) std::cout << sin_input - prev_sin_input << "\n";
    buffer[i] = sample;
    prev_sin_input = sin_input;
    prev_phase = phase;
  }

#endif


#if PLAY_AUDIO
  // Now we are going to use the buffer with one waveform as source in the
  // jack audio callback function, so we can listen to its content.

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  // keep track of the current read position with a read head
  int readH = 0;
  //assign a function to the JackModule::onProces
  jack.onProcess = [&readH, buffer](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      outBuf[i] = buffer[readH];
      readH++;
      if(readH >= BUFFER_SIZE) readH -= BUFFER_SIZE;
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
#endif
  // end of program
  return 0;
}
