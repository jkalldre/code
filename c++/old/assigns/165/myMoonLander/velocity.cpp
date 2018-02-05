#include "velocity.h"
#include <iomanip>

/**************************************
* Constructors for velocity
**************************************/
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

/**************************************
* will set Dy variable
**************************************/
void Velocity::setDy(float dy)
{
	this->dy += dy;
}

/**************************************
* will set Dx Variable.
**************************************/
void Velocity::setDx(float dx)
{
	this->dx += dx;
}

/**************************************
* adds two velocities together
**************************************/
void Velocity::addOnto(Velocity v)
{
	dx += v.dx;
	dy += v.dy;
}