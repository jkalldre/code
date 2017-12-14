#include "ship.h"
#include <iostream>
#include "uiDraw.h"


void Ship::draw()
{
	drawShip(location, rotation, false);
}

void Ship::turnRight()
{
  rotation -= 6;
}

void Ship::turnLeft()
{
  rotation += 6;
}

void Ship::thrust()
{
	velocity.addDy(cos(3.14159 / 180.0 * rotation) / 5);
    velocity.addDx(-sin(3.14159 / 180.0 * rotation) / 5);

	if ((velocity.getDx() * velocity.getDx()) + (velocity.getDy() * velocity.getDy()));

}

void Ship::breaks()
{
	if (velocity.getDy() > 0)
	   velocity.addDy(-0.3);
	if (velocity.getDy() < 0)
	   velocity.addDy(0.3);
	if (velocity.getDx() > 0)
	   velocity.addDx(-0.3);
	if (velocity.getDx() < 0)
		velocity.addDx(0.3);
	if (velocity.getDx() >= -0.5 && velocity.getDx() <= 0.5)
		velocity.setDx(0);
	if (velocity.getDy() >= -0.5 && velocity.getDy() <= 0.5)
		velocity.setDy(0);
}

void Ship::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}
// Put your ship methods here

