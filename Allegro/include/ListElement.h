/*
 * ListElement.h
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 */

#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

template <class T>
class ListElement
{
public:
	ListElement() : next(0), previous(0) { }
	ListElement* next;
	ListElement* previous;
	T element;
};


#endif /* LISTELEMENT_H_ */
