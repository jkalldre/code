#ifndef TOUGHBIRD_H
#define TOUGHBIRD_H
#include "bird.h"

//Attributes of a tough bird
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
    virtual void setScore()
	{
		if (hp > 1)
			score = 1;
		if (hp == 1)
			score = 3;
	}
};
#endif
