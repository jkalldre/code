/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   Date current;
   // prompt for month, day, year
   current.set();   
   // create a Date object
   
   // set its values
   
   // call each display function
   current.displayAmerican();
   current.displayEuropean();
   current.displayISO();

   return 0;
}
