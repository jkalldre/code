#include "missle.h"
#include <iostream>


Missle::Missle()
{
	location = Point();
	velocity = Velocity();
	shot = false;
	isAlive = true;
	rotate = 0;
}

Missle::Missle(int x, int y)
{
	location = Point(x, y);
	velocity = Velocity();
	shot = false;
	isAlive = true;
	rotate = 0;
}

void Missle::draw()
{
	
	rotate += 10;
	drawRect(location, 10, 10, rotate);

}

void Missle::advance(Point p, int i)
{
	if (i != -10)
	{
		if (p.getX() != location.getX())
		{
			if (p.getX() > location.getX())
				location.addX(4);
			else
				location.addX(-4);
		}
		
		if (p.getY() != location.getY())
		{
			if (p.getY() >= location.getY())
				location.addY(4);
			else
				location.addY(-4);
		}
		
		
	}
	else
	{
		if (location.getX() != 0)
		{
			if (location.getX() < 0)
				location.addX(4);
			else
				location.addX(-4);
		}

		if (location.getY() != 0)
		{
			if (location.getY() < 0)
				location.addY(4);
			else
				location.addY(-4);
		}
	}
}

