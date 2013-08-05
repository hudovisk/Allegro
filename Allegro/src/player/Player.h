/*
 * Player.h
 *
 *  Created on: 24/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "input/Input.h"
#include "weapon/Weapon.h"
#include "rect/Rect.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

class Player
{
public:
	Player(Input* i, int w, int h, char* filename);
	~Player();
	void update();
	void render(int xOffs, int yOffs);

	Point getPos() { return pos; }
	void setPos(Point p) { pos = p; }
	void setPos(float x, float y);

	int getWidth() { return width; }

	void setWeapon(Weapon* w) { weapon = w; }
	Weapon* getWeapon() { return weapon; }

private:
	bool collision(float x, float y);
	void shoot();

	//Não sei se isso realmente funciona, mas é para nao criar um player sem input!
	//Nunca deve ser chamado!
	Player() : input(0), angleDirection(0), pos(Point(0,0)), width(0), height(0), speed(0), weapon(NULL), spriteSheet(NULL), currentSprite(NULL) { }
	Input* input;

	//Para a rotação
	float angleDirection;
	//Class Rectangle!!
	Point pos;
	int width;
	int height;
	float speed;
	Weapon* weapon;

	ALLEGRO_BITMAP* spriteSheet;
	ALLEGRO_BITMAP* currentSprite;
};


#endif /* PLAYER_H_ */
