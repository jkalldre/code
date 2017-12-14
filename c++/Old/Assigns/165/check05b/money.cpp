/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);  
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display()
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

int Money :: setDollars(int d)
{
   if (d < 0)
      dollars = (d * -1);
   else
      dollars = d;      
}

int Money :: setCents(int c)
{
   if (c < 0)
      cents = (c * -1);
   else
      cents = c;   
}

Money::Money()
{
   dollars = 0;
   cents = 0;
}
   
Money::Money(int iDollars)
{
   setDollars(iDollars);
   cents = 0;
}
   
Money::Money(int iDollars, int iCents)
{
   setDollars(iDollars);
   setCents(iCents);
}
