#ifndef CIRCLE_H
#define CIRCLE_H
#include "point.h"

#include <iostream>

class Circle : public Point
{
   private:
    int radius;
    
   public:
    void promptForCircle();
    void display();
};

#endif