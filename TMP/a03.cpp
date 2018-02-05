/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics
*    Brother Alvey, CS165
* Author:
*    Lanie Molinar
* Summary:
*    This program searches a file containing access records for those accessed
*    between certain times, displaying their timestamp, filename, and the
*    username of the person who accessed them on the screen.
*
*    Estimated:  10.0 hrs
*    Actual:     3.0 hrs
*      I accidentally broke the computer I was borrowing. Mine hasn't been
*      repaired yet, so this meant I had to use my Chromebook. The text editor
*      and SSH client I found aren't nearly as good or accessible as those I
*      use on Windows, so using them made completing the assignment more
*      difficult.
************************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

/**********************************************************************
* This structure is used to store information from the access records file
* to be searched.
***********************************************************************/
struct AccessRecord
{
   string username;
   string filename;
   long timestamp;
};

/**********************************************************************
* getFileName prompts the user for the name of the file to be read.
***********************************************************************/
string getFileName()
{
   string fileName;
   cout << "Enter the access record file: ";
   cin >> fileName;
   return fileName;
}

void parseLine(string line, AccessRecord record) throw (string)
{
   stringstream buffer;
   string message = "Error parsing line: ";
   message += line;
   string newLine = "\n";
   message += newLine;
   buffer.str(line);
   buffer >> record.filename;
   if (buffer.fail())
      record.filename = '\0';
   buffer >> record.username;
   if (buffer.fail())
      record.username[0] = '\0';
   buffer >> record.timestamp;
   if (buffer.fail())
      record.timestamp = 0;
   if (record.filename[0] == '\0'
      || record.username[0] == '\0'
      || record.timestamp < 1000000000
      || record.timestamp > 10000000000)
      throw message;
   }

/**********************************************************************
* parseFile parses the file one line at a time, passing it to parseLine.
***********************************************************************/
void parseFile(string fileName, AccessRecord records[500])
{
   ifstream fin(fileName.c_str());
   if (fin.fail())
   {
      cout << "Error opening file \""
         << fileName
         << "\" for reading.\n";
   }
   string line;
   int i = 0;
   while (i < 500 && getline(fin, line))
   {
      AccessRecord record;
      try
      {
         parseLine(line, record);
         records[i].filename = record.filename;
         records[i].username = record.username;
         records[i].timestamp = record.timestamp;
         if (fin.fail())
         {
            cout << "Unable to read file\"" << fileName << "\".\n";
            return;
         }
      }
      catch (string message)
      {
         cout << message;
      }
      i++;
   }
   fin.close();
}

/**********************************************************************
* getStartTime prompts the user for the beginning of the timeframe the
* program should display records for.
***********************************************************************/
long getStartTime()
{
   long startTime;
   cout << "\nEnter the start time: ";
   cin >> startTime;
   return startTime;
}

/**********************************************************************
* getEndTime prompts the user for the end of the timeframe it the program
* should display records for.
***********************************************************************/
long getEndTime()
{
   long endTime;
   cout << "Enter the end time: ";
   cin >> endTime;
   return endTime;
}

/**********************************************************************
* searchRecords searches the records in a file for those accessed between
* certain times that the user specifies.
***********************************************************************/
void searchRecords(AccessRecord records[500], long startTime, long endTime)
{
   cout << "\nThe following records match your criteria:\n\n"
      << setw(15) << "Timestamp"
      << setw(20) << "File"
      << setw(20) << "User"
      << endl
      << "--------------- ------------------- -------------------\n";
   for (int i = 0; i < 500; i++)
   {
      if (records[i].timestamp >= startTime && records[i].timestamp <= endTime)
      {
         cout << setw(15) << records[i].timestamp
            << setw(20) << records[i].filename
            << setw(20) << records[i].username
            << endl;
      }
   }
   cout << "End of records\n";
}

/**********************************************************************
* Main calls the other functions in this program, passing parameters between
* them.
***********************************************************************/
int main()
{
   string fileName = getFileName();
   AccessRecord records[500];
   parseFile(fileName, records);
   long startTime = getStartTime();
   long endTime = getEndTime();
   searchRecords(records, startTime, endTime);
   return 0;
}
