#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	ScavTrap stA("Attack");
	ScavTrap stB("Defend");
	ScavTrap stC(stA);
	ScavTrap stD("Test");
	ScavTrap stE("PLEASE HELP ME I DONT WANT TO DIE!!!!");
	stE = stD;

	stA.attack("Doe");
	stB.takeDamage(5);
	stC.beRepaired(3);
	stD.attack("John");
	stA.takeDamage(10);
	stA.beRepaired(5);
	stE.attack("You");
	std::cout << "===================================" << std::endl;
	stA.guardGate();

	for (int i = 0; i < 20; ++i)
	{
		stC.attack("Defend");
		stB.takeDamage(1);
		if (i % 4 == 0)
			stB.beRepaired(5);
	}
	
	
	return 0;
}
