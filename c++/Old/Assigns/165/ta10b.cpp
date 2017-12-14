#include <iostream>
#include <list>

using namespace std;

void removeOdds(list<int> &number)
{
   list<int>::iterator it;
   
   for (it = number.begin(); it != number.end();)
   {
      if (*it % 2 != 0)
         it = number.erase(it);
      else
         it++;
   }
}

void displayNumbers(const list<int> &number)
{
   cout << "Your list is: \n";
   list<int>::const_reverse_iterator it;
   
   for (it = number.rbegin(); it != number.rend();)
   {
      cout << *it << endl;
      it++;
   }
}

void promptNumbers(list<int> &number)
{
   int j = 0;
   
   do
   {
      cout << "Enter int: ";
      cin >> j;
      cin.clear();
      cin.ignore();
      if (j != 0)
         number.push_back(j);
   }while(j != 0);
}

int main()
{
   list<int> number;
   
   promptNumbers(number);
   displayNumbers(number);
   removeOdds(number);
   displayNumbers(number);
   
   return 0;
}