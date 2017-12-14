/***********************************************************************
* Program:
*    Checkpoint 10a, Vectors
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // int array and cin and display
   vector<int> ints;
   int j = 0;
   vector<int>::iterator it;
   do
   {
      cout << "Enter int: ";
      cin >> j;
      cin.ignore();
      ints.push_back(j);
   }while(ints.back() != 0);
   
   cout << "Your list is:\n";
   
   for (it = ints.begin(); it != ints.end() - 1;)
      {
         cout << *it << endl;
         it++;
      }
   cout << endl;
   
   // string array and cin and display
   vector<string> strings;
   vector<string>::iterator it2;
   string s;
   do
   {
      cout << "Enter string: ";
      getline(cin, s);
      strings.push_back(s);
      
   }while(strings.back() != "quit");
   
   cout << "Your list is:\n";
   
   for (it2 = strings.begin(); it2 != strings.end() - 1;)
      {
         cout << *it2 << endl;
         it2++;
      }
  
   
   return 0;
}


//cin >> i;
//int i = 0;