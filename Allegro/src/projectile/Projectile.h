/*
 * Projectile.h
 *
 *  Created on: 26/07/2013
 *      Author: Hudo Cim Assenço
 */

#ifndef PROJECTILE_H_
#define PROJECTILE_H_

#include "rect/Rect.h"
#include "Vector.h"
#include <string>
#include <allegro5/allegro5.h>

class Projectile
{

public:
	Projectile(std::string filename, float r, float s, float dmg);
	Projectile() : bounds(Rect(Point(0,0),0,0)), direction(Vector(0,0)), range(0), speed(0), damage(0), angle(0), done(false), distance(0), sprite(NULL) { }

	bool isDone() { return done; }
	float getAngle() { return angle; }
	float getRange() { return range; }
	float getSpeed() { return speed; }
	Point getOrigin() { return bounds.getOrigin(); }
	Rect getBounds() { return bounds; }
	Vector getDirection() { return direction; }

	void setRange(float r) { range = r; }
	void setSpeed(float s) { speed = s; }
	void setBounds(Rect b) { bounds = b; }
	void setOrigin(Point o) { bounds.setOrigin(o); }
	void setDirection(Vector d) { direction = d; }
	void setAngle(float a) { angle = a; }

	void render(int xOffs, int yoffs);
	void update();

private:
	Rect bounds;
	Vector direction;
	float range;
	float speed;
	float damage;
	float angle;
	bool done;
	float distance;

	ALLEGRO_BITMAP* sprite;
};

#endif /* PROJECTILE_H_ */
