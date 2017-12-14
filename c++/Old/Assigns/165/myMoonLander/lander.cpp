#include "lander.h"
#include <iomanip>

/*******************************************************
* Lander's default constructor.
********************************************************/
Lander::Lander()
{
	fuel = 500;
	alive = true;
	velocity = Velocity();
	position = Point(0, 150);
}

/*******************************************************
* applies gravity to the lander.
********************************************************/
void Lander::applyGravity(Velocity g)
{
	velocity.addOnto(g);
}

/*******************************************************
* calculates the landers movements.
********************************************************/
void Lander::advance()
{
	position.addX(velocity.getDx());
	position.addY(velocity.getDy());
}

/*******************************************************
* function to consume lander fuel upon action.
********************************************************/
void Lander::consumeFuel(int amount)
{
	fuel -= amount;
}

/*******************************************************
* applies thrust left.
********************************************************/
void Lander::applyThrustLeft()
{
	velocity.setDx(.1);
}

/*******************************************************
* applies thrust right.
********************************************************/
void Lander::applyThrustRight()
{
	velocity.setDx(-.1);
}

/*******************************************************
* applies bottom thrust
********************************************************/
void Lander::applyThrustBottom()
{
	velocity.setDy(.3);
}

/*******************************************************
* states that the lander is still alive 
********************************************************/
bool Lander::isAlive()
{
	return true;
}

/*******************************************************
* endGameConditions : this will make the lander stop
* moving to end the game.
********************************************************/
void Lander::endGameConditions(float dx, float dy)
{
	velocity.setDx(dx);
	velocity.setDy(dy);	
}

/*******************************************************
* hasLanded : gives the successful conditions of a lunar
* landing.
********************************************************/
bool Lander::hasLanded(Point p, int w)
{
	if ((position.getY()) >= p.getY() &&   // gotta line yourself up just right.
		(position.getY()) <= (p.getY() + 4) &&
		position.getX() >= (p.getX() - (w / 2)) &&
		position.getX() <= (p.getX() + (w / 2)))
	{
		if ((velocity.getDy() + velocity.getDx()) < 3) // make sure you arent coming in too fast
			setLanded(true);
		else
			setLanded(false);

		return landed;
	}
	else
		return false;
}

/*****************************************************
* This function will make the lander fly off one side
* of the screen and appear on the other.
******************************************************/
void Lander::setPoint()
{
	if (position.getX() > 200)
		position.setX(-200);
	if (position.getX() < -200)
		position.setX(200);
}

/***************************************
* restartGame: will reset variables to
* starting conditions
***************************************/
void Lander::restartGame()
{
	fuel = 500;
	alive = true;
	velocity = Velocity();
	position = Point(0, 150);
}
