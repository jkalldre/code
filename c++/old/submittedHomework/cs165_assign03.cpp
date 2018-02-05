/***********************************************************************************
* Program:
*    Assignment 03, Forensics w/ corrupt files     (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    This program will read a filelog to see who accessed the files within
*    a certain amount of time. Then will present the log on the screen.
*
*  Estimated:  1.0 hrs   
*    Actual:     2.5 hrs
*       appeasing testBed, also my struct arry was not big enough and was causing 
*       errors..
**********************************************************************************/

#include <iostream> 
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct AccessRecord
{
   string userName;
   string fileName;
   double timeStamp;
};
   
int readFile(const char fileName[], AccessRecord entre[], string& theLine);
void displayData(AccessRecord entre[], int size);
void getFileName(char fileName[]);
void parseLine(string& theLine, AccessRecord entre[], int& i);

/***************************************************************
 * main will hold key variables and call all the other functions
 ***************************************************************/
int main()
{
   char fileName[256];
   AccessRecord entre[30];
   string theLine;

   getFileName(fileName);
     
   int size = readFile(fileName, entre, theLine);
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
   
}

void parseLine(string& theLine, AccessRecord entre[], int& i)
{

   istringstream buffer(theLine);
      buffer >> entre[i].fileName;
      buffer >> entre[i].userName;
      buffer >> entre[i].timeStamp;
      
      if (buffer.fail() || entre[i].timeStamp < 1000000000
         || entre[i].timeStamp > 10000000000)
      {
         throw (string)"Error parsing line: ";
         buffer.clear();
         buffer.ignore(256, '\n');
         
      }    
}
/*******************************************************************
 * readFile will read the given file and insert info into the struct
 * array. Will also detect any corrupt files and inform user
 *******************************************************************/
int readFile(const char fileName[], AccessRecord entre[], string& theLine)
{
   ifstream fin(fileName);
   int i = 0;

   if (fin.fail())
      return -1;

   while (getline(fin, theLine))
   {
      try
      {
      parseLine(theLine, entre, i);
      i++;
      }
      catch(string e)
      {
         cout << e << theLine << endl;
      }
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
      
   cout << "\nEnter the start time: ";
   cin >> userTime[0];
   cout << "Enter the end time: ";
   cin >> userTime[1];
   
   cout << "\nThe following records match your criteria:\n" << endl;
   
   cout << setw(15) << "Timestamp"
        << setw(20) << "File"
        << setw(21) << "User\n"
        << "--------------- ------------------- -------------------\n";
   
   for (int i = 0; i < (size); ++i)
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

