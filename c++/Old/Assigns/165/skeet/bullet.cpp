#include "bullet.h"
#include <iostream>


/**************************************
* Default constructor
**************************************/
Bullet::Bullet()
{
	location = Point(200, -200);
	//onScreen = false;
	velocity = Velocity();
	shot = false;
	
}

/**************************************
* nondefault constructor
**************************************/
Bullet::Bullet(int x, int y)
{
	location = Point(x, y);
	//onScreen = false;
	velocity = Velocity();
	shot = false;
	isAlive = true;
}

/**************************************
* reset bullet conditions
**************************************/
void Bullet::reset(int x, int y)
{
	location = Point(x, y);
	//onScreen = false;
	velocity = Velocity();
	shot = false;
}

/**************************************
* draw the bullet
**************************************/
void Bullet::draw()
{
	drawDot(location);
}

/**************************************
* set bullet velocity
**************************************/
void Bullet::setVelocity(float a)
{
	velocity.setDy((10.0 * (cos(3.14159 / 180.0 * a))));
	velocity.setDx((10.0 * (-sin(3.14159 / 180.0 * a))));
}

/**************************************
* move the bullet
**************************************/
void Bullet::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}