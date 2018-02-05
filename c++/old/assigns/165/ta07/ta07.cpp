#include <iostream>
using namespace std;

// Core requirements
float getValueFromPointer(float* thePointer);
float* getMinValue(float* a, float* b);

// Stretch goals
void swapElements(float* theArray[], int a, int b);
void sortArray(float* theArray[]);

int main()
{  

    // Core Requirement 1
   int arraySize;
   cout << "Enter the array size: ";
   cin >> arraySize;

   // Allocate your array(s) here
   float* myArray = new float[arraySize];
   float** arrayPoint = new float*[arraySize];
   
   // Fill your array with float values
   for(int i = 0; i < arraySize; i++) 
   {
          cout << "Enter a float value: ";
          cin >> myArray[i];
          cin.clear();
          cin.ignore();
   }

    // Core Requirement 2
   for (int i = 0; i < arraySize; i++)
   {
      float* pMyArray = &myArray[i];
      float value = getValueFromPointer(pMyArray);
      cout << "The value of the element " << i << " is: ";
      cout << value << endl;
   }
   
   // stretch 1
   for (int i = 0; i < arraySize; i++)
   {
      arrayPoint[i] = &myArray[i];
      cout << *arrayPoint[i] << endl;
   }

   // Core Requirement 3
   // Print the smaller of the first and last elements of the array
   
   float* pFirst = &myArray[0];
   float* pLast = &myArray[arraySize - 1];
   
   float *pointerToMin = getMinValue(pFirst, pLast);
   cout << *pointerToMin << endl;
   

   // Clean up your array(s) here
   delete [] myArray;
   delete [] arrayPoint;
   return 0;
}

float getValueFromPointer(float* thePointer)
{
   float value = *thePointer;
   return value;
}

float* getMinValue(float* a, float* b)
{
   if (*a < *b)
      return a;
   else
      return b;
}