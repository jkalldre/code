/***********************************************************************
* Program:
*    Assignment ex12, Many Prompts          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*   Prompts user for name, age, GPA, and the grade he wishes to earn.
*   
*   
*   
*   
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
   // Declared variables
   char name[256];
   int age;
   float gpa;
   char letterGrade;
   
   // configure display to show GPA: one digit of accuracy.
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   

   // Prompt user for their name
   cout << "What is your first  name? ";
   cin >> name;

   // Promt user for their age
   cout << "What is your age? ";
   cin >> age;

   // Prompt user for their GPA
   cout << "What is your GPA? ";
   cin >> gpa;

   // Asks user what grade they want to earn
   cout << "What grade do you hope to get in CS 124? ";
   cin >> letterGrade;
   
   // Display the results
   cout << "\t" << name
        << ", you are " << age
        << " with a " << gpa
        << " GPA.  You will get an " << letterGrade
        << ".\n";

   

   
   
      
   return 0;
}
