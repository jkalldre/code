#include <iostream>
#include "point.h"
#include "circle.h"

using namespace std;

void Circle::promptForCircle()
{
   promptForPoint();
   cout << "Enter radius: ";
   cin >> radius;
   
}
  
void Circle::display()
{
   Point::display();
   cout << " - Radius: " << radius << endl;
}