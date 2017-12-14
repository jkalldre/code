#include <iostream>
#include <string>


class World
{
private:
  std::string name;

public:
  World() { setName(""); }

  void setName(std::string s) { name = s; }
  void setBox(int hat, int cat, int & bat)
  {
    this->x = hat;
    this->y = cat;
    this->z = bat;
  }

  void display()
  {
    std::cout << "Hello from inside the world!" << std::end;
  }

};



void display()
{
  std::cout << "Hello, World!" << std::endl;

}

int main()
{
  display(); // call local function

  World w;
  w.display(); // member function display();
  w.setName("Earth");
  std::string x = "Earth";
  w.setName(x);

  World* wp = new World();
  (*wp).display(); /* THE SAME */ wp->display();
  wp->setName("Earth");
  std::string x = "Earth";
  wp->setName(x);

  int x = 50;
  int y = 60;
  int z = 70;

  world->setBox(x,y,z); // == world->setBox(50,60,70);

  delete wp;
  return 0;

}
