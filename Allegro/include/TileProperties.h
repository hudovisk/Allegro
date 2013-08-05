/*
 * Tile.h
 *
 *  Created on: 01/08/2013
 *      Author: Hudo
 */

#ifndef TILE_H_
#define TILE_H_

#include <map>

class TileProperties
{
private:
	int id;
	std::map<std::string, std::string> properties;
};


#endif /* TILE_H_ */
