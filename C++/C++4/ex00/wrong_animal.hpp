#include <string>
#include <iostream>
#define RESET       "\033[0m"
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

class wrong_animal
{
private:
	std::string type;
public:
	wrong_animal();
	wrong_animal(const std::string &type);
	wrong_animal(const wrong_animal &other);
	wrong_animal &operator=(const wrong_animal &other);
	~wrong_animal();
	void makeSound() const;
	std::string getType() const;
};
#endif //WRONG_ANIMAL_HPP