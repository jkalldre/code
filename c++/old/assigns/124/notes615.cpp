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

void display(char characters[]);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char characters[256];

   for (int i = 0; i < 256; i++)
      characters[i] = 256 - i;

   display(characters);
   
   return 0;
}

void display(char characters[])
{
   for (int i = 0; i < 256; i++)
      cout << characters[i] << endl;

   //cout << characters << endl;

   return;
}
