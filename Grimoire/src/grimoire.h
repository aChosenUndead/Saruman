/**
* @file grimoire.h
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#ifndef GRIMOIRE_H
#define GRIMOIRE_H

#include <fstream>
#include "page.h"

class Grimoire {
	private:
		Page* first;
		int quantity;
	public:
		Grimoire ();
		Monster* get(int i);
		void InsertMonster(Monster* monster);
		void RemoveMonster(Monster* Monster);
		bool isEmpty();
		int getQuantity();
};

#endif
