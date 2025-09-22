#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
	this->_type = type;
	return;
}

Weapon::Weapon()
{
	return;
}

Weapon::~Weapon()
{
	return;
}

void Weapon::setType(const std::string &type)
{
	this->_type = type;
	return;
}

std::string Weapon::getType() const
{
	return this->_type;
}