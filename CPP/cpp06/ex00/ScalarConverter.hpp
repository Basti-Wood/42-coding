#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <cfloat>
#include <iomanip>
#include <cstdlib>
#include <climits>


class ScalarConverter
{
private:
	ScalarConverter();
	~ScalarConverter();
public:
	static void converter(std::string input);

};


#endif