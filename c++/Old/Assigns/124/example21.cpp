/***********************************************************************
* Program:
*    Assignment ex21, asserts          (e.g. Assignment 01, Hello World)  
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
#include <cassert>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   float income = 0;
   assert(income >= 0.00);
   
   cout << "What is the income? $";
   cin >> income;

   float tithing = (income * .10);
   assert(tithing >= 0);
   assert(tithing < income);
   
   cout << "Tithe for $" << income << " is $" << tithing << endl;
   
   return 0;
}
