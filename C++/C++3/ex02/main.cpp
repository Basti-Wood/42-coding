#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	FragTrap ctA("John");
	FragTrap ctB("Doe");
	FragTrap ctC(ctA);
	FragTrap ctD("Test");
	ctD = ctB;

	ctA.attack("Doe");
	ctB.takeDamage(5);
	ctC.beRepaired(3);
	ctD.attack("John");
	ctB.highFivesGuys();
	ctA.takeDamage(10);
	ctA.beRepaired(5);

	for (int i = 0; i < 10; ++i) {
		ctA.takeDamage(10);
		ctB.takeDamage(10);
		ctC.takeDamage(10);
		ctD.takeDamage(10);
	}
	return 0;
}