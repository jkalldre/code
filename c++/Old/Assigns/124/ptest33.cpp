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

void getFileName(char fileName[]);
int readFile(char fileName[], char data[][256]);
void display(char data[][256], int size);
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   char fileName[256];
   char data[10000][256];
      
   getFileName(fileName);
   int size = readFile(fileName, data);
   if (size == -1)
      cout << "Bad file at " << fileName << endl;
   else
      display(data, size);
   
   return 0;
}

void getFileName(char fileName[])
{
   cout << "What is the name of the file: ";
   cin >> fileName;

   return;
}

int readFile(char fileName[], char data[][256])
{
   int i = 0;
   ifstream fin(fileName);
   
   if (fin.fail())
      return -1;

   while (fin >> data[i])
      i++;
         
   fin.close();
   return i;
}

void display (char data[][256], int size)
{
   char letter;
   int count = 0;
   
   //cout << "What letter should we count: ";
   //cin >> letter;
   
   for (int i = 0; i < size; i++)
      //if (letter == data[i])
      //count++
      cout << data[i] << " ";

   //cout << "There are " << count << " " << letter << "'s in the file\n";
   
   
   return;
}
