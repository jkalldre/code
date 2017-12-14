#ifndef rocks_h
#define rocks_h

#define BIG_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define BIG_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10
#include "flyingObject.h"
#include <list>


// Define the following classes here:
//   Rock
class Rock : public FlyingObject
{
protected:
	int rotation;
public:
	virtual void draw() {}
	virtual void breakApart(std::list<Rock*> &r) {}
	virtual void advance();
};
//   BigRock
class BigRock : public Rock
{
private:
public:
	
	BigRock(Point p)
	{
		radius = 16;
		rotation = 2;
		do
		{
			location = p;
		} while(p.getX() >= -10 && p.getX() <= 10);
		alive = true;
		velocity.setDx(random(-1, 1));
		velocity.setDy(random(-1, 1));
	}
	virtual void breakApart(std::list<Rock*> &r);
	virtual void draw();
	
};

//   MediumRock
class MediumRock : public Rock
{
private:
public:
	MediumRock(Rock b, int i)
	{
		radius = 8;
		rotation = 5;
		location = b.getPoint();
		alive = true;
		velocity.setDx(b.getDx());
		velocity.setDy(b.getDy() + i);
	}
	virtual void breakApart(std::list<Rock*> &r);
	virtual void draw();
};

//   SmallRock
class SmallRock : public Rock
{
private:
public:
	SmallRock(Rock b, int i)
	{
		radius = 6;
		rotation = 10;
		location = b.getPoint();
		alive = true;
		velocity.setDx(b.getDx() + i);
		velocity.setDy(b.getDy());
	}
	virtual void breakApart(std::list<Rock*> &r) {}
	virtual void draw();
};



#endif /* rocks_h */
