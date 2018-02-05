/******************
 * File: money.h
 ******************/
#ifndef MONEY_H
#define MONEY_H
 
class Money
{
private:
   int dollars;
   int cents;

public:
   Money();
   Money(int iDollars);
   Money(int iDollars, int iCents);
   void prompt();
   void display();
   int getDollars()
   {
      return dollars;
   }
   int getCents()
   {
      return cents;
   }   
   int setDollars(int d);
   int setCents(int c);
};

#endif
 