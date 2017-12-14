/**************************************************
* Program:
*    Test 1,
*    Brother {Burton, Grimmett, Helfrich, Jones, Sloan}, CS124
* Author:
*    your name
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS
************************************************************/

#include <iostream>

using namespace std;


bool getPassedOrNot(float testGrade);
float getInput();


int main()
{
   float testGrade = getInput();
   
    getPassedOrNot(testGrade);

   return 0;
}

bool getPassedOrNot(float testGrade)
{
   if (testGrade >= 60)
      cout << "You passed the test.\n";
            
   else
      cout << "You failed the test.\n";
         
   return 0;
   
}

float getInput()
{
   float testGrade = 0;

   cout << "What was your grade on the last test? ";
   cin >> testGrade;

   return testGrade;
   
}
