/*
 * Input_Allegro.h
 *
 *  Created on: 24/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef INPUT_ALLEGRO_H_
#define INPUT_ALLEGRO_H_

#include "input/Input.h"
#include <allegro5\allegro.h>

class Input_Allegro : public Input
{
public:

	Input_Allegro(ALLEGRO_EVENT* e); // Baita de uma gambiarra!! não consegui fazer a parada de thread, vai assim mesmo. pelo menos funciona!!
	~Input_Allegro();

	int isMouseClicked();
	Point getMousePos();

	bool isLeft();
	bool isRight();
	bool isUp();
	bool isDown();

	/*Futuramente:
	bool isPaused();
	*/

	void update();
private:

	enum KeysId
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN
	};

	bool keys[100];
	int mouseButton;
	Point mousePos;
	ALLEGRO_EVENT* ev;

};


#endif /* INPUT_ALLEGRO_H_ */
