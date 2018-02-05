#ifndef VELOCITY_H
#define VELOCITY_H


/**********************************************
* Holds velocity.
**********************************************/
class Velocity
{
private:
	float dx;
	float dy;

public:
	Velocity();
	Velocity(float dx, float dy);

	float getDx() { return dx; }
	float getDy() { return dy; }

	void setDx(float dx);
	void setDy(float dy);

	Velocity add(Velocity v);
	void addOnto(Velocity v);
};
#endif
