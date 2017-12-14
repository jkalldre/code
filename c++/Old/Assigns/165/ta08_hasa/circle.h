#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"
#include <iostream>

class Circle
{
  private:
   int radius;
   Point center;
   
  public:
   void promptForCircle();
   void display();
   int getX() { return center.getX(); }
   int getY() { return center.getY(); }
   int getRadius() { return radius; }
   void setX(float x) { center.setX(x); }
   void setY(float y) { center.setY(y); }
   void setR(int r)   { radius = r;     }
};


#endif