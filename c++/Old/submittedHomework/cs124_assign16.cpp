/***********************************************************************
* Program:
*    Assignment 16, Tax Bracket          (e.g. Assignment 01, Hello World)  
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

int decideBracket(int yearlyIncome);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int yearlyIncome = 0;
   
   cout << "Income: ";
   cin >> yearlyIncome;

   int bracket = decideBracket(yearlyIncome);

   cout << "Your tax bracket is " << bracket << "%\n";
   
   return 0;
}

int decideBracket(int yearlyIncome)
{
   if (yearlyIncome >= 0 && yearlyIncome <= 15100)
      return 10;

   else if (yearlyIncome > 15100 && yearlyIncome <= 61300)
      return 15;

   else if (yearlyIncome > 61300 && yearlyIncome <= 123700)
      return 25;

   else if (yearlyIncome > 123700 && yearlyIncome <= 188450)
      return 28;

   else if (yearlyIncome > 188450 && yearlyIncome <= 336550)
      return 33;

   else
      return 35;
}
