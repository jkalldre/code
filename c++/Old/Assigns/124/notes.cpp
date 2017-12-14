/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 01, Hello World)  
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
int main()
{
   return 0;
}

int getMonth()
{
   int month = 0;

      do
      {
         cout << "Enter the month: ";
         cin >> month;
         if (month > 12 || month < 1)
            cout << "Please enter a month between 1 and 12\n";
      }
      while(month > 12 || month < 1);

      return month;

}

int daysMonth()
{
   int daysMonth;
   int offset;

   cout << "Offset: ";
   cin >> offset;
   cout << "How many days in the month: ";
   cin >> daysMonth;

   for (int i = 0; i <= offset; i++)
      cout << "    ";

   for (int i = 1; i <= daysMonth; i++)
   {
      cout << setw(4) << i;

      if ((i + offset + 1) % 7 == 0 && i != daysMonth)
         cout << endl;
   }

   cout << endl;

   return 0;
}


