#include "Instrument.h"

class PolyphonicInstrument : public Instrument {
public:
  PolyphonicInstrument();
  ~PolyphonicInstrument();

  //overwrite play method, we want to play multiple tones
  void play();
};
