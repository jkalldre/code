#include "rifle.h"
#include "uiDraw.h"
#include "point.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

Rifle::Rifle()
{
	location = Point(200, -200);
	angle = 45;
}

void Rifle::draw()
{
	drawRect(location, 10, 101, angle);
}

void Rifle::rotateUp()
{
	angle -= 3;
}

void Rifle::rotateDown()
{
	angle += 3;
}
/*
Point Rifle::getGunEnd()
{
	gunEnd.setX(cos(angle) * 50);
	gunEnd.setY(sin(angle) * 50);
}
*/