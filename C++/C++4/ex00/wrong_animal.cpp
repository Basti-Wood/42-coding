#include "wrong_animal.hpp"
//============ConStructors & Destructor============//
wrong_animal::wrong_animal(){
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
	return;
}
wrong_animal::wrong_animal(const std::string &type) : type(type) {
	std::cout << GREEN << "Animal parameterized constructor called with type: " << type << RESET << std::endl;
	return;
}
wrong_animal::wrong_animal(const wrong_animal &other) : type(other.type) {
	std::cout << GREEN << "Animal copy constructor called" << RESET << std::endl;
	return;
}
wrong_animal &wrong_animal::operator=(const wrong_animal &other) {
	if (this != &other) {
		type = other.type;
		std::cout << GREEN << "Animal assignment operator called" << RESET << std::endl;
	}
	return *this;
}
wrong_animal::~wrong_animal() {
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
	return;
}


//============Member Functions============//

void wrong_animal::makeSound() const {
	std::cout << CYAN << "WRONG ANIMAL SOUND WEEEUUU WEEEUUUU!!!!!!" << RESET << std::endl;
}
std::string wrong_animal::getType() const {
	return type;
}