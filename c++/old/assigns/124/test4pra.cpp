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
#include <cstring>
using namespace std;

void getLine(char* lineOfText);
int findDigits(const char* lineOfText);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main(int argc, char** argv)
{
   char lineOfText[256];

   if (argc > 1)
      strcpy(lineOfText, argv[1]);
   else
      getLine(lineOfText);

   int digits = findDigits(lineOfText);

   if (digits == 0)
      cout << "There are no digits.\n";
   else if (digits == 1)
      cout << "There is 1 digit.\n";
   else
      cout << "There are " << digits << " digits.\n";
   return 0;
}

void getLine(char* lineOfText)
{
   cout << "Please enter a word to check: ";
   cin >> lineOfText;
      
   
}

int findDigits(const char* lineOfText)
{
   int count = 0;
   
   for (; *lineOfText; lineOfText++)
      if (*lineOfText >= '0'
          && *lineOfText <= '9')
         count++;
   return count;
}
