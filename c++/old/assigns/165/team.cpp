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
#include <fstream>
#include <sstream>
#include <cstring>
using namespace std;

struct Scripture
{
   string book;
   int chapter;
   int verse[2];
};

void readFile(const string & fileName, Scripture & scripture);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   string fileName;
   Scripture scripture;
   cout << "Please enter a file: ";
   cin  >> fileName;
   readFile(fileName, scripture);

   return 0;
}

void readFile(const string & fileName, Scripture & scripture)
{
   ifstream fin(fileName.c_str());   // needs to convert string to c-string
   if (fin.fail()) {   // check for readable file error
      return;
   }

   string theLine;
   scripture.verse[1] = 0;
   
   int i = 0;

   while (getline(fin, theLine))
   {
      istringstream buffer(theLine);
      buffer >> scripture.book
             >> scripture.chapter
             >> scripture.verse[0];
         
      buffer >> scripture.verse[1];

      if (buffer.fail())
      {
         scripture.verse[1] = 0;
         buffer.clear();
         buffer.ignore(256, '\n');
      }
      
      if (buffer.fail())
      {
         cout << "Bad Line\n";
         buffer.clear();
         buffer.ignore(256, '\n');
      }
      else
      {
         cout << scripture.book
              << " "
              << scripture.chapter
              << ":"
              << scripture.verse[0];
         if (scripture.verse[1] == 0)
            cout << endl;
         if (scripture.verse[1] != 0)
         {
            cout << "-"
                 << scripture.verse[1]
                 << endl;
         }
         i = 0;
      }
   }
}
