#ifndef VELOCITY_H
#define VELOCITY_H

// Defines what velocity is.
class Velocity
{
private:
	float dx;
	float dy;

public:
	Velocity();
	Velocity(float dx, float dy);

	//Getters and Setters
	float getDx() { return dx; }
	float getDy() { return dy; }

	void setDx(float dx);
	void setDy(float dy);

	Velocity add(Velocity v);
	void addOnto(Velocity v);
};
#endif
