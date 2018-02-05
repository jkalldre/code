#include "normalBird.h"
#include <iostream>

void NormalBird::draw()
{
	drawCircle(location, 10);
}

void NormalBird::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

void NormalBird::setVelocity()
{
	if (location.getY() < 0)
		velocity.setDy(random(-2, -1));//3.0 *((cos(3.14159 / 180.0 * r))));
	if (location.getY() >= 0)
		velocity.setDy(random(1, 2));//3.0 *((cos(3.14159 / 180.0 * r))));

	velocity.setDx(random(3, 6));//5.0 *((-sin(3.14159 / 180.0 * r))));
}
