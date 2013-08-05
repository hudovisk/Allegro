/*
 * Input.h
 *
 *  Created on: 24/07/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef INPUT_H_
#define INPUT_H_

#include "Point.h"

class Input
{
public:
	virtual ~Input() { }

	virtual int isMouseClicked() = 0;
	virtual Point getMousePos() = 0;

	virtual bool isLeft() = 0;
	virtual bool isRight() = 0;
	virtual bool isUp() = 0;
	virtual bool isDown() = 0;

	virtual void update() = 0;

	/*Futuramente:
	virtual bool isPaused() = 0;
	*/
protected:
	Input() { }
};


#endif /* INPUT_H_ */
