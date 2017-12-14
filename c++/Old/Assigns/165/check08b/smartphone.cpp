/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include <string>
#include <iostream>

using namespace std;
// TODO: Put your SmartPhone methods here
void SmartPhone::prompt()
{
   promptNumber();
   cin.ignore();
   cout << "Email: ";
   getline(cin, email);
   
}

void SmartPhone::display()
{
   Phone::display();
   cout << email << endl;
}