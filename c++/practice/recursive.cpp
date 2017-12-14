#include <iostream>
#include <stdlib.h>

int r(int n)
{

  if (n == 0)
    return 1;
  else
    return n * r(n-1);

}

int main(int argc, char ** argv)
{
  std::cout << r(atoi(argv[1])) << std::endl;
  int product = 1;
  for (int i = 4; i > 0; i--)
  {
    product *= i;
  }
}



/*
return 1 * 1 // r(0) = 1
return 2 * 1 // r(1) = 1
return 3 * 2 // r(2) = 2

return 4 * 6 // r(3) = 6

24

*/
