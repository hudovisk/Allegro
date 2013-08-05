/*
 * Level1.h
 *
 *  Created on: 03/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef LEVEL1_H_
#define LEVEL1_H_

#include "level/Level.h"
#include <allegro5/allegro_audio.h>

class Level1 : public Level
{
public:
	Level1(Input* i);
	~Level1();

	void render();
	void update();
private:
	ALLEGRO_SAMPLE* backGroundSound;
};


#endif /* LEVEL1_H_ */
