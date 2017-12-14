#include "lander.h"
#include <iomanip>

Lander::Lander()
{
	fuel = 500;
	alive = true;
	//velocity = Velocity();
	position = Point();
}