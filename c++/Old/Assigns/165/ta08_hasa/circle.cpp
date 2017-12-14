#include <iostream>
#include "circle.h"

using namespace std;

void Circle::promptForCircle()
{
   center.promptForPoint();
   cout << "Radius: ";
   cin >> radius;
}
 
void Circle::display()
{
   center.display();
   cout << " - Radius: " << radius << endl;
}