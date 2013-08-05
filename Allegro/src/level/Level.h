/*
 * Level.h
 *
 *  Created on: 03/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "map/Map.h"
#include "player/Player.h"
#include "input/Input.h"
#include "projectile/Projectile.h"
#include "List.h"

class Level
{
public:
	Level(Input* i) : input(i) { }
	virtual ~Level() { };
	virtual void render() = 0;
	virtual void update() = 0;

	Map* getMap() { return map; }
	Player* getPlayer() { return player; }
	List<Projectile*>* getProjectiles() { return &projectiles; }

protected:
	Map* map;
	Player* player;
	Input* input;
	List<Projectile*> projectiles;
};


#endif /* LEVEL_H_ */
