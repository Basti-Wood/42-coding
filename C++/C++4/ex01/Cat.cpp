#include "Cat.hpp"

//============ConStructors & Destructor============//
Cat::Cat() : Animal("Cat") {
	std::cout << MAGENTA << "Cat default constructor called" << RESET << std::endl;
	brain = new Brain(); // Initialize the Brain object
	return;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << MAGENTA << "Cat copy constructor called" << RESET << std::endl;
	brain = new Brain(*(other.brain)); // Deep copy the Brain object
	return;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		delete brain; // Clean up existing brain
		brain = new Brain(*(other.brain)); // Deep copy the new brain
		std::cout << MAGENTA << "Cat assignment operator called" << RESET << std::endl;
	}
	return *this;
}
Cat::~Cat() {
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
	delete brain; // Clean up the Brain object
	return;
}

//============Member Functions============//
void Cat::makeSound() const {
	std::cout << MAGENTA << "Meow!" << RESET << std::endl;
}

void Cat::setIdea(int index, const std::string &idea) {
	brain->setIdea(index, idea);
}
std::string Cat::getIdea(int index) const {
	return brain->getIdea(index);
}
