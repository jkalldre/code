#include <iostream>
#include <string>

// animal is not always a dog
class Animal
{
private:
  int numLegs;
public:
  Animal() : numLegs(0) {}
  Animal(int leg) : numLegs(leg) {}


  void displayLegs()
  {
    std::cout << "I have " << numLegs << " legs!" << std::endl;
  }

};

// dog is an Animal
class Dog : public Animal
{
private:
  bool hasTail;

public:
  // calls Animal default constructor
  Dog() {}   
  // calls Animal non-default constructor
  Dog(int leg) : Animal(leg), hasTail(true) {}
  bool getTail() {return hasTail;}
};


int main()
{
  // initilize animal object
  Animal a(4);
  a.displayLegs();

  // initilize dog object
  Dog d(8);
  d.displayLegs();
  std::cout << d.getTail() << std::endl;
  return 0;
}
