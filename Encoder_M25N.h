#include "Arduino.h"

class Encoder_M25N {
public:
  Encoder_M25N();
  int computeAngle();
  volatile int counter;
private:
  volatile int angle;
};
