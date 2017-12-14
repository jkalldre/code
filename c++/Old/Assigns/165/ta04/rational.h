/***************************************************************
 * File: rational.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Rational class
 ***************************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H

// put your class definition here
class Rational
{
  public:
   int top;
   int bottom;
   int mTop;
   int mBottom;

   void prompt();
   void display();
   void displayDecimal();
   void multiplyBy();
};


#endif
