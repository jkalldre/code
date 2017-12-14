/************************************************************
* Program:
*    Test 1, Dollar to Euro
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    This program will convert American dollars to
*    Euros. The amount is given by the user.
************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

void display(double euroAmount);
double convert(double dollarAmount);

/*******************************************
 * function will request user input and call
 * the other functions
 ******************************************/
int main()
{
   double dollarAmount = 0;

   cout << "Please enter the amount in US Dollars: $";
   cin >> dollarAmount;

   double euroAmount = convert(dollarAmount);
   display(euroAmount);
   
   return 0;
}

/********************************************************
* this function will display converted amount for the user
*********************************************************/
void display(double euroAmount)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   if (euroAmount >= 0)
      cout << "\tEuros: " << euroAmount << endl;
   
   else
      cout << "\tEuros: " << "(" << euroAmount << ")" << endl;

   return;
}

/******************************************
* function will convert user input to euros     
******************************************/
double convert(double dollarAmount)
{
   double euroAmount = 0;

   euroAmount = (dollarAmount / 0000001.4100);
   
   return euroAmount;
}
