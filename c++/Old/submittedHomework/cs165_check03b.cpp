/***********************************************************************
* Program:
*    Checkpoint 03b, Error Handling          (e.g. Checkpoint 01a, review)  
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

   prompt(num);
      
   return 0;
}

void prompt(int& num)
{
  
   cout << "Enter a number: ";
   cin >> num;

   do
      {
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');


         cout << "Invalid input.";
         cout << endl;
         cout << "Enter a number: ";
         cin >> num;

      }
      
      
   }
   while (cin.fail());
   
      cout << "The number is " << num << "." << endl;
}
