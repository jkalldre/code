#include "bullet.h"
#include "uiDraw.h"

void Bullet::draw()
{
	drawDot(location);
}

void Bullet::advance()
{
	velocity.setDy(  (cos(3.14159 / 180.0 * angle) * 5.0));
	velocity.setDx(  (-sin(3.14159 / 180.0 * angle) * 5.0));

	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

void Bullet::dieSlowly()
{
	if (lifeSpan != 0)
		lifeSpan--;
	else
		alive = false;	
}

// Put your bullet methods here
