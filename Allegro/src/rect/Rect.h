/*
 * Rectangle.h
 *
 *  Created on: 04/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Point.h"

class Rect
{
public:
	Rect() : origin(Point(0,0)), width(0), height(0) { }
	Rect(Point o, int w, int h) : origin(o), width(w), height(h) { }
	~Rect() { }

	int getWidth() { return width; }
	int getHeight() { return height; }
	Point getOrigin() { return origin; }

	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	void setOrigin(Point o) { origin = o; }

private:
	Point origin;
	int width;
	int height;
};


#endif /* RECTANGLE_H_ */
