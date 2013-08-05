/*
 * Map.h
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef MAP_H_
#define MAP_H_

#include "List.h"
#include "map/tileset/Tileset.h"
#include "map/layer/Layer.h"
#include "TileProperties.h"
#include <string>

class Map
{
public:
	Map(std::string filename);

	void render();
	void setOffs(int x, int y);

	int getXOffs() { return xOffs; }
	int getYOffs() { return yOffs; }

	int getWidth() { return width; }
	int getHeight() { return height; }

	int getTileWidth() { return tileWidth; }
	int getTileHeight() { return tileHeight; }

	bool isSolidAt(int x, int y);

private:

	void drawTile(int id, int x, int y);

	List<Layer*> layers;
	List<Tileset*> tilesets;

	int width;
	int height;

	int tileWidth;
	int tileHeight;

	int xOffs;
	int yOffs;
};


#endif /* MAP_H_ */
