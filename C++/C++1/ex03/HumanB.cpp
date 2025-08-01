#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
	return;
}

HumanB::~HumanB()
{
	return;
}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack() const
{
	if (_weapon == NULL)  // Check if pointer is NULL
	{
		std::cout << _name << " has no weapon to attack with." << std::endl;
	}
	else
	{
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
		// Use -> to access method through pointer, and don't use & to get address
	}
}