#include "wrong_animal.hpp"

#ifndef W_CAT_HPP
#define W_CAT_HPP

class wrong_cat : public wrong_animal
{
public:
	wrong_cat();
	wrong_cat(const wrong_cat &other);
	wrong_cat &operator=(const wrong_cat &other);
	void makeSound() const;
};

#endif