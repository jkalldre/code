#include "normalBird.h"
#include <iostream>

/**************************************
* draw the bird
**************************************/
void NormalBird::draw()
{
	drawCircle(location, 10);
}

/**************************************
* move the bird
**************************************/
void NormalBird::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

/**************************************
* determine the angle and velocity of bird
**************************************/
void NormalBird::setVelocity()
{
	if (location.getY() < 0)
		velocity.setDy(random(1, 2));
	if (location.getY() >= 0)
		velocity.setDy(random(1, 2));

	velocity.setDx(random(3, 6));
}
