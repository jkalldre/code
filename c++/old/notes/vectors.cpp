#include <iostream>
#include <vector>

using namespace std;

int main()
{
   vector <int> numbers;
   
   numbers.push_back(12);
   numbers.push_back(10);
   numbers.push_back(8);
   
   // if i want to use vectors for bullets it must be a vector of pointers
   // this is the code
   /*
   vector <Bullet*> b;
   b.push_back(new Bullet());
   
   
   
   
   cout << numbers[0] << endl; // works as expected but crashes if array is exceded
   cout << numbers.at(3) << endl; // this has better error handling and will throw an exeption
   */
   
   for (int i = 0; i < numbers.size(); i++)
   {
      cout << numbers.at(i) << endl;
   }
}


/*
 vector<int>::iterator it = numbers.begin();
 it += 2 <- this sets it to the second item

 vector<int>::iterator it;

 for (it = numbers.begin(); it != numbers.end();)
 {
     if (*it == 1)
        it = numbers.erase( it )
     else
        it++
 }
*/