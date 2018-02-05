/***********************************************************************
* Program:
*    Assignment 12, Inputs & Variables          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    your name
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
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   // Defined variables
   float incomeMonthly;
      
   cout.setf(ios::fixed);                    
   cout.setf(ios::showpoint);
   cout.precision(2);                    // set precision to two for money

   // Prompts for monthly income
   cout << "\t" << "Your monthly income: ";
   cin >> incomeMonthly;

   // Display the income
   cout << "Your income is: $" << setw(9) << incomeMonthly << endl;
   
   return 0;
}
