#include "velocity.h"

#include <iostream>
using namespace std;

// TODO: Put your method bodies here



void Velocity :: prompt()
{
   cout << "dx: ";
   cin >> dx;

   cout << "dy: ";
   cin >> dy;
}

void Velocity :: display() const 
{
   cout << "(dx=" << dx << ", dy=" << dy << ")";
}

void operator +=(Velocity & lhs, const Velocity & rhs)
{
   
   lhs.setDx(lhs.getDx() + rhs.getDx());
   lhs.setDy(lhs.getDy() + rhs.getDy());
   
}

Velocity operator +(const Velocity & lhs, const Velocity & rhs)
{
   Velocity answer;
   answer.setDx(lhs.getDx() + rhs.getDx());
   answer.setDy(lhs.getDy() + rhs.getDy());
   
   return answer;
}

void operator -=(Velocity & lhs, const Velocity & rhs)
{
   
   lhs.setDx(lhs.getDx() - rhs.getDx());
   lhs.setDy(lhs.getDy() - rhs.getDy());
   
}

Velocity operator -(const Velocity & lhs, const Velocity & rhs)
{
   Velocity answer;
   answer.setDx(lhs.getDx() - rhs.getDx());
   answer.setDy(lhs.getDy() - rhs.getDy());
   
   return answer;
}

bool operator ==(const Velocity & lhs, const Velocity & rhs)
{
   if (lhs.getDx() <= rhs.getDx() + .001 && lhs.getDx >= rhs.getDx() - .001
       && lhs.getDy() <= rhs.getDy() + .001 && lhs.getDy >= rhs.getDy() - .001)
      return true;
   else
      return false;
}

bool operator !=(const Velocity & lhs, const Velocity & rhs)
{
   if (!(lhs == rhs))
      return true;
   else
      return false;
}

bool operator >(const Velocity & lhs, const Velocity & rhs)
{
   if ( (lhs.getDx() * lhs.getDx() + lhs.getDy() * lhs.getDy())
       > (rhs.getDx() * rhs.getDx() + rhs.getDy() * rhs.getDy()))
      return true;
   else
      return false;
    
}

bool operator <(const Velocity & lhs, const Velocity & rhs)
{
   if (!(lhs > rhs))
      return true;
   else
      return false;
}

bool operator >=(const Velocity & lhs, const Velocity & rhs)
{
   if ( (lhs.getDx() * lhs.getDx() + lhs.getDy() * lhs.getDy())
       >= (rhs.getDx() * rhs.getDx() + rhs.getDy() * rhs.getDy()))
      return true;
   else
      return false;
}

bool operator <=(const Velocity & lhs, const Velocity & rhs)
{
   if (!(lhs >= rhs))
      return true;
   else
      return false;
}