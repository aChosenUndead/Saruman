/**
* @file monster.h
* @author Vinícius da Costa de Andrade <andradecostavinicius@gmail.com>
*/

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

class Monster {
	protected:
		std::string name;
		int health;
		int strength;
		int spirit;
		int vitality;
		int accuracy;
		char type;

	public:
		Monster(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type);
		std::string getName();
		int getHealth();
		int getStrength();
		int getSpirit();
		int getVitality();
		int getAccuracy();
		char getType();
		virtual int getSkill() = 0; // Abstract class; can't be instantiated
};

class Beast : public Monster {
	private:
		int fury;
	public:
		Beast(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type, int fury);
		int getSkill();
};

class Mage : public Monster {
	private:
		int magicPoint;
	public:
		Mage(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type, int magicPoint);
		int getSkill();
};

class Winged : public Monster {
	private:
		int agility;
	public:
		Winged(std::string name, int health, int strength, int spirit, int vitality, int accuracy, char type, int agility);
		int getSkill();
};

#endif
