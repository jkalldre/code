#include "sacredBird.h"
#include <iostream>

void SacredBird::draw()
{
	drawSacredBird(location, 10);
}

void SacredBird::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

void SacredBird::setVelocity()
{
	if (location.getY() < 0)
		velocity.setDy(random(-2, -1));//5.0 *((cos(3.14159 / 180.0 * r))));
	if (location.getY() >= 0)
		velocity.setDy(random(1, 2));//5.0 *((cos(3.14159 / 180.0 * r))));

	velocity.setDx(random(3, 6));//5.0 *((-sin(3.14159 / 180.0 * r))));
}