#include "Zombie.hpp"

Zombie* newZombie(std::string name) {

	Zombie *newZombie = new Zombie(name);
	if (!newZombie) {
		std::cerr << "Failed to create a new Zombie." << std::endl;
		return NULL;
	}
	newZombie->announce();
	return newZombie;
}