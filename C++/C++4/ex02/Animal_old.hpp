#include <string>
#include <iostream>
#include "Brain.hpp"
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
private:
	std::string type;
public:
	Animal();
	Animal(const std::string &type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal();
	virtual void makeSound() const;
	std::string getType() const;
};



#endif //ANIMAL_HPP