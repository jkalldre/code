#ifndef NORMALBIRD_H
#define NORMALBIRD_H
#include "bird.h"

class NormalBird : public Bird
{
private:
public:
	NormalBird()
	{ 
		hp = 1;
	    score = 1;
		location = Point(-250, random(-50,50));
		isAlive = true;
		
	}
	virtual void draw();
	virtual void advance();
	virtual void setVelocity();
};
#endif