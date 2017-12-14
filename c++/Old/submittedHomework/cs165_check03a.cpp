/***********************************************************************
* Program:
*    Checkpoint 03a, Exceptions          (e.g. Checkpoint 01a, review)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

void prompt(int& num);
/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int num = 0;

   try
   {
   prompt(num);
   }
   catch (const char * message)
   {
      cout << "Error: " << message << endl;;
   }
   
   
   return 0;
}

void prompt(int& num)
{
   cout << "Enter a number: ";
   cin >> num;

   if (num < 0)
      throw "The number cannot be negative.";
   if (num > 100)
      throw "The number cannot be greater than 100.";
   if (num % 2 != 0)
      throw "The number cannot be odd.";
   else
      cout << "The number is " << num << "." << endl;
}
