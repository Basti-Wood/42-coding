#include "Animal.hpp"


#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog &operator=(const Dog &other);
	void makeSound() const;
};


#endif
