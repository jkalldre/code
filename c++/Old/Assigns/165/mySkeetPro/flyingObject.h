#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

class FlyingObject
{
  protected:
   Point location;
   Velocity velocity;
   bool onScreen;
   bool isAlive;

  public:
	  FlyingObject() {}
	  FlyingObject(int x, int y) { location.setX(x); location.setY(y); }
	  virtual void draw() = 0;
	  virtual void advance()     {}
	  Point getLocation()        { return location;        }
	  float getY()               { return location.getY(); }
	  float getX()               { return location.getX(); }
	  bool getAlive()            { return isAlive;         }
	  void kill()                { isAlive = false;        }
	  bool getOnScreen()         { return onScreen;        }
	  void setOnScreen(bool b)   { onScreen = b;           }
	  virtual void setVelocity()         {}
};

#endif
