#ifndef ship_h
#define ship_h

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5
#include "flyingObject.h"



// Put your Ship class here
class Ship : public FlyingObject
{
  private:
   int rotation;
   int lives;
  public:
	 Ship()
	 {
		 location = Point();
		 alive = true;
         rotation = 0;
		 lives = 3;
		 radius = 10;
	 }
  
	 int getRotation()  const { return rotation; }
	 int getLives()      const { return lives; }
	 virtual void draw();
 	 void turnRight();
 	 void turnLeft();
	 void thrust();
	 void breaks();
	 void advance();
	 void giveLife() { alive = true; }
	 void subLife() { --lives; }
};

#endif /* ship_h */
