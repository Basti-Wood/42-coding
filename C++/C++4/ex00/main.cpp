#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "wrong_animal.hpp"
#include "wrong_cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* l = new Cat();
	const wrong_animal* i = new wrong_cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << l->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound(); //will output the no sound!
	j->makeSound();
	l->makeSound();
	meta->makeSound();


	delete meta;
	delete j;
	delete l;
    delete i;
	return 0;
}
