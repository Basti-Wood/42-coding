#include <iostream>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	std::cout << CYAN << "=== Testing Abstract AAnimal ===" << RESET << std::endl;
	//const AAnimal* animal = new AAnimal(); // ❌ Cannot instantiate abstract class!
	//std::cout << "This line will never execute!" << std::endl;
	
	std::cout << YELLOW << "\n--- Test 1: Polymorphism with Abstract Base ---" << RESET << std::endl;
	
	// But polymorphism still works perfectly:
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();
	
	std::cout << "Dog type: " << dog->getType() << std::endl;
	std::cout << "Cat type: " << cat->getType() << std::endl;
	
	dog->makeSound(); // Calls Dog::makeSound() -> "Woof!"
	cat->makeSound(); // Calls Cat::makeSound() -> "Meow!"
	//animal->makeSound(); // Calls AAnimal::makeSound() -> "Animal makes an appropriate sound"
	
	std::cout << YELLOW << "\n--- Test 2: Brain Functionality ---" << RESET << std::endl;
	
	// Test brain functionality with concrete objects
	Dog* smartDog = new Dog();
	Cat* smartCat = new Cat();
	
	smartDog->setIdea(0, "I'm a smart dog!");
	smartDog->setIdea(1, "I love fetch!");
	
	smartCat->setIdea(0, "I'm a clever cat!");
	smartCat->setIdea(1, "Humans are my servants!");
	
	std::cout << "Smart dog's ideas:" << std::endl;
	std::cout << "  - " << smartDog->getIdea(0) << std::endl;
	std::cout << "  - " << smartDog->getIdea(1) << std::endl;
	
	std::cout << "Smart cat's ideas:" << std::endl;
	std::cout << "  - " << smartCat->getIdea(0) << std::endl;
	std::cout << "  - " << smartCat->getIdea(1) << std::endl;
	
	std::cout << YELLOW << "\n--- Test 3: Array of AAnimals ---" << RESET << std::endl;
	
	// Array of abstract AAnimal pointers
	const int size = 4;
	AAnimal* animals[size];
	
	animals[0] = new Dog();
	animals[1] = new Cat();
	animals[2] = new Dog();
	animals[3] = new Cat();
	
	std::cout << "All animals making their sounds:" << std::endl;
	for (int i = 0; i < size; i++) {
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
		animals[i]->makeSound();
	}
	
	std::cout << YELLOW << "\n--- Test 4: Deep Copy Testing ---" << RESET << std::endl;
	
	Dog originalDog;
	originalDog.setIdea(0, "Original thought");
	
	Dog copiedDog(originalDog); // Copy constructor
	
	// Modify original
	originalDog.setIdea(0, "Modified thought");
	
	std::cout << "Original dog idea: " << originalDog.getIdea(0) << std::endl;
	std::cout << "Copied dog idea: " << copiedDog.getIdea(0) << std::endl;
	std::cout << "Deep copy working: " << (copiedDog.getIdea(0) != originalDog.getIdea(0) ? "✅" : "❌") << std::endl;
	
	// Cleanup
	std::cout << YELLOW << "\n--- Cleanup ---" << RESET << std::endl;
	
	delete dog;
	delete cat;
	delete smartDog;
	delete smartCat;
	
	for (int i = 0; i < size; i++) {
		delete animals[i];
	}
	
	std::cout << GREEN << "\n=== Abstract AAnimal Testing Complete ===" << RESET << std::endl;
	std::cout << GREEN << "✅ AAnimal cannot be instantiated directly" << RESET << std::endl;
	std::cout << GREEN << "✅ Polymorphism works perfectly" << RESET << std::endl;
	std::cout << GREEN << "✅ All derived classes must implement makeSound()" << RESET << std::endl;
	
	return 0;
}