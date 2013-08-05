/*
 * Input_Allegro.cpp
 *
 *  Created on: 24/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#include "input/inputAllegro/Input_Allegro.h"

Input_Allegro::~Input_Allegro()
{

}

Input_Allegro::Input_Allegro(ALLEGRO_EVENT* e)
{
	for(int i=0; i < 100; i++)
		keys[i] = false;

	mouseButton = 0;
	mousePos = Point(0,0);

	ev = e;
}

void Input_Allegro::update()
{
	if(ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		if(ev->mouse.button & 1)
			mouseButton = 1;
		else if (ev->mouse.button & 2)
			mouseButton = 2;
	}
	else if(ev->type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
		mouseButton = 0;
	}
	else if(ev->type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		mousePos = Point(ev->mouse.x,ev->mouse.y);
	}
	else if(ev->type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch(ev->keyboard.keycode)
		{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
		}
	}
	else if(ev->type == ALLEGRO_EVENT_KEY_UP)
	{
		switch(ev->keyboard.keycode)
		{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
		}
	}
}

int Input_Allegro::isMouseClicked()
{
	return mouseButton;
}

Point Input_Allegro::getMousePos()
{
	return mousePos;
}

bool Input_Allegro::isLeft()
{
	return keys[LEFT];
}

bool Input_Allegro::isRight()
{
	return keys[RIGHT];
}

bool Input_Allegro::isUp()
{
	return keys[UP];
}

bool Input_Allegro::isDown()
{
	return keys[DOWN];
}


