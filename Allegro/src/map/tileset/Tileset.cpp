/*
 * Tileset.cpp
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#include "map/tileset/Tileset.h"

#include <iostream>

Tileset::Tileset(int first, int tw, int th, ALLEGRO_BITMAP* im)
	: firstId(first), tileWidth(tw), tileHeight(th), image(im)
{

	int width = al_get_bitmap_width(image);
	int height = al_get_bitmap_height(image);

	lastId = width/tileWidth * height/tileHeight + firstId - 1;
}


