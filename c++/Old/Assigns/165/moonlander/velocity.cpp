#include "velocity.h"
#include <iomanip>

Velocity::Velocity()
{
	dx = 0;
	dy = 0;
}

Velocity::Velocity(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}