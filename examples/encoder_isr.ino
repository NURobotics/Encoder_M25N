#include <Encoder_M25N.h>

Encoder_M25N left_encoder;

void setup()
{
}

void loop()
{
}

ISR(PCINT18_vect)
{
  left_encoder.counter++;
}

ISR(PCINT20_vect)
{
  left_encoder.counter--;
}
