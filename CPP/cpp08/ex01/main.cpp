#include "Span.hpp"


int randomint(int min, int max)
{
	if (min > max) std::swap(min, max);
	static bool seeded = false;
	if (!seeded) {
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}
	int range = max - min + 1;
	return min + (std::rand() % range);
}

void givenfunc()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int main()
{
	Span s1(20);
	Span s2;
	Span s3(3);
	std::cout << "Span1" << std::endl;
	for(int i = 0; i <= 20; i++)
	{
		try
		{
			s1.addNumber(i);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	try {
		std::cout << "Longest span: " << s1.longestSpan() << std::endl;
		std::cout << "Shortest span: " << s1.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Span2" << std::endl;
	for(int i = 0; i <= 11; i++)
	{
		try
		{
			s2.addNumber(randomint(1, 100));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	try {
		std::cout << "Longest span: " << s2.longestSpan() << std::endl;
		std::cout << "Shortest span: " << s2.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Span3" << std::endl;
	s3.addNumber(4);
	try {
		std::cout << "Longest span: " << s3.longestSpan() << std::endl;
		std::cout << "Shortest span: " << s3.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "___________________GIVEN FUNCTION____________________" << std::endl;
	givenfunc();
	std::cout << "___________________Span Fill____________________" << std::endl;
	Span s4;
	s4.fillSpan(5);
	try {
		std::cout << "Longest span: " << s4.longestSpan() << std::endl;
		std::cout << "Shortest span: " << s4.shortestSpan() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}