#ifndef ENCODER_M25N_H
#define ENCODER_M25N_H

#include "Arduino.h"

class Encoder_M25N {
public:
  Encoder_M25N();
  int computeAngle();
  volatile int counter;
private:
  volatile int angle;
};

#endif // ENCODER_M25N_H
