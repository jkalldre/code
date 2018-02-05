#include "toughBird.h"
#include <iostream>

/**************************************
* draw the bird
**************************************/
void ToughBird::draw()
{
	drawToughBird(location, 10, hp);
}

/**************************************
* move the bird
**************************************/
void ToughBird::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

/**************************************
* determine velocity and angle of bird
**************************************/
void ToughBird::setVelocity()
{
	if (location.getY() < 0)
		velocity.setDy(random(1, 2));
	if (location.getY() >= 0)
		velocity.setDy(random(-1, 0));

	velocity.setDx(random(2, 4));
}