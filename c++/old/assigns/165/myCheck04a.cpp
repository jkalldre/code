/***********************************************************************
* Program:
*    Checkpoint 04a, Classes          (e.g. Checkpoint 01a, review)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

class Book
{
   public:
      string title;
      string author;
   
   void prompt();
   void display();
};

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   Book favBook;
   
   favBook.prompt();
   favBook.display();
   return 0;
}

void Book :: prompt()
{
   cout << "Title: ";
   getline(cin, title);
   cout << "Author: ";
   getline(cin, author);
}

void Book :: display()
{
   cout << "\"" << title << "\" by " << author << endl;
}