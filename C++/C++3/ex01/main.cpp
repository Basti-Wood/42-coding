#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ClapTrap ctA("John");
	ScavTrap ctB("Doe");
	ClapTrap ctC(ctA);
	ScavTrap ctD("Test");
	ctD = ctB;

	ctA.attack("Doe");
	ctB.takeDamage(5);
	ctC.beRepaired(3);
	ctD.attack("John");
	std::cout<< CYAN "-------------------------ABOUT TO DEFEND---------------------------------" RESET << std::endl;
	ctB.guardGate();
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