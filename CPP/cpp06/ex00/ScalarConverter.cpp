#include "ScalarConverter.hpp"


static void charConvert(std::string input)
{
	std::cout<< "Char Conversion:" << input[0] << std::endl;
	std::cout<< "Int Conversion:" << static_cast<int>(input[0]) << std::endl;
	std::cout<< "Float Conversion:" << std::fixed << std::setprecision(1) << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout<< "Double Conversion:" << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << std::endl;
}

static void intConvert(std::string input)
{
	int i = std::atoi(input.c_str());

	if (i < 0 || i > 127)
		std::cout << "Char: Impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "Char: Non Displayable" << std::endl;
	else
		std::cout<< "Char Conversion:" << static_cast<char>(i) << std::endl;
	std::cout<< "Int Conversion:" << i << std::endl;
	std::cout<< "Float Conversion:" << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
	std::cout<< "Double Conversion:" << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
}

static void floatConvert(std::string input)
{
	float i = std::atof(input.c_str());

	if (i < 0 || i > 127)
		std::cout << "Char: Impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "Char: Non Displayable" << std::endl;
	else
		std::cout<< "Char Conversion:" << static_cast<char>(i) << std::endl;
	std::cout<< "Int Conversion:" << static_cast<int>(i) << std::endl;
	std::cout<< "Float Conversion:" << std::fixed << std::setprecision(2) << i << "f" << std::endl;
	std::cout<< "Double Conversion:" << std::fixed << std::setprecision(2) << static_cast<double>(i) << std::endl;
}

static void doubleConvert(std::string input)
{
	float i = std::atof(input.c_str());

	if (i < 0 || i > 127)
		std::cout << "Char: Impossible" << std::endl;
	else if (i < 32 || i == 127)
		std::cout << "Char: Non Displayable" << std::endl;
	else
		std::cout<< "Char Conversion:" << static_cast<char>(i) << std::endl;
	std::cout<< "Int Conversion:" << static_cast<int>(i) << std::endl;
	std::cout<< "Float Conversion:" << std::fixed << std::setprecision(2) << static_cast<float>(i) << "f" << std::endl;
	std::cout<< "Double Conversion:" << std::fixed << std::setprecision(2) << (i) << std::endl;
}

static void		minInfConvert() {
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << INT_MIN << std::endl;
	std::cout << "float: " << FLT_MIN << 'f' << std::endl;
	std::cout << "double: " << DBL_MIN << std::endl;
}

static void		maxInfConvert() {
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << INT_MAX << std::endl;
	std::cout << "float: " << FLT_MAX << 'f' << std::endl;
	std::cout << "double: " << DBL_MAX << std::endl;
}

static void		nanConvert() {
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0.0 << 'f' << std::endl;
	std::cout << "double: " << 0.0 << std::endl;
}

static void		errorConvert() {
	std::cout << "char: Impossible" << std::endl;
	std::cout << "int: " << 0 << std::endl;
	std::cout << "float: " << 0.0 << 'f' << std::endl;
	std::cout << "double: " << 0.0 << std::endl;
}

void ScalarConverter::converter(std::string input)
{
	if(!std::isdigit(input[0]) && std::isprint(input[0]))
	{
		if (input.length() == 1)
			charConvert(input);
		else if (input == "-inf" || input == "-inff")
			minInfConvert();
		else if (input == "+inf" || input == "+inff" || input == "inff" || input == "inf")
			maxInfConvert();
		else if (input == "nan" || input == "nanf")
			nanConvert();
		else
			errorConvert();
	}
	else if(input[input.length() - 1] == 'f')
	{
		unsigned int i = 0;
		while (i < input.length() - 1 && (std::isdigit(input[i]) || input[i] == '.'))
			i++;
		if (i == input.length() - 1)
			floatConvert(input);
		else
			errorConvert();
	}
	else if (input.find('.') != std::string::npos)
	{
		unsigned int i = 0;
		int doub = 0;
		while (std::isdigit(input[i]) || input[i] == '.')
		{
			i++;
			if (input[i] == '.')
			{
				doub++;
			}
			
		}
		if (i == input.length() && doub == 1)
			doubleConvert(input);
		else
			errorConvert();
	}
	else if (std::isdigit(input[0])) {
		long unsigned int	i = 0;
		while (std::isdigit(input[i]))
			i++;
		if (i == input.length())
			intConvert(input);
		else
			errorConvert();
	}
	else
		errorConvert();
}