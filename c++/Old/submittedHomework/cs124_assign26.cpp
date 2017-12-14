/***********************************************************************
* Program:
*    Assignment 26, files          (e.g. Assignment 01, Hello World)  
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
#include <iomanip>
using namespace std;

void getFileName(char fileName[]);
float readFile(char fileName[]);
void display(char fileName[], float average);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char fileName[256];
      
   getFileName(fileName);

   float average = readFile(fileName);

   display(fileName, average);
   
   return 0;
}

void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
}

float readFile(char fileName[])
{
   float sum = 0;
   float value = 0;
   float average = 0;
   
   ifstream fin(fileName);
   
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"\n";
      return -1;
   }
   
   while (fin >> value)
      sum += value;

   average = sum / 10.00;
    
   if (average < 0.9 || average > 100)
   {
      cout << "Error reading file \"" << fileName << "\"\n";
  
      return -1;
   }
   
   fin.close();

  
   return average;
}
   

void display(char fileName[], float average)
{
   cout.setf(ios::fixed);
   cout.precision(0);


   if (average > 0.0 && average <= 100.0)
      cout << "Average Grade: " << average << "%" << endl;
     
}
