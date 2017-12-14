/***********************************************************************
* Program:
*    Assignment EXX21, Driver          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

double computeTax(double income);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   double income = 0;
   cout << "Income: ";
   cin >> income;

   double monthlyTax = computeTax(income);

   cout << "montlyTax == " << monthlyTax << endl;
   
   return 0;
}

double computeTax(double income)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   double yearlyIncome = (income * 12);
   double yearlyTax = 0;
   double monthlyTax = 0;

   if ( yearlyIncome >= 0.0 && yearlyIncome < 15100.0)
      yearlyTax = (yearlyIncome * .10);

   else if ( yearlyIncome >= 15100.0 && yearlyIncome < 61300.0)
      yearlyTax = (1510.0 + (.15 * (yearlyIncome - 15100.0)));

   else if ( yearlyIncome >= 61300.0 && yearlyIncome < 123700.0)
      yearlyTax = (8440.0 + (.25 * (yearlyIncome - 61300.0)));

   else if ( yearlyIncome >= 123700.0 && yearlyIncome < 188450.0)
      yearlyTax = (24040.0 + (.28 * (yearlyIncome - 123700.0)));

   else if ( yearlyIncome >= 188450.0 && yearlyIncome < 336550.0)
      yearlyTax = (42170.0 + (.33 * (yearlyIncome - 188450.0)));

   else
      yearlyTax = (91043.0 + (.35 * (yearlyIncome - 336550.0)));

   monthlyTax = (yearlyTax / 12);

   return monthlyTax;

}
