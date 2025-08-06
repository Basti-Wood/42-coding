#include "dog.hpp"

//============ConStructors & Destructor============//
Dog::Dog() : Animal("Dog") {
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
	return;
}	
Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
	return;
}
Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << BLUE << "Dog assignment operator called" << RESET << std::endl;
	}
	return *this;
}
//============Member Functions============//
void Dog::makeSound() const {
	std::cout << BLUE << "Woof!" << RESET << std::endl;
}