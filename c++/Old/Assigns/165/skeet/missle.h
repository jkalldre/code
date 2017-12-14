#ifndef MISSLE_H
#define MISSLE_H
#include "bullet.h"

class Missle : public Bullet
{
   private:
	   int rotate;

   public:
	   Missle();
	   Missle(int x, int y);
	   virtual void draw();
	   virtual void advance(Point p, int i);
};

#endif