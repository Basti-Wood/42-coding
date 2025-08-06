#include "Animal.hpp"


#ifndef DOG_HPP
#define DOG_HPP

class Dog : public Animal
{
	private:
		Brain* brain;
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();
		void makeSound() const;
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};


#endif
