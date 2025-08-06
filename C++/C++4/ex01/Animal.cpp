#include "Animal.hpp"
//============ConStructors & Destructor============//
Animal::Animal(){
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
	return;
}
Animal::Animal(const std::string &type) : type(type) {
	std::cout << GREEN << "Animal parameterized constructor called with type: " << type << RESET << std::endl;
	return;
}
Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
	return;
}
Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << GREEN << "Animal assignment operator called" << RESET << std::endl;
	}
	return *this;
}
Animal::~Animal() {
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
	return;
}


//============Member Functions============//

void Animal::makeSound() const {
	std::cout << YELLOW << "Animal makes an appropriate sound" << RESET << std::endl;
}
std::string Animal::getType() const {
	return type;
}