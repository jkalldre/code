#ifndef RIFLE_H
#define RIFLE_H
#include "point.h"
#include "uiDraw.h"


//Defines what a rifle is.
class Rifle
{
private:
	Point location;
	float angle;
	Point gunEnd;

public:
	Rifle();
	void rotateUp();
	void rotateDown();
	void draw();
	
	Point getLocation()
	{
		return location;
	}
	float getAngle()
	{
		return angle;
	}

	int setAngle(float a)
	{
		angle = a;
	}

};
#endif