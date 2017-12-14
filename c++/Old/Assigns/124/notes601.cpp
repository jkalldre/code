/***********************************************************************
* Program:
*    Assignment ##, ????          (e.g. Assignment 01, Hello World)  
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
#include <fstream>
using namespace std;

int readFile(char fileName[], char names[][20]);
void displayNames(char names[][20]);
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   // int grades[10];
   char names[10][20];
   char fileName[256];
   
   cout << "Enter the file name: ";
   cin >> fileName;
   
   int size = readFile(fileName, names);
   
   if (size != -1)
      displayNames(names);
   else
      cout << "Bad file name\n";
         
   return 0;
}

int readFile(char fileName[], char names[][20])
{
   int i = 0;
   ifstream input;
   input.open(fileName);

   if (input.fail())
      return -1;

   while (input >> names[i])
      i++;
   
   // for(int i = 0; i < 10; i++)
   // {
   //   cout << "Enter grade " << i + 1 << endl;
   //   cin >> grades[i];
   // }
   input.close();
   return i;
}

void displayNames(char names[][20])
{
   for (int i = 0; i < 10; i++)
      cout << "Names " << i + 1 << " = " << names[i] << endl;

   return;
}
