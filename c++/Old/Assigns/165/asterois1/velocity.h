#ifndef VELOCITY_H
#define VELOCITY_H


// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity
{
private:
	float dx;
	float dy;
public:
	float getDx() const { return dx; }
	float getDy() const { return dy; }
	void setDx(float f) { dx = f; }
	void setDy(float f) { dy = f; }
	void addDx(float f) { setDx(getDx() + f); }
	void addDy(float f) { setDy(getDy() + f); }
};

#endif /* velocity_h */
