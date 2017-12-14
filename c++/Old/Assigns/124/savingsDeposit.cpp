/***********************************************************************
* Program:
*    Assignment 14a, Compute Fct          (e.g. Assignment 01, Hello World)  
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

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/

int computeSavings(int centsIncome)
{

   // take tithing out of income
   int centsTithing = centsIncome / 10;
   centsIncome -= centsTithing;

   // now take out savings
   int centsSavings = centsIncome / 2;

   return centsSavings;
}


int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   // Prompt user for his income
   float dollarAllowance;
   cout << endl;
   cout << "===================================\n";
   cout << "What is your montly income? ";
   cin >> dollarAllowance;
   int centsAllowance = dollarAllowance * 100;

   // display how much is to be deposited in savings
   int centsDeposit = computeSavings(centsAllowance);
   cout << "You need to deposit $ "
        << static_cast<float>(centsDeposit) / 100.0 << endl;
   cout << "===================================\n";
   cout << endl;
   
   return 0;
}










