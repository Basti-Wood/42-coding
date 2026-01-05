#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *Donald;
	Bureaucrat *Mickey;
	try
	{
		Donald = new Bureaucrat("Duck", 1);
		Donald->promote();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Mickey = new Bureaucrat(*Donald);
		for (size_t i = 0; i < 150; i++)
		{
			Mickey->demote();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << *Donald << std::endl;
	std::cout << *Mickey << std::endl;

	delete(Donald);
	delete(Mickey);
	return 0;
}