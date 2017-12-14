#ifndef LANDER_H
#define LANDER_H
#include <iostream>
#include "point.h"
#include "velocity.h"


class Lander
{
private:
	Point position;
	Velocity velocity;
	int fuel;
	bool alive;
	bool landed;

public:
	Lander();
	Point getPoint()        const { return position; }
	Velocity getVelocity()  const { return velocity; }
	int getFuel()           const { return fuel;     }
	
	bool isAlive();
	bool hasLanded();
	
	void setPoint(Point p);
	void setVelocity(Velocity v);
	void setAlive(bool b);
	void setLanded(bool b);
	
	bool canThrust();
	void applyGravity(float f);
	void applyThrustLeft();
	void applyThrustRight();
	void applyThrustBottom();
	void consumeFuel(int amount);
	
	void advance();
	void draw();
};
#endif //lander.h
