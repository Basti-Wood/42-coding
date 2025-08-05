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

	ctD.whoAmI();

	return 0;
}