/*
 * Vector.h
 *
 *  Created on: 04/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <cmath>

class Vector
{
public:
	Vector(float xx, float yy) : x(xx), y(yy) { }
	Vector() : x(0), y(0) { }
	float getX() { return x; }
	float getY() { return y; }
	float getMagnitude() {	return sqrt(x*x + y*y);}
	float dotProdut(Vector v) { return x*v.getX() + y*v.getY(); }
	Vector getInverse() { return Vector(-x,-y);}
	Vector getNormalized()
	{
		float mag = getMagnitude();
		return Vector(x/mag,y/mag);
	}
private:
	float x;
	float y;
};


#endif /* VECTOR_H_ */
