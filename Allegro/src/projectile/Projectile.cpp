/*
 * Projectile.cpp
 *
 *  Created on: 04/08/2013
 *      Author: Hudo Cim Assen�o
 *      Author: Felipe Ukan Pereira
 */

#include "projectile/Projectile.h"
#include "game/Game.h"
#include <iostream>
#include <cmath>

Projectile::Projectile(std::string filename, float r, float s, float dmg)
	: range(r), speed(s), damage(dmg), angle(0), done(false), distance(0)
{
	sprite = al_load_bitmap(filename.c_str());
	if(!sprite)
	{
		std::cout<<"Erro no sprite de bullet: "<<filename<<std::endl;
		return;
	}

	al_convert_mask_to_alpha(sprite,al_map_rgb(255,0,255));

	bounds = Rect(Point(0,0),al_get_bitmap_width(sprite), al_get_bitmap_height(sprite));
}

void Projectile::render(int xOffs, int yOffs)
{
	al_draw_rotated_bitmap(sprite,bounds.getWidth()/2,bounds.getHeight()/2,bounds.getOrigin().getX() - xOffs,bounds.getOrigin().getY() - yOffs,angle,0);
}


void Projectile::update()
{
	distance += speed;
	if(distance > range)
	{
		done = true;
		return;
	}
	bounds.setOrigin(Point(bounds.getOrigin().getX() + speed*sin(angle),bounds.getOrigin().getY() + speed*-cos(angle)));
	if(Game::getCurrentLevel()->getMap()->isSolidAt(bounds.getOrigin().getX(),bounds.getOrigin().getY()))
	{
		done = true;
	}
}


