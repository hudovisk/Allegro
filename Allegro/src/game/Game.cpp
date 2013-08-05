/*
 * Game.cpp
 *
 *  Created on: 26/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */


#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <iostream>

#include "game/Game.h"
#include "input/inputAllegro/Input_Allegro.h"
#include "level/level1/Level1.h"



int Game::height = 0;
int Game::width = 0;
Level* Game::currentLevel = 0;

Game::Game(int w, int h, float fp)
	: fps(fp), running(false), input(0), buffer(0), display(0)
{
	width = w;
	height = h;

	if(initGraphics())
	{
		initSound();
		mainLoop();
	}
}

Game::Game()
	: fps(60.0), running(false), input(0), buffer(0), display(0)
{
	width = 640;
	height = 480;

	if(initGraphics())
	{
		initSound();
		mainLoop();
	}
}

Game::~Game()
{
	al_destroy_bitmap(buffer);
	al_destroy_display(display);

	delete input;
}

bool Game::initGraphics()
{

	if(!al_init())	//initialize Allegro
	{
		std::cout<<"Erro na inicialização allegro!"<<std::endl;
		return false;
	}

	al_init_image_addon();

	display = al_create_display(width,height);
	if(!display)
	{
		std::cout<<"Erro na criação do display!"<<std::endl;
		return false;
	}

	buffer = al_create_bitmap(width,height);
	if(!buffer)
	{
		std::cout<<"Erro na criação do buffer!"<<std::endl;
		return false;
	}

	return true;
}

bool Game::initSound()
{
	al_install_audio();
	al_init_acodec_addon();

	al_reserve_samples(30);

	return true;
}

void Game::mainLoop()
{
	ALLEGRO_EVENT ev;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;

	al_install_mouse();
	al_install_keyboard();


	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / fps);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));


	al_start_timer(timer);

	input = new Input_Allegro(&ev);

	currentLevel = new Level1(input);

	running = true;


	while(running)
	{
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_TIMER)
		{
			update();
		}
		else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			running = false;
		}
		else
		{
			input->update();
		}

		render();
	}

	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
}


void Game::update()
{
	currentLevel->update();
}

void Game::render()
{
	al_set_target_bitmap(buffer);
	al_clear_to_color(al_map_rgb(0,0,0));

	currentLevel->render();

	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap_region(buffer,0,0,width,height,0,0,0);

	al_flip_display();
}

