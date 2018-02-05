/***************************************************************
 * File: product.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iomanip>
#include <iostream>
using namespace std;
// put your method bodies here

void Product::prompt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "Enter name: ";
   getline(cin, name);
   
   cout << "Enter description: ";
   getline(cin, description);
   
   cout << "Enter weight: ";
   cin >> weight;
   cin.ignore();
   
   do
   {
      cout << "Enter price: ";
      cin >> price;
      cin.ignore();
      
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
         cout << "Enter price: ";
         cin >> price;
         cin.ignore();
      }  
   }while(price < 0);
}

float Product::getSalesTax()
{
   salesTax = price * 0.06;
}

float Product::getShippingCost()
{ 
   if (weight < 5.0)
      shippingCost = 2.0;
   else
      shippingCost = 2.0 + ((weight - 5) * .10);  
}

float Product::getTotalPrice()
{
   totalPrice = price + salesTax + shippingCost;
}

void Product::displayAdvertisingProfile()
{
   cout << name << " - $" << price << endl;
   cout << "(" << description << ")\n";
}
 
void Product::displayInventoryLineItem()
{
   
   cout << "$" << price << " - " << name << " - ";
   {
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << weight << " lbs" << endl;
   }
}

void Product::displayReceipt()
{
   cout << name << std::endl;
   cout << "  Price:         $ " << setw(7) << price << endl;
   cout << "  Sales tax:     $ " << setw(7) << salesTax << endl;
   cout << "  Shipping cost: $ " << setw(7) << shippingCost << endl;
   cout << "  Total:         $ " << setw(7) << totalPrice << endl;
}