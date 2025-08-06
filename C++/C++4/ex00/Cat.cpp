#include "Cat.hpp"

//============ConStructors & Destructor============//
Cat::Cat() : Animal("Cat") {
	std::cout << MAGENTA << "Cat default constructor called" << RESET << std::endl;
	return;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << MAGENTA << "Cat copy constructor called" << RESET << std::endl;
	return;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << MAGENTA << "Cat assignment operator called" << RESET << std::endl;
	}
	return *this;
}

//============Member Functions============//
void Cat::makeSound() const {
	std::cout << MAGENTA << "Meow!" << RESET << std::endl;
}
