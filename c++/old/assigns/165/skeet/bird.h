#ifndef BIRD_H
#define BIRD_H
#include "flyingObject.h"

//Defines what a bird is
class Bird : public FlyingObject
{
  protected:
   int hp;
   int score;
   int r;

  public:
	  Bird() {}
	  virtual void advance() = 0;
	  int getHp()    { return hp;    }
	  void subtractHp() { hp -= 1; }
	  int getScore() { return score; }
	  virtual void draw() = 0;
	  virtual void setVelocity() {}
	  virtual void setScore() {}
};

#endif