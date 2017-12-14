#ifndef ROBOT_H
#define ROBOT_H

#include "point.h"
using namespace std;
class Robot
{
private:
   Point position;
   int energy;

public:
   Robot();
   Robot(int iEnergy);
   Robot(Point inputPosition, int iEnergy);
   void moveUp();
   void moveDown();
   void moveLeft();
   void moveRight();
   void fireLaser();
   void display() const;
   int getEnergy() const
   {
      return energy;
   }
   void setEnergy(int energyInput)
   {
      if (energyInput < 0)
         energy = 0;
      else
         energy = energyInput;
   }
   void setPosition(Point positionInput)
   {
      position = positionInput;
   }

};

#endif
