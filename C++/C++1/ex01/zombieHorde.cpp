#include "Zombie.hpp"
#include <sstream>
#include <string>

Zombie	*newZombie( std::string name );
void	randomChump( std::string name );

Zombie* zombieHorde( int N, std::string name )
{
	std::stringstream ss;
	if (N <= 0) {
		std::cerr << "Invalid number of zombies: " << N << std::endl;
		return NULL;
	}
	Zombie* horde = new Zombie[N];
	if (!horde) {
		std::cerr << "Failed to create a zombie horde." << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; ++i) {
		ss.str("");
		ss << i + 1;
		horde[i].setName(name + "-" + ss.str());
	}
	return horde;
}