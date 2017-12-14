/***************************************************************
 * File: product.cpp
 * Author: (your name here)
 * Purpose: Contains the method implementations for the Product class.
 ***************************************************************/

#include "product.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

/******************************************************
* This is my default constructor that will set all the 
* class values to 0
******************************************************/
Product::Product()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   name = "none";
   description = "";
   basePrice = 0.0;
   weight = 0.0;
   
}

/******************************************************
* This constructor that will set all the class values
* to values passed by the user
******************************************************/
Product::Product(string n, string d, float bP, float w)
{
   name = n;
   description = d;
   basePrice = bP;
   weight = w;
}

/******************************************************
* This function will prompt the user for information
* and incert it into the class
******************************************************/
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
      cin >> basePrice;
      cin.ignore();
      
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
         cout << "Enter price: ";
         cin >> basePrice;
         cin.ignore();
      }  
   }while(basePrice < 0);
}

/******************************************************
* These are my simple getters and setters for my class
* that will allow other functions to access the private
* members and variables of my product class
******************************************************/
float Product::getSalesTax()
{
   salesTax = basePrice * 0.06;
}
 
float Product::getShippingCost()
{ 
   if (weight < 5.0 )
      return shippingCost = 2.0;
   else
      shippingCost = (2.0 + ((weight - 5) * .10));  
}

float Product::getTotalPrice()
{
   totalPrice = getBasePrice() + getSalesTax() + getShippingCost();
}

/******************************************************
* These three functions will display all the given info
* in the format requested by the user.
******************************************************/
void Product::displayAdvertising()
{
   cout << name << " - $" << basePrice << endl;
   cout << "(" << description << ")\n";
}
 
void Product::displayInventory()
{
   
   cout << "$" << basePrice << " - " << name << " - ";
   {
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   cout << weight << " lbs" << endl;
   }
}

void Product::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << name << std::endl;
   cout << "  Price:         $ " << setw(7) << basePrice << endl;
   cout << "  Sales tax:     $ " << setw(7) << getSalesTax() << endl;
   cout << "  Shipping cost: $ " << setw(7) << getShippingCost() << endl;
   cout << "  Total:         $ " << setw(7) << getTotalPrice() << endl;
}