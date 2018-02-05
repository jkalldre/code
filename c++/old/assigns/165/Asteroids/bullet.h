#ifndef bullet_h
#define bullet_h

#define BULLET_SPEED 5
#define BULLET_LIFE 40
#include "flyingObject.h"
#include "ship.h"

// Put your Bullet class here
class Bullet : public FlyingObject
{
private:
	int lifeSpan; // how long bullets stay on screen
	int angle;
public:
	Bullet(Ship s)
	{
		location = s.getPoint();
		velocity.setDx(s.getVelocity().getDx() + 5.0);
		velocity.setDy(s.getVelocity().getDy() + 5.0);
		alive = true;
		lifeSpan = 40;
		angle = s.getRotation();
		radius = 1;
	}
	virtual void draw();
	void advance();
	void dieSlowly();
};



#endif /* bullet_h */
