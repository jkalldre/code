// File: address.cpp

#include "address.h"
#include <string>
#include <iostream>

using namespace std;
/******************************************************
* This will display the customer address in a clean
* format
******************************************************/
void Address::display()
{
   cout << street << endl;
   cout << city << ", " << state << " " << zip;
}

/******************************************************
* This is my default constructor that will set all the 
* class values to 0
******************************************************/
Address::Address()
{
   street = "unknown";
   zip = "00000";
   state = "";
   city = "";
}

/******************************************************
* This constructor will set the class values to a value
* passed to the class by the user.
******************************************************/
Address::Address(string s, string c, string st, string z)
{
   street = s;
   city = c;
   state = st;
   zip = z;
}

void Address::prompt()
{

}