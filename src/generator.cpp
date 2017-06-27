/**
 * @file
 * Generator library functions "generator.cpp"
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "generator.h"
#include "monster.h"

SarumanGrimoire::SarumanGrimoire()
{
	//Weak
	monsterList.push_back(new Mage  (  "Frodo", 190, 110, 40, 40, 50, 'm', 1));
	monsterList.push_back(new Mage  ("Samwise", 210, 120, 50, 50, 50, 'm', 1));
	monsterList.push_back(new Beast ("Boromir", 600, 130, 40, 30, 30, 'b', 1));
	monsterList.push_back(new Beast ("Smeagol", 400, 190, 50, 40, 30, 'b', 1));
	monsterList.push_back(new Winged(  "Merry", 290,  90, 30, 50, 70, 'w', 1));
	monsterList.push_back(new Winged( "Pippin", 250,  90, 20, 50, 70, 'w', 1));

	//Average
	monsterList.push_back(new Mage  ("Aragorn", 210, 150, 50, 50, 50, 'm', 1));
	monsterList.push_back(new Beast (  "Gimli", 400, 200, 50, 40, 30, 'b', 1));
	monsterList.push_back(new Winged("Legolas", 250, 100, 20, 50, 70, 'w', 1));

	//Strong
	monsterList.push_back(new Mage("Gandalf", 220, 250, 60, 60, 50, 'm', 1));
}


Monster* SarumanGrimoire::getRandomMonster()
{
    srand(time(0));
    int limit = 1 + (rand() % 10);
    std::list<Monster*>::iterator it;
    it = monsterList.begin();
    it = std::next(it, limit-1);
    return *it;
}
