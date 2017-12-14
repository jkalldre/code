#ifndef VELOCITY_H
#define VELOCITY_H

class Velocity
{
private:
   float dx;
   float dy;

public:
   /**************************
    * Getters and Setters
    **************************/
   float getDx() const { return dx; }
   float getDy() const { return dy; }

   void setDx(float dx) { this->dx = dx; }
   void setDy(float dy) { this->dy = dy; }

   /**************************
    * Public member functions
    **************************/
   void prompt();
   void display() const;
   friend void operator -=(Velocity & lhs, const Velocity & rhs);
   friend Velocity operator -(const Velocity & lhs, const Velocity & rhs);
};

void operator +=(Velocity & lhs, const Velocity & rhs);
Velocity operator +(const Velocity & lhs, const Velocity & rhs);
bool operator ==(const Velocity & lhs, const Velocity & rhs);
bool operator !=(const Velocity & lhs, const Velocity & rhs);
bool operator >(const Velocity & lhs, const Velocity & rhs);
bool operator <(const Velocity & lhs, const Velocity & rhs);
bool operator >=(const Velocity & lhs, const Velocity & rhs);
bool operator <=(const Velocity & lhs, const Velocity & rhs);



#endif
