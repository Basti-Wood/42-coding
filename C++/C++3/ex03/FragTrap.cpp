#include "FragTrap.hpp"

//==========================Constructors and Destructor==========================
FragTrap::FragTrap(const std::string &name)
	: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout <<MAGENTA "FragTrap " << name << " constructed." RESET<< std::endl;
}

FragTrap::FragTrap(const FragTrap &other)
	: ClapTrap(other.name) {
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout <<MAGENTA "FragTrap " << name << " copy constructed." RESET<< std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	if (this != &other) {
		name = other.name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout <<MAGENTA "FragTrap " << name << " assigned." RESET<< std::endl;
	return *this;
}
FragTrap::~FragTrap() {
	std::cout <<RED "FragTrap " << name << " destructed." RESET<< std::endl;
}
//==========================Functions==========================
void FragTrap::attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout <<RED "FragTrap " << name << " cannot attack, either out of hit points or energy." RESET<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout <<MAGENTA "FragTrap " << name << " Oblitorates " << target 
	          << "! causing " << _attackDamage << " points of damage!" RESET<< std::endl;
}
void FragTrap::highFivesGuys() {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout <<RED "FragTrap " << name << " cannot high five, either out of hit points or energy." RESET<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout <<MAGENTA "FragTrap " << name << " requests a high five!" RESET<< std::endl;
}