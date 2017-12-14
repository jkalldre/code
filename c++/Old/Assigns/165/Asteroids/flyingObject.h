#ifndef flyingObject_h
#define flyingObject_h
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

// Put your FlyingObject class here
class FlyingObject
{
protected:
	bool alive;
	Point location;
	Velocity velocity;
	int radius;

public:
	virtual void advance() = 0;
	virtual void draw() = 0;
	
	// getters and setters
	bool isAlive()         const { return alive;            }  
	void kill()                  { alive = false;           }
	int getSize()          const { return radius;           }
	Velocity getVelocity() const { return velocity;         }
	Point getPoint()       const { return location;         }
	int getX()             const { return location.getX();  }
	int getY()             const { return location.getY();  }
	void setX(int f)             { location.setX(f);        }
	void setY(int f)             { location.setY(f);        }
	void setDx(float f)          { velocity.setDx(f);       }
	void setDy(float f)          { velocity.setDy(f);       }
	float getDx()          const { return velocity.getDx(); }
	float getDy()          const { return velocity.getDy(); }
};



#endif /* flyingObject_h */
