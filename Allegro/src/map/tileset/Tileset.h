/*
 * Tileset.h
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef TILESET_H_
#define TILESET_H_

#include <allegro5/allegro5.h>
#include <string>

class Tileset
{
public:
	Tileset(int first, int tw, int th, ALLEGRO_BITMAP* im);

	int getFirstId() { return firstId; }
	int getLasttId() { return lastId; }
	int getTileWidth() { return tileWidth; }
	int getTileHeight() { return tileHeight; }

	ALLEGRO_BITMAP* getImage() { return image; }
private:
	int firstId;
	int lastId;

	int tileWidth;
	int tileHeight;

	ALLEGRO_BITMAP* image;
};


#endif /* TILESET_H_ */
