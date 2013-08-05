/*
 * Point.h
 *
 *  Created on: 24/07/2013
 *      Author: Hudo Cim Assenço
 */

#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
	Point() : x(0), y(0) { }
	Point(float xx, float yy) : x(xx), y(yy) { }

	float getX() { return x; }
	float getY() { return y; }
	void setX(float xx) { x = xx; }
	void setY(float yy) { y = yy; }

private:
	float x,y;
};


#endif /* POINT_H_ */
