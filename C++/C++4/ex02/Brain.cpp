#include "Brain.hpp"

//============Constructors & Destructor============//
Brain::Brain() {
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = "Empty Idea";
	}
	return;
}
Brain::Brain(const Brain &other) {
	std::cout << GREEN << "Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; ++i) {
		ideas[i] = other.ideas[i];
	}
	return;
}
Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		std::cout << GREEN << "Brain assignment operator called" << RESET << std::endl;
		for (int i = 0; i < 100; ++i) {
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}
Brain::~Brain() {
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
	return;
}
//============Member Functions============//
void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		ideas[index] = idea;
	} else {
		std::cerr << RED << "Index out of bounds!" << RESET << std::endl;
	}
}

std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return ideas[index];
	} else {
		std::cerr << RED << "Index out of bounds!" << RESET << std::endl;
		return "Invalid Index";
	}
}