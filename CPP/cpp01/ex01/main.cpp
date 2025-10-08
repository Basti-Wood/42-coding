#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );
Zombie *zombieHorde( int N, std::string name );

int main() {
	int hordeSize = 5;
	Zombie* horde = zombieHorde(hordeSize, "HordeZombie");
	if (horde) {
		std::cout << "\n=== ZOMBIE HORDE ANNOUNCES ===" << std::endl;
		for (int i = 0; i < hordeSize; ++i) {
			horde[i].announce();
		}
		std::cout << "\n=== DESTROYING HORDE ===" << std::endl;
		delete[] horde;
	}
	return 0;
}