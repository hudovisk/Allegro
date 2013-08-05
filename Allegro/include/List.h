/*
 * List.h
 *
 *  Created on: 27/07/2013
 *      Author: Hudo Cim Assenço
 */

#ifndef LIST_H_
#define LIST_H_

#include "ListElement.h"

template<class T>
class List
{
public:
	List() : size(0), first(0), last(0) { }

	void add(T iten)
	{
		ListElement<T>* aux = new ListElement<T>();
		aux->element = iten;
		if(size==0)
		{
			first=aux;
			last=aux;
		}
		else
		{
			aux->previous = last;
			last->next = aux;
			last = aux;
		}
		size++;
	}

	T get(int i)
	{
		if(i<=size/2)
		{
			ListElement<T>* iten = first;
			for(int aux=0; aux < i; aux++)
			{
				iten = iten->next;
			}
			return iten->element;
		}
		else
		{
			ListElement<T>* iten = last;
			for(int aux=size-1; aux > i; aux--)
			{
				iten = iten->previous;
			}
			return iten->element;
		}
	}


	void remove(int i)
	{
		ListElement<T>* iten;

		if(i==0)
		{
			iten = first;
			first = iten->next;
			if(size>1)
				first->previous = 0;
		}
		else if(i==size-1)
		{
			iten = last;
			last = iten->previous;
			last->next = 0;
		}
		else
		{
			if(i<=size/2)
			{
				iten = first;
				for(int aux=0; aux < i; aux++)
				{
					iten = iten->next;
				}
			}
			else
			{
				iten = last;
				for(int aux=size-1; aux > i; aux--)
				{
					iten = iten->previous;
				}
			}

			iten->previous->next = iten->next;
			iten->next->previous = iten->previous;
		}
		delete iten;
		size--;
	}

	int getSize() { return size; }

private:
	int size;
	ListElement<T>* first;
	ListElement<T>* last;
};



#endif /* LIST_H_ */
