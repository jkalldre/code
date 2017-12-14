/***********************************************************************
* Program:
*    Assignment 02, file & structs          (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS165
* Author:
*    Shawn Li
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
#include <string>
#include <iomanip>
using namespace std;

/**********************************************************************
 * define the structure before using it
 ***********************************************************************/
struct Doc
{
   string username;
   string filename;
   long int timestamp;
};

/**********************************************************************
 * this is the function where i get the filename
 * i pass the varible filename by reference into this function
 ***********************************************************************/
void getFileName(string &filename)
{
   cout << "Enter the access record file: ";
   cin >> filename;
}

/**********************************************************************
 * read file function, use fin put the information into the array
 ***********************************************************************/
int readFile(Doc aRecord[50],string filename)
{
   ifstream fin(filename.c_str());
    // have to use c_str() here because it won't read string

    //   if (fin.fail())
    //    cout << "Error!\n";

   for(int i = 0; i < 50 && i != fin.eof(); i ++)
   {
      fin >> aRecord[i].username;
      fin >> aRecord[i].filename;
      fin >> aRecord[i].timestamp;
   }

   fin.close();
}

/**********************************************************************
 * prompt the user for start time and end time,
 * pass it by refference so we can use it later
 ***********************************************************************/
long int getTime(long int &startTime, long int &endTime)
{
   cout << "Enter the start time: ";
   cin >> startTime;
   cout << "Enter the end time: ";
   cin >> endTime;
}

/**********************************************************************
 * this is the Display function.
 * I passed everything in so it can display the properform for it
 ***********************************************************************/
void DisplayRecord(Doc aRecord[50],long int startTime, long int endTime)
{
   cout << endl;
   cout << "The following records match your criteria:\n";
   cout << endl;
   cout << "      Timestamp                File                User\n";
   cout << "--------------- ------------------- -------------------\n";
   for (int i = 0; i < 50; i++)
   {
      if(startTime < aRecord[i].timestamp < endTime)
      {
         cout << aRecord[i].timestamp << setw(15) << aRecord[i].filename
              << setw(15) <<aRecord[i].username
              << endl;
      }
   }
      cout << "End of records\n";

   
}
   
/**********************************************************************
 * the main function I define all the varibles.
 * call the functions to make the program runs.
 ***********************************************************************/
int main()
{
   Doc aRecord[50];
   string filename;
   long int startTime;
   long int endTime;
   
   getFileName(filename);
   readFile(aRecord,filename);

   getTime(startTime,endTime);
   
   DisplayRecord(aRecord,startTime,endTime);
   
   return 0;
}