#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
	DiamondTrap ctA("John");
	DiamondTrap ctB("Doe");
	DiamondTrap ctC(ctA);
	DiamondTrap ctD("Test");
	ctD = ctB;

	ctA.guardGate();
	ctB.highFivesGuys();
	ctD.whoAmI();
	
	ctA.takeDamage(1);
	ctB.attack("You");
	
	

	return 0;
}
