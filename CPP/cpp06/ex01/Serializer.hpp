#ifndef SERIE_HPP
#define SERIE_HPP
#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer();
	Serializer & operator=(Serializer const &src);
	~Serializer();
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif