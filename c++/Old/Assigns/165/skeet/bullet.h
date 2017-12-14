#ifndef BULLET_H
#define BULLET_H
#include "flyingObject.h"

//Defines what a bullet is
class Bullet : public FlyingObject
{
  public:
	  Bullet();
	  Bullet(int x, int y);
	  ~Bullet() {}
	  
	  void setVelocity(float a);
	  virtual void advance();
	  bool shot;
	  void reset(int x, int y);
	  void shoot(bool b) { shot = b; }
	  Point gunAngle;
	  virtual void draw();
	  bool getShot()           { return shot; }

  private:
	 

};


#endif 
