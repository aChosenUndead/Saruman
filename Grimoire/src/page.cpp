/**
* @file page.cpp
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#include "page.h"
#include "monster.h"
#include <iostream>

Page::Page (Monster* monster) : monster(monster)
{
    this->next = NULL;
}

Monster* Page::getMonster ()
{
	return this->monster;
}

Page* Page::getNext()
{
    return this->next;
}

void Page::setNext(Page* page)
{
    this->next = page;
}
