// File: address.h

#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <iostream>
using namespace std;

/*****************************************************
* Address will hold all the variables and members for
* any given customer indicated by the user.
*****************************************************/
class Address
{
   private:
    string street;
    string city;
    string state;
    string zip;
    
   public:
    Address();
    Address(string s, string c, string st, string z);
    
/*****************************************************
* these are my simple getter and setter functions that
* the other files and functions will use to access and
* modify the private functions of tis class.
*****************************************************/
    string getStreet()
    {
       return street;
    }
    void setStreet(string s)
    {
       street = s;
    }
    
    string getCity()
    {
       return city;
    }
    void setCity(string c)
    {
       city = c;
    }
    
    string getState()
    {
       return state;
    }
    void setState(string st)
    {
       state = st;
    }
    
    string getZip()
    {
       return zip;
    }
    void setZip(string z)
    {
       zip = z;
    }
    void prompt();
    void display();
};

#endif

