/***********************************************************************
* Program:
*    Assignment 21, Stubs          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jacob Alldredge
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

float getPeriodicCost();
float getUsageCost();
float promptDevalue();
float promptInsurance();
float promptParking();
float promptMileage();
float promptGas();
float promptRepairs();
float promptTires();
void display(float costUsage, float costPeriodic);

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   float costUsage = 0;
   float costPeriodic = 0;
   
   getPeriodicCost();
   getUsageCost();
   display(costUsage, costPeriodic);
   
   return 0;
}

float getPeriodicCost()
{
   promptDevalue();
   promptInsurance();
   promptParking();
   
   return 0;
}

float getUsageCost()
{
   promptMileage();
   promptGas();
   promptRepairs();
   promptTires();
   
   return 0;
}

float promptDevalue()
{
   return 0;
}

float promptInsurance()
{
   return 0;
}

float promptParking()
{
   return 0;
}

float promptMileage()
{
   return 0;
}

float promptGas()
{
   return 0;
}

float promptRepairs()
{
   return 0;
}

float promptTires()
{
   return 0;
}

void display(float costUsage, float costPeriodic)
{
   cout << "Success\n";
   
   return;
}

