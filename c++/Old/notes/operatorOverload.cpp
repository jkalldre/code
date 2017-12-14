#include <iostream>
using namespace std;

class CatanPlayer
{
   private:
    int ore;
    int wool;
   
   public:
    CatanPlayer(int ore, int wool) : ore(ore), wool(wool) {}
    int getOre() {return ore;}
    int getWool() {return wool;}
  /*  void display(ostream & theStream)
    {
       theStream << "This player has " << ore
            << " pieces of ore and " << wool
            << " pieces of wool." << endl;
    }
*/
};

ostream & operator <<(ostream & lhs, CatanPlayer rhs) // this is overloading the << operator
{
       lhs << "This player has " << rhs.getOre()
            << " pieces of ore and " << rhs.getWool()
            << " pieces of wool." << endl;
}

CatanPlayer operator +(CatanPlayer & lhs, CatanPlayer & rhs) // this is overloading the + operator
{
   CatanPlayer answer(lhs.getOre() + rhs.getOre(),
                      lhs.getWool() + rhs.getWool());
   return answer; // the new CatanPlayer is returned as a copy not by reference
}

CatanPlayer operator +=(CatanPlayer & lhs, int rhs) // this is overloading the + operator
{
   CatanPlayer answer(lhs.getOre() + rhs,
                      lhs.getWool() + rhs);
   return answer; // the new CatanPlayer is returned as a copy not by reference
}

CatanPlayer operator +(CatanPlayer lhs, int rhs) // this is overloading the + operator
{
   return lhs += rhs;
}

int main()
{
   CatanPlayer p1(1,2);
   CatanPlayer p2(10,0);
   
   CatanPlayer p3 = p1 + p2;
   CatanPlayer p4 = p1 + 5;
   cout << endl << p3 << endl;
   cout << p4 << endl;
}

/*
Rules to operator overloading
1. Op. Overload should make sense
2. Op. Should come in sets
   +       -      && ==
   +=      -=     || !=
3. Op. should be defined in terms of one another
*/