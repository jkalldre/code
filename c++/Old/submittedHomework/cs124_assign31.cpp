/***********************************************************************
* Program:
*    Assignment 31, array design          (e.g. Assignment 01, Hello World)  
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

int getGrades(int listGrades[], int num);
int averageGrades(int listGrades[], int num);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   int listGrades[10] = {};
   int num = 10;
   
   getGrades(listGrades, num);
   int average = averageGrades(listGrades, num);

   if (average != -1)
      cout << "Average Grade: " << average << "%" << endl;

   else
      cout << "Average Grade: ---%\n";
   
   return 0;
}

int getGrades(int listGrades[], int num)
{
   for (int i = 0; i < num; i++)
   {
      cout << "Grade " << i + 1 << ": ";
      cin >> listGrades[i];
      
   }

   
}

int averageGrades(int listGrades[], int num)
{
   int sum = 0;
   int divide = 0;
   
   for (int iGrade = 0; iGrade < num; iGrade++)
   {
      if (listGrades[iGrade] != -1)
      {
         sum += listGrades[iGrade];
         divide++;
      }
      else
         sum -= 1;
            
   }

   if (sum != -10) 
   {
      int average = sum / divide;
      return average;
   }
   
   else
      return -1;
         
}
