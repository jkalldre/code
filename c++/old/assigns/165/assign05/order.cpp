// File: order.cpp

#include "order.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/******************************************************
* This is my default constructor that will set all the 
* class values to 0
******************************************************/
Order::Order()
{
   quantity = 0;
   product = Product();
   customer = Customer();
}

/******************************************************
* This constructor that will set all the class values
* to values indicated by the user
******************************************************/
Order::Order(Product p, int q, Customer c)
{
   product = p;
   quantity = q; 
   customer = c;
}

/******************************************************
* This will display the order receipt with all the info
* collected from the user and other classes
******************************************************/
void Order::displayReceipt()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << customer.getName() << endl;
   cout << product.getName() << endl;
   cout << "  Price:         $ " << setw(7) << product.getBasePrice() << endl;
   cout << "  Sales tax:     $ " << setw(7) << product.getSalesTax() << endl;
   cout << "  Shipping cost: $ " << setw(7) << product.getShippingCost() << endl;
   cout << "  Total:         $ " << setw(7) << product.getTotalPrice() << endl;
     
} 