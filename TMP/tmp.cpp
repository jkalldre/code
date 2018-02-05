#include <iostream>
#include <cassert>

class Money
{
public:
  int dollar;
  int cents;
  void prompt()
  {
    cout << "give dollar and cents amounts";
  }
};

int main()
{
  Money money;     // 0xabcd
  Money* pmoney;
  pmoney = &money; // pmoney = 0xabcd

  delete pmoney;
  pmoney = NULL;

  dosomething(tmp);
  return 0;
}

void dosomething(int & p)
{

}
