/***********************************************************************
* Program:
*    Assignment ex14, promptFct          (e.g. Assignment 01, Hello World)  
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
int getAge()
{
   int age;

   // request user's input
   cout << endl;
   cout << "======================\n";
   cout << "What is your age? ";
   cin >> age;

   return age;

}

int getGpa()
{
   float gpa;
   
   // get the user's input
   cout << "What is your GPA? ";
   cin >> gpa;

   return gpa;

}

int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(1);
   
   // get the user's input
   int age = getAge();
   float gpa = getGpa();

   // display the results
   cout << "You are " << age << " years old!!\n";
   cout << "and you have a " << gpa << " GPA!! WOW!!\n";
   cout << "======================\n";
   cout << endl;
   
   return 0;
}




      







