#include "toughBird.h"
#include <iostream>

void ToughBird::draw()
{
	drawToughBird(location, 10, hp);
}

void ToughBird::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

void ToughBird::setVelocity()
{
	if (location.getY() < 0)
		velocity.setDy(random(-1, 0));//2.0 *((cos(3.14159 / 180.0 * r))));
	if (location.getY() >= 0)
		velocity.setDy(random(0, 1));//2.0 *((cos(3.14159 / 180.0 * r))));

	velocity.setDx(random(2, 4));//2.0 *((-sin(3.14159 / 180.0 * r))));
}