/***********************************************************************
* Program:
*    Checkpoint 01a, Getting Started          (e.g. Checkpoint 01a, review)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   char name[50];
   int age;
   
   cout << "Hello CS 165 World!\n";
   cout << "Please enter your first name: ";
   cin >> name;

   cout << "Please enter your age: ";
   cin >> age;

   cout << "\nHello " << name << ", you are "
        << age << " years old.\n";
      
   return 0;
}
