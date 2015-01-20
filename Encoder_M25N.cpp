#include <Encoder_M25N.h>

Encoder_M25N::Encoder_M25N()
{
  // Initialization
	angle = 0;
}

int Encoder_M25N::computeAngle()
{
	angle = (counter % 26720)*360;
  	return angle;

}
