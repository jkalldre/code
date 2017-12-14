#ifndef SACREDBIRD_H
#define SACREDBIRD_H
#include "bird.h"

class SacredBird : public Bird
{
   private:
  
public:
	SacredBird()
	{
		hp = 1;
		score = -10;
		isAlive = true;
		location = Point(-250, random(-50, 50));
	}
	virtual void draw();
	virtual void advance();
	virtual void setVelocity();
};
#endif
