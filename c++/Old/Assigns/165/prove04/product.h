/***************************************************************
 * File: product.h
 * Author: (your name here)
 * Purpose: Contains the definition of the Product class
 ***************************************************************/
#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <string>

using namespace std;

// put your class definition here
class Product
{
  public:
   string name;
   float price;
   float salesTax;
   float totalPrice;
   float shippingCost;
   float weight;
   string description;
   
   float getSalesTax();
   float getShippingCost();
   float getTotalPrice();
   void displayAdvertisingProfile();
   void displayInventoryLineItem();
   void displayReceipt();   
   void prompt();
   
};


#endif
