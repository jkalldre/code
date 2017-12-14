/***********************************************************************
* Program:
*    Assignment 33, pointers          (e.g. Assignment 01, Hello World)  
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
#include <iomanip>
using namespace std;

void display();
void getBalance(float &balanceSam, float &balanceSue);
void doMath(float * pAccount, float balanceSam, float balanceSue);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   float balanceSam = 0;
   float balanceSue = 0;

   getBalance(balanceSam, balanceSue);

   float * pAccount;

   if (balanceSam > balanceSue)
      pAccount = &balanceSam;
   
   else
      pAccount = &balanceSue;

   doMath(pAccount, balanceSam, balanceSue);

   cout << "Sam's balance: $" << balanceSam << endl;
   cout << "Sue's balance: $" << balanceSue << endl;
   

   return 0;
}

void getBalance(float &balanceSam, float &balanceSue)
{
   cout << "What is Sam's balance? ";
   cin >> balanceSam;
   
   cout << "What is Sue's balance? ";
   cin >> balanceSue;

   return;
}

void doMath(float * pAccount, float balanceSam, float balanceSue)
{
   float dinner = 0;
   float movie = 0;
   float iceCream = 0;
   float dateCost = 0;
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

   cout << "Cost of the date:\n";
   cout << "\tDinner:    ";
   cin >> dinner;

   cout << "\tMovie:     ";
   cin >> movie;

   cout << "\tIce cream: ";
   cin >> iceCream;

   dateCost = dinner + movie + iceCream;

   *pAccount -= dateCost;

}
