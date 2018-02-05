/***********************************************************************
* Program:
*    Test 3, Reverse a File          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary:
*    This program will read a text file and print it in reverse!
*    How confusing!
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*  testBed wants me to place an endline where it is not necessary.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

int readFile(char fileName[], char text[]);
void getFileName(char fileName[]);
void display(char text[], int size);

/**********************************************************************
 * main will call getFile and readFile to collect the desired data
 * then call display to print it out backwards to make Sue happy
 ***********************************************************************/
int main()
{
   char fileName[256];
   char text[4000];
   
   getFileName(fileName);
   int size = readFile(fileName, text);

   if (size != -1)
      display(text, size);
   
   return 0;
}

/***********************************************************
 * getFileName will request user input to find intended file
 ***********************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
   
   return;
}

/*********************************************************************
 * readFile is a standard readFile function but will read the file one
 * character at a time
 *********************************************************************/
int readFile(char fileName[], char text[])
{
   int i = 0;
   ifstream fin(fileName);

   if (fin.fail())
      return -1;

   while (fin.get(text[i]))
      i++;

   fin.close();

   return i;
}

/********************************************************************
 * display will take the info gathered from the file and print it out
 * backwards
 *******************************************************************/
void display(char text[], int size)
{
   for (int i = 0; i < size; i++)
      cout << text[size - i];

   return;
}
