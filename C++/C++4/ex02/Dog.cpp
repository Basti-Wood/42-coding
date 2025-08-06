#include "Dog.hpp"

//============ConStructors & Destructor============//
Dog::Dog() : AAnimal("Dog") {
	std::cout << BLUE << "Dog default constructor called" << RESET << std::endl;
	brain = new Brain(); // Initialize the Brain object
	return;
}	
Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << BLUE << "Dog copy constructor called" << RESET << std::endl;
	brain = new Brain(*(other.brain)); // Deep copy the Brain object
	return;
}
Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		AAnimal::operator=(other);
		delete brain; // Clean up existing brain
		brain = new Brain(*(other.brain)); // Deep copy the new brain
		std::cout << BLUE << "Dog assignment operator called" << RESET << std::endl;
	}
	return *this;
}
Dog::~Dog() {
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
	delete brain; // Clean up the Brain object
	return;
}
//============Member Functions============//
void Dog::makeSound() const {
	std::cout << BLUE << "Woof!" << RESET << std::endl;
}

void Dog::setIdea(int index, const std::string &idea) {
	brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const {
	return brain->getIdea(index);
}