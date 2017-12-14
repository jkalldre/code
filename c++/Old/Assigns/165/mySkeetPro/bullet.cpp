#include "bullet.h"
#include <iostream>



Bullet::Bullet()
{
	location = Point(200, -200);
	onScreen = false;
	velocity = Velocity();
	shot = false;
	
}

Bullet::Bullet(int x, int y)
{
	location = Point(x, y);
	onScreen = false;
	velocity = Velocity();
	shot = false;
	isAlive = true;
}

void Bullet::reset(int x, int y)
{
	location = Point(x, y);
	onScreen = false;
	velocity = Velocity();
	shot = false;
}

void Bullet::draw()
{
	drawDot(location);
}

void Bullet::setVelocity(float a)
{
	velocity.setDy((10.0 * (cos(3.14159 / 180.0 * a))));
	velocity.setDx((10.0 * (-sin(3.14159 / 180.0 * a))));
}

void Bullet::advance(float a)
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}