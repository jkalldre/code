/*************************************************************************
* Program:                                                               
*    Project 1, Monthly Budget                                           
*    Brother Grimmett, cs124                                              
* Author:                                                                
*    Jacob Alldredge                                                     
* Summary:                                                               
*    This program will ask for user input to calculate and display       
*    the users budget in an organized format.                            
*                                                                        
*    Estimated:  5.0 hrs                                                 
*    Actual:     5.0 hrs                                                 
*                                                                        
*   Making style checker happy.                                          
**************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

float getIncome();
float getBudgetLiving();
float getBudgetTithing(float income);
float getComputedTax(float income);
float getActualLiving();
float getActualTax();
float getActualTithing();
float getActualOther();
float getBudgetOther(float income, float computeTax, float budgetTithing,
                     float budgetLiving);
float getBudgetDifference(float income, float computeTax, float budgetTithing,
                          float budgetLiving, float budgetOther);
float getActualDifference(float income, float actualTax, float actualLiving,
                          float actualTithing, float actualOther);
float display(float income, float budgetLiving, float budgetTithing,
              float computeTax, float actualLiving, float actualTax,
              float actualTithing, float actualOther, float budgetDifference,
              float actualDifference, float budgetOther);
   
/******************************************
* Main function will call other functions *
* to get variable values from the user    *
*******************************************/
int main()
{
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "This program keeps track of your monthly budget\n"
        << "Please enter the following:\n";

   float income = getIncome();
   float budgetLiving = getBudgetLiving();
   float budgetTithing = getBudgetTithing(income);
   float computeTax = getComputedTax(income);
   float actualLiving = getActualLiving();
   float actualTax = getActualTax();
   float actualTithing = getActualTithing();
   float actualOther = getActualOther();
   float budgetOther = getBudgetOther(income, computeTax, budgetTithing,
                                      budgetLiving);
   float budgetDifference = getBudgetDifference(income, computeTax,
                             budgetTithing, budgetLiving, budgetOther);
   float actualDifference = getActualDifference(income, actualTax,
                             actualLiving, actualTithing, actualOther);
   
   
   cout << "The following is a report on your monthly expenses\n";
   cout << "\tItem                  " << setw(10)
        << "Budget    " << setw(13) << "Actual\n";
        
   display(income, budgetLiving, budgetTithing, computeTax,
           actualLiving, actualTax, actualTithing, actualOther,
           budgetDifference, actualDifference, budgetOther);
   
   return 0;
}

/***********************
* Get income from user *
************************/
float getIncome()
{
   float income = 0;
   cout << "\tYour monthly income: ";
   cin >> income;

   return income;
}

/**************************************
* Get predicted living cost from user *
***************************************/
float getBudgetLiving()
{
   float budgetLiving = 0;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;

   return budgetLiving;
}

/***********************************
* Get actual living cost from user *
************************************/
float getActualLiving()
{
   float actualLiving = 0;
   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;

   return actualLiving;
}

/***************************
* Get actual tax from user *
****************************/
float getActualTax()
{
   float actualTax = 0;
   cout << "\tYour actual taxes withheld: ";
   cin >> actualTax;

   return actualTax;
} 

/*******************************
* Get actual tithing from user *
********************************/
float getActualTithing()
{
   float actualTithing;
   cout << "\tYour actual tithe offerings: ";
   cin >> actualTithing;

   return actualTithing;
}

/**************************************
* Get actual other expenses from user *
***************************************/
float getActualOther()
{
   float actualOther = 0;
   cout << "\tYour actual other expenses: ";
   cin >> actualOther;
   cout << endl;

   return actualOther;
}

/****************************************
* Will discover tithing owed for budget *
*****************************************/
float getBudgetTithing(float income)
{
   float budgetTithing = (income * .10);

   return budgetTithing;
}

/*************************************************
* Will compute tax required according to income *
**************************************************/
float getComputedTax(float income)
{
   float yearlyIncome = (income * 12);
   float yearlyTax = 0;
   float monthlyTax = 0;

   if ( yearlyIncome >= 0.0 && yearlyIncome < 15100.0)
      yearlyTax = (yearlyIncome * .10);
   
   else if ( yearlyIncome >= 15100.0 && yearlyIncome < 61300.0)
      yearlyTax = (1510.0 + (.15 * (yearlyIncome - 15100.0)));
   
   else if ( yearlyIncome >= 61300.0 && yearlyIncome < 123700.0)
      yearlyTax = (8440.0 + (.25 * (yearlyIncome - 61300.0)));
   
   else if ( yearlyIncome >= 123700.0 && yearlyIncome < 188450.0)
      yearlyTax = (24040.0 + (.28 * (yearlyIncome - 123700.0)));

   else if ( yearlyIncome >= 188450.0 && yearlyIncome < 336550.0)
      yearlyTax = (42170.0 + (.33 * (yearlyIncome - 188450.0)));

   else
      yearlyTax = (91043.0 + (.35 * (yearlyIncome - 336550.0)));

   monthlyTax = (yearlyTax / 12);

   return monthlyTax;
}

/*************************************************************
 * Will calculate the other cost to reach a difference of $0 *
 *************************************************************/
float getBudgetOther(float income, float computeTax, float budgetTithing,
                     float budgetLiving)
{
   float budgetOther = (income - (computeTax + budgetTithing + budgetLiving));

   return budgetOther;
}

/**************************************
* Will discover the budget difference *
***************************************/
float getBudgetDifference(float income, float computeTax, float budgetTithing,
                          float budgetLiving, float budgetOther)
{
   float budgetDifference = (income - (computeTax + budgetTithing +
                                       budgetLiving + budgetOther));

   return budgetDifference;
}

/**************************************
* Will discover the actual difference *
***************************************/
float getActualDifference(float income, float actualTax, float actualLiving,
                          float actualTithing, float actualOther)
{
   float actualDifference = (income - (actualTax + actualLiving +
                                       actualTithing + actualOther));

   return actualDifference;
}

/******************************************
* Function will display all the collected *
* and calculated information for the user *
*******************************************/
float display(float income, float  budgetLiving, float budgetTithing,
              float computeTax, float actualLiving, float actualTax,
              float actualTithing, float actualOther, float budgetDifference,
              float actualDifference, float budgetOther)
{
   cout << "\t=============== =============== ===============\n"
          << "\tIncome          $" << setw(11) << income << setw(5)
          << "$" << setw(11) << income    << endl;
     
   cout << "\tTaxes           $" << setw(11) << computeTax << setw(5)
          << "$" << setw(11) << actualTax << endl;
     
   cout << "\tTithing         $" << setw(11) << budgetTithing << setw(5)
          << "$" << setw(11) << actualTithing << endl;
     
   cout << "\tLiving          $" << setw(11) << budgetLiving << setw(5)
          << "$" << setw(11) << actualLiving << endl;
     
   cout << "\tOther           $" << setw(11) << budgetOther << setw(5)
          << "$" << setw(11) << actualOther << endl;
     
   cout << "\t=============== =============== ===============\n"
          << "\tDifference      $" << setw(11) << budgetDifference << setw(5)
          << "$" << setw(11) << actualDifference << endl;
     
   return 0;
}
