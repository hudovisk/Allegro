/*
 * Map.cpp
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#include "map/Map.h"
#include "rapidxml.hpp"
#include <stdio.h>
#include <allegro5/allegro5.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "game/Game.h"

using namespace rapidxml;

void getLayers(xml_node<>* root, List<Layer*>* layers);
void getMapInfo(xml_node<>* root, int* width, int* height, int* tileWidth, int* tileHeight);
void getTileset(xml_node<>* root, List<Tileset*>* tilesetList);

Map::Map(std::string filename)
{
	xml_document<> doc;
	std::ifstream file(filename.c_str());
	std::stringstream buffer;

	if(!file.is_open())
	{
		std::cout<<"Erro no arquivo do mapa: "<<filename<<std::endl;
		return;
	}

	buffer << file.rdbuf();
	file.close();

	std::string content(buffer.str());

	doc.parse<0>(&content[0]);
	xml_node<>* root = doc.first_node("map");

	getMapInfo(root,&width,&height,&tileWidth,&tileHeight);
	getTileset(root,&tilesets);
	getLayers(root,&layers);

	xOffs = 0;
	yOffs = 0;
}

void Map::render()
{

	int w = Game::getWidth();
	int h = Game::getHeight();

	for(int i=0; i < layers.getSize(); i++)
	{
		Layer* layer = layers.get(i);
		if(!layer->isVisible())
			continue;
		for(int y=0; y < (h/tileHeight) + 1; y++)
		{
			int yy = y + yOffs/tileHeight;
			if(yy > layer->getHeight() - 1)
				break;
			for(int x=0; x < (w/tileWidth) + 1; x++)
			{
				int xx = x + xOffs/tileWidth;
				if(xx > layer->getWidth() - 1)
					break;
				int id = layer->getTilesId()[xx+(yy*layer->getWidth())];
				if(id!=0)
					drawTile(id,x,y);
			}
		}
	}
}

void Map::drawTile(int id,int x, int y)
{
	for(int k=0; k < tilesets.getSize(); k++)
	{
		Tileset* tileset = tilesets.get(k);
		if(id <= tileset->getLasttId() && id >= tileset->getFirstId())
		{
			id -= tileset->getFirstId();
			int tw = tileset->getTileWidth();
			int th = tileset->getTileHeight();
			int imw = al_get_bitmap_width(tileset->getImage());

			//tile
			int sx = id*tw % imw;
			int sy = id/(imw/tw)*th;

			al_draw_bitmap_region(tileset->getImage(),sx,sy,tileWidth,tileHeight,(x*tileWidth) - (xOffs%tileWidth),(y*tileHeight) - (yOffs%tileHeight),0);
		}
	}
}


bool Map::isSolidAt(int x, int y)
{
	for(int i=0; i < layers.getSize(); i++)
	{
		Layer* layer = layers.get(i);
		if(layer->getName().compare("collision") == 0)
		{
			int xx = x/tileWidth;
			int yy = y/tileHeight;
			if(xx < 0 || yy < 0 || xx > layer->getWidth() || yy > layer->getHeight())
				return true;
			int id = layer->getTilesId()[x/tileWidth + (y/tileHeight * layer->getWidth())];
			if(id)
			{
				return true;
			}
		}
	}
	return false;
}

void Map::setOffs(int x, int y)
{
	if(x>=0 && x < width*tileWidth - Game::getWidth())
		xOffs = x;
	if(y>=0 && y < height*tileHeight - Game::getHeight())
		yOffs = y;
}


void getLayers(xml_node<>* root, List<Layer*>* layers)
{
	xml_node<> *layerNode = root->first_node("layer");
	while(layerNode)
	{
		xml_attribute<>* atr = layerNode->first_attribute("name");
		std::string name(atr->value());

		atr = layerNode->first_attribute("width");
		int width = atoi(atr->value());

		atr = layerNode->first_attribute("height");
		int height = atoi(atr->value());

		atr = layerNode->first_attribute("visible");
		bool visible = true;
		if(atr)
			visible = false;

		int* tilesId = new int[width*height];
		int i=0;

		xml_node<>* tileNode = layerNode->first_node("data")->first_node("tile");
		while(tileNode)
		{
			atr = tileNode->first_attribute("gid");
			tilesId[i] = atoi(atr->value());
			i++;

			tileNode = tileNode->next_sibling("tile");
		}

		layers->add(new Layer(width,height,name,visible,tilesId));

		layerNode = layerNode->next_sibling("layer");
	}
}

void getMapInfo(xml_node<>* root, int* width, int* height, int* tileWidth, int* tileHeight)
{
	xml_attribute<>* atr = root->first_attribute("tilewidth");
	*tileWidth = atoi(atr->value());

	atr = root->first_attribute("tileheight");
	*tileHeight = atoi(atr->value());

	atr = root->first_attribute("width");
	*width = atoi(atr->value());

	atr = root->first_attribute("height");
	*height = atoi(atr->value());
}

void getTileset(xml_node<>* root, List<Tileset*>* tilesetList)
{
	xml_node<> *tilesetNode = root->first_node("tileset");
	while(tilesetNode)
	{
		xml_attribute<>* atr = tilesetNode->first_attribute("firstgid");
		int firstGid = atoi(atr->value());
		atr = root->first_attribute("tilewidth");
		int tileWidth = atoi(atr->value());
		atr = root->first_attribute("tileheight");
		int tileHeight = atoi(atr->value());

		xml_node<>* image = tilesetNode->first_node("image");
		atr = image->first_attribute("source");
		std::string imageSource(atr->value());
		atr = image->first_attribute("trans");

		int r = 0,g = 0,b = 0;

		sscanf(atr->value(), "%2x",&r);
		sscanf(atr->value() + 2, "%2x",&g);
		sscanf(atr->value() + 4, "%2x",&b);

		ALLEGRO_BITMAP* im = al_load_bitmap(imageSource.c_str());
		if(!im)
		{
			std::cout<<"Erro no tileset: "<<imageSource<<std::endl;
			return;
		}
		al_convert_mask_to_alpha(im,al_map_rgb(r,g,b));

		tilesetList->add(new Tileset(firstGid,tileWidth,tileHeight,im));

		tilesetNode = tilesetNode->next_sibling("tileset");
	}
}
