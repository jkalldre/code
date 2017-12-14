#include <iostream>

using namespace std;


template <typename T>
void findTheNumber(T haystack[], int hayStackSize, T needle)
{
   for (int i = 0; i < hayStackSize; i++)
      if(haystack[i] == needle)
         cout << "Found " << needle << " at index: " << i << endl;
}

int main()
{
   int someNumber[] = {1,2,3,4,5};
   int size = sizeof(someNumber) / sizeof(someNumber[0]);
   
   findTheNumber(someNumber, size, 3); 
   
   float someNumbers[] = {1.2, 2.4, 3.3, 4.3, 5.6};
   int size2 = sizeof(someNumbers) / sizeof(someNumbers[0]);
   
   findTheNumber(someNumbers, size2, 4.3f); 
}