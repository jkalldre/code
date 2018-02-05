/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy      (e.g. Assignment 01, Hello World)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    My program will take a given DNA sequence and compare it against
*    multiple others to compare the similarities between them
*    
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

char getVariables();
float compareDna(char userDna[], char relativeDna[][50],
                 int numRelative, int i);

/**********************************************************************
 * main will initiate the program
 **********************************************************************/
int main()
{
   getVariables();
   
   return 0;
}

/**********************************************************************
 * getVariables will collect all the input information from user and
 * call compareDNA
 ***********************************************************************/
char getVariables()
{
   
   char userDna[256];
   int numRelative = 0;
   char relativeNames[256][50];
   char relativeDna[10][50];
   
   cout << "Enter your DNA sequence: ";
   cin >> userDna;
   cin.ignore();

   cout << "Enter the number of potential relatives: ";
   cin >> numRelative;
   cin.ignore();
   cout << endl;
   
   for (int i = 0; i < numRelative; ++i) // collects names of relatives
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      cin.getline(relativeNames[i], 256);
   }

   cout << endl;
   
   for (int i = 0; i < numRelative; ++i) // collects dna of relatives
   {
      cout << "Please enter the DNA sequence for " << relativeNames[i]
           << ": ";
      cin >> relativeDna[i];
   }
   
   cout << endl;
   
   for (int i = 0; i < numRelative; ++i) // finds percent by calling function
   {
      cout << "Percent match for " << relativeNames[i] << ": "
           << compareDna(userDna, relativeDna, numRelative, i)
           << "%" << endl;
   }
   
}

/**********************************************************************
 * compareDna will compare the user and relative dna to determine
 * how similar the two strands are.
 ***********************************************************************/
float compareDna(char userDna[], char relativeDna[][50],
                 const int &numRelative, const int &i)
{
   
   int count = 0;
   
   for (int j = 0; j < 10; ++j)
      if (userDna[j] == relativeDna[i][j])
      {
         count++;
      }
   
   int percent = count * 10;
   count = 0;
   
   return percent;
   
}
