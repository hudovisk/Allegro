/*
 * Ak47.h
 *
 *  Created on: 02/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef AK47_H_
#define AK47_H_

#include "weapon/Weapon.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_audio.h>

class Ak47 : public Weapon
{
public:
	Ak47();
	~Ak47();

	bool shoot(Projectile* p);
	void reload();

private:
	float lastShoot;
	float lastReload;
	ALLEGRO_SAMPLE* aShootSound;
	ALLEGRO_SAMPLE* aReloadSound;
};


#endif /* AK47_H_ */
