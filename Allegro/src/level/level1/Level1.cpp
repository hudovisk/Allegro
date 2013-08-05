/*
 * Level1.cpp
 *
 *  Created on: 03/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#include <iostream>

#include "level/level1/Level1.h"
#include "game/Game.h"

Level1::Level1(Input* i)
	: Level(i)
{
	map = new Map("teste.tmx");
	player = new Player(input,32,32,"resource/sprites/ct1.bmp");
	player->setPos(Point(100,100));
	backGroundSound = al_load_sample("resource/sounds/somjogo.ogg"); // é só mudar o caminho aqui pra mudar a musica
	if(!backGroundSound)
	{
		std::cout<<"Erro no som background"<<std::endl;
		return;
	}

	al_play_sample(backGroundSound, 1, 0, 1,  ALLEGRO_PLAYMODE_LOOP, 0);
}

Level1::~Level1()
{
	al_destroy_sample(backGroundSound);

	delete player;
	delete map;
}

void Level1::render()
{
	map->render();
	player->render(map->getXOffs(),map->getYOffs());
	for(int i=0; i < projectiles.getSize(); i++)
		projectiles.get(i)->render(map->getXOffs(), map->getYOffs());
}

void Level1::update()
{
	player->update();
	int xOffs = player->getPos().getX() - Game::getWidth()/2;
	int yOffs = player->getPos().getY() - Game::getHeight()/2;
	map->setOffs(xOffs,yOffs);
	for(int i=0; i < projectiles.getSize();)
	{
			projectiles.get(i)->update();
			if(projectiles.get(i)->isDone())
				projectiles.remove(i);
			else
				i++;
	}
}


