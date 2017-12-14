#include <iostream>
#include <vector>

using namespace std;

void removeOdds(vector<int> &number)
{
   vector<int>::iterator it;
   
   for (it = number.begin(); it != number.end();)
   {
      if (*it % 2 != 0)
         it = number.erase(it);
      else
         it++;
   }
}

void displayNumbers(vector<int> &number)
{
   cout << "Your list is: \n";
   vector<int>::iterator it;
   
   for (it = number.begin(); it != number.end() - 1;)
   {
      cout << *it << endl;
      it++;
   }
}

void promptNumbers(vector<int> &number)
{
   int j = 0;
   
   do
   {
      cout << "Enter int: ";
      cin >> j;
      cin.clear();
      cin.ignore();
      number.push_back(j);
   }while(number.back() != 0);
}

int main()
{
   vector<int> number;
   
   promptNumbers(number);
   displayNumbers(number);
   removeOdds(number);
   displayNumbers(number);
   
   return 0;
}