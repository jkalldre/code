#include "robot.h"
#include <iostream>
using namespace std;

/************************************
 * Function: Display
 * Purpose: Displays the robot.
 ************************************/
void Robot :: display() const
{
   position.display();
   cout << " - Energy: " << getEnergy();
}

Robot::Robot()
{
   energy = 100;
}
   
Robot::Robot(int iEnergy)
{
   setEnergy(iEnergy);
}

Robot::Robot(Point inputPosition, int iEnergy)
{
   position = inputPosition;
   setEnergy(iEnergy);
}

void Robot::moveUp()
{
   if (position.getX() != 10 && getEnergy() - 10 >= 0)
   {
      int newX = position.getX() + 1;
      position.setX(newX);
      int energyLoss = getEnergy() - 10;
      setEnergy(energyLoss);
   }
   else if (position.getX() == 10)
      cout << "Oh wait, that's a wall.." << endl;
   else if (getEnergy() - 10 < 0)
      cout << "Insufficient power.. It's getting dark..\n";
}

void Robot::moveDown()
{
   if (position.getX() != 0 && getEnergy() - 10 >= 0)
   {
      int newX = position.getX() - 1;
      position.setX(newX);
      int energyLoss = getEnergy() - 10;
      setEnergy(energyLoss);
   }
   else if (position.getX() == 0)
      cout << "Oh wait, that's a wall.." << endl;
   else if (getEnergy() - 10 < 0)
      cout << "Insufficient power.. It's getting dark..\n";
}

void Robot::moveLeft()
{
   if (position.getY() != 0 && getEnergy() - 10 >= 0)
   {
      int newY = position.getY() - 1;
      position.setY(newY);
      int energyLoss = getEnergy() - 10;
      setEnergy(energyLoss);
   }
   else if (position.getY() == 0)
      cout << "Oh wait, that's a wall.." << endl;
   else if (getEnergy() - 10 < 0)
      cout << "Insufficient power.. It's getting dark..\n";
}

void Robot::moveRight()
{
   if (position.getY() != 10 && getEnergy() - 10 >= 0)
   {
      int newY = position.getY() + 1;
      position.setY(newY);
      int energyLoss = getEnergy() - 10;
      setEnergy(energyLoss);
      
   }
   else if (position.getY() == 10)
      cout << "Oh wait, that's a wall.." << endl;
   else if (getEnergy() - 10 < 0)
      cout << "Insufficient power.. It's getting dark..\n";
}

void Robot::fireLaser()
{
   if (getEnergy() - 25 >= 0)
   {
      cout << "Pew!Pew!\n";
      int energyLoss = getEnergy() - 25;
      setEnergy(energyLoss);
   }
   else
      cout << "Insufficient power.. It's getting dark..\n";
}