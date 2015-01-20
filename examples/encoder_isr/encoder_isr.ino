#include <Encoder_M25N.h>

Encoder_M25N left_encoder;

int angle = 0;

void setup()
{
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  Serial.begin(9600);
  *digitalPinToPCMSK(18) |= bit (digitalPinToPCMSKbit(18));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(18)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(18)); // enable interrupt for the group 
  *digitalPinToPCMSK(19) |= bit (digitalPinToPCMSKbit(19));  // enable pin
  PCIFR  |= bit (digitalPinToPCICRbit(19)); // clear any outstanding interrupt
  PCICR  |= bit (digitalPinToPCICRbit(19)); // enable interrupt for the group 
}

void loop()
{
  analogWrite(12, HIGH);
  analogWrite(11, 255);
  angle = left_encoder.computeAngle();
  Serial.println(angle);
}

ISR(PCINT18_vect)
{
  left_encoder.counter = 1;
}

ISR(PCINT19_vect)
{
  left_encoder.counter = 1;
}
