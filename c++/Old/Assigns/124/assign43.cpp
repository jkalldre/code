/***********************************************************************
* Program:
*    Assignment 43, command line          (e.g. Assignment 01, Hello World)  
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
#include <cstring>
#include <cstdlib>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main(int argc, char** argv)
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   
   char cFoot[256][5];
   
   for (int i = 0; i < 5; i++)
      strcpy(cFoot[i], argv[i + 1]);
      
   float feet[5];

   for (int j = 0; j < 5; j++)
   {
      feet[j] = atof(cFoot[j]);
      cout << feet[j] << " feet is "
           << feet[j] * 0.3048 << " meters\n";
   }
   
   return 0;
   
}
