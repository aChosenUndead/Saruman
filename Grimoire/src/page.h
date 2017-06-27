/**
* @file page.h
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#ifndef PAGE_H
#define PAGE_H

#include "monster.h"

class Page {
	private:
		Monster* monster;
		Page* next;
	public:
		Page (Monster* monster);
		Monster* getMonster ();
		Page* getNext();
		void setNext(Page* page);
};

#endif
