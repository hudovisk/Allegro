/*
 * Game.h
 *
 *  Created on: 26/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef GAME_H_
#define GAME_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>


#include "input/Input.h"
#include "level/Level.h"

class Game
{
public:
	~Game();
	Game();
	Game(int w, int h, float fp);

	static int getWidth() { return width; }
	static int getHeight() { return height; }

	static Level* getCurrentLevel() { return currentLevel; }
private:
	bool initGraphics();
	bool initSound();
	void mainLoop();
	void update();
	void render();

	static int width;
	static int height;

	float fps;

	bool running;

	Input* input;
	static Level* currentLevel;


	ALLEGRO_BITMAP* buffer;
	ALLEGRO_DISPLAY* display;
};


#endif /* GAME_H_ */
