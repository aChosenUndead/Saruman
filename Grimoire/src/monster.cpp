/**
* @file monster.cpp
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#include "monster.h"

Monster::Monster(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type)
{

	/**
	* @brief Creates a monster
    * @param name Monster's name
    * @param health Monster's health
    * @param strength Monster's strength
    * @param spirit Monster's spirit
    * @param vitality Monster's vitality
    * @param accuracy Monster's accuracy
    * @param type Monster's type
    */
	this->name = name;
	this->health = health;
	this->strength = strength;
	this->spirit = spirit;
	this->vitality = vitality;
	this->accuracy = accuracy;
	this->type = type;
}

std::string Monster::getName()
{
    /**
	* @brief Returns monster's name
	*/
    return this->name;
}

int Monster::getHealth()
{
	/**
	* @brief Returns monster's health
	*/
	return this->health;
}

int Monster::getStrength()
{
	/**
	* @brief Returns monster's strength
	*/
	return this->strength;
}

int Monster::getSpirit()
{
	/**
	* @brief Returns monster's spirit
	*/
	return this->spirit;
}

int Monster::getVitality()
{
	/**
	* @brief Returns monster's vitality
	*/
	return this->vitality;
}

int Monster::getAccuracy()
{
    /**
	* @brief Returns monster's accuracy
	*/
    return this->accuracy;
}

char Monster::getType()
{
    /**
	* @brief Returns monster's type
	*/
    return this->type;
}

Beast::Beast(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type, int fury) : Monster (name, health, strength, spirit, vitality, accuracy, type)
{
	this->fury = fury;
}

Mage::Mage(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type, int magicPoint) : Monster (name, health, strength, spirit, vitality, accuracy, type)
{
	this->magicPoint = magicPoint;
}

Winged::Winged(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type, int agility) : Monster (name, health, strength, spirit, vitality, accuracy, type)
{
	this->agility = agility;
}

int Beast::getSkill()
{
    return this->fury;
}

int Mage::getSkill()
{
    return this->magicPoint;
}

int Winged::getSkill()
{
    return this->agility;
}
