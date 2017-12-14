/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Falin, CS165
* Author:
*    Jacob Alldredge
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;



// TODO: Define your Complex struct here
struct Complex
{
   double real;
   double imaginary;
};

void display(Complex sum);
double prompt(Complex numbers[]);
Complex addComplex(const Complex numbers[], Complex &sum);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex numbers[2];
  
   // Call your prompt function twice to fill in c1, and c2
   
   prompt(numbers);

   // Declare another Complex for the sum
   Complex sum;

   // Call the addComplex function, putting the result in sum;
   addComplex(numbers, sum);

   display(sum);
   

   return 0;
}

// TODO: Add your prompt function here
double prompt(Complex numbers[])
{
   for (int i = 0; i < 2; ++i)
   {
      cout << "Real: ";
      cin >> numbers[i].real;
      
      cout << "Imaginary: ";
      cin >> numbers[i].imaginary;
   }
   cout << endl;
}

// TODO: Add your display function here
void display(Complex sum)
{
   cout << "The sum is: " << sum.real << " + "
        << sum.imaginary << "i\n";
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex numbers[], Complex &sum)
{
   // TODO: Fill in the body of the add function
   sum.real = numbers[0].real + numbers[1].real;
   sum.imaginary = numbers[0].imaginary + numbers[1].imaginary;

}





