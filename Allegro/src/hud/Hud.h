/*
 * Hud.h
 *
 *  Created on: 07/08/2013
 *      Author: Hudo Cim Assenço
 *      Author: Felipe Ukan Pereira
 */

#ifndef HUD_H_
#define HUD_H_


class Hud
{
public:
	virtual ~Hud() { }
	virtual void render() = 0;
	virtual void update() = 0;
};

#endif /* HUD_H_ */
