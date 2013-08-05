/*
 * Layer.h
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef LAYER_H_
#define LAYER_H_

#include <string>


class Layer
{
public:
	Layer(int w, int h, std::string n, bool v, int* tiles)
		: name(n), width(w), height(h), visible(v), tilesId(tiles) { }

	std::string getName() { return name; }

	int getWidth() { return width; }
	int getHeight() { return height; }
	int* getTilesId() { return tilesId; }

	bool isVisible() { return visible; }

private:
	std::string name;
	int width;
	int height;
	bool visible;
	int* tilesId;
};



#endif /* LAYER_H_ */
