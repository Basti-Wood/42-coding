#include "ClapTrap.hpp"


//==========================Constructors and Destructor==========================
ClapTrap::ClapTrap(const std::string &name)
	: name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout <<YELLOW "ClapTrap " << name << " constructed." RESET<< std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other)
	: name(other.name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
	std::cout <<YELLOW "ClapTrap " << name << " copy constructed." RESET<< std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if (this != &other) {
		name = other.name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout <<YELLOW "ClapTrap " << name << " assigned." RESET<< std::endl;
	return *this;
}
ClapTrap::~ClapTrap() {
	std::cout <<RED "ClapTrap " << name << " destructed." RESET<< std::endl;
}


//==========================Functions==========================
void ClapTrap::attack(const std::string &target)
{
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout <<RED "ClapTrap " << name << " cannot attack, either out of hit points or energy." RESET<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout <<GREEN "ClapTrap " << name << " attacks " << target 
	          << ", causing " << _attackDamage << " points of damage!" RESET<< std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout <<RED "ClapTrap " << name << " has taken too much damage and is now destroyed!" RESET<< std::endl;
	} else {
		_hitPoints -= amount;
		std::cout <<YELLOW "ClapTrap " << name << " takes " << amount 
		          << " points of damage, remaining hit points: " << _hitPoints << RESET<< std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints == 0 || _hitPoints != 0) {
		std::cout <<RED "ClapTrap " << name << " cannot be repaired, out of energy or dead." RESET<< std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout <<GREEN "ClapTrap " << name << " repairs itself for " << amount 
	          << " points, new hit points: " << _hitPoints << RESET<< std::endl;
}