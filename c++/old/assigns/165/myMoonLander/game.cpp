/****************************************
 * The game of moonlander
 ****************************************/

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "ground.h"
#include "lander.h"
#include "velocity.h"


#define FUEL        500    // initial fuel for the game
#define MIN_SPEED   3.0    // minimal landing speed
#define FALL_HEIGHT 4.0    // greatest height we can fall from

/*****************************************
 * GAME
 * The main game class containing all the state
 *****************************************/
class Game
{
   public:
      // create the game
      Game(Point tl, Point br) : topLeft(tl), bottomRight(br),
       ground(Ground(topLeft, bottomRight)),       gravity(0.0, -0.1) {  }

      // handle user input
      void handleInput(const Interface & ui);

      // advance the game
      void advance();
         
      // draw stuff
      void draw(const Interface & ui);
   
   private:

      Point topLeft;
      Point bottomRight;
      Ground ground;
  
   // TODO: add any objects or variables that are required
      Lander lander;
   
      Velocity gravity;
};

/***************************************
 * GAME :: ADVANCE
 * advance the game one unit of time
 ***************************************/
void Game::advance()
{
   // TODO: move lander and check for crashed
   // will apply these effects to every frame until lander crashes 
   if (!ground.crashed(lander.getPoint()) && !lander.getLanded())    
   {                      
      lander.applyGravity(gravity);
      lander.advance();
      lander.setVelocity(lander.getVelocity());
      lander.hasLanded(ground.getPlatformPosition(),
       ground.getPlatformWidth());
      lander.setPoint();   
   }
}

/***************************************
 * GAME :: input
 * accept input from the user
 ***************************************/
void Game :: handleInput(const Interface & ui)
{
   // TODO: handle user input
   if (!ground.crashed(lander.getPoint()) || !lander.getLanded())
   {
      if (ui.isLeft()) // detects left thrust & consumes fuel
      {
         if ((lander.getFuel() - 1) > 0)
         {
            lander.applyThrustLeft();
            lander.consumeFuel(1);
         }
      }

      if (ui.isRight()) // detects right thrust & consumes fuel
      {
         if ((lander.getFuel() - 1) > 0)
         {
            lander.applyThrustRight();
            lander.consumeFuel(1);
         }
      }

      if (ui.isDown()) // detects downward thrust & consumes fuel
      {
         if ((lander.getFuel() - 3) > 0)
         {
            lander.applyThrustBottom();
            lander.consumeFuel(3);
         }
         else
            lander.setFuel(0);
      }
   }
   else
   {
      // sets lander velocity to 0 and stops gravity.
      lander.endGameConditions(0.0, 0.0); 
   }

}

/*********************************************
 * GAME :: DRAW
 * Draw everything on the screen
 *********************************************/
void Game :: draw(const Interface & ui)
{
   char crash[30] = "You Have Crashed!";
   char* pCrash = crash;
   char land[30] = "You Have Landed!";
   char* pLand = land;
   char restart[40] = "Push \"space\" to try Again!";
   char* pRestart = restart;
   Point text(-150, 100);
   Point text2(-20, 150);

   // TODO: draw the lander or a status message
   if (ground.crashed(lander.getPoint()))
   { 
      drawText(text, pCrash);
      drawText(text2, pRestart);
      lander.setFuel(0);
      if (ui.isSpace())
      {
         ground.draw();
         lander.restartGame();
      }
   }
   else if (lander.getLanded())  // prints you have landed
   {
      drawText(text, pLand);
      drawLander(lander.getPoint());
   }
   else // continues drawing flames and ship until endgame conditions are met
   {
      if (lander.getFuel() > 0)
         drawLanderFlames(lander.getPoint(),
          ui.isDown(), ui.isLeft(), ui.isRight());
      
      drawLander(lander.getPoint());   
   }                                   
   
   // TODO: draw the fuel
   drawNumber(topLeft, lander.getFuel());
   // draw ground
   ground.draw();
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
   Point topLeft(-200, 200);
   Point bottomRight(200, -200);
   
   Interface ui(argc, argv, "Moon Lander", topLeft, bottomRight);
   Game game(topLeft, bottomRight);
   ui.run(callBack, &game);
   
   return 0;
}
