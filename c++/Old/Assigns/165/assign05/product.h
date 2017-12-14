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

/*****************************************************
* Product will hold all the variables and members for
* any given product indicated by the user.
*****************************************************/
class Product
{
  private:
   string name;
   float basePrice;
   float salesTax;
   float totalPrice;
   float shippingCost;
   float weight;
   string description;
   
  public:
   Product();
   Product(string n, string d, float bP, float w);
   float getSalesTax();
   float getShippingCost();
   float getTotalPrice();
   void displayAdvertising();
   void displayInventory();
   void displayReceipt();   
   void prompt();
    
/*****************************************************
* these are my simple getter and setter functions that
* the other files and functions will use to access and
* modify the private functions of tis class.
*****************************************************/
   string getName()
   {
      return name;
   }
   void setName(string n)
   {
      name = n;
   }
   
   string getDescription()
   {
      return description;
   }
   void setDescription(string d)
   {
      description = d;
   }
   
   float getBasePrice()
   {
      return basePrice;
   }
   void setBasePrice(float bP)
   {
      basePrice = bP;
   }
   
   float getWeight()
   {
      return weight;
   }
   void setWeight(float w)
   {
      weight = w;
   }
   
};


#endif
