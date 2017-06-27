/**
* @file monster.cpp
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#include <iostream>
#include <fstream>
#include <string>
#include "monster.h"
#include "grimoire.h"
#include "page.h"

Grimoire::Grimoire()
{
    first = NULL;
    this->quantity = 0;
}

Monster* Grimoire::get(int i)
{
    Page* current = first;
    int counter = 1;
    while(current != NULL && counter < i)
    {
        current = current->getNext();
        counter++;
    }

    return current->getMonster();
}

void Grimoire::InsertMonster(Monster* monster)
{
    if(this->quantity == 0)
    {
        first = new Page(monster);
    }
    else
    {
        Page* current = first;
        while(current->getNext() != NULL)
        {
            current = current->getNext();
        }
        current->setNext(new Page (monster));
    }
    this->quantity++;
}

void Grimoire::RemoveMonster(Monster* monster)
{
    if (this->quantity == 0){}
    else {
        Page* current = first;
        if(current->getMonster() == monster){
            Page* prev = first;
            first = first->getNext();
            delete prev;
        }

        else {
            while(current->getNext() != NULL && (current->getNext()->getMonster()) != monster)
            {
                current = current->getNext();
            }
            current->setNext(current->getNext()->getNext());
            delete current->getNext();
            }
        this->quantity--;
    }

}

bool Grimoire::isEmpty()
{
	return this->getQuantity() == 0;
}

int Grimoire::getQuantity()
{
	return this->quantity;
}
