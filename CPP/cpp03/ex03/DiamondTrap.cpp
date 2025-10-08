#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

//==========================Constructors and Destructor==========================
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), ScavTrap(name + "_scav_name"), FragTrap(name + "_frag_name"), name(name) {
	ClapTrap::_hitPoints = FragTrap::_hitPoints;
	ClapTrap::_energyPoints = ScavTrap::_energyPoints;
	ClapTrap::_attackDamage = FragTrap::_attackDamage;
	std::cout <<CYAN "DiamondTrap " << name << " constructed." RESET<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other.name), ScavTrap(other.name), FragTrap(other.name), name(other.name) {
	ClapTrap::_hitPoints = other.FragTrap::_hitPoints;
	ClapTrap::_energyPoints = other.ScavTrap::_energyPoints;
	ClapTrap::_attackDamage = other.FragTrap::_attackDamage;
	std::cout <<CYAN "DiamondTrap " << name << " copy constructed." RESET<< std::endl;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		ClapTrap::name = other.ClapTrap::name;
		ClapTrap::_hitPoints = other._hitPoints;
		ClapTrap::_energyPoints = other._energyPoints;
		ClapTrap::_attackDamage = other._attackDamage;
		name = other.name;
	}
	std::cout <<CYAN "DiamondTrap " << name << " assigned." RESET<< std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout <<RED "DiamondTrap " << name << " destructed." RESET<< std::endl;
}

//==========================Functions==========================
void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
void DiamondTrap::whoAmI() const {
	std::cout <<CYAN "I am " << name 
	          << " The DiamondTrap. Descendant of the all mighty " << ClapTrap::name << RESET<< std::endl;
}
