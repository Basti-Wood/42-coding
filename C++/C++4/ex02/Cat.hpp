#include "AAnimal.hpp"

#ifndef CAT_HPP
#define CAT_HPP

class Cat : public AAnimal
{
	private:
		Brain* brain; // Pointer to Brain object for Cat
	public:
		Cat();
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat();
		void makeSound() const; // Must implement this pure virtual function!
		void setIdea(int index, const std::string &idea);
		std::string getIdea(int index) const;
};

#endif