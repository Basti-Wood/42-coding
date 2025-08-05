#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
//==========================Constructors and Destructor==========================
ScavTrap::ScavTrap() : ClapTrap("Default") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout <<BLUE "ScavTrap Default constructed." RESET<< std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
	: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout <<BLUE "ScavTrap " << name << " constructed." RESET<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
	: ClapTrap(other.name) {
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout <<BLUE "ScavTrap " << name << " copy constructed." RESET<< std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if (this != &other) {
		name = other.name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout <<BLUE "ScavTrap " << name << " assigned." RESET<< std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout <<RED "ScavTrap " << name << " destructed." RESET<< std::endl;
}

//==========================Functions==========================
void ScavTrap::attack(const std::string &target) {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout <<RED "ScavTrap " << name << " cannot attack, either out of hit points or energy." RESET<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout <<GREEN "ScavTrap " << name << " Charges up for an attack against " << target 
	          << ", causing " << _attackDamage << " points of damage!" RESET<< std::endl;
}
void ScavTrap::guardGate() {
	if (_hitPoints == 0 || _energyPoints == 0) {
		std::cout <<RED "ScavTrap " << name << " cannot guard, either out of hit points or energy." RESET<< std::endl;
		return;
	}
	std::cout <<YELLOW "ScavTrap " << name << " is now guarding the gate!" RESET<< std::endl;
}