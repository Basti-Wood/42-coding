#include "AAnimal.hpp"

#ifndef DOG_HPP
#define DOG_HPP

class Dog : public AAnimal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const; // Must implement this pure virtual function!
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif