#include "Zombie.hpp"

std::string Zombie::_GetName() const {
	return _name;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "A New Zombie " << _GetName() << " created." << std::endl;
	return;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << " destroyed." << std::endl;
	return;
}

void Zombie::announce() const {
	std::cout << _GetName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}