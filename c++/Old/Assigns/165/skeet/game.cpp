/****************************************
 * The game of Skeet
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "bullet.h"
#include "rifle.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include "bird.h"
#include "toughBird.h"
#include "sacredBird.h"
#include "normalBird.h"
#include "missle.h"


using namespace std;



/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
public:
   // create the game
	Game(Point tl, Point br) : topLeft(tl), bottomRight(br)
	{
	   numBullet = 0;
	   bullet[0] = new Bullet(200, -200);
	   clip = 30;
	   mClip = 0;
	   score = 0;
	   numBirds = 0;
	   numMissle = 0;
	   r = random(0, 8);
	   if (r >= 0 && r < 3)
		   bird = new NormalBird();
	   if (r >= 3 && r < 6)
		   bird = new ToughBird();
	   if (r >= 6 && r < 9)
		   bird = new SacredBird();
	   bird->setVelocity();
	   time = 50;
	   usedMissle = true;
	   
	   //missle[0] = new Missle(200, -200);
	}

   
   // handle user input
   void handleInput(const Interface & ui);

   // advance the game
   void advance();
         
   // draw stuff
   void draw(const Interface & ui);
   
private:
   Point topLeft;
   Point bottomRight;

   // TODO: add any objects or variables that are required
   Rifle rifle;
   Bullet *bullet[31];
   int numBullet;
   int clip;
   int mClip;
   Bird* bird;
   int numBirds;
   int numMissle;
   int score;
   int r;
   int time;
   Missle missle;
   bool usedMissle;

};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void birdAdvance(Bird * b)
{
	b->advance();
}

/******************************************
* this will detect any items that collide
********************************************/
bool collision(Point *p, Point *p2)
{
	if (p->getX() < p2->getX() + 10 && p->getX() > p2->getX() - 10
		&& p->getY() < p2->getY() + 10 && p->getY() > p2->getY() - 10)
		return true;
	else
		return false;
}

void Game :: advance()
{
	for (int i = 0; i < numBullet; i++)
	{
		if (bullet[i]->getShot() == true)
			bullet[i]->advance();

		if (bullet[i]->getX() < -200 || bullet[i]->getY() > 200)
		{
			bullet[i]->reset(200, -200);
			bullet[i]->kill();
		}

		if (collision(&bullet[i]->getLocation(), &bird->getLocation()))
		{
            bullet[i]->kill();
			score += bird->getScore();

			if (bird->getHp() - 1 <= 0)
			{
				bird->kill();
				
			}
			else
			{
				bird->subtractHp();
				bird->setScore();
			}
		}

	}

	if (bird->getAlive())
	   birdAdvance(bird);
	else //creates a new bird at random when one dies
	{
		r = random(0, 8);
		if (r >= 0 && r < 3)
		{
			bird = new NormalBird();
			numBirds++;
		}
		if (r >= 3 && r < 6)
		{
			bird = new ToughBird();
			numBirds++;
		}
		if (r >= 6 && r < 9)
		{
			bird = new SacredBird();
			numBirds++;
		}

		bird->setVelocity();
		
	}

	if (bird->getX() > 205 || bird->getY() > 205 || bird->getY() < -205) // kill bird if it leaves the screen
		bird->kill();
   
	if (mClip < 1 && usedMissle == true)
		if (numBirds % 10 == 0 && numBirds > 0)
		{
			mClip++;
			usedMissle = false;
		}

	if (missle.getShot())
		missle.advance(bird->getLocation(), bird->getScore());

	if (collision(&missle.getLocation(), &bird->getLocation())) // missle collision detection
	{
		missle.shoot(false);
		if (bird->getHp() > 1)
			score += 5;
		else
		   score += bird->getScore();
		
		numMissle = 0;
		missle.reset(200, -200);

		bird->kill();
		usedMissle = true;
		
	}

}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game::handleInput(const Interface & ui)
{
	// TODO: handle user input
	if (ui.isRight() && rifle.getAngle() > 0)
		rifle.rotateUp();

	if (ui.isLeft() && rifle.getAngle() < 90)
		rifle.rotateDown();

	if (ui.isSpace()) // shoot a bullet!!
	{
		bullet[numBullet] = new Bullet(200, -200);
		bullet[numBullet]->shoot(true);
		bullet[numBullet]->setVelocity(rifle.getAngle());

		if (clip != 0)
			clip--;

		if (numBullet + 1 > 30)
			numBullet = 30;
		else
			numBullet++;

	}
	
	if (ui.isUp()) // this is my reload function
	{		
		time--;
		if (time == 0)
		{
			numBullet = 0;
			clip = 30;
			time = 50;
		}
	}
	
	if (mClip == 1)
	   if (ui.isDown()) // shoot a missle!
	   {
		    numMissle++;
			missle.shoot(true);
			mClip--;
			
       }
}

/******************************
* drawBird will draw any kind
* of bird subclass passed to it
*******************************/
void drawBird(Bird * b)
{
	b->draw();
	
}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
	Point text(0, 180);
	Point text1(0, 160);
	Point text2(20, 155);
	Point ammoTxt(-195, -195);
	Point ammo(-150, -186);
	Point dScore(-190, 195);
	Point dNumBirds(180, 195);
	Point miss(-110, -195);

	
	// TODO: Draw the various elements of the game
	drawNumber(dScore, score);
	drawNumber(dNumBirds, numBirds);
	drawText(ammoTxt, "AMMO: ");
	drawNumber(ammo, clip);
	if (mClip == 1)
	   drawText(miss, "Press Down!!");
    
	drawBird(bird); // draw the birds
	
	rifle.draw(); // draw the gun

	if (missle.getShot())
		missle.draw();

	for (int i = 0; i < numBullet; i++) // draw each individual bullet
	{
		if (bullet[i]->getAlive())
			bullet[i]->draw();
	}
	if (numBullet == 30)
	   drawText(text, "Hold \"Up Arrow\" to Reload!"); // reload texts
	
	if (ui.isUp() && clip < 25)
	{
		drawText(text1, "Reloading!");
		drawNumber(text2, time);
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
   
   pGame->draw(*pUI);
   pGame->advance();
   pGame->handleInput(*pUI);
   
}


/*********************************
 * Main is pretty sparse.  Just initialize
 * the game and call the display engine.
 * That is all!
 *********************************/
int main(int argc, char ** argv)
{
   Point topLeft(-200, 200);
   Point bottomRight(200, -200);

   Interface ui(argc, argv, "Skeet", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}
