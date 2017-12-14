/***********************************************************************
* Program:
*    Test 4, String Copy          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    Function will imitate the function of strcpy() function
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      In testBed my function keeps printing random numbers(sometimes..)
************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

void stringCopy(char* destination, char* source);

/**********************************************************************
 * main will receive a string either through prompt or commandline 
 * to be copied
 ***********************************************************************/
int main(int argc, char** argv)
{
   char source[256];
   char destination[256];

   if (argc > 1)
   {
      stringCopy(destination, argv[argc - 1]);
   }
   else
   {
      cout << "Please enter a string: ";
      cin.getline(source,256);
      stringCopy(destination, source);
   }

   cout << "The string is: \"" << destination << "\"" << endl;
   return 0;
}

/**********************************************************************
 * stringCopy is copying one string to another, imitating the strcpy
 * function
 ***********************************************************************/
void stringCopy(char* destination, char* source)
{
   for (; *source; source++)
   {
      *destination = *source;
      destination++;
   }
   *destination = 0;
}
         
        
