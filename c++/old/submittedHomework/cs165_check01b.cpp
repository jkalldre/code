/***********************************************************************
* Program:
*    Checkpoint 01b, Divisible by 3          (e.g. Checkpoint 01a, review)  
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

int getSize(int &size);
int getList(int size, int list[]);
void displayMultiples(int size, int list[]);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int size;
   int list[20];

   getSize(size);
   getList(size, list);
   displayMultiples(size, list);
   
   return 0;
}

int getSize(int &size)
{
   cout << "Enter the size of the list: ";
   cin >> size;

   return size;
}

int getList(int size, int list[])
{
   for(int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
   }
   cout << endl;
}

void displayMultiples(int size, int list[])
{
   cout << "The following are divisible by 3:\n";
   
   for(int i = 0; i < size; i++)
   {
      if (list[i] % 3 == 0)
         cout << list[i] << endl;
   }
}
