/*
 * Ak47.cpp
 *
 *  Created on: 02/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#include "weapon/ak47/Ak47.h"
#include <allegro5/allegro_image.h>

#include <iostream>

Ak47::Ak47()
	: Weapon(10,1.2,30,30,90)
{
	lastReload = 0;
	lastShoot = 0;

	bullet = Projectile("resource/sprites/bullet1.bmp", 350,18,10);

	sprite = al_load_bitmap("resource/weapons/ak47.bmp");
	if(!sprite)
	{
		std::cout<<"Erro no sprite da Ak47"<<std::endl;
		return;
	}

	width = al_get_bitmap_width(sprite);
	height = al_get_bitmap_height(sprite);

	al_convert_mask_to_alpha(sprite,al_map_rgb(255,0,255));

	aShootSound = al_load_sample("resource/sounds/ak47.wav");
	if(!aShootSound)
	{
		std::cout<<"Erro no audio de shoot"<<std::endl;
		return;
	}

	aReloadSound = al_load_sample("resource/sounds/reload.wav");
	if(!aReloadSound)
	{
		std::cout<<"Erro no audio reload"<<std::endl;
		return;
	}


}

Ak47::~Ak47()
{
	al_destroy_bitmap(sprite);
	al_destroy_sample(aShootSound);
}

void Ak47::reload()
{
	if(bullets == magazineSize)
		return;
	if(totalBulletes - (magazineSize - bullets) < 0)
		return;

	if(al_get_time() - lastReload < reloadTime)
		return;

	//tocar som de reload
	al_play_sample(aReloadSound, 0.7, 0, 1,  ALLEGRO_PLAYMODE_ONCE, 0);

	totalBulletes -= magazineSize - bullets;
	bullets = magazineSize;

	lastReload = al_get_time();
}

bool Ak47::shoot(Projectile* p)
{
	if(al_get_time() - lastShoot < 1/rateOfFire && lastShoot)
		return false;

	if(al_get_time() - lastReload < reloadTime && lastReload)
		return false;

	if(bullets == 0 )
	{
		reload();
		return false;
	}

	*p = bullet;

	bullets--;
	al_play_sample(aShootSound, 0.7, 0, 1,  ALLEGRO_PLAYMODE_ONCE, 0);

	lastShoot = al_get_time();

	return true;
}


