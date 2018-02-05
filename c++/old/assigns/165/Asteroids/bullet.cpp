#include "bullet.h"
#include "uiDraw.h"

// Put your bullet methods here
/**********************************************
* draw:
*	draw the bullets
***********************************************/
void Bullet::draw()
{
	drawDot(location);
}

/**********************************************
* advance:
*	advance each bullet on screen
***********************************************/
void Bullet::advance()
{
	velocity.setDy(  (cos(3.14159 / 180.0 * angle) * 5.0));
	velocity.setDx(  (-sin(3.14159 / 180.0 * angle) * 5.0));

	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

/**********************************************
* dieSlowly:
*	causes the bullets to disappear after 40
*   frames.
***********************************************/
void Bullet::dieSlowly()
{
	if (lifeSpan != 0)
		lifeSpan--;
	else
		alive = false;	
}


