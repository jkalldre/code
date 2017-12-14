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

void Velocity::setDy(float dy)
{
	this->dy = dy;
}

void Velocity::setDx(float dx)
{
	this->dx = dx;
}

void Velocity::addOnto(Velocity v)
{
	dx += v.dx;
	dy += v.dy;
}