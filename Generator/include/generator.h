/**
 * @file
 * Generator library headers "generator.h"
 */
#ifndef GENERATOR_H
#define GENERATOR_H
#include <list>
#include "monster.h"
/**
 * @brief      Class for representing the Saruman's Grimoire
 */
class SarumanGrimoire
{
private:
	/** @brief The list of Saruman's monsters */
    std::list<Monster*> monsterList;
public:
	/**
	 * @brief      Constructor
	 */
    SarumanGrimoire();
    /**
     * @brief      Gets a random monster
     *
     * @return     Random monster
     */
    Monster* getRandomMonster();

};
#endif
