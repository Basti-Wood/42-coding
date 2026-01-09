#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ScalarConverter::converter(argv[1]);
	}
	else
	{
		std::cout << "invalid input" << std::endl;
	}
	return 0;
}