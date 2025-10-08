#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

int main() {
	Zombie* zombie1 = newZombie("Zombie1");
	if (zombie1) {
		delete zombie1;
	}

	randomChump("ChumpZombie");

	return 0;
}