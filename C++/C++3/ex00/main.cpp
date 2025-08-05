#include "ClapTrap.hpp"

int main() {
	ClapTrap ctA("John");
	ClapTrap ctB("Doe");
	ClapTrap ctC(ctA);
	ClapTrap ctD("Test");
	ctD = ctB;

	ctA.attack("Doe");
	ctB.takeDamage(5);
	ctC.beRepaired(3);
	ctD.attack("John");
	ctA.takeDamage(10);
	ctA.beRepaired(5);

	for (int i = 0; i < 5; ++i) {
		ctA.takeDamage(1);
		ctB.takeDamage(1);
		ctC.takeDamage(1);
		ctD.takeDamage(1);
	}
	return 0;
}