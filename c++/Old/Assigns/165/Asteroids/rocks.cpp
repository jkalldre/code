#include "rocks.h"
#include "uiDraw.h"

// Put your Rock methods here
/**********************************************
* draw:
*	draws the designated rock
***********************************************/
void BigRock::draw()
{
	rotation += 2;
	drawLargeAsteroid(location, rotation);
}
void MediumRock::draw()
{
	rotation += 5;
	drawMediumAsteroid(location, rotation);
}
void SmallRock::draw()
{
	rotation += 10;
	drawSmallAsteroid(location, rotation);
}

/**********************************************
* advance:
*	moves each rock forward
***********************************************/
void Rock::advance()
{
	location.addX(velocity.getDx());
	location.addY(velocity.getDy());
}

/**********************************************
* breakApart:
*	breaks bigger rocks into smaller ones
*   and returns number of additional rocks
*	created.
***********************************************/
int BigRock::breakApart(std::list<Rock*> &r)
{
	Rock* pRock = new MediumRock(*this, 1);
	r.push_back(pRock);

	Rock* pRock2 = new MediumRock(*this, -1);
	r.push_back(pRock2);

	Rock* pRock3 = new SmallRock(*this, 2);
	r.push_back(pRock3);
	
	return 3;
}
int MediumRock::breakApart(std::list<Rock*> &r)
{
	Rock* pRock = new SmallRock(*this, 3);
	r.push_back(pRock);

	Rock* pRock2 = new SmallRock(*this, -3);
	r.push_back(pRock2);

	return 2;
}

