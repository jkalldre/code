#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H
#include "bird.h"

class ToughBird : public Bird
{
private:
public:
	ToughBird()
	{ 
		hp = 3;
		score = 1;
		isAlive = true;
	    location = Point(-250, random(-50, 50));
	}
	virtual void draw();
	virtual void advance();
	virtual void setVelocity();
};
#endif
