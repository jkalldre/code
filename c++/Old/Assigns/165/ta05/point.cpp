#include "point.h"

#include <iostream>
using namespace std;

/******************************************
 * Function: display
 * Purpose: Displays the point
 ******************************************/
void Point :: display() const
{
   cout << "(" << getX() << ", " << getY() << ")";
}

Point::Point()
{
   x = 5;
   y = 5;
}

Point::Point(int inputX, int inputY)
{
   setX(inputX);
   setY(inputY);
}

