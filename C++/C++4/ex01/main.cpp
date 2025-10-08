#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Animal* dog1 = new Dog();
	Animal* cat1 = new Cat();

	static_cast<Dog*>(dog1)->setIdea(0, "Chase the cat");
	static_cast<Cat*>(cat1)->setIdea(0, "Climb the tree");
	std::cout << "Dog's idea: " << static_cast<Dog*>(dog1)->getIdea(0) << std::endl;
	std::cout << "Cat's idea: " << static_cast<Cat*>(cat1)->getIdea(0) << std::endl;

	Animal *animalArray[4];
	for (int i = 0; i < 4; ++i) {
		if (i < 2) {
			animalArray[i] = new Dog();
		} else {
			animalArray[i] = new Cat();
		}
	}
	Dog* dog2 = new Dog(*static_cast<Dog*>(dog1));
	Cat* cat2 = new Cat(*static_cast<Cat*>(cat1));
	static_cast<Dog*>(dog1)->setIdea(0, "Play fetch");
	static_cast<Cat*>(cat1)->setIdea(0, "Sleep on the couch");
	std::cout << "Dog1's idea: " << static_cast<Dog*>(dog1)->getIdea(0) << std::endl;
	std::cout << "Dog2's idea: " << dog2->getIdea(0) << std::endl;
	std::cout << "Cat1's idea: " << static_cast<Cat*>(cat1)->getIdea(0) << std::endl;
	std::cout << "Cat2's idea: " << cat2->getIdea(0) << std::endl;

	for (int i = 0; i < 4; ++i) {
		animalArray[i]->makeSound();
	}

	delete dog1;
	delete cat1;
	delete dog2;
	delete cat2;
	for (int i = 0; i < 4; ++i) {
		delete animalArray[i];
	}
	return 0;
}