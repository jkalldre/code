/***************************************************************
 * File: rational.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Rational class.
 ***************************************************************/

#include "rational.h"
#include <iostream>

using namespace std;
// put your method bodies here
void Rational::prompt()
{
   cout << "Top: ";
   cin >> top;
   cout << "Bottom: ";
   cin >> bottom;
   
   cout << "Top 2: ";
   cin >> mTop;
   cout << "Bottom 2: ";
   cin >> mBottom;
}

void Rational::display()
{
   if (top < bottom)
      cout << top << "/" << bottom << endl;
   else
      cout << top/bottom << " " << (top % bottom) << "/" << bottom << endl;  
}

void Rational::displayDecimal()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << (float)top / (float)bottom << endl;
}

void Rational::multiplyBy()
{
   cout << endl << (top*mTop) << "/" << (bottom*mBottom) << endl;  
}