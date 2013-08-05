/*
 * Weapon.h
 *
 *  Created on: 02/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Point.h"
#include "projectile/Projectile.h"
#include <allegro5/allegro5.h>

class Weapon
{
public:
	Weapon() : rateOfFire(0), reloadTime(0), magazineSize(0), bullets(0), totalBulletes(0), width(0), height(0), bullet(Projectile()), sprite(NULL) { }
	Weapon(float rateFire, float reloadT, int magSize, int b, int totalB) : rateOfFire(rateFire), reloadTime(reloadT), magazineSize(magSize), bullets(b),totalBulletes(totalB), width(0), height(0),bullet(Projectile()), sprite(NULL) { }
	virtual ~Weapon() { };

	virtual bool shoot(Projectile* p) = 0;
	virtual void reload() = 0;
	int getWidth() { return width; }
	int getHeight() { return height; }

	ALLEGRO_BITMAP* getSprite() { return sprite; }
protected:
	float rateOfFire;
	float reloadTime;
	int magazineSize;
	int bullets;
	int totalBulletes;
	int width;
	int height;
	Projectile bullet;

	ALLEGRO_BITMAP* sprite;
};


#endif /* WEAPON_H_ */
