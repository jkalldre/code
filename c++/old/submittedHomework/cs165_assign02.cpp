/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics     (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    This program will read a filelog to see who accessed the files within
*    a certain amount of time. Then will present the log on the screen.
*
*  Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*       appeasing testBed
************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct AccessRecord
{
   string userName;
   string fileName;
   double timeStamp;
};
   
int readFile(const char fileName[], AccessRecord entre[]);
void displayData(AccessRecord entre[], int size);
void getFileName(char fileName[]);

/***************************************************************
 * main will hold key variables and call all the other functions
 ***************************************************************/
int main()
{
   char fileName[256];
   AccessRecord entre[20];

   getFileName(fileName);
   
   int size = readFile(fileName, entre);
   displayData(entre, size);
   
   return 0;
}

/**************************************************
 * getFileName will prompt user for a file to read
 *************************************************/
void getFileName(char fileName[])
{
   cout << "Enter the access record file: ";
   cin >> fileName;
   cout << endl;
}

/*******************************************************************
 * readFile will read the given file and insert info into the struct
 * array
 *******************************************************************/
int readFile(const char fileName[], AccessRecord entre[])
{
   ifstream fin(fileName);
   int i = 0;

   if (fin.fail())
      return -1;

   while (!fin.eof())
   {
      fin >> entre[i].fileName;
      fin >> entre[i].userName;
      fin >> entre[i].timeStamp;
      i++;
   }
   
   fin.close();
   
   return i;
}

/**********************************************************************
 * displayData will display the read data onto the screen within the
 * range indicated by the user.
 ***********************************************************************/
void displayData(AccessRecord entre[], int size)
{
   cout.setf(ios::fixed);
   cout.precision(0);
   double userTime[2];

   cout << "Enter the start time: ";
   cin >> userTime[0];
   cout << "Enter the end time: ";
   cin >> userTime[1];
   
   cout << "\nThe following records match your criteria:\n" << endl;
   
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n"
        << "--------------- ------------------- -------------------\n";

   for (int i = 0; i < (size - 1); ++i)
   {
      if (entre[i].timeStamp >= userTime[0]
          && entre[i].timeStamp <= userTime[1])
      {
         cout << setw(15) << entre[i].timeStamp
              << setw(20) << entre[i].fileName 
              << setw(20) << entre[i].userName;
         if (i != size)
            cout << endl;
      }
   }

   cout << "End of records\n";
}
