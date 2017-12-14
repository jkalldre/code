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
	virtual int breakApart(std::list<Rock*> &r) { return 0; } // function creats smaller rocks and returns how many rocks resulted 
	virtual void advance();                                   // to track number of rocks on screen
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
		location = p;
		alive = true;
		velocity.setDx(random(-1, 1));
		velocity.setDy(random(-1, 1));
	}
	virtual int breakApart(std::list<Rock*> &r);
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
	virtual int breakApart(std::list<Rock*> &r);
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
	virtual int breakApart(std::list<Rock*> &r) { return 0; }
	virtual void draw();
};



#endif /* rocks_h */
