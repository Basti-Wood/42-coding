#include "wrong_cat.hpp"

//============ConStructors & Destructor============//
wrong_cat::wrong_cat() : wrong_animal("Cat") {
	std::cout << MAGENTA << "Cat default constructor called" << RESET << std::endl;
	return;
}

wrong_cat::wrong_cat(const wrong_cat &other) : wrong_animal(other) {
	std::cout << MAGENTA << "Cat copy constructor called" << RESET << std::endl;
	return;
}

wrong_cat &wrong_cat::operator=(const wrong_cat &other) {
	if (this != &other) {
		wrong_animal::operator=(other);
		std::cout << MAGENTA << "Cat assignment operator called" << RESET << std::endl;
	}
	return *this;
}
//============Member Functions============//
void wrong_cat::makeSound() const {
	std::cout << MAGENTA << "wrong Meow!" << RESET << std::endl;
}
