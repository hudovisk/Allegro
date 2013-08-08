/*
 * HudLevel1.h
 *
 *  Created on: 07/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef HUDLEVEL1_H_
#define HUDLEVEL1_H_

#include "hud/Hud.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>

class HudLevel1 : public Hud
{
public:
	void render();
	void update();
private:

};


#endif /* HUDLEVEL1_H_ */
