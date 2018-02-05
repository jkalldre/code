/*********************************************************************
 * File: game.cpp
 * Author: Br. Burton
 *
 * This file is provided as the instructor's "half" of the project.
 *
 * Please DO NOT provide, share, or distribute this file to students
 * of other sections or semesters.
 *********************************************************************/

#include "game.h"
#include <limits>
#include <cmath>
#include <algorithm>


#define WINDOW_X_SIZE 200
#define WINDOW_Y_SIZE 200

Point Game :: topLeft;
Point Game :: bottomRight;

/***************************************
 * GAME :: getRandomPoint
 * Gets a random point within the boundaries of the world.
 ***************************************/
Point Game :: getRandomPoint() const
{
   int x = random(topLeft.getX(), bottomRight.getX());
   int y = random(bottomRight.getY(), topLeft.getY());

   Point p(x, y);

   return p;
}


/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game :: advance()
{
   if (pShip->isAlive())
      pShip->advance();

   if (pShip->getX() < -200)  // this makes creates the wrap around feature
	   pShip->setX(200);      //
   if (pShip->getX() > 200)   //
	   pShip->setX(-200);     //
   if (pShip->getY() < -200)  //
	   pShip->setY(200);      //
   if (pShip->getY() > 200)   //
	   pShip->setY(-200);     //

   for (list<Bullet*>::iterator bulletIt = bullets.begin();
        bulletIt != bullets.end();
        bulletIt++)
   {
      (*bulletIt)->advance();
	  (*bulletIt)->dieSlowly();
	  if ((*bulletIt)->getX() < -200) // wrap around
		  (*bulletIt)->setX(200);
	  if ((*bulletIt)->getX() > 200)
		  (*bulletIt)->setX(-200);
	  if ((*bulletIt)->getY() < -200)
		  (*bulletIt)->setY(200);
	  if ((*bulletIt)->getY() > 200)
		  (*bulletIt)->setY(-200);
   }

   for (list<Rock*>::iterator rockIt = rocks.begin();
        rockIt != rocks.end();
        rockIt++)
   {
      (*rockIt)->advance();
	  if ((*rockIt)->getX() < -200)  //wrap around
		  (*rockIt)->setX(200);
	  if ((*rockIt)->getX() > 200)
		  (*rockIt)->setX(-200);
	  if ((*rockIt)->getY() < -200)
		  (*rockIt)->setY(200);
	  if ((*rockIt)->getY() > 200)
		  (*rockIt)->setY(-200);
   }


   checkForCollisions();
   cleanUpZombies(); // deletes any "dead" objects

}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
	if (pShip->isAlive())
	{
		if (ui.isLeft())    // rotate left
		{
			pShip->turnLeft();
		}

		if (ui.isRight())  // rotate right
		{
			pShip->turnRight();
		}


		if (ui.isUp())   // apply thrust
		{
			pShip->thrust();
		}

		if (ui.isDown()) // apply breaks
		{
			pShip->breaks();
		}

		if (ui.isSpace()) // shoot
		{
			Bullet* pBullet = new Bullet(*pShip);
			bullets.push_back(pBullet);
		}
	}
	  if (ui.isR() && !(pShip->isAlive()) && pShip->getLives() > 0) // death conditions
	  {
		  pShip->giveLife();
		  pShip->setX(0);
		  pShip->setY(0);
		  pShip->setDx(0.0);
		  pShip->setDy(0.0);
		  pShip->subLife();
	  }
	  if (ui.isR() && !(pShip->isAlive()) && pShip->getLives() == 0) // game over conditions
	  {
		  for (list<Rock*>::iterator rockIt = rocks.begin();
		  rockIt != rocks.end();
			  rockIt++)
		  {
			  (*rockIt)->kill();
		  }
		  for (int i = 0; i < INITIAL_ROCK_COUNT; i++)
		  {
			  Rock* pRock = new BigRock(getRandomPoint());
			  rocks.push_back(pRock);
		  }
		  pShip->giveLife();
		  pShip->setX(0);
		  pShip->setY(0);
		  pShip->setDx(0.0);
		  pShip->setDy(0.0);
		  pShip->setLives(3);
	  }
	  if (ui.isR() && pShip->isAlive() && pShip->getLives() > 0 && rockCount == 0) // victory conditions
	  {
		  for (list<Rock*>::iterator rockIt = rocks.begin();
		  rockIt != rocks.end();
			  rockIt++)
		  {
			  (*rockIt)->kill();
		  }
		  for (int i = 0; i < INITIAL_ROCK_COUNT; i++)
		  {
			  Rock* pRock = new BigRock(getRandomPoint());
			  rocks.push_back(pRock);
		  }
		  pShip->giveLife();
		  pShip->setX(0);
		  pShip->setY(0);
		  pShip->setDx(0.0);
		  pShip->setDy(0.0);
		  pShip->setLives(3);
	  }

}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
	Point endGame(0, 0);
	Point reset(0, -15);
	Point life1(150,-180);
	Point life2(162,-180);
	Point life3(174,-180);

	if (pShip->getLives() >= 1)     // draw lives
	   drawShip(life1, 0, false);   //
	if (pShip->getLives() >= 2)     //
	   drawShip(life2, 0, false);   //
	if (pShip->getLives() >= 3)     //
	   drawShip(life3, 0, false);   //


   if (pShip->isAlive()) // draw ship
      pShip->draw();

   for (list<Bullet*>::iterator bulletIt = bullets.begin();
        bulletIt != bullets.end();
        bulletIt++)
   {
      (*bulletIt)->draw(); // draw bullets
   }

   for (list<Rock*>::iterator rockIt = rocks.begin();
        rockIt != rocks.end();
        rockIt++)
   {
      (*rockIt)->draw(); // draw rocks
   }

   if (!(pShip->isAlive()))
   {
      if (pShip->getLives() == 0)
	  {
	     drawText(endGame, "Game Over!"); // game over message
		 drawText(reset, "Push R to Retry");
	  }
	  else
	     drawText(reset, "Push R for Next Life!"); // next life message
   }
   else
   {
	   if (pShip->getLives() > 0 && rockCount == 0)
	   {
		   drawText(endGame, "VICTORY!!!!!!!"); // victory message // you will never achieve this.. but it works
		   drawText(reset, "Push R to Play Again!");
	   }
   }
}

/*********************************************
 * GAME :: checkForCollisions
 * Check for collisions between any two objects.
 *********************************************/
void Game::checkForCollisions()
{
   // go through each rock
   for (list<Rock*>::iterator rockIt = rocks.begin();
        rockIt != rocks.end();
        rockIt++)
   {
      // check for collision with the ship
      if (isCollision(*pShip, **rockIt))
      {
         pShip->kill();
         (*rockIt)->kill();
		       --rockCount;
         rockCount += (*rockIt)->breakApart(rocks);
      }

      // go through each bullet
      for (list<Bullet*>::iterator bulletIt = bullets.begin();
           bulletIt != bullets.end();
           bulletIt++)
      {
         // check for collision between this rock and this bullet
         if (isCollision(**bulletIt, **rockIt))
         {
            (*bulletIt)->kill();
            (*rockIt)->kill();
			--rockCount;
			rockCount += (*rockIt)->breakApart(rocks);
         }
      }
   }
}

/******************************************************
 * Function: isCollision
 * Description: Determine if two objects are colliding
 ******************************************************/
bool Game :: isCollision(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   bool collision = false;

   // we only collide if we're both alive
   if (obj1.isAlive() && obj2.isAlive())
   {
      float diff = getClosestDistance(obj1, obj2);
      float tooClose = obj1.getSize() + obj2.getSize();

      if (diff < tooClose)
      {
         // we have a hit!
         collision = true;
      }
   }

   return collision;
}

/**********************************************************
 * Function: getClosestDistance
 * Description: Determine how close these two objects will
 *   get in between the frames.
 **********************************************************/
float Game :: getClosestDistance(const FlyingObject &obj1, const FlyingObject &obj2) const
{
   // from Br. Helfrich:
   // find the maximum distance traveled
   float dMax = max(abs(obj1.getVelocity().getDx()), abs(obj1.getVelocity().getDy()));
   dMax = max(dMax, abs(obj2.getVelocity().getDx()));
   dMax = max(dMax, abs(obj2.getVelocity().getDy()));
   dMax = max(dMax, 0.1f); // when dx and dy are 0.0. Go through the loop once.

   // we will advance by this number
   float distMin = std::numeric_limits<float>::max();
   for (float i = 0.0; i <= dMax; i++)
   {
      Point point1(obj1.getPoint().getX() + (obj1.getVelocity().getDx() * i / dMax),
                     obj1.getPoint().getY() + (obj1.getVelocity().getDy() * i / dMax));
      Point point2(obj2.getPoint().getX() + (obj2.getVelocity().getDx() * i / dMax),
                     obj2.getPoint().getY() + (obj2.getVelocity().getDy() * i / dMax));

      float xDiff = point1.getX() - point2.getX();
      float yDiff = point1.getY() - point2.getY();

      float distSquared = (xDiff * xDiff) +(yDiff * yDiff);

      distMin = min(distMin, distSquared);
   }

   return sqrt(distMin);
}

/*********************************************
 * GAME :: cleanUpZombies()
 * Look for and remove any objects that are dead.
 *********************************************/
void Game::cleanUpZombies()
{
   // Look for dead bullets
   list<Bullet*>::iterator bulletIt = bullets.begin();
   while (bulletIt != bullets.end())
   {
      Bullet* pBullet = *bulletIt;

      if (!(pBullet->isAlive()))
      {
         // first deallocate
         delete pBullet;

         // now remove from list and advance
         bulletIt = bullets.erase(bulletIt);
      }
      else
      {
         bulletIt++; // advance
      }
   }

   // Look for dead rocks
   list<Rock*>::iterator rockIt = rocks.begin();
   while (rockIt != rocks.end())
   {
      Rock* pRock = *rockIt;

      if (!pRock->isAlive())
      {
         // first deallocate
         delete pRock;

         // now remove from list and advance
         rockIt = rocks.erase(rockIt);
      }
      else
      {
         rockIt++; // advance
      }
   }
}


/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface *pUI, void *p)
{
   Game *pGame = (Game *)p;

   pGame->advance();
   pGame->handleInput(*pUI);
   pGame->draw(*pUI);
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Point topLeft(-WINDOW_X_SIZE, WINDOW_Y_SIZE);
   Point bottomRight(WINDOW_X_SIZE, -WINDOW_Y_SIZE);

   Interface ui(argc, argv, "Asteroids", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);

   return 0;
}
