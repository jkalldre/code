/***********************************************************************
* Program:
*    Assignment 11, Output          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*   Print out a monthly budget
*   
*   
*   
*   
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   // show monthly budget
   
   cout.setf(ios::fixed);          // no scientific notation please
   cout.setf(ios::showpoint);      // always shows the point
   cout.precision(2);              // two digits for money


   cout << "\tItem" << setw(21) << "Projected\n";
   cout << "\t=============" << setw(13) << "==========\n";
   cout << "\tIncome" << setw(10) << "$" << setw(9) << 1000.00 << endl;
   cout << "\tTaxes" << setw(11) << "$" << setw(9) << 100.00 << endl;
   cout << "\tTithing" << setw(9) << "$" << setw(9) << 100.00 << endl;
   cout << "\tLiving" << setw(10) << "$" << setw(9) << 650.00 << endl;
   cout << "\tOther" << setw(11) << "$" << setw(9) << 90.00 << endl;
   cout << "\t=============" << setw(13) << "==========\n";
   cout << "\tDelta" << setw(11) << "$" << setw(9) << 60.00 << endl;
   
   return 0;
}
