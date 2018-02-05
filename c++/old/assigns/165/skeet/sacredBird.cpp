#include "sacredBird.h"
#include <iostream>

/**************************************
* draw the bird
**************************************/
void SacredBird::draw()
{
	drawSacredBird(location, 10);
}

/**************************************
* move the bird
**************************************/
void SacredBird::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

/**************************************
* determine angle and velocity of bird
**************************************/
void SacredBird::setVelocity()
{
	if (location.getY() < 0)
		velocity.setDy(random(-1, 1));
	if (location.getY() >= 0)
		velocity.setDy(random(1, 2));

	velocity.setDx(random(3, 6));
}