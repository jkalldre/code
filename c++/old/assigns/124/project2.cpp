/***********************************************************************
* Program:
*    Project 2, Calendar          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    Program will receive input for month and year and print out a 
*    calendar for them.
*
*    Estimated:  3.0 hrs   
*    Actual:     1.45 hrs
*     style checker made me change my program a little, and i had some
*     difficulty with my calcOffset function returning strange values
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int getMonth();
int getYear();
void display(int month, int year);
void displayDays(int month, int year);
void displayHeader(int month, int year);
int numDaysMonth(int month, int year);
int isLeapYear(int year);
int numDaysYear(int i);
int calcOffset(int month, int year);

/*****************************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ****************************************************************************/
int main()
{
   int month = getMonth();
   int year = getYear();

   display(month, year);
   
   return 0;
}

/******************************************
 * getMonth will ask user for which month
 * they want the calendar made
 *****************************************/
int getMonth()
{
   int month = 0;

   do
   {
      cout << "Enter a month number: ";
      cin >> month;
      if (month <= 0 || month > 12)
         cout << "Month must be between 1 and 12.\n";
   }
   while (month <= 0 || month > 12);

   return month;
      
}

/*****************************************
 * getYear will ask user for the year they
 * want the calendar to display
 ****************************************/
int getYear()
{
   int year = 0;

   do
   {
      cout << "Enter year: ";
      cin >> year;
      if (year < 1753)
         cout << "Year must be 1753 or later.\n";
   }
   while (year < 1753);

   return year;
}

/***********************************************
 * display will call the other display functions
 * to create the calendar
 **********************************************/
void display(int month, int year)
{
   displayHeader(month, year);
   displayDays(month, year);
   
}

/**********************************************
 * displayDays will display the numbers of the
 * month on the screen for the user
 *********************************************/
void displayDays(int month, int year)
{
   int numDays = numDaysMonth(month, year);
   int offset = calcOffset(month, year);

   if (offset != 6)
   {
      for (int i = 0; i <= offset; i++)
         cout << "    ";
   }
   
   for (int i = 1; i <= numDays; i++)
   {
      cout << setw(4) << i;
      
      if ((i + offset + 1) % 7 == 0 && i != numDays)
         cout << endl;
   }

   cout << endl;
   
}

/******************************************
 * displayHeader will display on the screen
 * the header for the calendar
 *****************************************/
void displayHeader(int month, int year)
{
   cout << endl;
   
   if (month == 1)
      cout << "January, ";
   if (month == 2)
      cout << "February, ";
   if (month == 3)
      cout << "March, ";
   if (month == 4)
      cout << "April, ";
   if (month == 5)
      cout << "May, ";
   if (month == 6)
      cout << "June, ";
   if (month == 7)
      cout << "July, ";
   if (month == 8)
      cout << "August, ";
   if (month == 9)
      cout << "September, ";
   if (month == 10)
      cout << "October, ";
   if (month == 11)
      cout << "November, ";
   if (month == 12)
      cout << "December, ";

   cout << year << endl;
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";
}

/*******************************************
 * numDaysMonth will determine how many days
 * are in the month and call the isLeapYear
 * function for the month of February
 *******************************************/
int numDaysMonth(int month, int year)
{
   int numDays = 0;
   
   if (month == 1 || month == 3 || month == 5 ||
              month == 7 || month == 8 || month == 10 ||
       month == 12)

      return 31;

   else if (month == 4 || month == 6 || month == 9
            || month == 11)

      return 30;

   else if (month == 2)
   {
      numDays = isLeapYear(year);

      return numDays;
   }
   
}

/**********************************************
 * isLeapYear will determine if given year is a
 * leap year.
 **********************************************/
int isLeapYear(int year)
{
   if (year % 4 != 0)
      return 28;

   else if (year % 100 == 0 && year % 400 != 0)
      return 28;

   else 
      return 29;
}

/************************************************
 * numDaysYear will find how many days there are
 * in a given year, checking to see if its a leap
 * year
 ************************************************/
int numDaysYear(int i)
{
   int numDays = isLeapYear(i) + 337;

   return numDays;  
}

/****************************************************
 * calcOffset will determine how far over the first
 * day of the month will need to be shifted to remain
 * accurate
 ***************************************************/
int calcOffset(int month, int year)
{
   int sum = 0;
   int offset = 0;
   
   for (int i = 1; i < month; i++)
      sum = sum + numDaysMonth(i, year);
   
   for (int i = 1753; i < year; i++)
      sum = sum + numDaysYear(i);

   offset = sum % 7;

   return offset;
}


