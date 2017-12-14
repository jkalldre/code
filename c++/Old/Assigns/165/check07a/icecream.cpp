/***********************************
 * File: icecream.cpp
 ***********************************/
#include "icecream.h"

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

float IceCream :: salesTax = .06;
/***********************************
 * Constructors
 ***********************************/
IceCream::IceCream()
{
   flavor = "unknown";
   price = 0;
   
}

IceCream::IceCream(string flavor, float price)
{
   this->flavor = flavor;
   this->price = price;
}

/**********************************************************************
 * Function: IceCream::getTotalPrice
 * Purpose: Gets the total price of the ice cream, including sales tax.
 **********************************************************************/
float IceCream::getTotalPrice() const
{
   // TODO: Change this to include sales tax
   
   return (price * (1 + salesTax));
}

/**********************************************************************
 * Function: IceCream::getTotalPrice
 * Purpose: Prompts the user for the values of ice cream.
 **********************************************************************/
void IceCream::prompt()
{
   cout << "Flavor: ";
   getline(cin, flavor);

   // It would be better to check for bad values here...
   cout << "Price: ";
   cin >> price;
   cin.ignore();
}

/**********************************************************************
 * Function: IceCream::display
 * Purpose: Displays the current ice cream.
 **********************************************************************/
void IceCream::display() const
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "$" << getTotalPrice() << " - " << flavor << endl;
}

