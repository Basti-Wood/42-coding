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

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

class AAnimal
{
	protected:
		std::string type;
	public:
		AAnimal();
		AAnimal(const std::string &type);
		AAnimal(const AAnimal &other);
		AAnimal &operator=(const AAnimal &other);
		virtual ~AAnimal();
		
		virtual void makeSound() const = 0; //= 0 means IT DOESNT EXIST WAKE UP THIS IS PURELY VIRTUAL!!!!
		
		std::string getType() const;
};

#endif //AANIMAL_HPP