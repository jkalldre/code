#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

//Defines what a flying object is
class FlyingObject
{
  protected:
   Point location;
   Velocity velocity;
   bool isAlive;

  public:
	  FlyingObject() {}
	  FlyingObject(int x, int y) { location.setX(x); location.setY(y); }
	  virtual void draw() = 0;
	  virtual void advance()     {}
	  
	  // Getters and Setters
	  Point getLocation()        { return location;        }
	  float getY()               { return location.getY(); }
	  float getX()               { return location.getX(); }
	  bool getAlive()            { return isAlive;         }
	  void kill()                { isAlive = false;        }
	  virtual void setVelocity()         {}
};

#endif
