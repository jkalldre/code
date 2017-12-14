/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include "date.h"
#include <iostream>

// Put your method bodies here...
void Date::set()
{
   std::cout << "Month: ";
   std::cin >> month;
   std::cout << "Day: ";
   std::cin >> day;
   std::cout << "Year: ";
   std::cin >> year;
   std::cout << std::endl; 
   
}

void Date::displayAmerican()
{
   std::cout << month << "/" << day << "/" << year << std::endl;
}

void Date::displayEuropean()
{
   std::cout << day << "/" << month << "/" << year << std::endl;
}

void Date::displayISO()
{
   std::cout << year << "-" << month << "-" << day << std::endl;
}