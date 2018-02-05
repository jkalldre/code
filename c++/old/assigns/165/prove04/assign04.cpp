/***************************************************************
 * File: assign04.cpp
 * Author: (your name here)
 * Purpose: Contains the main function to test the Product class.
 ***************************************************************/

#include <iostream>
#include <string>
using namespace std;

#include "product.h"

int main()
{
   // Declare your Product object here
   Product x;   
   
   
   // Call your prompt function here
   x.prompt();
   x.getSalesTax();
   x.getShippingCost();
   x.getTotalPrice();

   cout << endl;
   cout << "Choose from the following options:\n";
   cout << "1 - Advertising profile\n";
   cout << "2 - Inventory line item\n";
   cout << "3 - Receipt\n";
   cout << endl;
   cout << "Enter the option that you would like displayed: ";

   int choice;
   cin >> choice;

   cout << endl;

   if (choice == 1)
   {
      // Call your display advertising profile function here
      x.displayAdvertisingProfile();
   }
   else if (choice == 2)
   {
      // Call your display inventory line item function here
      x.displayInventoryLineItem();
   }
   else
   {
      // Call your display receipt function here
      x.displayReceipt();
   }

   return 0;
}
