// File: customer.cpp

#include "customer.h"
#include <iostream>
#include <string>
using namespace std;

/******************************************************
* This is my default constructor that will set all the 
* class values to 0
******************************************************/
Customer::Customer()
{
   name = "unspecified";
   address = Address();
}

/******************************************************
* This constructor will set the values of the class to
* a user input value
******************************************************/
Customer::Customer(string n, Address a)
{
   name = n;
   address = a;
}

/******************************************************
* This will display the customer information on the
* screen in a clean format
******************************************************/
void Customer::display()
{
   cout << name << endl;
   cout << address.getStreet() << endl;
   cout << address.getCity() << ", " << address.getState() << " " << address.getZip() << endl; 
}