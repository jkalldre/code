#ifndef POINT_H
#define POINT_H

class Point
{
private:
   int x;
   int y;

public:
   Point();
   Point(int inputX, int inputY);
   void display() const;
   int getX() const
   {
      return x;
   }
   int getY() const
   {
      return y;
   }
   void setX(int xInput)
   {
      if (xInput < 1)
         x = 1;
      else if (xInput > 10)
         x = 10;
      else
         x = xInput;
   }
   void setY(int yInput)
   {
      if (yInput < 1)
         y = 1;
      else if (yInput > 10)
         y = 10;
      else
         y = yInput;
   }

};

#endif
