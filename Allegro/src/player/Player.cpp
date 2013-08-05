/*
 * Player.cpp
 *
 *  Created on: 24/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#include <cmath>
#include <iostream>

#include "player/Player.h"
#include "game/Game.h"
#include "weapon/ak47/Ak47.h"
#include "Vector.h"


Player::~Player()
{
	al_destroy_bitmap(currentSprite);
	al_destroy_bitmap(spriteSheet);
	delete weapon;
}

Player::Player(Input* i, int w, int h, char* filename)
	: input(i), angleDirection(0), width(w), height(h),speed(2), weapon(NULL)
{
	spriteSheet = al_load_bitmap(filename);
	if(!spriteSheet)
	{
		std::cout<<"Erro no bitmap de player"<<std::endl;
		return;
	}
	al_convert_mask_to_alpha(spriteSheet,al_map_rgb(255,0,255));

	currentSprite = al_create_sub_bitmap(spriteSheet,width,height,width,height);

    weapon = new Ak47();
}

bool Player::collision(float x, float y)
{
	if(Game::getCurrentLevel()->getMap()->isSolidAt(x,y))
		return true;
	if(Game::getCurrentLevel()->getMap()->isSolidAt(x+width/2-1,y))
		return true;
	if(Game::getCurrentLevel()->getMap()->isSolidAt(x,y+height/2-1))
		return true;
	if(Game::getCurrentLevel()->getMap()->isSolidAt(x+width/2-1,y+height/2-1))
		return true;
	return false;
}

//Logica do movimento
void Player::update()
{
	Point mousePos = input->getMousePos();
	Vector mouseVector(mousePos.getX() - pos.getX() + Game::getCurrentLevel()->getMap()->getXOffs(), mousePos.getY() - pos.getY() + Game::getCurrentLevel()->getMap()->getYOffs());
	mouseVector = mouseVector.getNormalized();

	angleDirection =  atan2(mouseVector.getY(),mouseVector.getX()) - atan2(-1,0);

	if(input->isLeft())
	{
		if(!collision(pos.getX() - speed,pos.getY()))
		{
			pos.setX(pos.getX() - speed);
		}
	}
	else if(input->isRight())
	{
		if(!collision(pos.getX() + speed,pos.getY()))
		{
			pos.setX(pos.getX() + speed);
		}
	}

	if(input->isUp())
	{
		if(!collision(pos.getX(),pos.getY() - speed))
		{
			pos.setY(pos.getY() - speed);
		}
	}
	else if(input->isDown())
	{
		if(!collision(pos.getX(),pos.getY() + speed))
		{
			pos.setY(pos.getY() + speed);
		}
	}

	if(input->isMouseClicked() == 1 )
	{
		Projectile* p = new Projectile();
		if(weapon->shoot(p))
		{
			int xx = pos.getX() + 20*sin(angleDirection);
			int yy = pos.getY() + 20*-cos(angleDirection);
			p->setOrigin(Point(xx,yy));
			p->setAngle(angleDirection);
			std::cout<<"Angle: "<<angleDirection<<std::endl;
			Game::getCurrentLevel()->getProjectiles()->add(p);
		}
	}


}

void Player::render(int xOffs, int yOffs)
{
	al_draw_rotated_bitmap(currentSprite,width/2.0,height/2.0,pos.getX() - xOffs,pos.getY() - yOffs, angleDirection, 0);
	al_draw_rotated_bitmap(weapon->getSprite(), weapon->getWidth()/2.0, weapon->getHeight()/2.0 + 20, pos.getX() - xOffs,pos.getY() - yOffs, angleDirection, 0);
}

void Player::setPos(float x, float y)
{
	pos.setX(x);
	pos.setY(y);
}

