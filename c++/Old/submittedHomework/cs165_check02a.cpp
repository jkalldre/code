/***********************************************************************
* Program:
*    Checkpoint 02a, Student Struct          (e.g. Checkpoint 01a, review)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>

using namespace std;

void displayStudent(string name1, string name2, string idNum);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   string name1;
   string name2;
   string idNum;

   cout << "Please enter your first name: ";
   cin >> name1;

   cout << "Please enter your last name: ";
   cin >> name2;

   cout << "Please enter your id number: ";
   cin >> idNum;

   displayStudent(name1, name2, idNum);
   
   return 0;
}

void displayStudent(string name1, string name2, string idNum)
{
   cout << endl << "Your information:\n" << idNum << " - " << name1
        << " " << name2 << endl;
}
