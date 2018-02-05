/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 01, Hello World)  
*    Brother {Burton, Helfrich, Comeau}, CS165
* Author:
*    your name
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

struct Scripture
{
   string bookName;
   int chapter;
   int verse;
};

void displayScripture(Scripture scripture[]);
void promptScripture(Scripture scripture[]);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   Scripture scripture[3];
   
   promptScripture(scripture);
   displayScripture(scripture);
   
   return 0;
}

void displayScripture(Scripture scripture[])
{
   cout << "\nYour scriptures are:\n";
      
   for (int i = 0; i < 3; ++i)
   {
      cout << scripture[i].bookName << " " << scripture[i].chapter
           << ":" << scripture[i].verse << endl;
   }
}

void promptScripture(Scripture scripture[])
{
   for (int i = 0; i < 3; ++i)
   {
      cout << "Enter a Book" << i + 1 << ": ";
      getline(cin, scripture[i].bookName);

      cout << "Chapter: ";
      cin >> scripture[i].chapter;
      cin.ignore();
      
      cout << "Verse: ";
      cin >> scripture[i].verse;
      cin.ignore();

      cout << endl;
   }
}
