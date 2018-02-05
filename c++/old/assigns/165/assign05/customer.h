// File: customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "address.h"
using namespace std;

/*****************************************************
* Customer will hold all the variables and members for
* any given customer indicated by the user.
*****************************************************/
class Customer
{
   private:
    string name;
    Address address;
    
   public:
    Customer();
    Customer(string n, Address a);
    
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
    
    Address getAddress()
    {
       return address;
    }
    void setAddress(Address a)
    {
       address = a;
    }
    void prompt();
    void display();
};
#endif
