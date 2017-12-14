#include "rifle.h"
#include "uiDraw.h"
#include "point.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

/**************************************
* Default constructor
**************************************/
Rifle::Rifle()
{
	location = Point(200, -200);
	angle = 45;
}

/**************************************
* draw the rifle
**************************************/
void Rifle::draw()
{
	drawRect(location, 10, 101, angle);
}

/**************************************
* rotate up
**************************************/
void Rifle::rotateUp()
{
	angle -= 3;
}

/**************************************
* rotate down
**************************************/
void Rifle::rotateDown()
{
	angle += 3;
}
