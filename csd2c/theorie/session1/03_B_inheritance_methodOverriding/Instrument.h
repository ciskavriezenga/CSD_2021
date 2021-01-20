#ifndef H_INSTRUMENT
#define H_INSTRUMENT

#include <iostream>

class Instrument {
public:
  //constructor and destructor
  Instrument();
  ~Instrument();

  void play();

  //getters and setters
  void setNote(int note);
  int getNote();

private:
  int note;
  int noteMin;
  int noteMax;
};




#endif
