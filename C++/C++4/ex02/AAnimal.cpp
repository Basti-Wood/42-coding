#include "AAnimal.hpp"

//============ConStructors & Destructor============//
AAnimal::AAnimal(){
	std::cout << GREEN << "AAnimal default constructor called" << RESET << std::endl;
	return;
}

AAnimal::AAnimal(const std::string &type) : type(type) {
	std::cout << GREEN << "AAnimal parameterized constructor called with type: " << type << RESET << std::endl;
	return;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
	std::cout << GREEN << "AAnimal copy constructor called" << RESET << std::endl;
	return;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << GREEN << "AAnimal assignment operator called" << RESET << std::endl;
	}
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
	return;
}

//============Member Functions============//
// Note: NO makeSound() implementation! It's pure virtual.

std::string AAnimal::getType() const {
	return type;
}