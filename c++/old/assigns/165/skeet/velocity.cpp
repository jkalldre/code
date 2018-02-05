#include "velocity.h"
#include <iomanip>

/**************************************
* Default constructor
**************************************/
Velocity::Velocity()
{
	dx = 0;
	dy = 0;
}

/**************************************
* Nondefault constructor
**************************************/
Velocity::Velocity(float dx, float dy)
{
	this->dx = dx;
	this->dy = dy;
}

/**************************************
* setter
**************************************/
void Velocity::setDy(float dy)
{
	this->dy = dy;
}

/**************************************
* setter
**************************************/
void Velocity::setDx(float dx)
{
	this->dx = dx;
}

/**************************************
* combine two velocities
**************************************/
void Velocity::addOnto(Velocity v)
{
	dx += v.dx;
	dy += v.dy;
}