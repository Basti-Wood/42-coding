#include "ClapTrap.hpp"

int main() {
	ClapTrap ctA("Attack");
	ClapTrap ctB("Defend");
	ClapTrap ctC(ctA);
	ClapTrap ctD("Test");
	ClapTrap ctE("PLEASE HELP ME I DONT WANT TO DIE!!!!");
	ctE = ctD;

	ctA.attack("Doe");
	ctB.takeDamage(5);
	ctC.beRepaired(3);
	ctD.attack("John");
	ctA.takeDamage(10);
	ctA.beRepaired(5);
	ctE.attack("You");

	for (int i = 0; i < 20; ++i)
	{
		ctC.attack("Defend");
		ctB.takeDamage(1);
		if (i % 4 == 0)
			ctB.beRepaired(5);
	}
	
	
	return 0;
}
