#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    std::cout << CYAN << "=== Testing Brain Functionality ===" << RESET << std::endl;
    
    // Test 1: Create animals and test brain functionality
    std::cout << YELLOW << "\n--- Test 1: Basic Brain Operations ---" << RESET << std::endl;
    
    Dog* dog1 = new Dog();
    Cat* cat1 = new Cat();
    
    // Set some ideas for the dog
    dog1->setIdea(0, "Chase the mailman");
    dog1->setIdea(1, "Fetch the ball");
    dog1->setIdea(2, "Bark at squirrels");
    
    // Set some ideas for the cat
    cat1->setIdea(0, "Sleep all day");
    cat1->setIdea(1, "Knock things off tables");
    cat1->setIdea(2, "Ignore humans");
    
    // Display ideas
    std::cout << "Dog's ideas:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "  Idea " << i << ": " << dog1->getIdea(i) << std::endl;
    }
    
    std::cout << "Cat's ideas:" << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "  Idea " << i << ": " << cat1->getIdea(i) << std::endl;
    }
    
    // Test 2: Deep copy functionality
    std::cout << YELLOW << "\n--- Test 2: Deep Copy Testing ---" << RESET << std::endl;
    
    // Create copies using copy constructor
    Dog dog2(*dog1);
    Cat cat2(*cat1);
    
    // Modify original animals' ideas
    dog1->setIdea(0, "Modified dog idea");
    cat1->setIdea(0, "Modified cat idea");
    
    std::cout << "Original dog's first idea (modified): " << dog1->getIdea(0) << std::endl;
    std::cout << "Copied dog's first idea (should be unchanged): " << dog2.getIdea(0) << std::endl;
    
    std::cout << "Original cat's first idea (modified): " << cat1->getIdea(0) << std::endl;
    std::cout << "Copied cat's first idea (should be unchanged): " << cat2.getIdea(0) << std::endl;
    
    // Test 3: Assignment operator
    std::cout << YELLOW << "\n--- Test 3: Assignment Operator Testing ---" << RESET << std::endl;
    
    Dog dog3;
    dog3.setIdea(0, "Dog3 original idea");
    
    std::cout << "Dog3's idea before assignment: " << dog3.getIdea(0) << std::endl;
    
    // Assign dog2 to dog3
    dog3 = dog2;
    
    std::cout << "Dog3's idea after assignment: " << dog3.getIdea(0) << std::endl;
    std::cout << "Dog2's idea (should be same): " << dog2.getIdea(0) << std::endl;
    
    // Modify dog2's idea to test deep copy
    dog2.setIdea(0, "Dog2 modified after assignment");
    
    std::cout << "Dog2's idea after modification: " << dog2.getIdea(0) << std::endl;
    std::cout << "Dog3's idea (should be unchanged): " << dog3.getIdea(0) << std::endl;
    
    // Test 4: Array of Animals with Brain functionality
    std::cout << YELLOW << "\n--- Test 4: Array of Animals ---" << RESET << std::endl;
    
    const int arraySize = 4;
    Animal* animals[arraySize];
    
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();
    
    // Set ideas for animals in array (need to cast to access brain methods)
    static_cast<Dog*>(animals[0])->setIdea(0, "Guard the house");
    static_cast<Cat*>(animals[1])->setIdea(0, "Hunt mice");
    static_cast<Dog*>(animals[2])->setIdea(0, "Play fetch");
    static_cast<Cat*>(animals[3])->setIdea(0, "Nap in sunbeam");
    
    // Display animal types and their first ideas
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << ") ";
        animals[i]->makeSound();
        
        if (animals[i]->getType() == "Dog") {
            std::cout << "  First idea: " << static_cast<Dog*>(animals[i])->getIdea(0) << std::endl;
        } else if (animals[i]->getType() == "Cat") {
            std::cout << "  First idea: " << static_cast<Cat*>(animals[i])->getIdea(0) << std::endl;
        }
    }
    
    // Test 5: Boundary testing
    std::cout << YELLOW << "\n--- Test 5: Boundary Testing ---" << RESET << std::endl;
    
    Dog* boundaryDog = new Dog();
    
    // Test valid boundaries
    boundaryDog->setIdea(0, "First idea");
    boundaryDog->setIdea(99, "Last idea");
    
    std::cout << "Idea at index 0: " << boundaryDog->getIdea(0) << std::endl;
    std::cout << "Idea at index 99: " << boundaryDog->getIdea(99) << std::endl;
    
    // Test invalid boundaries
    std::cout << "Testing invalid boundaries:" << std::endl;
    boundaryDog->setIdea(-1, "Invalid negative index");
    boundaryDog->setIdea(100, "Invalid high index");
    std::string invalidGet1 = boundaryDog->getIdea(-1);
    std::string invalidGet2 = boundaryDog->getIdea(100);
    
    std::cout << "Result from invalid get(-1): " << invalidGet1 << std::endl;
    std::cout << "Result from invalid get(100): " << invalidGet2 << std::endl;
    
    // Cleanup
    std::cout << YELLOW << "\n--- Cleanup ---" << RESET << std::endl;
    
    delete dog1;
    delete cat1;
    delete boundaryDog;
    
    for (int i = 0; i < arraySize; i++) {
        delete animals[i];
    }
    
    std::cout << GREEN << "\n=== Brain Testing Complete ===" << RESET << std::endl;
    
    return 0;
}