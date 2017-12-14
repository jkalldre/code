#ifndef LANDER_H
#define LANDER_H
#include <iostream>
#include "point.h"
#include "velocity.h"

/********************************************************
* Lander is our primary object and will track its the
* location, velocity and life of our lander.
********************************************************/
class Lander
{
private:
	Point position;
	Velocity velocity;
	int fuel;
	bool alive;
	bool landed;

public:
	/************************
	* Constructors
	*************************/
	Lander();
	Point getPoint()        const { return position; }
	Velocity getVelocity()  const { return velocity; }

	/********************
	* getter functions
	********************/
	int getFuel()           const { return fuel;     }
	bool getLife()
  {
     return alive;
  }

  bool isAlive();
	bool hasLanded(Point p, int w);
	bool getLanded()
  {
     return landed;
  }

	/******************
	* setter functions
	*******************/
	void setPoint(const Point& br);
	void setFuel(int i)
  {
     fuel = i;
  }

  void setVelocity(Velocity v)
  {
     velocity = v;
  }

  void setAlive(bool b)
  {
     alive = b;
  }

  void setLanded(bool b)
  {
     landed = b;
  }

  void endGameConditions(float dx, float dy);

	/***********************************
	* these functions modify velocity
	***********************************/
	bool canThrust()
  {
     if (fuel > 0)
        return true;
  }

  void applyGravity(Velocity g);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void consumeFuel(int amount);

	void advance();

	/*******************************
	* reset function
	*******************************/
	void restartGame();
};
#endif //lander.h
